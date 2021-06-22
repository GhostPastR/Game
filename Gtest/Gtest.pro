QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gtest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vobjs.cpp \
    dobja.cpp \
    renderscene.cpp \
    dobjy.cpp \
    vobjs_2ob.cpp \
    gobject.cpp

HEADERS  += mainwindow.h \
    vobjs.h \
    dobja.h \
    renderscene.h \
    dobjy.h \
    vobjs_2ob.h \
    gobject.h

FORMS    += mainwindow.ui
