//
// Created by 毛华伟 on 2020/1/6.
//

#ifndef PLUGIN_WEB_WEB_H
#define PLUGIN_WEB_WEB_H


#include <QObject>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QtWebEngine>
#include "plugin-web_global.h"
#include "apppluginterface/IAppPluginInterface.h"
#include "apppluginterface/PluginMetaData.h"
#include "Document.h"

class PLUGINWEB_EXPORT Web : public IAppPluginInterface
{
Q_OBJECT
    Q_PLUGIN_METADATA(IID
                              IAppPluginInterface_iid
                              FILE
                              "pluginconfig.json")
    Q_INTERFACES(IAppPluginInterface)
public:

    Web();
    ~Web() override;

    void loader() override;


signals:

    void sendMessage(PluginMetaData *data) override;

public slots:

    void receiveMessage(PluginMetaData *data) override;


private:
    QQmlApplicationEngine engine;

};


#endif //PLUGIN_WEB_WEB_H