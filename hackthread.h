#ifndef HACKTHREAD_H
#define HACKTHREAD_H

#include <QThread>
#include "hacker.h"

class HackThread : public QThread
{
    Q_OBJECT
public:
    explicit HackThread(HackParams params, QObject *parent = 0);

signals:
    void startHack(HackInfo&);
    void stopHack();

    void hackResult(HackInfo&);
    void hackStatus(QString&);
    void hackDone();

public slots:

protected:
    void run();

private:
    HackParams hackParams;

public:
    Hacker* hacker;

};

#endif // HACKTHREAD_H
