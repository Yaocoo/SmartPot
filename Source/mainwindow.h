#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <spconnector.h>
#include <datahandler.h>
#include <dataview.h>
#include <mutex>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    SPConnector *spc;
    DataHandler *dataHdl;
    DataView *dataView;

private slots:
    void stopRecord();
    void setProgressBar(int num);
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionRecord_triggered();

    void on_view1Btn_clicked();

    void on_view2Btn_clicked();

    void on_view3Btn_clicked();

    void on_view4Btn_clicked();

    void on_view5Btn_clicked();

    void on_view6Btn_clicked();

    void on_view7Btn_clicked();

    void on_view8Btn_clicked();

    void on_view9Btn_clicked();

    void on_view10Btn_clicked();

    void on_view11Btn_clicked();

    void on_view12Btn_clicked();

    void on_view13Btn_clicked();

    void on_view14Btn_clicked();

    void on_view15Btn_clicked();

    void on_view16Btn_clicked();

    void on_view17Btn_clicked();

    void on_view18Btn_clicked();

    void on_applyBtn_clicked();

private:
    Ui::MainWindow *ui;
    bool recordStatus;

    void openStatusWidget();
    void closeStatusWidget();
    void submitStatusWidget();
    void initParam();
};

#endif // MAINWINDOW_H
