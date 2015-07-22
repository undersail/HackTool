/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit_charset;
    QLineEdit *lineEdit_cipherKey;
    QLineEdit *lineEdit_expectedCipherText;
    QPushButton *pushButton_hack;
    QLineEdit *lineEdit_cipherText;
    QLabel *label_tips;
    QLabel *label_status;
    QLineEdit *lineEdit_plainText;
    QLineEdit *lineEdit_plainMask;
    QComboBox *comboBox_cryptography;
    QTableView *tableView_records;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_cv;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(461, 573);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit_charset = new QLineEdit(centralWidget);
        lineEdit_charset->setObjectName(QStringLiteral("lineEdit_charset"));
        lineEdit_charset->setGeometry(QRect(30, 30, 401, 20));
        lineEdit_cipherKey = new QLineEdit(centralWidget);
        lineEdit_cipherKey->setObjectName(QStringLiteral("lineEdit_cipherKey"));
        lineEdit_cipherKey->setGeometry(QRect(30, 460, 401, 20));
        lineEdit_expectedCipherText = new QLineEdit(centralWidget);
        lineEdit_expectedCipherText->setObjectName(QStringLiteral("lineEdit_expectedCipherText"));
        lineEdit_expectedCipherText->setGeometry(QRect(30, 150, 401, 20));
        pushButton_hack = new QPushButton(centralWidget);
        pushButton_hack->setObjectName(QStringLiteral("pushButton_hack"));
        pushButton_hack->setGeometry(QRect(350, 500, 81, 23));
        lineEdit_cipherText = new QLineEdit(centralWidget);
        lineEdit_cipherText->setObjectName(QStringLiteral("lineEdit_cipherText"));
        lineEdit_cipherText->setGeometry(QRect(30, 110, 401, 20));
        label_tips = new QLabel(centralWidget);
        label_tips->setObjectName(QStringLiteral("label_tips"));
        label_tips->setGeometry(QRect(30, 190, 151, 21));
        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setGeometry(QRect(190, 190, 241, 21));
        lineEdit_plainText = new QLineEdit(centralWidget);
        lineEdit_plainText->setObjectName(QStringLiteral("lineEdit_plainText"));
        lineEdit_plainText->setGeometry(QRect(240, 70, 191, 20));
        lineEdit_plainMask = new QLineEdit(centralWidget);
        lineEdit_plainMask->setObjectName(QStringLiteral("lineEdit_plainMask"));
        lineEdit_plainMask->setGeometry(QRect(30, 70, 191, 20));
        comboBox_cryptography = new QComboBox(centralWidget);
        comboBox_cryptography->setObjectName(QStringLiteral("comboBox_cryptography"));
        comboBox_cryptography->setGeometry(QRect(30, 500, 191, 22));
        tableView_records = new QTableView(centralWidget);
        tableView_records->setObjectName(QStringLiteral("tableView_records"));
        tableView_records->setGeometry(QRect(30, 230, 401, 211));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(234, 500, 41, 20));
        doubleSpinBox_cv = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_cv->setObjectName(QStringLiteral("doubleSpinBox_cv"));
        doubleSpinBox_cv->setGeometry(QRect(280, 500, 62, 22));
        doubleSpinBox_cv->setMaximum(1);
        doubleSpinBox_cv->setSingleStep(0.1);
        doubleSpinBox_cv->setValue(0.5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 461, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_hack, SIGNAL(clicked()), MainWindow, SLOT(hack()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "HackTool", 0));
        lineEdit_charset->setText(QString());
        lineEdit_cipherKey->setText(QString());
        lineEdit_expectedCipherText->setText(QString());
        pushButton_hack->setText(QApplication::translate("MainWindow", "Hack", 0));
        label_tips->setText(QString());
        label_status->setText(QString());
        label->setText(QApplication::translate("MainWindow", "REC CV:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
