#-------------------------------------------------
#
# Project created by QtCreator 2014-07-30T14:38:30
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEdit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    db.cpp \
    mapwidget.cpp

HEADERS  += mainwindow.h \
    db.h \
    mapwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    Map.qrc
