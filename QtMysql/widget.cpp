#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //加载MySQL数据库驱动
    db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName("mydatabase");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("321826");

    if(db.open()) {
        QMessageBox::information(this,"连接提示","连接成功");
    }else {
        QMessageBox::warning(this,"连接提示","连接失败");
    }
}

Widget::~Widget()
{
    delete ui;
}
