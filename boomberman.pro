#-------------------------------------------------
#
# Project created by QtCreator 2018-11-24T20:34:23
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Boomberman
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    player.cpp \
    map.cpp \
    game_engine.cpp

HEADERS += \
    player.h \
    map.h \
    game_engine.h \
    defaults.h

FORMS += \
    game.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DEFINES += "PRO_PATH=\\\"$${_PRO_FILE_PWD_}\\\""
