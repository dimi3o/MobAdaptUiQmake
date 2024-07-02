import QtQuick 2.0
import Sailfish.Silica 1.0
import StringObject 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All
    StringObject {
        id: stringObject //----second way CPPtoQML
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
    Button {
        id: updateModel
        anchors.top: pageHeader.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Update"
        onClicked: {
//            for (var i = 0; i < 2000; i++) {
                nMes = nMes + 1
                stringObject.updateValue(nMes.toString());
                consoleModel.insert(0, { text: stringObject.value }) //.append({ text: stringObject.value })
//            }
        }
    }
    ListView {
        id:  consoleListView
        anchors.top: updateModel.bottom
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.margins: 10
        spacing: 20
        model: ListModel {
            id: consoleModel
        }

        delegate: Item {
            height: Theme.itemSizeMedium
            Row{
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
