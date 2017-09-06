#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T20:00:21
#
#-------------------------------------------------

QT       += core gui sql

TARGET = QtForBoli
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    verificationmethod.cpp \
    checkdev.cpp \
    log/qlog.cpp \
    system/systemmanager.cpp \
    keyborad/digitkey.cpp \
    system/manageruser.cpp \
    system/managernetworkset.cpp \
    system/managermodechange.cpp \
    system/managerlockcontrol.cpp \
    system/managerdatetime.cpp \
    dev/qextserialbase.cpp \
    dev/posix_qextserialport.cpp \
    dev/lockconctlserial.cpp \
    dev/idcardserial.cpp \
    user/usermsg.cpp \
    user/mylineedit.cpp

HEADERS  += mainwindow.h \
    verificationmethod.h \
    checkdev.h \
    log/qlog.h \
    system/systemmanager.h \
    keyborad/digitkey.h \
    system/manageruser.h \
    system/managernetworkset.h \
    system/managermodechange.h \
    system/managerlockcontrol.h \
    system/managerdatetime.h \
    dev/qextserialbase.h \
    dev/posix_qextserialport.h \
    dev/lockconctlserial.h \
    dev/idcardserial.h \
    user/usermsg.h \
    user/mylineedit.h

FORMS    +=
