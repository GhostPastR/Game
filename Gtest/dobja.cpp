#include "dobja.h"

DObjA::DObjA(int x, int y)
{
    this->setX(x);
    this->setY(y);
    this->priznac = 2;
    this->flagyn = false;   

    polygon1 << QPoint(0,0) <<  QPoint(3,15) <<  QPoint(6,0) <<  QPoint(3,-15);
    polygon2 << QPoint(6,0) <<  QPoint(12,30) <<  QPoint(18,0) <<  QPoint(12,-30);
    polygon3 << QPoint(18,0) <<  QPoint(21,15) <<  QPoint(24,0) <<  QPoint(21,-15);
}

DObjA::~DObjA()
{   
    scene()->removeItem(this);
}

void DObjA::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRadialGradient gradientRadial(QPoint(10, 0), 40);
    QLinearGradient gradientLinear(0,0, 20, 0);

    gradientRadial.setColorAt(0, Qt::blue);
    gradientRadial.setColorAt(0.8, Qt::cyan);

    painter->setPen(Qt::NoPen);
    if(this->flagyn)
    {
        emit this->closeG();
    }
    else
    {

        painter->setBrush(gradientRadial);
        painter->drawPolygon(this->polygon1);
        painter->setBrush(gradientRadial);
        painter->drawPolygon(this->polygon2);
        painter->setBrush(gradientRadial);
        painter->drawPolygon(this->polygon3);
    }
}

QRectF DObjA::boundingRect() const
{
    return QRectF(0, -30, 24, 60);
}
void DObjA::advance(int phase)
{
}

QPainterPath DObjA::shape() const
{
    QPainterPath path;
    path.addPolygon(this->polygon1);
    path.addPolygon(this->polygon2);
    path.addPolygon(this->polygon3);
    return path;
}

void DObjA::newAtac(int score, bool click)
{
    if(score < 500)
    {
        if(score < 200)
        {
            if(score < 120)
            {
                if(score < 70)
                {
                    if(score < 30)
                    {
                        if(click)
                        {
                            objy = new DObjY(this->x() + 11, this->y() - 10);
                            this->scene()->addItem(objy);
                        }
                    }
                    else
                    {
                        if(click)
                        {
                            objy = new DObjY(this->x() + 2, this->y());
                            this->scene()->addItem(objy);
                            objy = new DObjY(this->x() + 20, this->y());
                            this->scene()->addItem(objy);
                        }
                    }
                }
                else
                {
                    if(click)
                    {
                        objy = new DObjY(this->x() + 8, this->y()-10);
                        this->scene()->addItem(objy);
                        objy = new DObjY(this->x() + 14, this->y()-10);
                        this->scene()->addItem(objy);
                        objy = new DObjY(this->x() + 11, this->y());
                        this->scene()->addItem(objy);
                        objy = new DObjY(this->x() + 11, this->y()-20);
                        this->scene()->addItem(objy);
                    }
                }
            }
            else
            {
                if(click)
                {
                    objy = new DObjY(this->x() + 2, this->y()-10, 1);
                    this->scene()->addItem(objy);
                    objy = new DObjY(this->x() + 11, this->y()-10);
                    this->scene()->addItem(objy);
                    objy = new DObjY(this->x() + 20, this->y()-10, 3);
                    this->scene()->addItem(objy);
                }
            }
        }
        else
        {
            if(click)
            {
                int j=0;
                for(int i=2;i<21;i=i+9)
                {
                    objy = new DObjY(this->x() + i - 3, this->y()-10, j);
                    this->scene()->addItem(objy);
                    objy = new DObjY(this->x() + i + 3, this->y()-10, j);
                    this->scene()->addItem(objy);
                    objy = new DObjY(this->x() + i, this->y(), j);
                    this->scene()->addItem(objy);
                    objy = new DObjY(this->x() + i, this->y()-20, j);
                    this->scene()->addItem(objy);
                    j += 2;
                }
            }
        }
    }
    else
    {
        if(click)
        {
            int j=0;
            for(int i=0;i<21;i=i+5)
            {
                objy = new DObjY(this->x() + i - 3, this->y()-10, j);
                this->scene()->addItem(objy);
                objy = new DObjY(this->x() + i + 3, this->y()-10, j);
                this->scene()->addItem(objy);
                objy = new DObjY(this->x() + i, this->y(), j);
                this->scene()->addItem(objy);
                objy = new DObjY(this->x() + i, this->y()-20, j);
                this->scene()->addItem(objy);
                j++;
            }
        }
    }
}
