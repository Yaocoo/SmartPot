#include "dataview.h"
#include "ui_dataview.h"
#include <QTime>
#include <ctime>

DataView::DataView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataView)
{
    ui->setupUi(this);
    timeVector = new QVector<double>;
    init();
}

DataView::~DataView()
{
    delete ui;
    delete timeVector;
}

void DataView::resetVector()
{
    delete timeVector;
    timeVector = new QVector<double>;
    index = 0;
}

void DataView::setDetectIndex(int value)
{
    detectIndex = value;
}

void DataView::updateView(int upTemperature)
{
    ui->plotView->yAxis->setRange(0, upTemperature);
    ui->plotView->replot();
}

void DataView::setDataHdl(DataHandler *value)
{
    dataHdl = value;
}

void DataView::receiveData(QStringList dataList)
{
//    this->dataHdl->addData(dataList);
//    this->replot();
}

void DataView::replot()
{
//    ui->plotView->graph(0)->setData(*timeVector, dataHdl->getDataSet());
//    ui->plotView->replot();
}

void DataView::init()
{
    //initialize time vector
//    for (int i = 0, iLimit = dataHdl->getTotality(); i < iLimit; i ++ ) {
//        timeVector->append(i * 20);
//    }
    //initialize graph
    ui->plotView->addGraph();
    ui->plotView->xAxis->setRange(0, 1000);
    ui->plotView->yAxis->setRange(0, 200);
}

void DataView::on_updateBtn_clicked()
{
    ui->plotView->xAxis->setRange(0, ui->XCbBox->currentText().toInt());
    ui->plotView->yAxis->setRange(0, ui->YCbBox->currentText().toInt());
    ui->plotView->replot();
}
