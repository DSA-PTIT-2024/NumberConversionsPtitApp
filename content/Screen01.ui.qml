

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts
import NumberConversions 1.0

Rectangle {
    id: mainScreen
    width: 500
    height: 600
    property alias lbBaseOutputType: lbBaseOutputType
    property alias tfOuputType: tfOuputType
    property alias lbOutputType: lbOutputType
    property alias rbSwapAction: rbSwapAction
    property alias rbResetAction: rbResetAction
    property alias rbConvertAction: rbConvertAction
    property alias sbPrecision: sbPrecision
    property alias lbBaseInputType: lbBaseInputType
    property alias tfInputType: tfInputType
    property alias lbInputType: lbInputType
    property alias lbTitltleConversionTypes: lbTitltleConversionTypes
    property alias cbbToType: cbbToType
    property alias cbbFromType: cbbFromType
    layer.smooth: false
    layer.enabled: false

    Column {
        id: column1
        anchors.fill: parent

        Label {
            id: lbTitltleConversionTypes
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
                        font.family: "JetBrains Mono"
                        focusPolicy: Qt.ClickFocus
                        flat: true
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
                        currentIndex: 0
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
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 0
                    anchors.rightMargin: 200
                    font.pixelSize: 20
                    verticalAlignment: Text.AlignVCenter
                    wrapMode: Text.WrapAnywhere
                    clip: false
                    rightInset: -5
                    bottomInset: 0
                    selectionColor: "#000000"
                    renderType: Text.QtRendering
                    persistentSelection: false
                    hoverEnabled: true
                    font.family: "JetBrains Mono"
                    font.capitalization: Font.AllUppercase
                    cursorVisible: false
                    Layout.fillWidth: true
                    background: Rectangle {
                        border.color: "#ced4da"
                        border.width: 1
                        radius: 4
                    }
                }

                Label {
                    id: lbBaseInputType
                    width: 50
                    text: qsTr("Label")
                    anchors.verticalCenter: tfInputType.verticalCenter
                    anchors.left: tfInputType.right
                    anchors.bottom: tfInputType.bottom
                    anchors.leftMargin: 0
                    anchors.bottomMargin: 0
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignBottom
                    topPadding: 0
                    topInset: 0
                    padding: 0
                    leftInset: 0
                    font.family: "JetBrains Mono"
                    bottomPadding: 0
                    anchors.verticalCenterOffset: 0
                    Layout.preferredHeight: -1
                    Layout.fillHeight: false
                    background: Rectangle {
                        color: "#e9ecef"
                        radius: 4
                        border.color: "#ced4da"
                        border.width: 1
                    }
                }

                SpinBox {
                    id: sbPrecision
                    x: 323
                    width: 130
                    height: 56
                    value: -1
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    anchors.rightMargin: 0
                    from: -1
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
                y: 379
                width: 468
                height: 96
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

                Row {
                    id: rowLayout
                    height: 70
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    Layout.fillHeight: true
                    Layout.margins: 0
                    spacing: 0
                    Layout.fillWidth: true
                    TextField {
                        id: tfOuputType
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        anchors.leftMargin: 0
                        anchors.rightMargin: 50
                        anchors.bottomMargin: 0
                        font.pixelSize: 20
                        verticalAlignment: Text.AlignVCenter
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        Layout.fillWidth: true
                        clip: false
                        Layout.rowSpan: 1
                        readOnly: true
                        selectionColor: "#000000"
                        placeholderText: qsTr("")
                        font.family: "JetBrains Mono"
                        Layout.fillHeight: true
                        background: Rectangle {
                            color: "#e9ecef"
                            radius: 4
                            border.color: "#ced4da"
                            border.width: 1
                        }
                    }

                    Label {
                        id: lbBaseOutputType
                        width: 50
                        text: qsTr("Label")
                        anchors.verticalCenter: tfOuputType.verticalCenter
                        anchors.right: parent.right
                        anchors.bottom: tfOuputType.bottom
                        anchors.rightMargin: 0
                        anchors.bottomMargin: 0
                        font.pixelSize: 16
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignBottom
                        Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                        font.family: "JetBrains Mono"
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        background: Rectangle {
                            color: "#e9ecef"
                            radius: 4
                            border.color: "#ced4da"
                            border.width: 1
                        }
                    }
                }
            }
        }
    }
}
