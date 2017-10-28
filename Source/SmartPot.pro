#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T14:13:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport

TARGET = SmartPot
TEMPLATE = app


SOURCES += main.cpp\
    qcustomplot.cpp \
    spconnector.cpp \
    mainwindow.cpp \
    datahandler.cpp \
    dataview.cpp

HEADERS  += \
    qcustomplot.h \
    spconnector.h \
    mainwindow.h \
    datahandler.h \
    dataview.h

FORMS    += mainwindow.ui \
    dataview.ui

DISTFILES +=

RESOURCES += \
    res.qrc
