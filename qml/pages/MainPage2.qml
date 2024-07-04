import QtQuick 2.0
import Sailfish.Silica 1.0
import ru.bmstu.MobAdaptUi 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All
    ModelInfo {
        id: modelInfo
        objectName: "modelInfo"
    }
    property int nMes: 0
    PageHeader {
        id: pageHeader
        objectName: "pageHeader"
        title: qsTr("MobAdaptUiQmake")
        extraContent.children: [
            IconButton {
                objectName: "aboutButton"
                icon.source: "image://theme/icon-m-about"
                anchors.verticalCenter: parent.verticalCenter

                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
        ]
    }
    Row{
        id: commandPanel
        anchors.top: pageHeader.bottom
        width: parent.width
        Button {
            text: "Get state"
            width: parent.width/3
            onClicked: {
                if (! modelInfo.timer_is_active())
                {
                    nMes = nMes + 1
                    var n_state = "";
                    modelInfo.updateState("mystate "+nMes.toString());
                }
                consoleModel.insert(0, { text: modelInfo.state })
            }
        }
        Button {
            text: "Start"
            width: parent.width/3
            onClicked: modelInfo.start_timer();
        }
        Button {
            text: "Stop"
            width: parent.width/3
            onClicked: modelInfo.stop_timer();
        }
    }
    ListView {
        id:  consoleListView
        anchors.top: commandPanel.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.margins: 10
        spacing: 10
        model: ListModel {
            id: consoleModel
        }

        delegate: Item {
            height: Theme.itemSizeMedium
            Row{
//                visible: modelInfo.available
                Rectangle {
                    width: consoleListView.width
                    height: Theme.itemSizeMedium
                    color: "#69adb5"
                    radius: 5
                    border.color: "#D0D0D0"
                    border.width: 1

                    Label {
                        id: textArea
                        horizontalAlignment: Text.AlignHCenter
                        text: model.text
                    }
                }
            }
        }
    }

}
