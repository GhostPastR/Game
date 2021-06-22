#include "vobjs_2ob.h"

VobjS_2ob::VobjS_2ob(int x, int y, int tip)
{
    this->setX(x);
    this->setY(y);
    color = Qt::gray;
    removeObj = false;
    this->priznac = 3;
    this->tip = tip;
}

VobjS_2ob::~VobjS_2ob()
{

}

void VobjS_2ob::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);
    painter->drawEllipse(0, 0, 2, 10);

    QList<QGraphicsItem*> item = scene()->collidingItems(this);
    if(item.count() == 1)
    {
        DObjY *obj = (DObjY*)item.at(0);
        DObjA *objy = (DObjA*)item.at(0);
        if(obj->priznac == 1)
        {
            obj->removeObj = true;
            this->removeObj = true;
            delete this;
        }
        if(objy->priznac == 2)
        {
            if(objy!=NULL)
            {
                objy->flagyn = true;
            }
        }
    }
}

QRectF VobjS_2ob::boundingRect() const
{
    return QRectF(0, 0, 2, 10);
}

void VobjS_2ob::advance(int phase)
{
    this->dvih();
}

QPainterPath VobjS_2ob::shape() const
{
    QPainterPath path;
    path.addEllipse(QPointF(5, 15), 5, 15);
    return path;
}

void VobjS_2ob::dvih()
{
    this->setY(this->y() + 20);
    if(tip == 1)
        this->setX(this->x() - 5);
    if(tip == 2)
        this->setX(this->x() + 5);
    if(this->y() > 950)
        delete this;
}
