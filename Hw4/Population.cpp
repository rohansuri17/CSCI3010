#include "Population.h"
//Overloaded constructor that sets x,y,length, and width of population bar
Population::Population(int pop_bar_x, int pop_bar_y, int pop_bar_width, int pop__bar_length)
{
    pop_bar_x_ = pop_bar_x;
    pop_bar_y_ = pop_bar_y;
    pop_bar_width_ = pop_bar_width;
    pop_bar_length_ = -pop__bar_length;
    QColor color(255,255,255);
    color_=color;

}
/**
Returns a population bars

@param none
@return a population bars length
*/
int Population::GetPopBarLength()
{
    return pop_bar_length_;

}
/**
Returns None

@param a population bars length
@return None
*/
void Population::SetPopBarLength(int pop_bar_length)
{
    pop_bar_length_ = pop_bar_length;


}
/**
Returns a population bars width

@param none
@return a population bars width
*/
int Population::GetPopBarWidth()
{
    return pop_bar_width_;

}
/**
Returns None

@param a population bars width
@return None
*/
void Population::SetPopBarWidth(int pop_bar_width)
{
    pop_bar_width_ = pop_bar_width;

}
/**
Returns a population bars x value

@param none
@return a population bars x value
*/
int Population::GetPopBarX()
{
    return pop_bar_x_;

}
/**
Returns None

@param a population bars x value
@return None
*/
void Population::SetPopBarX(int pop_bar_x)
{
    pop_bar_x_ = pop_bar_x;


}
/**
Returns a population bars y value

@param none
@return a population bars y value
*/
int Population::GetPopBarY()
{
    return pop_bar_y_;


}
/**
Returns None

@param a population bars y value
@return None
*/
void Population::SetPopBarY(int pop_bar_y)
{
     pop_bar_y_ = pop_bar_y;
}
/**
Returns Color of the population bar

@param None
@return Color of the population bar
*/
QColor Population::GetColor()
{
    return color_;

}
/**
Returns None

@param QColor object
@return None
*/
void Population::SetColor(QColor color)
{
    color_ = color;

}
/**
Returns QRectF object

@param None
@return QRectF object
*/
QRectF Population::boundingRect() const
{
    return QRectF(pop_bar_x_,pop_bar_y_, pop_bar_width_, pop_bar_length_ );

}
/**
Returns QPainerPath object

@param None
@return QPainterPath object
*/
QPainterPath Population::shape() const
{
    QPainterPath path;
    path.addRect(pop_bar_x_,pop_bar_y_,pop_bar_width_,pop_bar_length_);
    return path;

}
/**
Returns None

@param QRectF object, QStyleOptionGraphicsItem,QWidget
@return None
*/
void Population::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget)


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));

    painter->drawRect(QRect(pop_bar_x_,pop_bar_y_,pop_bar_width_,pop_bar_length_));
    painter->setBrush(b);

}
