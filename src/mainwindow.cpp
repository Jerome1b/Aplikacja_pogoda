#include "mainwindow.h"
#include "app.hpp"
#include <QLineSeries>
#include <QChart>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    series = new QLineSeries();
    chart = new QChart();
    axisX = new QValueAxis();
    axisY = new QValueAxis();
    chartView = new QChartView(chart);

    series->setName("Prognoza temperatury");

    chart->addSeries(series);
    chart->setTitle("Dane z API Open-Meteo");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    CURL_Klient klient;
    Extract_data pogoda("Krakow", klient);
    pogoda.get();

    Extract_wykres wyk(pogoda.x, pogoda.y, klient);
    wyk.get();

    int currX = 1;
    for(int i = 0; i < 28; i++) {
        qDebug() << "Indeks:" << i << "Wartość temp:" << wyk.temp[i];
        series->append(currX, wyk.temp[i]);
        currX++;
    }


    axisX->setRange(1, 28);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY->setRange(-20, 40);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    chartView->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(chartView);
    resize(800, 600);
}
