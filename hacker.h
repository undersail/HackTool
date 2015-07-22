#ifndef HACKER_H
#define HACKER_H

#include <QObject>
#include "hack_define.h"

class Hacker : public QObject
{
    Q_OBJECT

public:
    explicit Hacker(HackParams params, QObject *parent = 0);

signals:
    void hackResult(HackInfo&);
    void hackStatus(QString&);
    void hackDone();

public slots:
    void hack(HackInfo& req);
    void stop();
    void dealComb(QString& combRes);
    void dealPerm(QString& permRes);

private:
    HackParams hackParams;
    HackInfo hackInfo;
    volatile bool stopped;

    float similarity(QString& str1, QString& str2);
    void comb(QString& seed, int m, int n, QString& combRes);
    void perm(QString& seed, int m, int n);
    void swap(QString& seed, int m, int n);
};

#endif // HACKER_H
