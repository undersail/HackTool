#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T16:19:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HackTool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hacker.cpp \
    hackthread.cpp

HEADERS  += mainwindow.h \
    hacker.h \
    hackthread.h \
    hack_define.h

FORMS    += mainwindow.ui
