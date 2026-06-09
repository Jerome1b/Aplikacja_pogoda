#include "weatherwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherWindow w;
    w.show();
    return a.exec();
}
