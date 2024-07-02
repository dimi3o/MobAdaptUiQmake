TARGET = ru.bmstu.MobAdaptUiQmake

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/connection.cpp \
    src/main.cpp \
    src/net.cpp \
    src/neural-net.cpp \
    src/neuron.cpp \
    src/stringobject.cpp \
    src/trainingdata.cpp

HEADERS += \
    src/connection.h \
    src/layer.h \
    src/net.h \
    src/neuron.h \
    src/stringobject.h \
    src/trainingdata.h

DISTFILES += \
    rpm/ru.bmstu.MobAdaptUiQmake.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.bmstu.MobAdaptUiQmake.ts \
    translations/ru.bmstu.MobAdaptUiQmake-ru.ts \
