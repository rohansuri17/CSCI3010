#ifndef CELLS_H
#define CELLS_H
#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QObject>
class Cells : public QObject, public QGraphicsItem
{
    Q_OBJECT

    public:
        Cells( int cell_x, int cell_y,int cell_width,int cell_length); //constructor
        int GetCellLength();
        void SetCellLength(int);
        int GetCellWidth();
        void SetCellWidth(int);
        int GetCellX();
        void SetCellX(int);
        int GetCellY();
        void SetCellY(int);
        bool GetAliveStatus();
        void SetAliveStatus(bool);
        QColor GetColor();
        void SetColor(QColor c);
        QRectF boundingRect() const override;
        QPainterPath shape() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;



    signals:

    private:
        int cell_length_;
        int cell_width_;
        int cell_x_;
        int cell_y_;
        bool alive_;
        QColor color_;
        bool isalive_prev_;
        QColor color_prev_;

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};



















#endif
