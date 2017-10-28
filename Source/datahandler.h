#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QFile>
#include <qdatastream.h>
#include <QLinkedList>

class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = 0);
    ~DataHandler();

    void addData(QStringList data);
    QList<QVector<double> > getDataSet();
    QVector<double> getDataSet(int num);
    void resetDataSet();
    void saveData();

    int getTotality() const;

private:
    QList<QVector<double> > *dataSet;
    int totalTime;  //unit: ms
    int intervalTime;   //unit: ms
    int totality;

    int dataBulk; //the amount of the data imported in the same time

    int index;

    void init();

signals:
    void saveFinished();
    void noticeProgressBar(int num);

public slots:
};

#endif // DATAHANDLER_H
