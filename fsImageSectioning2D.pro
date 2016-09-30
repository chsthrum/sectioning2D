#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T14:38:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = fsImageSectioning2D
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fsimagesection2d.cpp \
    fsfilledrotatedrect.cpp

HEADERS += \
    fsimagesection2d.h \
    fsfilledrotatedrect.h

INCLUDEPATH += $(OPENCV_BUILD)\include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv245/build/x86/vc10/lib/ -lopencv_core245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv245/build/x86/vc10/lib/ -lopencv_core245d

INCLUDEPATH += $$PWD/../../../../../../../../opencv245/build/x86/vc10
DEPENDPATH += $$PWD/../../../../../../../../opencv245/build/x86/vc10

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv245/build/x86/vc10/lib/ -lopencv_highgui245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv245/build/x86/vc10/lib/ -lopencv_highgui245d

INCLUDEPATH += $$PWD/../../../../../../../../opencv245/build/x86/vc10
DEPENDPATH += $$PWD/../../../../../../../../opencv245/build/x86/vc10

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv245/build/x86/vc10/lib/ -lopencv_imgproc245
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../opencv245/build/x86/vc10/lib/ -lopencv_imgproc245d

INCLUDEPATH += $$PWD/../../../../../../../../opencv245/build/x86/vc10
DEPENDPATH += $$PWD/../../../../../../../../opencv245/build/x86/vc10
