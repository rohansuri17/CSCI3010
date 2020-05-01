/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *Grid;
    QPushButton *Step;
    QPushButton *Play;
    QPushButton *Pause;
    QPushButton *StepBack;
    QGraphicsView *PopulationGrid;
    QLabel *Turn;
    QLabel *Population;
    QSlider *horizontalSlider;
    QLabel *Slower;
    QLabel *Faster;
    QLabel *Speed;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Grid = new QGraphicsView(centralwidget);
        Grid->setObjectName(QString::fromUtf8("Grid"));
        Grid->setGeometry(QRect(140, 50, 491, 301));
        Step = new QPushButton(centralwidget);
        Step->setObjectName(QString::fromUtf8("Step"));
        Step->setGeometry(QRect(140, 520, 112, 32));
        Play = new QPushButton(centralwidget);
        Play->setObjectName(QString::fromUtf8("Play"));
        Play->setGeometry(QRect(260, 520, 112, 32));
        Pause = new QPushButton(centralwidget);
        Pause->setObjectName(QString::fromUtf8("Pause"));
        Pause->setGeometry(QRect(380, 520, 112, 32));
        StepBack = new QPushButton(centralwidget);
        StepBack->setObjectName(QString::fromUtf8("StepBack"));
        StepBack->setGeometry(QRect(500, 520, 112, 32));
        PopulationGrid = new QGraphicsView(centralwidget);
        PopulationGrid->setObjectName(QString::fromUtf8("PopulationGrid"));
        PopulationGrid->setGeometry(QRect(140, 350, 491, 111));
        Turn = new QLabel(centralwidget);
        Turn->setObjectName(QString::fromUtf8("Turn"));
        Turn->setGeometry(QRect(100, 10, 91, 16));
        Population = new QLabel(centralwidget);
        Population->setObjectName(QString::fromUtf8("Population"));
        Population->setGeometry(QRect(100, 30, 171, 16));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(290, 500, 161, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        Slower = new QLabel(centralwidget);
        Slower->setObjectName(QString::fromUtf8("Slower"));
        Slower->setGeometry(QRect(240, 500, 58, 16));
        Faster = new QLabel(centralwidget);
        Faster->setObjectName(QString::fromUtf8("Faster"));
        Faster->setGeometry(QRect(460, 500, 58, 16));
        Speed = new QLabel(centralwidget);
        Speed->setObjectName(QString::fromUtf8("Speed"));
        Speed->setGeometry(QRect(650, 530, 81, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Step->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        Play->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        Pause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        StepBack->setText(QCoreApplication::translate("MainWindow", "Step Back", nullptr));
        Turn->setText(QCoreApplication::translate("MainWindow", "Turn:", nullptr));
        Population->setText(QCoreApplication::translate("MainWindow", "Population:", nullptr));
        Slower->setText(QCoreApplication::translate("MainWindow", "Slower", nullptr));
        Faster->setText(QCoreApplication::translate("MainWindow", "Faster", nullptr));
        Speed->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
