QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
	sources/main.cpp \
	sources/mainwindow.cpp \
	sources/network/client.cpp \
	sources/network/connection.cpp \
	sources/network/resource.cpp \
	sources/network/server.cpp \
	sources/network/timers/windowstimer.cpp

HEADERS += \
	sources/mainwindow.h \
	sources/network/client.h \
	sources/network/connection.h \
	sources/network/request.h \
	sources/network/resource.h \
	sources/network/server.h \
	sources/network/timers/windowstimer.h

FORMS += \
	sources/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	sources/resources/resource.qrc
