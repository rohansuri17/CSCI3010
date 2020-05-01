#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Cells.h"
#include "Population.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include <QFloat16>
/**
Rohan Suri
Homework 4
This is a life game simulation in qtcreator. Have fun and see what kind of random outcome you get!
There's a lot of rules! Lets see who will live.
Extra Features include step back button that goes back in time/state/turn/population
And after turns is greater than 100 the cells turn green because of your excellent random survivial
skills. Enjoy!
*/

//Default Constructor for Main Window
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    CreateGrid();
    CreatePopulationGraph();

}
//destructor
MainWindow::~MainWindow()
{
    delete ui;
}
/**
Returns None

@param None
@return None
Creates the initial population grid, sets the turn counter, population counter, and speed counter
*/
void MainWindow::CreateGrid()
{
    timer_=new QTimer();
    connect(timer_, SIGNAL(timeout()), this, SLOT(on_Play_clicked()));
    ui->setupUi(this);
    turn_=0;
    QColor color(255, 0, 0);
    Board_ = new QGraphicsScene;
    cell_view_ = ui->Grid;
    cell_view_->setScene(Board_);
    cell_view_->setSceneRect(0,0,cell_view_->frameSize().width(),cell_view_->frameSize().height());
    qsrand(time(0));

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            Cells * item = new Cells(j, i, cell_view_->frameSize().width()/20, cell_view_->frameSize().height()/10);
            Cells_Matrix_[i][j] = item;
            Board_->addItem(Cells_Matrix_[i][j]);
            population_++;
            cell_states_.push_back({turn_,Cells_Matrix_[i][j]->GetAliveStatus(), Cells_Matrix_[i][j]->GetColor(),i,j});
        }
    }
    ui->Turn->setText(QString("Turn: ")+QString::number(turn_));
    for(int i = 0; i < 10;i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(Cells_Matrix_[i][j]->GetAliveStatus()==true)
            {
                alive_counter_++;
            }
        }
    }
    ui->Population->setText(QString("Population: ")+QString::number(alive_counter_)+ QString(" (") + QString::number(( alive_counter_*100 )/200 ) + QString("%)" ));
    ui->Speed->setText(QString("Speed: ")+QString::number(speed_, 'f', 6));

}
/**
Returns None

@param None
@return None
Creates the initial population graph and appends to population_bars_ vector
*/
void MainWindow::CreatePopulationGraph()
{
    alive_counter_ = 0;
    for(int i = 0; i < 10;i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(Cells_Matrix_[i][j]->GetAliveStatus()==true)
            {
                alive_counter_++;
            }
        }
    }
    population_graph_ = new QGraphicsScene;
    population_view_ = ui->PopulationGrid;
    population_view_->setScene(population_graph_);
    population_view_->setSceneRect(0,0, population_view_->frameSize().width(), population_view_->frameSize().height());
    Population *game = new Population(0,population_view_->frameSize().height()-5,population_view_->frameSize().width()/20,int(population_view_->frameSize().height()*(double(alive_counter_)/population_)));
    population_graph_->addItem(game);
    population_bars_.push_back(game);

}
/**
Returns None

@param None
@return None
Performs a turn by incrementing turn counter, also accounts for extra feature where after 100 turns alive cells turn green
*/
void MainWindow::TakeTurn()
{
    turn_++;
    ui->Turn->setText(QString("Turn: ")+QString::number(turn_));
    if(turn_ > 100)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                if(Cells_Matrix_[i][j]->GetAliveStatus())
                {
                    Cells_Matrix_[i][j]->SetColor(QColor(0,255,0));
                }
            }
        }
    }

    Board_->update();

}
/**
Returns None

@param None
@return None
Accounts for all logic with respect to neigbor cells by calculating the count of neighbors around an arbritrary cell and updating according to the rules stated in the writeup
*/
void MainWindow::NeighborCellLogic()
{
    int count = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            count = 0;
            if(i==0)
            {

                if(j==0)
                {
                    count += Cells_Matrix_[0][1]->GetAliveStatus()+Cells_Matrix_[1][0]->GetAliveStatus()+Cells_Matrix_[1][1]->GetAliveStatus()+Cells_Matrix_[0][19]->GetAliveStatus()+Cells_Matrix_[1][19]->GetAliveStatus()+Cells_Matrix_[9][0]->GetAliveStatus()+Cells_Matrix_[9][1]->GetAliveStatus()+Cells_Matrix_[9][19]->GetAliveStatus();

                }
                else if(j==19)
                {
                    count += Cells_Matrix_[0][18]->GetAliveStatus()+Cells_Matrix_[1][18]->GetAliveStatus()+Cells_Matrix_[1][19]->GetAliveStatus()+Cells_Matrix_[0][0]->GetAliveStatus()+Cells_Matrix_[1][0]->GetAliveStatus()+Cells_Matrix_[9][18]->GetAliveStatus()+Cells_Matrix_[9][19]->GetAliveStatus()+Cells_Matrix_[9][0]->GetAliveStatus();
                }
                else
                {
                    count += (Cells_Matrix_[9][j-1]->GetAliveStatus())+(Cells_Matrix_[9][j]->GetAliveStatus()+Cells_Matrix_[9][j+1]->GetAliveStatus())+Cells_Matrix_[i][j-1]->GetAliveStatus()+Cells_Matrix_[i][j+1]->GetAliveStatus()+Cells_Matrix_[i+1][j-1]->GetAliveStatus()+Cells_Matrix_[i+1][j]->GetAliveStatus()+Cells_Matrix_[i+1][j+1]->GetAliveStatus();

                }
             }

            else if(i==9)
            {
                qDebug()<<count;
                if(j==0)
                {
                    count += (Cells_Matrix_[8][19]->GetAliveStatus())+(Cells_Matrix_[8][0]->GetAliveStatus()+Cells_Matrix_[8][1]->GetAliveStatus())+Cells_Matrix_[9][19]->GetAliveStatus()+Cells_Matrix_[9][1]->GetAliveStatus()+Cells_Matrix_[0][19]->GetAliveStatus()+Cells_Matrix_[0][0]->GetAliveStatus()+Cells_Matrix_[0][1]->GetAliveStatus();
                }
                else if(j==19)
                {
                    count += (Cells_Matrix_[8][18]->GetAliveStatus())+(Cells_Matrix_[8][19]->GetAliveStatus()+Cells_Matrix_[8][0]->GetAliveStatus())+Cells_Matrix_[9][18]->GetAliveStatus()+Cells_Matrix_[9][0]->GetAliveStatus()+Cells_Matrix_[0][18]->GetAliveStatus()+Cells_Matrix_[0][19]->GetAliveStatus()+Cells_Matrix_[0][0]->GetAliveStatus();

                }
                else
                {
                    count += (Cells_Matrix_[0][j-1]->GetAliveStatus())+(Cells_Matrix_[0][j]->GetAliveStatus()+Cells_Matrix_[0][j+1]->GetAliveStatus())+Cells_Matrix_[i][j-1]->GetAliveStatus()+Cells_Matrix_[i][j+1]->GetAliveStatus()+Cells_Matrix_[i-1][j-1]->GetAliveStatus()+Cells_Matrix_[i-1][j]->GetAliveStatus()+Cells_Matrix_[i-1][j+1]->GetAliveStatus();

                }
            }

            else if(j == 0 && i > 0 && i < 19)
            {
                count += (Cells_Matrix_[i-1][19]->GetAliveStatus())+(Cells_Matrix_[i][19]->GetAliveStatus()+Cells_Matrix_[i+1][19]->GetAliveStatus())+Cells_Matrix_[i-1][j]->GetAliveStatus()+Cells_Matrix_[i+1][j]->GetAliveStatus()+Cells_Matrix_[i-1][j+1]->GetAliveStatus()+Cells_Matrix_[i][j+1]->GetAliveStatus()+Cells_Matrix_[i+1][j+1]->GetAliveStatus();

            }

            else if(j == 19 && i > 0 && i<19)
            {
                count += (Cells_Matrix_[i-1][0]->GetAliveStatus())+(Cells_Matrix_[i][0]->GetAliveStatus()+Cells_Matrix_[i+1][0]->GetAliveStatus())+Cells_Matrix_[i-1][j]->GetAliveStatus()+Cells_Matrix_[i+1][j]->GetAliveStatus()+Cells_Matrix_[i-1][j-1]->GetAliveStatus()+Cells_Matrix_[i][j-1]->GetAliveStatus()+Cells_Matrix_[i+1][j-1]->GetAliveStatus();
            }

            else
            {
                count += (Cells_Matrix_[i-1][j-1]->GetAliveStatus())+(Cells_Matrix_[i-1][j]->GetAliveStatus()+Cells_Matrix_[i-1][j+1]->GetAliveStatus())+Cells_Matrix_[i][j-1]->GetAliveStatus()+Cells_Matrix_[i][j+1]->GetAliveStatus()+Cells_Matrix_[i+1][j-1]->GetAliveStatus()+Cells_Matrix_[i+1][j]->GetAliveStatus()+Cells_Matrix_[i+1][j+1]->GetAliveStatus();
            }
            counts_[i][j] = count;

        }
    }

    QColor color(255, 255, 255);

    for(int i = 0; i < 10; i++)
    {

        for(int j = 0; j < 20; j++)
        {
            if(counts_[i][j]<2 && Cells_Matrix_[i][j]->GetAliveStatus()==true)
            {
                color.setRgb(255,255,255);
                Cells_Matrix_[i][j]->SetAliveStatus(false);
                Cells_Matrix_[i][j]->SetColor(color);
            }
            else if((counts_[i][j]==2 || counts_[i][j]==3)&& Cells_Matrix_[i][j]->GetAliveStatus()==true)
            {
                Cells_Matrix_[i][j]->SetAliveStatus(true);
                color.setRgb(242,19,131);
                Cells_Matrix_[i][j]->SetColor(color);

            }
            else if(counts_[i][j] >3 && Cells_Matrix_[i][j]->GetAliveStatus()==true)
            {
                color.setRgb(255,255,255);
                Cells_Matrix_[i][j]->SetAliveStatus(false);
                Cells_Matrix_[i][j]->SetColor(color);
            }
            else if(counts_[i][j]==3 && Cells_Matrix_[i][j]->GetAliveStatus()==false)
            {
                Cells_Matrix_[i][j]->SetAliveStatus(true);
                color.setRgb(242, 19, 131);
                Cells_Matrix_[i][j]->SetColor(color);
            }


        }
    }


    Board_->update();
}
/**
Returns None

@param None
@return None
Updates the population
*/
void MainWindow::UpdatePopulationGraph()
{
    population_graph_->update();
    alive_counter_ = 0;
    for(int i = 0; i < 10;i++)
    {
        for(int j = 0; j < 20; j++)
        {

            if(Cells_Matrix_[i][j]->GetAliveStatus()==true)
            {
                alive_counter_++;
            }
        }
    }

    if(population_bars_.size()>=20)
    {

        for(unsigned int i = 0; i < population_bars_.size();i++)
        {
            population_bars_[i]->SetPopBarX(population_bars_[i]->GetPopBarX() - population_view_->frameSize().width()/20);

        }
        population_back_count_++;
    }
    Population *g = new Population(turn_*population_view_->frameSize().width()/20+population_view_->frameSize().width()/20-(population_back_count_*population_view_->frameSize().width()/20),population_view_->frameSize().height()-5,population_view_->frameSize().width()/20,int(population_view_->frameSize().height()*(double(alive_counter_)/population_)));
    population_bars_.push_back(g);
    population_graph_->addItem(g);
    std::string s = "Turn: " +std::to_string(turn_);
    QString qs(s.c_str());
    ui->Turn->setText(qs);

    for(int i = 0; i < 10;i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cell_states_.push_back({turn_,Cells_Matrix_[i][j]->GetAliveStatus(), Cells_Matrix_[i][j]->GetColor(),i,j});

        }
    }


    population_graph_->update();
}
/**
Returns None

@param integer turn number
@return None
Gets the state of the turn given as a parameter from the cell states vector. Implements the extra feature for the step back function as well
*/
void MainWindow::SavedState(int t)
{

    alive_counter_ = 0;
    for(unsigned int k = 0; k < cell_states_.size();k++)
    {

        if(cell_states_[k].turn==t)
        {

            Cells_Matrix_[cell_states_[k].row][cell_states_[k].col]->SetAliveStatus(cell_states_[k].alive);
            QColor color(cell_states_[k].color);
            Cells_Matrix_[cell_states_[k].row][cell_states_[k].col]->SetColor(color);
            if(cell_states_[k].alive==true && k >1)
            {
                    alive_counter_++;
            }
        }
    }
    int alive_counter_curr = 0;
    if(turn_ > 100)
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 20; j++)
            {
                if(Cells_Matrix_[i][j]->GetAliveStatus())
                {
                    Cells_Matrix_[i][j]->SetColor(QColor(0,255,0));
                    alive_counter_curr++;
                }
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            if(Cells_Matrix_[i][j]->GetAliveStatus())
            {
                alive_counter_curr++;
            }
        }
    }
    qDebug()<<alive_counter_;
    ui->Population->setText(QString("Population: ")+QString::number(alive_counter_)+ QString(" (") + QString::number(((alive_counter_)*100 )/200 ) + QString("%)" ));
    Board_->update();
    population_graph_->update();
    ui->Population->repaint();
}
//Slot when Play button is clicked
void MainWindow::on_Play_clicked()
{
    NeighborCellLogic();
    UpdatePopulationGraph();
    timer_->start(speed_*1000.0);
    TakeTurn();
    ui->Turn->repaint();
    ui->Population->setText(QString("Population: ")+QString::number(alive_counter_)+ QString(" (") + QString::number(( alive_counter_*100 )/200 ) + QString("%)" ));
    ui->Population->repaint();
}
//Slot when step button is clicked
void MainWindow::on_Step_clicked()
{
     NeighborCellLogic();
     UpdatePopulationGraph();
     TakeTurn();
     ui->Turn->repaint();
     ui->Population->setText(QString("Population: ")+QString::number(alive_counter_)+ QString(" (") + QString::number(( alive_counter_*100 )/200 ) + QString("%)" ));
     ui->Population->repaint();
}
//Slot when horizontal slider value was changed
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    speed_=1-(value/100.0);
    ui->Speed->setText(QString("Speed: ")+QString::number(speed_, 'f', 6));
}
//Slot when pause button was clicked
void MainWindow::on_Pause_clicked()
{
    timer_->stop();

}
//Slot when step back button is clicked
void MainWindow::on_StepBack_clicked()
{

    population_graph_->removeItem(population_bars_[turn_-1]);
    population_graph_->update();
    population_bars_.pop_back();
    turn_--;
    ui->Turn->setText(QString("Turn: ")+QString::number(turn_));
    ui->Turn->repaint();
    SavedState(turn_);
}
