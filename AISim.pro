TEMPLATE = subdirs

CONFIG += ordered

CONFIG(release, debug|release) {
DEFINES += NDEBUG
}

SUBDIRS += \
        Neural \
	Engine \
	Tools \
	Simulator
