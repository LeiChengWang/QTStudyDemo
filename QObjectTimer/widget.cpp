#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix;
    if(pix.load(":/photos/photos/1.jpg")){
        ui->label->setPixmap(pix);
    }else {
        qDebug() << "Failed to load image!";
    }

    picID = 2;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startBtn_clicked()
{
    //开启定时器，返回定时器ID
    myTimerID = this->startTimer(TIME_OUT);
}

void Widget::timerEvent(QTimerEvent *event){
    if(event->timerId() != myTimerID) return;
    QString path = ":/photos/photos/";
    path += QString::number(picID);
    path + ".jpg";

    QPixmap pix(path);
    ui->label->setPixmap(pix);

    picID++;
    if(4 == picID){
        picID = 1;
    }
}

void Widget::on_stopBtn_clicked()
{
    this->killTimer(myTimerID);
}

