TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/Sources/Robot.cpp \
    src/Sources/estado.cpp \
    src/Sources/aestrella.cpp \
    src/Sources/escenario.cpp

HEADERS += \
    src/Headers/estado.h \
    src/Headers/aestrella.h \
    src/Headers/escenario.h

