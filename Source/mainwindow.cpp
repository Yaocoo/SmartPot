#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtSerialPort/QtSerialPort>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    spc = new SPConnector(this);
    dataHdl = new DataHandler(this);
//    ui->dataView->setDataHdl(dataHdl);

    this->initParam();

//    connect(spc, SIGNAL(sendData(QStringList)), ui->dataView, SLOT(receiveData(QStringList)));
//    connect(dataHdl, SIGNAL(recordFinished()), this, SLOT(stopRecord()));
//    connect(dataHdl, SIGNAL(noticeProgressBar(int)), this, SLOT(setProgressBar(int)));
}

MainWindow::~MainWindow()
{
    delete spc;
    delete dataHdl;
    delete ui;
}

void MainWindow::stopRecord()
{
    this->recordStatus = false;
    QMessageBox::warning(this, "Message", "Saving file is succeed!", QMessageBox::Yes);
}

void MainWindow::setProgressBar(int num)
{
    qDebug() << num;
//    ui->progressBar->setValue(num);
}

void MainWindow::initParam()
{
    recordStatus = false;
    foreach (QSerialPortInfo portInfo, QSerialPortInfo::availablePorts()) {
        ui->portCB->addItem(portInfo.portName() + " : " + portInfo.description());
    }
}

void MainWindow::on_actionOpen_triggered()
{
    spc->autoSetPortName();
    if(spc->open()) {
    } else {
        QMessageBox::warning(NULL, "Message", "COM opening is failed!", QMessageBox::Yes);
    }
}

void MainWindow::on_actionClose_triggered()
{
    spc->close();
    dataHdl->resetDataSet();
    ui->dataView->resetVector();
}

void MainWindow::on_actionRecord_triggered()
{
    this->recordStatus = true;
}

void MainWindow::on_view1Btn_clicked()
{
    ui->dataView->setDetectIndex(0);
    ui->dataView->resetVector();
}

void MainWindow::on_view2Btn_clicked()
{
    ui->dataView->setDetectIndex(1);
    ui->dataView->resetVector();
}

void MainWindow::on_view3Btn_clicked()
{
    ui->dataView->setDetectIndex(2);
    ui->dataView->resetVector();
}

void MainWindow::on_view4Btn_clicked()
{
    ui->dataView->setDetectIndex(3);
    ui->dataView->resetVector();
}

void MainWindow::on_view5Btn_clicked()
{
    ui->dataView->setDetectIndex(4);
    ui->dataView->resetVector();
}

void MainWindow::on_view6Btn_clicked()
{
    ui->dataView->setDetectIndex(5);
    ui->dataView->resetVector();
}

void MainWindow::on_view7Btn_clicked()
{
    ui->dataView->setDetectIndex(6);
    ui->dataView->resetVector();
}

void MainWindow::on_view8Btn_clicked()
{
    ui->dataView->setDetectIndex(7);
    ui->dataView->resetVector();
}

void MainWindow::on_view9Btn_clicked()
{
    ui->dataView->setDetectIndex(8);
    ui->dataView->resetVector();
}

void MainWindow::on_view10Btn_clicked()
{
    ui->dataView->setDetectIndex(9);
    ui->dataView->resetVector();
}

void MainWindow::on_view11Btn_clicked()
{
    ui->dataView->setDetectIndex(10);
    ui->dataView->resetVector();
}

void MainWindow::on_view12Btn_clicked()
{
    ui->dataView->setDetectIndex(11);
    ui->dataView->resetVector();
}

void MainWindow::on_view13Btn_clicked()
{
    ui->dataView->setDetectIndex(12);
    ui->dataView->resetVector();
}

void MainWindow::on_view14Btn_clicked()
{
    ui->dataView->setDetectIndex(13);
    ui->dataView->resetVector();
}

void MainWindow::on_view15Btn_clicked()
{
    ui->dataView->setDetectIndex(14);
    ui->dataView->resetVector();
}

void MainWindow::on_view16Btn_clicked()
{
    ui->dataView->setDetectIndex(15);
    ui->dataView->resetVector();
}

void MainWindow::on_view17Btn_clicked()
{
    ui->dataView->setDetectIndex(16);
    ui->dataView->resetVector();
}

void MainWindow::on_view18Btn_clicked()
{
    ui->dataView->setDetectIndex(17);
    ui->dataView->resetVector();
}

void MainWindow::on_applyBtn_clicked()
{
    ui->dataView->updateView(ui->temperatureCB->currentText().toInt());
    spc->setPortName(ui->portCB->currentText().split(" : ").at(0));
}
