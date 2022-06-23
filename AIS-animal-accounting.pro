QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animal.cpp \
    animalsform.cpp \
    bird.cpp \
    caretaker.cpp \
    database.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    mammal.cpp \
    reptile.cpp \
    updateanimalform.cpp \
    updateworkersform.cpp \
    veterinarian.cpp \
    viewanimalsform.cpp \
    workersform.cpp

HEADERS += \
    animal.h \
    animalsform.h \
    bird.h \
    caretaker.h \
    database.h \
    employee.h \
    mainwindow.h \
    mammal.h \
    reptile.h \
    structures.h \
    updateanimalform.h \
    updateworkersform.h \
    veterinarian.h \
    viewanimalsform.h \
    workersform.h

FORMS += \
    animalsform.ui \
    mainwindow.ui \
    updateanimalform.ui \
    updateworkersform.ui \
    viewanimalsform.ui \
    workersform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
