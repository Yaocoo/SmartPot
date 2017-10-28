#include "DataHandler.h"
#include <QDateTime>
#include <QMutableListIterator>
#include <QDebug>

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{
    dataSet = new QList<QVector<double>>;
    for (int i = 0; i < dataBulk; i ++ ) {

    }
    init();
}

DataHandler::~DataHandler()
{
    delete dataSet;
}

void DataHandler::addData(QStringList data)
{
    QMutableListIterator<QVector<double>> it(*dataSet);
    if (index < totality) {
        index ++ ;
        int i = 0;
        while(it.hasNext()) {
            i ++ ;
            it.next().append(data.at(i).toDouble());
        }
    } else {
        int i = 0;
        while(it.hasNext()) {
            i ++ ;
            QVector<double> v = it.next();
            v.removeFirst();
            v.append(data.at(i).toDouble());
        }
    }
}

QList<QVector<double>> DataHandler::getDataSet()
{
    return *dataSet;
}

QVector<double> DataHandler::getDataSet(int num)
{
    return dataSet->at(num);
}

void DataHandler::resetDataSet()
{
    delete dataSet;
    dataSet = new QList<QVector<double>>;
    index = 0;
}

void DataHandler::saveData()
{
    int tmpIndex = index;
    QList<QVector<double>> tmpSet(*dataSet);
    QDateTime time = QDateTime::currentDateTime();
    QString filename = "data/" + time.toString("yyyyMMddhhmmss") + ".csv";
    QFile file(filename);
    if(file.open(QFile::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        double base = tmpSet.at(dataBulk - 1).first();
        for (int i = 0; i < tmpIndex; i ++ ) {
            for (int j = 0; j < dataBulk - 1; j ++ ) {
                out << tmpSet.at(j).at(i) << ", ";
            }
            out << tmpSet.at(i).at(dataBulk - 1) - base << "\n";
        }

        qDebug() << "[Notice] generate file: " << filename; //for debug

    }
    this->resetDataSet();
}

int DataHandler::getTotality() const
{
    return totality;
}

void DataHandler::init()
{
//    totalTime = 15 * 1000;
//    intervalTime = 50;
//    totality = totalTime / intervalTime;
    totality = 500;

    dataBulk = 19;

    index = 0;
}
