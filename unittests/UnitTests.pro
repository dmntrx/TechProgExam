QT = core
QT += testlib sql network
QT -= gui
QT += sql

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_funcforserver_test.cpp \
    ../MyProj_Shkuran_231-3210/filmdb.cpp \


HEADERS += \
    ../MyProj_Shkuran_231-3210/filmdb.h \

