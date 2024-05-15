QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    background.cpp \
    botton.cpp \
    brick.cpp \
    bullet.cpp \
    coin.cpp \
    flag.cpp \
    floor.cpp \
    flower.cpp \
    gaming.cpp \
    goomba.cpp \
    main.cpp \
    mainwindow.cpp \
    mario.cpp \
    mushroom.cpp \
    pipe.cpp \
    pole.cpp

HEADERS += \
    background.h \
    botton.h \
    brick.h \
    bullet.h \
    coin.h \
    flag.h \
    floor.h \
    flower.h \
    gaming.h \
    goomba.h \
    mainwindow.h \
    mario.h \
    mushroom.h \
    pipe.h \
    pole.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    NewMario_zh_TW.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
