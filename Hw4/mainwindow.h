#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include "Cells.h"
#include "Population.h"
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    struct CellInfo
    {
        int turn;
        bool alive;
        QColor color;
        int row;
        int col;

    };

public:
    MainWindow(QWidget *parent = nullptr);
    void CreateGrid();
    void CreatePopulationGraph();
    void TakeTurn();
    void NeighborCellLogic();
    void PopulationGraph();
    void UpdatePopulationGraph();
    void SavedState(int t);
    ~MainWindow();

private slots:
    void on_Play_clicked();

    void on_Step_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_Pause_clicked();

    void on_StepBack_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Board_;
    QGraphicsScene *population_graph_;
    QGraphicsView *population_view_;
    QGraphicsView * cell_view_;
    double speed_ = 1.0;
    int population_ = 0;
    int turn_=0;
    std::vector<Population*> population_bars_;
    Cells *Cells_Matrix_[10][20];
    std::vector<CellInfo> cell_states_;
    int counts_[10][20];
    QTimer *timer_;
    int alive_counter_=0;
    int population_back_count_=0;

};
#endif // MAINWINDOW_H
