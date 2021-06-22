#include "dobjy.h"

DObjY::DObjY(int x, int y, int tip)
{
    this->setX(x);
    this->setY(y);
    this->priznac = 1;
    this->removeObj = false;
    this->tip = tip;
}

DObjY::~DObjY()
{
    scene()->removeItem(this);
}


void DObjY::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(Qt::black));
    painter->drawEllipse(0, 0, 2, 20);
    if(this->removeObj)
        delete this;
}

QRectF DObjY::boundingRect() const
{
    return QRectF(0, 0, 2, 20);
}
void DObjY::advance(int phase)
{
    this->dvih();
}

QPainterPath DObjY::shape() const
{
    QPainterPath path;
    path.addEllipse(QPointF(1, 10), 1, 10);
    return path;
}

void DObjY::dvih()
{
    this->setY(this->y() - 25);
    if(tip == 0)
        this->setX(this->x() - 5);
    if(tip == 1)
        this->setX(this->x() - 2);
    if(tip == 3)
        this->setX(this->x() + 2);
    if(tip == 4)
        this->setX(this->x() + 5);
    if(this->y() < -50)
    {
        emit deletD(this);
        delete this;
    }
}
