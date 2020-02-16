#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QString>

#include <iostream>

class Document : public QObject
{
Q_OBJECT
    Q_PROPERTY(QString msg READ readMsg  NOTIFY msgChange)
public:
    Document();
    QString readMsg();
    Q_INVOKABLE void sendMsg(QString msg);

public slots:
    void onCallMsg(QString s);

signals:
    void msgChange(QString msg);

private:
    QString mMsg;

};

#endif // DOCUMENT_H
