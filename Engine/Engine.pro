#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T16:29:11
#
#-------------------------------------------------

### QMake definitions (Config, Template, Target etc.)

QT       -= gui

TEMPLATE = lib
CONFIG += staticlib c++11

TARGET = Engine

INCLUDEPATH += . include

OBJECTS_DIR 	= build/obj
MOC_DIR		= build/moc
RCC_DIR 	= build/rcc
UI_DIR 		= build/ui

CONFIG(release) {
        DESTDIR = release
}

include($$PWD/../neural.pri)

### Sources

SOURCES += \
    src/Map.cpp \
    src/Agent.cpp \
    src/Environment.cpp \
    src/NeuralAgent.cpp

HEADERS += \
    include/Engine/Map.hpp \
    include/Engine/Agent.hpp \
    include/Engine/Environment.hpp \
    include/Engine/NeuralAgent.hpp



