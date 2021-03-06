#-------------------------------------------------
#
# Project created by QtCreator 2019-12-24T18:36:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = APP_PLC
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    information.cpp \
        mainwindow.cpp \
    dialog.cpp \
    panel_add_component.cpp \
    parseld2.cpp \
    editld2.cpp \
    UiUpdata.cpp \
    windows.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    information.h \
    panel_add_component.h \
    newstruct.h \
    parseld2.h \
    editld2.h \
    UiUpdata.h \
    windows.h \
    stable.h

FORMS    += mainwindow.ui \
    dialog.ui \
    information.ui \
    panel_add_component.ui \
    windows.ui

CONFIG+=precompile_header
PRECOMPILED_HEADER=stable.h
