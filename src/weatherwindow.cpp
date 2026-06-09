#include "weatherwindow.h"
#include "ui_weatherwindow.h"
#include "app.hpp"
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <iostream>


WeatherWindow::WeatherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WeatherWindow)
{
    ui->setupUi(this);
    ui->mapView->setAttribute(Qt::WA_TranslucentBackground);
    ui->mapView->page()->setBackgroundColor(Qt::transparent);
    ui->chartView->setStyleSheet("background: transparent;");
    if (ui->chartView->chart()) {
        ui->chartView->chart()->setBackgroundBrush(Qt::NoBrush);
    }
    ui->chartView_2->setStyleSheet("background: transparent;");
    if (ui->chartView_2->chart()) {
        ui->chartView_2->chart()->setBackgroundBrush(Qt::NoBrush);
    }
    ui->chartView_3->setStyleSheet("background: transparent;");
    if (ui->chartView_3->chart()) {
        ui->chartView_3->chart()->setBackgroundBrush(Qt::NoBrush);
    }
    ui->textBrowser_2->setAttribute(Qt::WA_TranslucentBackground);
    this->setStyleSheet("#WeatherWindow { background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(29, 255, 255, 255), stop:1 rgba(0, 0, 255, 255)); }");
    ui->lineEdit->setPlaceholderText("Wpisz miasto");
}


WeatherWindow::~WeatherWindow()
{
    delete ui;
}


void WeatherWindow::on_pushButton_clicked()
{

    CURL_Klient klient;


    std::string miasto = ui->lineEdit->text().toStdString();



    std::cout << "Pobieram dane dla miasta: " << miasto << std::endl;

    Extract_data dane(miasto, klient);
    dane.get();

    if(dane.odp!="200") {
        std::string err = "Błąd " + dane.odp;
        QString error = QString::fromStdString(err);
        ui->label_8->setText(error);
        ui->label->setText("");
        ui->label_2->setText("");
        ui->label_3->setText("");
        ui->label_4->setText("");
        ui->label_5->setText("");
        ui->label_6->setText("");
        ui->label_7->setText("");

        QChart *sChart1 = ui->chartView->chart();
        ui->chartView->setChart(new QChart());
        delete sChart1;
        QChart *sChart2 = ui->chartView_2->chart();
        ui->chartView_2->setChart(new QChart());
        delete sChart2;
        QChart *sChart3 = ui->chartView_3->chart();
        ui->chartView_3->setChart(new QChart());
        delete sChart3;

        ui->chartView->setStyleSheet("background: transparent;");
        ui->chartView->chart()->setBackgroundBrush(Qt::NoBrush);
        ui->chartView_2->setStyleSheet("background: transparent;");
        ui->chartView_2->chart()->setBackgroundBrush(Qt::NoBrush);
        ui->chartView_3->setStyleSheet("background: transparent;");
        ui->chartView_3->chart()->setBackgroundBrush(Qt::NoBrush);

        ui->mapView->setUrl(QUrl("about:blank"));
        return;
    }
    ui->label_8->setText("");
    QString m = QString::fromStdString(miasto);
    ui->label_4->setText(m);
    Wind_inf kat(dane.v,dane.deg);
    QString v= QString::number(kat.conv(), 'f', 2);
    QString k = QString::fromStdString(kat.kat());
    ui->label->setText("Aktualny kierunek wiatru:");
    ui->label_2->setText(k);
    ui->label_5->setText(v+ " Km/h");

    Icon emoji(dane.id);
    QString e = QString::fromStdString(emoji.to_icon());
    ui->label_3->setText(e);



    Location lokalizacja(dane.x, dane.y);
    std::string mapaUrl = lokalizacja.genUrl();


    if (ui->mapView) {
        ui->mapView->setUrl(QUrl(QString::fromStdString(mapaUrl)));
    }
    Extract_wykres downloader(dane.x, dane.y, klient);


    downloader.get();


    QLineSeries *seriesT = new QLineSeries();
    QLineSeries *seriesW = new QLineSeries();
    QLineSeries *seriesH = new QLineSeries();


    for (int x = 0; x < 24; x++) {

        seriesT->append(x, downloader.temp[x]);
        seriesW->append(x,downloader.wind_v[x]);
        seriesH->append(x,downloader.hum[x]);
    }
    QString t= QString::number(downloader.temp[0], 'f', 1);
    QString h= QString::number(downloader.hum[0], 'f', 1);
    ui->label_6->setText(h+"%");
    ui->label_7->setText(t+"°C");

    QChart *chartt = new QChart();
    chartt->addSeries(seriesT);
    chartt->createDefaultAxes();
    chartt->setTitle(QString::fromStdString("Prognoza Temperatury (°C) dla: " + miasto));
    chartt->legend()->hide();

    if (auto axisY = qobject_cast<QValueAxis*>(chartt->axes(Qt::Vertical).first())) {
        axisY->setRange(-20.0, 50.0);
    }

    QChart *chartw = new QChart();
    chartw->addSeries(seriesW);
    chartw->createDefaultAxes();
    chartw->setTitle(QString::fromStdString("Prognoza Wiatru (Km/h) dla: " + miasto));
    chartw->legend()->hide();

    if (auto axisY = qobject_cast<QValueAxis*>(chartw->axes(Qt::Vertical).first())) {
        axisY->setRange(0, 100);
    }


    QChart *charth = new QChart();
    charth->addSeries(seriesH);
    charth->createDefaultAxes();
    charth->setTitle(QString::fromStdString("Prognoza Wilgotności (%) dla: " + miasto));
    charth->legend()->hide();


    if (auto axisY = qobject_cast<QValueAxis*>(charth->axes(Qt::Vertical).first())) {
        axisY->setRange(0, 100);
    }

    QChart *sChart1 = ui->chartView->chart();
    ui->chartView->setChart(chartt);
    ui->chartView->setRenderHint(QPainter::Antialiasing);
    delete sChart1;

    QChart *sChart3 = ui->chartView_3->chart();
    ui->chartView_3->setChart(chartw);
    ui->chartView_3->setRenderHint(QPainter::Antialiasing);
    delete sChart3;

    QChart *sChart2 = ui->chartView_2->chart();
    ui->chartView_2->setChart(charth);
    ui->chartView_2->setRenderHint(QPainter::Antialiasing);
    delete sChart2;
}
