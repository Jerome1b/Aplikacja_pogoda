#pragma once
#include "app.hpp"
#include <QMainWindow>
#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QValueAxis>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QChartView *chartView=nullptr;
    QChart *chart=nullptr;
    QLineSeries *series=nullptr;
    QValueAxis *axisX=nullptr;
    QValueAxis *axisY=nullptr;
    int xSkala=0;
};
