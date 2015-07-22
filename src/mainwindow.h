#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define METHOD_COUNT 2

#include <QMainWindow>
#include <QStandardItemModel>
#include "hackthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void startHack(HackInfo&);
    void stopHack();

private slots:
    void hack();
    void hackResult(HackInfo& res);
    void hackStatus(QString& status);
    void hackDone();

private:

    Ui::MainWindow *ui;
    QStandardItemModel *modelRecords;

    HackThread* hackThread;
    HackParams hackParams;
    HackInfo hackInfo;

};

#endif // MAINWINDOW_H
