import QtQuick 2.0

Rectangle {
    signal press
    property alias text: clickable.text
    property alias image: image.source

    id: container
    border.color: "#333"
    border.width: 1
    height: 110
    width: 150
    radius: 3
    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: clickable.pressed ?  "#3C1414" : Qt.rgba(0.18, 0.18, 0.18, 1)
        }
        GradientStop {
            position: 1.0
            color: clickable.pressed ? "#9C3335" : "black"
        }
    }
    Clickable {
        anchors.fill: parent
        id: clickable
        onPress: container.press()

        textAnchors.horizontalCenter: horizontalCenter
        textAnchors.bottom: bottom
        textAnchors.bottomMargin: 10

        Image {
            id: image
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
