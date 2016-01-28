#-------------------------------------------------
#
# Project created by QtCreator 2016-01-24T02:23:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shape.cpp \
    circle.cpp \
    rectangle.cpp \
    triangle.cpp

HEADERS  += mainwindow.h \
    shape.h \
    circle.h \
    rectangle.h \
    triangle.h

FORMS    += mainwindow.ui
