import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    objectName: "defaultCover"

    CoverTemplate {
        objectName: "applicationCover"
        primaryText: "bmstu"
        secondaryText: "Adaptive UI DQN"
        icon {
            source: Qt.resolvedUrl("../icons/MobAdaptUiQmake.svg")
            sourceSize { width: icon.width; height: icon.height }
        }
    }
}
