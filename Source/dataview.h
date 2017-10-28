#ifndef OSCILLOGRAMVIEW_H
#define OSCILLOGRAMVIEW_H

#include <QWidget>
#include <QVector>
#include <datahandler.h>

namespace Ui {
class DataView;
}

class DataView : public QWidget
{
    Q_OBJECT

public:
    explicit DataView(QWidget *parent = 0);
    ~DataView();

    void resetVector();
    void setDetectIndex(int value);
    void updateView(int upTemperature);
    void setDataHdl(DataHandler *value);
    void replot();

private:
    Ui::DataView *ui;
    DataHandler *dataHdl;
    bool status;
    int index;
    int listSize;
    int detectIndex;

    QVector<double> *timeVector;

    void init();

public slots:
    void receiveData(QStringList dataList);
private slots:
    void on_updateBtn_clicked();
};

#endif // OSCILLOGRAMVIEW_H
