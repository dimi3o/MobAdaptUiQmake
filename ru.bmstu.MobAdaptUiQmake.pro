TARGET = ru.bmstu.MobAdaptUiQmake

CONFIG += \
    auroraapp

DEPLOYMENT_PATH = /usr/share/$${TARGET}

data.files = data
data.path = $${DEPLOYMENT_PATH}

PKGCONFIG += \

SOURCES += \
    src/connection.cpp \
    src/main.cpp \
    src/modelinfo.cpp \
    src/net.cpp \
    src/neural-net.cpp \
    src/neuron.cpp \
    src/stringobject.cpp \
    src/trainingdata.cpp

INSTALLS += data

HEADERS += \
    src/connection.h \
    src/layer.h \
    src/modelinfo.h \
    src/net.h \
    src/neuron.h \
    src/stringobject.h \
    src/trainingdata.h

DISTFILES += \
    AUTHORS.md \
    LICENSE.BSD-3-Clause.md \
    README.md \
    data/trainingData.txt \
    data/xor/xordata.txt \
    data/xor/xordataT.txt \
    qml/pages/MainPage2.qml \
    rpm/ru.bmstu.MobAdaptUiQmake.spec

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.bmstu.MobAdaptUiQmake.ts \
    translations/ru.bmstu.MobAdaptUiQmake-ru.ts \
