#ifndef HACK_DEFINE_H
#define HACK_DEFINE_H

#include <QString>



typedef struct tagHackParams
{
    int mode;

    tagHackParams()
    {
        mode = 0;
    }

}HackParams;



typedef struct tagHackInfo
{
    int method;
    int cryptography;
    QString charset;
    QString plainMask;
    QString plainSeed;
    QString plainText;
    QString cipherKey;
    QString cipherText;
    QString expectedCipherText;

    double totalCount;
    double tryCount;
    float similarity;
    QString tips;

    tagHackInfo()
    {
        method = 0;
        cryptography = 0;
        totalCount = 0;
        tryCount = 0;
        similarity = 0;
    }

}HackInfo;



#endif // HACK_DEFINE_H

