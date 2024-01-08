#include "mythread.h"

myThread::myThread(QTcpSocket *s)
{
    socket = s;
}

void myThread::run() {
    connect(socket,&QTcpSocket::readyRead,this,&myThread::clientInfoSlot);
}

void myThread::clientInfoSlot() {
    //qDebug()<<socket->readAll();
    QByteArray ba = socket->readAll();
    emit sendToWidget(ba);  //发送信号
}
