// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick 6.6
import QtQuick.Dialogs
import NumberConversions 1.0
import MainScreenController 1.0
Window {
    id: window
    width: 500
    height: 600

    visible: true
    maximumHeight: 600
    maximumWidth: 500
    title: "NumberConversions"

    NumberConversionsController {
        id: mainScreenController

    }

    Screen01 {
        id: mainScreen
        anchors.fill: parent

        tfInputType.text: qsTr()

        cbbFromType.valueRole: "baseType"
        cbbFromType.textRole: "displayName"
        cbbFromType.model: [
            { baseType: 2, displayName: qsTr("Binary") },
            { baseType: 10, displayName: qsTr("Decimal") },
            { baseType: 16, displayName: qsTr("Hexadecimal") } ]
        cbbFromType.currentIndex: mainScreenController.fromType

        cbbToType.valueRole: "baseType"
        cbbToType.textRole: "displayName"
        cbbToType.model: [
            { baseType: 2, displayName: qsTr("Binary") },
            { baseType: 10, displayName: qsTr("Decimal") },
            { baseType: 16, displayName: qsTr("Hexadecimal") } ]
        cbbToType.currentIndex: mainScreenController.toType

        cbbFromType.onActivated: (index) => mainScreenController.changeFromType(index)
        cbbToType.onActivated: (index) => mainScreenController.changeToType(index)

        lbTitltleConversionTypes.text: qsTr("Convert %1 to %2").arg(cbbFromType.currentText).arg(cbbToType.currentText)

        lbInputType.text: qsTr("Enter %1 number").arg(cbbFromType.currentText.toLowerCase())
        lbOutputType.text: qsTr("Result in %1").arg(cbbToType.currentText.toLowerCase())

        lbBaseInputType.text: qsTr("%1").arg(cbbFromType.currentValue)
        lbBaseOutputType.text: qsTr("%1").arg(cbbToType.currentValue)

        rbConvertAction.onClicked: mainScreenController.convertNumber(tfInputType.text, sbPrecision.value)

        rbResetAction.onClicked: {
            tfInputType.text = ""
            tfOuputType.text = ""
        }

        rbSwapAction.onClicked: {
            var fromType = cbbFromType.currentIndex
            cbbFromType.activated(cbbToType.currentIndex)
            cbbToType.activated(fromType)
        }

    }

    Connections {
        target: mainScreenController

        onResultChanged: (result) => {
           mainScreen.tfOuputType.text = result
        }
        onErrorOccurred: (error) => {
            if (error) {
                errorDialog.text = error
                errorDialog.open()
            }
        }
        onFromTypeChanged: (fromType) => {
            mainScreen.cbbFromType.currentIndex = fromType
        }
        onToTypeChanged: (toType) => {
            mainScreen.cbbToType.currentIndex = toType
        }
    }

    MessageDialog {
        id: errorDialog
        buttons: StandardButton.Ok
        onAccepted: errorDialog.close()
    }

}

