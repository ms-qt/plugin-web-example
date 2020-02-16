

#include "Document.h"

Document::Document()
{

}

void Document::sendMsg(QString msg)
{


    std::cout<<"void Document::sendMsg(QString msg)"<<std::endl;
    mMsg=msg;

    emit msgChange(msg);

}


void Document::onCallMsg(QString msg)
{
    std::cout<<"msg : "<<msg.toStdString()<<std::endl;
}

QString Document::readMsg()
{
    return mMsg;
}
