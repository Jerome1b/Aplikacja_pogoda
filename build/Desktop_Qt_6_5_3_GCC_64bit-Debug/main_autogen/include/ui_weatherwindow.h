/********************************************************************************
** Form generated from reading UI file 'weatherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWINDOW_H
#define UI_WEATHERWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QChartView *chartView;
    QTextBrowser *textBrowser_2;
    QWebEngineView *mapView;
    QChartView *chartView_2;
    QChartView *chartView_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *WeatherWindow)
    {
        if (WeatherWindow->objectName().isEmpty())
            WeatherWindow->setObjectName("WeatherWindow");
        WeatherWindow->resize(1012, 666);
        QFont font;
        font.setPointSize(13);
        WeatherWindow->setFont(font);
        WeatherWindow->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(29, 255, 255, 255), stop:1 rgba(0, 0, 255, 255));"));
        centralwidget = new QWidget(WeatherWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 90, 94, 26));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 90, 221, 26));
        chartView = new QChartView(centralwidget);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(630, 0, 361, 201));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(10, 10, 641, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Z003")});
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(true);
        textBrowser_2->setFont(font1);
        textBrowser_2->setStyleSheet(QString::fromUtf8("font: 700 italic 11pt \"Z003\";\n"
"background: transparent;"));
        mapView = new QWebEngineView(centralwidget);
        mapView->setObjectName("mapView");
        mapView->setGeometry(QRect(30, 360, 341, 241));
        mapView->setStyleSheet(QString::fromUtf8("background: transparent;"));
        chartView_2 = new QChartView(centralwidget);
        chartView_2->setObjectName("chartView_2");
        chartView_2->setGeometry(QRect(630, 430, 361, 211));
        chartView_3 = new QChartView(centralwidget);
        chartView_3->setObjectName("chartView_3");
        chartView_3->setGeometry(QRect(630, 210, 361, 211));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 290, 321, 41));
        QFont font2;
        font2.setPointSize(20);
        font2.setItalic(true);
        label->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(340, 290, 67, 41));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        label_2->setFont(font3);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 180, 111, 81));
        QFont font4;
        font4.setPointSize(34);
        label_3->setFont(font4);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 130, 321, 41));
        QFont font5;
        font5.setPointSize(28);
        font5.setBold(true);
        label_4->setFont(font5);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(420, 270, 201, 81));
        label_5->setFont(font5);
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 480, 201, 81));
        label_6->setFont(font5);
        label_6->setLayoutDirection(Qt::RightToLeft);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 180, 201, 81));
        label_7->setFont(font5);
        label_7->setLayoutDirection(Qt::RightToLeft);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(120, 130, 201, 81));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Z003")});
        font6.setPointSize(28);
        font6.setBold(true);
        font6.setItalic(true);
        label_8->setFont(font6);
        label_8->setLayoutDirection(Qt::RightToLeft);
        label_8->setAlignment(Qt::AlignCenter);
        WeatherWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WeatherWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1012, 22));
        WeatherWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WeatherWindow);
        statusbar->setObjectName("statusbar");
        WeatherWindow->setStatusBar(statusbar);

        retranslateUi(WeatherWindow);

        QMetaObject::connectSlotsByName(WeatherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WeatherWindow)
    {
        WeatherWindow->setWindowTitle(QCoreApplication::translate("WeatherWindow", "JKSquare WeatherApp", nullptr));
        pushButton->setText(QCoreApplication::translate("WeatherWindow", "Wyszukaj", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("WeatherWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Z003'; font-size:11pt; font-weight:700; font-style:italic;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu Sans'; font-size:36pt; font-style:normal; color:#ffffff;\">JKSquare WeatherApp</span></p></body></html>", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeatherWindow: public Ui_WeatherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWINDOW_H
