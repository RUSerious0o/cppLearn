import QtQuick 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12

Item {
    id: main

    Item {
        id: taskNameBlock
        width: 200

        Text {
            id: taskNameLabel
            text: qsTr("Введите задачу:")
            width: parent.width
            //anchors.horizontalCenter: parent
        }

        Rectangle {
            border.width: 1
            border.color: 'black'
            radius: 5

            anchors.top: taskNameLabel.bottom
            anchors.topMargin: 6
            width: parent.width
            height: 30

            TextInput {
                objectName: "taskNameInput"

                width: parent.width
                anchors.centerIn: parent
                leftPadding: 10
                selectByMouse: true
            }
        }
    }

    Item {
        id: deadlineBlock
        width: 100
        anchors.left: taskNameBlock.right
        anchors.leftMargin: 6

        Text {
            id: deadlineLabel
            text: qsTr("Deadline:")
            //anchors.horizontalCenter: parent
        }

        Rectangle {
            border.width: 1
            border.color: 'black'
            radius: 5

            anchors.top: deadlineLabel.bottom
            anchors.topMargin: 6
            width: parent.width
            height: 30

            TextInput {
                id: selectedDateInput
                objectName: "selectedDateInput"

                width: parent.width
                anchors.centerIn: parent
                leftPadding: 10
                selectByMouse: false
                //mouseSelectionMode: TextInput.SelectWords
                inputMask: "99.99.9999"
                readOnly: true
            }

            Image {
                id: calendarShowButoon
                source: "qrc:/icons/arrow.png"
                width: 16
                height: 16

                anchors.right: parent.right
                anchors.rightMargin: 6
                anchors.verticalCenter: parent.verticalCenter

                MouseArea {
                    width: parent.width
                    height: parent.height

                    onClicked: {
                        if(calendar.visible === true) {
                            calendar.visible = false;
                        } else {
                            calendar.visible = true;
                        }
                    }
                }
            }

            Calendar {
                id: calendar
                objectName: "calendar"

                anchors.top: parent.bottom
                anchors.topMargin: 6
                z: 100

                visible: false

                onClicked: {
                    selectedDateInput.text = Qt.formatDate(calendar.selectedDate, "dd.MM.yyyy");
                }
            }
        }
    }

    Item {
        id: progressBarBlock
        anchors.left: deadlineBlock.right
        anchors.leftMargin: 6

        Text {
            id: progressBarLabel
            text: qsTr("Прогресс выполнения:")
            //anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: currentProgress
            objectName: "progressSliderTextValue"
            //text: "5"

            anchors.left: progressBarLabel.right
            anchors.leftMargin: 6
        }

        Slider {
            id: progressBar
            objectName: "progressSlider"

            anchors.top: progressBarLabel.bottom
            anchors.topMargin: 6
            height: 30
            from: 0
            to: 10
            stepSize: 1
            //value: 5

            onMoved: {
                currentProgress.text = progressBar.value
            }
        }

        CustomButton {
            anchors.left: progressBar.right
            anchors.verticalCenter: progressBar.verticalCenter
            anchors.leftMargin: 6
        }
    }
}
