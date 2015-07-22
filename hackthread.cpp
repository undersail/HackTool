#include "hackthread.h"

HackThread::HackThread(HackParams params, QObject *parent) :
    hackParams(params), QThread(parent)
{

}


void HackThread::run()
{
    hacker = new Hacker(hackParams);
    connect(hacker,SIGNAL(destroyed()),this,SLOT(quit()));

    connect(this,SIGNAL(startHack(HackInfo&)),hacker,SLOT(hack(HackInfo&)));
    connect(this,SIGNAL(stopHack()),hacker,SLOT(stop()));
    connect(hacker,SIGNAL(hackResult(HackInfo&)),this,SIGNAL(hackResult(HackInfo&)));
    connect(hacker,SIGNAL(hackStatus(QString&)),this,SIGNAL(hackStatus(QString&)));
    connect(hacker,SIGNAL(hackDone()),this,SIGNAL(hackDone()));

    exec();
}

