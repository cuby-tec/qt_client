######################################################################
# Automatically generated by qmake (2.01a) ?? ??? 6 18:36:39 2018
######################################################################

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TEMPLATE = app
TARGET = thermo
DEPENDPATH += . exchange links profiles links/msmotor
INCLUDEPATH += . exchange links links/msmotor profiles

# Input
HEADERS += mainwindow.h \
           qcustomplot.h \
           exchange/cnccommand.h \
           exchange/exchange.h \
           links/ComDataReq_t.h \
           links/json_sintax.h \
           links/modelState.h \
           links/parson.h \
           links/sHotendControl.h \
#           links/sProfile.h \
           links/status.h \
           links/Status_t.h \
           profiles/profile.h \
           profiles/profiledialog.h \
           links/msmotor/msport.h \
           links/msmotor/sControl.h \
           links/msmotor/sSegment.h \
    thermoplot.h \
    exchange/thermothread.h \
    exchange/usbexchange.h \
    myglobal.h \
    thermolog/thermologview.h \
    thermolog/thermologdialog.h \
    profiles/thermopiddialog.h \
    gparcer/gParcer.h \
    gparcer/ghelper.h \
    gparcer/sgcode.h \
    gparcer/sgparam.h \
    gparcer/gcodeworker.h \
    links/sModelCompState.h \
    links/eModelstate.h \
    gconsole.h \
    exchange/threadexchange.h \
    gparcer/comdata.h
FORMS += mainwindow.ui profiles/profiledialog.ui \
    thermolog/thermologdialog.ui \
    profiles/thermopiddialog.ui
SOURCES += main.cpp \
           mainwindow.cpp \
           qcustomplot.cpp \
           exchange/cnccommand.cpp \
           exchange/exchange.cpp \
           links/json_sintax.c \
           links/parson.c \
           profiles/profile.cpp \
           profiles/profiledialog.cpp \
    thermoplot.cpp \
    exchange/thermothread.cpp \
    exchange/usbexchange.cpp \
    myglobal.cpp \
    thermolog/thermologview.cpp \
    thermolog/thermologdialog.cpp \
    profiles/thermopiddialog.cpp \
    gparcer/gParcer.c \
    gparcer/ghelper.c \
    gparcer/gcodeworker.cpp \
    gconsole.cpp \
    exchange/threadexchange.cpp \
    gparcer/comdata.cpp
RESOURCES += resources.qrc

DISTFILES += \
    readme.txt
