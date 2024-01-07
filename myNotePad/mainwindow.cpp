#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action_N,&QAction::triggered,this,&MainWindow::newActionSlot);
    connect(ui->action_O,&QAction::triggered,this,&MainWindow::openActionSlot);
    connect(ui->action_S,&QAction::triggered,this,&MainWindow::saveActionSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newActionSlot(){
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文档.txt");
}

void MainWindow::openActionSlot(){
    QString fileName = QFileDialog::getOpenFileName(this,"选择一个文件",
                                 QCoreApplication::applicationFilePath(),
                                 "*");
    if(fileName.isEmpty()) {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }else {
        //qDebug()<<fileName;
        QFile file(fileName);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->textEdit->setText(QString(ba));
        file.close();
    }
}

void MainWindow::saveActionSlot(){
    QString fileName = QFileDialog::getSaveFileName(this,"选择一个文件",
                                                    QCoreApplication::applicationFilePath());
    if(fileName.isEmpty()) {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }else {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QByteArray ba;
        ba.append(ui->textEdit->toPlainText().toLatin1());
        file.write(ba);
        file.close();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k){
    if(k->modifiers() == Qt::ControlModifier && Qt::Key_S) {
        saveActionSlot();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m) {
    QPoint pt = m->pos();
    qDebug()<<pt;

    if(m->button() == Qt::LeftButton) {
        qDebug()<<"按下鼠标左键";
    }else if(m->button() == Qt::RightButton) {
        qDebug()<<"按下鼠标右键";
    }
}

