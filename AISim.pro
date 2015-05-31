TEMPLATE = subdirs

CONFIG += ordered

CONFIG(release, debug|release) {
DEFINES += NDEBUG
}

SUBDIRS += \
	opennn \
	Engine \
        Tools \
        Simulator
