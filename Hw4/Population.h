#ifndef POPULATION_H
#define POPULATION_H
#include <QColor>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QObject>
class Population : public QObject, public QGraphicsItem
{
    Q_OBJECT
    public:
        Population(int pop_bar_x, int pop_bar_y, int pop_bar_width, int pop__bar_length);
        int GetPopBarLength();
        void SetPopBarLength(int);
        int GetPopBarWidth();
        void SetPopBarWidth(int);
        int GetPopBarX();
        void SetPopBarX(int);
        int GetPopBarY();
        void SetPopBarY(int);
        QColor GetColor();
        void SetColor(QColor);
        QRectF boundingRect() const override;
        QPainterPath shape() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    private:
        int pop_bar_x_;
        int pop_bar_y_;
        int pop_bar_width_;
        int pop_bar_length_;
        QColor color_;
};

#endif
