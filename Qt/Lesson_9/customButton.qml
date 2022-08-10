import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    signal addTaskRequest()

    id: addTaskButton
    objectName: "addTaskButton"

    width: 120
    height: 30
    gradient: Gradient {
        GradientStop { position: 0.0; color: mouseArea.pressed ? '#7F7F7F' : '#262626' }
        GradientStop { position: 1.0; color: mouseArea.pressed ? '#262626' : '#7F7F7F' }
    }

    radius: 10

    MouseArea {
        id: mouseArea
        acceptedButtons: Qt.LeftButton
        anchors.fill: parent

        onClicked: {
            addTaskRequest()
        }
    }

    Text {
        text: qsTr("Добавить")
        color: '#E5E5E5'
        anchors.centerIn: parent

    }
}
