#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modelRecords = new QStandardItemModel(this);
    modelRecords->setColumnCount(5);
    QStringList header;
    header.clear();
    header.append("Method");
    header.append("Index");
    header.append("PlainText");
    header.append("CipherText");
    header.append("Similarity");
    modelRecords->setHorizontalHeaderLabels(header);
    ui->tableView_records->setModel(modelRecords);
    ui->tableView_records->verticalHeader()->hide();
//  ui->tableView_records->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_records->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->lineEdit_charset->setPlaceholderText("Plain text charset");
//  ui->lineEdit_charset->setText("abcdefghijklmnopqrstuvwxyz0123456789");
    ui->lineEdit_charset->setText("jacksezapps");
    ui->lineEdit_plainMask->setPlaceholderText("Plain text mask");
    ui->lineEdit_plainText->setPlaceholderText("Current plain text");
    ui->lineEdit_cipherText->setPlaceholderText("Current cipher text");
    ui->lineEdit_expectedCipherText->setPlaceholderText("Expected cipher text");
    ui->lineEdit_expectedCipherText->setText("4051e89fe37fcfae9c1b8b4d5f347045");
    ui->lineEdit_cipherKey->setPlaceholderText("Cipher key");

    QString tips = QString("A	ASCII alphabetic character required. A-Z, a-z.\r\n"
                           "a	ASCII alphabetic character permitted but not required.\r\n"
                           "N	ASCII alphanumeric character required. A-Z, a-z, 0-9.\r\n"
                           "n	ASCII alphanumeric character permitted but not required.\r\n"
                           "X	Any character required.\r\n"
                           "x	Any character permitted but not required.\r\n"
                           "9	ASCII digit required. 0-9.\r\n"
                           "0	ASCII digit permitted but not required.\r\n"
                           "D	ASCII digit required. 1-9.\r\n"
                           "d	ASCII digit permitted but not required (1-9).\r\n"
                           "#	ASCII digit or plus/minus sign permitted but not required.\r\n"
                           "H	Hexadecimal character required. A-F, a-f, 0-9.\r\n"
                           "h	Hexadecimal character permitted but not required.\r\n"
                           "B	Binary character required. 0-1.\r\n"
                           "b	Binary character permitted but not required.\r\n"
                           ">	All following alphabetic characters are uppercased.\r\n"
                           "<	All following alphabetic characters are lowercased.\r\n"
                           "!	Switch off case conversion.\r\n"
                           "\\	Use \\ to escape the special characters listed above to use them as separators.\r\n"
                           "\r\ne.g. AAAAAA	6 ASCII alphabetic characters required.");
    ui->lineEdit_plainMask->setToolTip(tips);
    ui->lineEdit_plainMask->setText("AAAAAA");

    QStringList cryptography;
    cryptography<<"Md4"
        <<"Md5"
        <<"Sha1"
        <<"Sha224"
        <<"Sha256"
        <<"Sha384"
        <<"Sha512"
        <<"Sha3_224"
        <<"Sha3_256"
        <<"Sha3_384"
        <<"Sha3_512";
    ui->comboBox_cryptography->addItems(cryptography);
    ui->comboBox_cryptography->setCurrentIndex(1);

    qRegisterMetaType<HackInfo>("HackInfo");
    qRegisterMetaType<HackInfo>("HackInfo&");
    qRegisterMetaType<QString>("QString");
    qRegisterMetaType<QString>("QString&");

    hackThread = new HackThread( hackParams, this);
    connect(hackThread,SIGNAL(finished()),hackThread,SLOT(deleteLater()));
    connect(this,SIGNAL(startHack(HackInfo&)),hackThread,SIGNAL(startHack(HackInfo&)));
    connect(this,SIGNAL(stopHack()),hackThread,SIGNAL(stopHack()));
    connect(hackThread,SIGNAL(hackResult(HackInfo&)),this,SLOT(hackResult(HackInfo&)));
    connect(hackThread,SIGNAL(hackStatus(QString&)),this,SLOT(hackStatus(QString&)));
    connect(hackThread,SIGNAL(hackDone()),this,SLOT(hackDone()));
    hackThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;

    if(modelRecords != NULL)
    {
        delete modelRecords;
        modelRecords = NULL;
    }
}

void MainWindow::hack()
{
    hackInfo.method = 0;
    hackInfo.cryptography = ui->comboBox_cryptography->currentIndex();
    hackInfo.charset = ui->lineEdit_charset->text();
    hackInfo.plainMask = ui->lineEdit_plainMask->text();
    hackInfo.plainText = ui->lineEdit_plainText->text();
    hackInfo.cipherKey = ui->lineEdit_cipherKey->text();
    hackInfo.expectedCipherText = ui->lineEdit_expectedCipherText->text();

    if(ui->pushButton_hack->text() == "Hack")
    {
        while(modelRecords->rowCount() > 0)
        {
            modelRecords->takeRow(0);
        }
        ui->pushButton_hack->setText("Hacking...");
        emit startHack(hackInfo);
    }
    else if(ui->pushButton_hack->text() == "Stop")
    {
        emit stopHack();
        ui->pushButton_hack->setText("Hack");
    }
}

void MainWindow::hackResult(HackInfo& res)
{
    ui->lineEdit_plainText->setText(res.plainText);
    ui->lineEdit_cipherText->setText(res.cipherText);
    ui->label_tips->setText(res.tips);

    if(res.similarity >= ui->doubleSpinBox_cv->value())
    {
        while(modelRecords->rowCount() > 1000)
        {
            modelRecords->takeRow(0);
        }

        int nRow = modelRecords->rowCount();
        modelRecords->insertRow(nRow);
        QStandardItem *item = new QStandardItem(QString("%1:%2").arg(res.method).arg(res.cryptography));
        modelRecords->setItem(nRow,0,item);
        item = new QStandardItem(QString("%1").arg(res.tryCount));
        modelRecords->setItem(nRow,1,item);
        item = new QStandardItem(QString("%1").arg(res.plainText));
        item->setData(res.plainText);
        modelRecords->setItem(nRow,2,item);
        item = new QStandardItem(QString("%1").arg(res.cipherText));
        item->setData(res.cipherText);
        modelRecords->setItem(nRow,3,item);
        item = new QStandardItem(QString("%1").arg(res.similarity));
        item->setData(res.similarity);
        modelRecords->setItem(nRow,4,item);
    }
}

void MainWindow::hackStatus(QString& status)
{
    ui->label_status->setText(status);
}


void MainWindow::hackDone()
{
    ui->pushButton_hack->setText("Hack");
}


