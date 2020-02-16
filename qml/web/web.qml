import QtQuick 2.0
import QtQuick.Window 2.0
import QtWebEngine 1.7
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.11
import QtWebChannel 1.0

import Document 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Document{
        id:document
        WebChannel.id: "cppAndjavascript"
    }

    WebEngineView {
        id: webEngineView
        // 网页路径
        url: "qrc:/html/web/index.html"
        anchors.fill: parent
        settings.pluginsEnabled: true
        settings.screenCaptureEnabled: true
        //AllowRunningInsecureContent
        settings.allowRunningInsecureContent: true

        settings.javascriptEnabled: true
        webChannel: channel
        onJavaScriptConsoleMessage: {
            console.log(message)
        }

        onFeaturePermissionRequested: {

            if(feature  == WebEngineView.MediaAudioCapture
                    || feature == WebEngineView.MediaAudioVideoCapture
                    || feature ==  WebEngineView.MediaVideoCapture){

                grantFeaturePermission(securityOrigin,feature,true)

            } else{
                grantFeaturePermission(securityOrigin,feature,false)

            }
        }
    }

    WebChannel {
        id: channel
        registeredObjects: [document]
    }

    Button {
        text: "Enlighten"
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 30

        // 参考解释：https://www.pressc.cn/1085.html
        // 调用方法
        onClicked: document.sendMsg("Hello")
    }
}
