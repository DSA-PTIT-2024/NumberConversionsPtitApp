import QtQuick 2.15
import QtQuick 6.2
import QtQuick.Controls 6.2
import MainScreenController 1.0
import QtQuick.Layouts

Rectangle {

    id: mainScreen
    width: 500
    height: 600
    layer.smooth: false
    layer.enabled: false

    Column {
        id: column1
        anchors.fill: parent

        Label {
            id: lbTitltleConversionTypes
            text: qsTr("Label")
            anchors.left: rectangle.left
            anchors.bottom: rectangle.top
            anchors.leftMargin: 0
            anchors.bottomMargin: 5
            font.pixelSize: 22
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.family: "JetBrains Mono"
        }

        Rectangle {
            id: rectangle
            y: 78
            width: 484
            height: 514
            visible: true
            color: "#f0eedc"
            radius: 7
            border.color: "#f0eedc"
            border.width: 1
            anchors.horizontalCenter: parent.horizontalCenter
            layer.smooth: false
            clip: true

            RowLayout {
                id: rowLayout1
                x: 8
                y: 34
                width: 468
                height: 118
                spacing: 20
                ColumnLayout {
                    id: columnLayout
                    x: 55
                    y: 66
                    width: 144
                    height: 132
                    Label {
                        id: lbFromType
                        width: 118
                        text: qsTr("From")
                        font.pixelSize: 20
                        verticalAlignment: Text.AlignVCenter
                        lineHeightMode: Text.ProportionalHeight
                        renderType: Text.QtRendering
                        fontSizeMode: Text.FixedSize
                        font.family: "JetBrains Mono"
                        font.bold: true
                    }

                    ComboBox {
                        id: cbbFromType
                        y: 125
                        height: 68
                        font.pixelSize: 16
                        wheelEnabled: false
                        textRole: "rwter"
                        state: ""
                        font.family: "JetBrains Mono"
                        focusPolicy: Qt.ClickFocus
                        flat: true
                        displayText: "rwter"
                        currentIndex: 0
                        Layout.fillWidth: true
                    }
                    Layout.rowSpan: 1
                    Layout.fillWidth: true
                    Layout.columnSpan: 1
                }

                ColumnLayout {
                    id: columnLayout1
                    x: 172
                    y: 193
                    width: 100
                    height: 100
                    Label {
                        id: lbToType
                        width: 50
                        text: qsTr("To")
                        font.pixelSize: 20
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        font.family: "JetBrains Mono"
                        font.bold: true
                    }

                    ComboBox {
                        id: cbbToType
                        y: 125
                        font.pixelSize: 16
                        layer.smooth: false
                        font.family: "JetBrains Mono"
                        focusPolicy: Qt.ClickFocus
                        Layout.rowSpan: 1
                        Layout.preferredWidth: -1
                        Layout.minimumWidth: 0
                        Layout.fillWidth: true
                    }
                    Layout.rowSpan: 2
                    Layout.fillWidth: true
                    Layout.columnSpan: 2
                }
            }

            Row {
                id: row
                x: 8
                y: 165
                width: 468
                height: 61
                Label {
                    id: lbInputType
                    width: 100
                    text: "DAFSGR"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    font.pixelSize: 20
                    verticalAlignment: Text.AlignVCenter
                    font.family: "JetBrains Mono"
                    font.bold: true
                }

                Label {
                    id: lbPrecision
                    x: 58
                    width: 123
                    height: 60
                    text: qsTr("Precision")
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    font.pixelSize: 16
                    verticalAlignment: Text.AlignBottom
                    font.family: "JetBrains Mono"
                }
            }

            Row {
                id: row1
                x: 8
                y: 220
                width: 468
                height: 73
                TextField {
                    id: tfInputType
                    height: 56
                    text: "bvgfds"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 0
                    anchors.rightMargin: 200
                    font.pixelSize: 20
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    selectionColor: "#000000"
                    renderType: Text.QtRendering
                    persistentSelection: false
                    hoverEnabled: true
                    font.family: "JetBrains Mono"
                    font.capitalization: Font.AllUppercase
                    cursorVisible: false
                    Layout.fillWidth: true
                }

                Label {
                    id: lbBaseInputType
                    width: 59
                    text: qsTr("Label")
                    anchors.verticalCenter: tfInputType.verticalCenter
                    anchors.left: tfInputType.right
                    anchors.leftMargin: 0
                    font.pixelSize: 18
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    topPadding: 10
                    topInset: 0
                    padding: 10
                    leftInset: 0
                    font.family: "JetBrains Mono"
                    bottomPadding: 10
                    anchors.verticalCenterOffset: 0
                    Layout.preferredHeight: -1
                    Layout.fillHeight: false
                }

                SpinBox {
                    id: sbPrecision
                    x: 323
                    width: 124
                    height: 56
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                }
            }

            Row {
                id: row2
                x: 8
                y: 299
                width: 468
                height: 57
                RoundButton {
                    id: rbConvertAction
                    x: 18
                    width: 118
                    height: 52
                    radius: 5
                    text: "= Convert"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                    transformOrigin: Item.Center
                    icon.color: "#207411"
                    hoverEnabled: true
                    highlighted: false
                    font.family: "JetBrains Mono"
                    flat: false
                    enabled: true
                    contentItem: Text {
                        color: "#ffffff"
                        text: rbConvertAction.text
                        verticalAlignment: Text.AlignVCenter
                        font: rbConvertAction.font
                    }
                    clip: true
                    checkable: false
                    autoRepeat: false
                    Material.background: "#207411"
                    Layout.fillWidth: true
                }

                RoundButton {
                    id: rbResetAction
                    x: 142
                    width: 118
                    height: 52
                    radius: 5
                    text: "Reset"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                    transformOrigin: Item.Center
                    rotation: 0.299
                    layer.smooth: false
                    icon.source: "../asset_imports/closeIcon.png"
                    icon.color: "white"
                    hoverEnabled: true
                    highlighted: false
                    font.family: "JetBrains Mono"
                    focusPolicy: Qt.ClickFocus
                    flat: false
                    enabled: true
                    clip: true
                    checkable: false
                    background: Rectangle {
                        color: rbResetAction.down ? "#aa905e" : "#7d83d8"
                        radius: 5
                        clip: true
                    }
                    autoRepeat: false
                    antialiasing: false
                    Material.foreground: "white"
                    Layout.fillWidth: true
                }

                RoundButton {
                    id: rbSwapAction
                    x: 142
                    width: 118
                    height: 52
                    radius: 5
                    text: "Swap"
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 16
                    transformOrigin: Item.Center
                    rotation: 0.299
                    icon.source: "../asset_imports/swapIcon.png"
                    icon.color: "white"
                    hoverEnabled: true
                    highlighted: false
                    font.family: "JetBrains Mono"
                    focusPolicy: Qt.ClickFocus
                    flat: false
                    enabled: true
                    clip: true
                    checkable: false
                    background: Rectangle {
                        color: rbSwapAction.down ? "#aa905e" : "#7d83d8"
                        radius: 5
                        clip: true
                    }
                    autoRepeat: false
                    Material.foreground: "white"
                    Layout.fillWidth: true
                }
            }

            ColumnLayout {
                id: column
                x: 8
                y: 362
                width: 468
                height: 118
                Label {
                    id: lbOutputType
                    text: qsTr("Label")
                    anchors.left: parent.left
                    anchors.bottom: rowLayout.top
                    anchors.leftMargin: 0
                    anchors.bottomMargin: 0
                    font.pixelSize: 20
                    verticalAlignment: Text.AlignVCenter
                    font.family: "JetBrains Mono"
                    font.bold: true
                }

                RowLayout {
                    id: rowLayout
                    height: 70
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    TextField {
                        id: tfOuputType
                        font.pixelSize: 20
                        verticalAlignment: Text.AlignVCenter
                        readOnly: true
                        selectionColor: "#000000"
                        placeholderText: qsTr("")
                        font.family: "JetBrains Mono"
                        Layout.fillWidth: true
                        Layout.fillHeight: false
                    }

                    Label {
                        id: lbBaseOutputType
                        text: qsTr("Label")
                        font.pixelSize: 18
                        verticalAlignment: Text.AlignVCenter
                        font.family: "JetBrains Mono"
                        Layout.fillWidth: false
                        Layout.fillHeight: false
                    }
                }
            }
        }
    }
}
