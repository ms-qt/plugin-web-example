//
// Created by 毛华伟 on 2020/1/6.
//

#include "Web.h"


Web::Web()
{

    // 关联信号
    connect(this, SIGNAL(sendMessage(PluginMetaData * )), this,
            SLOT(receiveMessage(PluginMetaData * )));


}

Web::~Web()
{

}

void Web::loader()
{
    qDebug() << " Login::loader ";
    qmlRegisterType<Document>("Document", 1, 0, "Document");
    QtWebEngine::initialize();
    const QUrl url(QStringLiteral("qrc:/qml/web/web.qml"));

    engine.load(url);


    // 如果需要TOKEN
    QJsonObject qJsonObject;
    // values 为插件名称
    qJsonObject.insert("name", "login");
    // data 下数组为需要获取的数据,
    // access_token
    // refresh_token
    // ...
    qJsonObject.insert("data", "{\"access_token\","
                               "\"refresh_token\","
                               "\"version\""
                               "}");


    PluginMetaData *data = new PluginMetaData();
    QString str = QJsonDocument(qJsonObject).toJson();
    data->setData(&str);
    emit sendMessage(data);

}

void Web::receiveMessage(PluginMetaData *data)
{
    qDebug() << " Login::receiveMessage ";

    QString str = *data->getData();

    qDebug() << "插件接收到的TOKEN : " << str;
}