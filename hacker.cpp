#include "hacker.h"
#include <QCryptographicHash>
#include <QThread>

Hacker::Hacker(HackParams params, QObject *parent) :
    hackParams(params), QObject(parent)
{
    stopped = true;
}

void Hacker::hack( HackInfo& req )
{
    stopped = false;
    if(req.charset == "")
    {
        emit hackDone();
        QString info = QString("Hack done! Charset is empty.");
        emit hackStatus(info);
        return;
    }

    hackInfo = req;
    if(hackInfo.method == 0)
    {
        int m = hackInfo.plainMask.size();
        int n = hackInfo.charset.size();
        double facm = 1;
        double facn = 1;
        double facnsm = 1;
        for(int i = 1; i <= n; i++)
        {
            facn *= i;
            if(i <= m)
            {
               facm *= i;
            }
            if(i <= n - m)
            {
               facnsm *= i;
            }
        }

        hackInfo.totalCount = facm*facn/(facm*facnsm);

        if(m > 0)
        {
            QString combRes(m, 'A');
            comb(hackInfo.charset, m, n, combRes);
        }
        else
        {
            hackInfo.plainSeed = hackInfo.charset;
            int n = hackInfo.plainSeed.size();
            perm(hackInfo.plainSeed, 0, n);
        }
    }
}

void Hacker::stop()
{
    stopped = true;
}


void Hacker::dealComb(QString& combRes)
{
    hackInfo.plainSeed = combRes;
    int n = hackInfo.plainSeed.size();
    perm(hackInfo.plainSeed, 0, n);
}

void Hacker::dealPerm(QString& permRes)
{
    hackInfo.plainText = permRes;
    if(hackInfo.method == 0)
    {
        QByteArray srcData,resData;
        QCryptographicHash hash((QCryptographicHash::Algorithm)hackInfo.cryptography);

        srcData.append(hackInfo.plainText);
        hash.addData(srcData);
        resData = hash.result();
        hackInfo.tryCount++;
        hackInfo.cipherText = "";
        hackInfo.cipherText.append(resData.toHex());
    }

    hackInfo.similarity = similarity(hackInfo.cipherText, hackInfo.expectedCipherText);
    hackInfo.tips = QString("[%1:%2:%3:%4] ").
            arg(hackInfo.method).
            arg(hackInfo.cryptography).
            arg(hackInfo.tryCount).
            arg(hackInfo.similarity, 0, 'f', 5);
    if(hackInfo.similarity > 0.5)
    {
        hackInfo.tips += "Bingo!";
    }
    else
    {
        hackInfo.tips += "Fail!";
    }
    emit hackResult(hackInfo);

    double d = hackInfo.totalCount - hackInfo.tryCount;
    double secs = d/1000;
    QString info = QString("Remain %1 seconds to complete.").arg(secs);
    if(secs > 60*60*24)
    {
        double days = secs/60/60/24;
        info = QString("Remain %1 days to complete.").arg(days);
        if(days > 365)
        {
            double years = days/365;
            info = QString("Remain %1 years to complete.").arg(years);
        }
    }
    emit hackStatus(info);
    QThread::usleep(10);

    if(hackInfo.tryCount >= hackInfo.totalCount)
    {
        emit hackDone();
        info = QString("Hack done! Total count: %1.").arg(hackInfo.totalCount);
        emit hackStatus(info);
    }
}


/////////////////////////////////////////////////////////////


float Hacker::similarity(QString& str1, QString& str2)
{
    QString s1 = str1.toLower();
    QString s2 = str2.toLower();
    if((s2 != "" && s1.contains(s2)) || (s1 != NULL && s2.contains(s1)))
    {
        return 1;
    }

    if(s1.size() < s2.size())
    {
        QString tmp = s1;
        s1 = s2;
        s2 = tmp;
    }

    int n = s1.size() - s2.size();
    int **diffs = new int*[n + 1];
    for(int i = 0; i <= n; i++)
    {
        diffs[i] = new int[s2.size()];
        memset(diffs[i],0,sizeof(int)*s2.size());
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < s2.size(); j++)
        {
            int diff = s1[i + j].unicode() - s2[j].unicode();
            diffs[i][j] = diff;
        }
    }

    int maxMaxSameDiff = -1;
    for(int i = 0; i <= n; i++)
    {
        int maxSameDiff = -1;
        for(int j = 0; j < s2.size(); j++)
        {
            int sameDiff = 1;
            for(int k = j + 1; k < s2.size(); k++)
            {
                if(diffs[i][j] == diffs[i][k])
                {
                    sameDiff++;
                }
            }

            if(maxSameDiff < sameDiff)
            {
                maxSameDiff = sameDiff;
            }
        }

        if(maxMaxSameDiff < maxSameDiff)
        {
            maxMaxSameDiff = maxSameDiff;
        }
    }

    for(int i = 0; i <= n; i++)
    {
        delete [] diffs[i];
        diffs[i] = NULL;
    }
    delete [] diffs;
    diffs = NULL;

    float similarity = (float)maxMaxSameDiff/s1.size();
    if(similarity < 0) similarity = 0;
    return similarity;
}

void Hacker::comb(QString& seed, int m, int n, QString& combRes)
{
    if(stopped || m > n)
    {
        return;
    }

    for(int i = n; i >= m; i--)
    {
        combRes.insert(m - 1, seed.at(i - 1));
        combRes.remove(m, 1);
        if (m > 1)
        {
            comb(seed, m-1, i-1, combRes);
        }
        else
        {
            dealComb(combRes);
        }
    }
}

void Hacker::perm(QString& seed, int m, int n)
{
    if(stopped || m > n || n > seed.size())
    {
        return;
    }

    if(m == n - 1)
    {
        QString permRes = "";
        for(int i = 0; i < n; i++)
        {
            permRes.append(seed.at(i));
        }

        dealPerm(permRes);
    }
    else
    {
        for(int i = m; i < n; i++)
        {
            swap(seed,i,m);
            perm(seed, m+1, n);
            swap(seed,i,m);
        }
    }
}

void Hacker::swap(QString& seed, int index1, int index2)
{
    if(index1 >= seed.size() || index2 >= seed.size())
    {
        return;
    }

    QChar temp = seed.at(index1);
    seed.insert(index1,seed.at(index2));
    seed.remove(index1 + 1, 1);
    seed.insert(index2,temp);
    seed.remove(index2 + 1, 1);
}
