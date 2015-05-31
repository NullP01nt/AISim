#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T15:40:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapEdit
TEMPLATE = app

include("../../engine.pri")
INCLUDEPATH += . src

QMAKE_CXXFLAGS += -Wall -Wextra -pedantic

CONFIG += c++11

CONFIG(release, debug|release) {
	message("Release build")
	DESTDIR = build/release
} 
CONFIG(debug, debug|release) {
	message("Debug build")
	DESTDIR = build/debug
    QMAKE_CXXFLAGS += -g
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR     = $$DESTDIR/.moc
RCC_DIR     = $$DESTDIR/.rcc
UI_DIR      = $$DESTDIR/.ui


SOURCES += src/main.cpp \
    src/MutableMap.cpp \
    src/MapEditWindow.cpp \
    src/MapEditWidget.cpp

HEADERS  += \
    src/MutableMap.hpp \
    src/MapEditWindow.hpp \
    src/MapEditWidget.hpp

FORMS    += \
    src/MapEditWindow.ui
