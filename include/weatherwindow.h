#ifndef WEATHERWINDOW_H
#define WEATHERWINDOW_H

#include <QMainWindow>


class QWebEngineView;

QT_BEGIN_NAMESPACE
namespace Ui { class WeatherWindow; }
QT_END_NAMESPACE

class WeatherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeatherWindow(QWidget *parent = nullptr);
    ~WeatherWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::WeatherWindow *ui;
};

#endif
