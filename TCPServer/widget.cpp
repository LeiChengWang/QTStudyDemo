#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4, PORT);

    //客户端发起连接，server发出信号
    connect(server,&QTcpServer::newConnection,this,&Widget::newClientHandler);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::newClientHandler() {
    //建立TCP连接
    QTcpSocket * socket = server->nextPendingConnection();
    socket->peerAddress();  //获取客户端地址
    socket->peerPort();  //获取客户端端口

    ui->ipLineEdit->setText(socket->peerAddress().toString());
    ui->portLineEdit->setText(QString::number(socket->peerPort()));

    //服务端收到客户端的信号，socket发出readyread信号
    connect(socket,&QTcpSocket::readyRead,this,&Widget::clientInfoSlot);

}

void Widget::clientInfoSlot() {
    //获取信号的发出者
    QTcpSocket * s = (QTcpSocket *)sender();
    ui->myLineEdit->setText(QString(s->readAll()));
}
