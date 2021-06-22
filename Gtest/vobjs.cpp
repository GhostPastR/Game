#include "vobjs.h"
#include "iostream"
#include "ctime"

VObjS::VObjS(int x, int y, int tipObj, QGraphicsScene *scene)
{
    this->setX(x);
    this->setY(y);
    this->sceneIt = scene;
    this->priznac = 0;
    this->removeObj = false;
    this->tipObj = tipObj;
    this->timerV = 0;
    this->timerVsr = 0;
    this->d = 0;
    this->napravlenie = rand() % 2 - 1;
    if(this->napravlenie == 0)
        this->napravlenie = 1;
    this->period = rand() % 5 + 1;

    if(this->tipObj == 1)
    {
        color = Qt::black;
    }
    if(this->tipObj == 2)
    {
        this->St = 2;
        color = Qt::green;
    }
    if(this->tipObj == 3)
    {
        color = Qt::blue;
    }
    if(this->tipObj == 4)
    {
        color = Qt::cyan;
    }
    if(this->tipObj == 5)
    {
        this->St = 5;
        color = Qt::gray;
    }
    if(this->tipObj == 6)
    {
        this->St = 5;
        color = Qt::darkYellow;
    }
    vsr = rand()%200 + 50;

    polygon << QPoint(0,0) <<  QPoint(15,30) <<  QPoint(30,0) <<  QPoint(15,-30);
}

VObjS::~VObjS()
{
    scene()->removeItem(this);
}

void VObjS::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(color);
    painter->drawPolygon(this->polygon);
    //painter->drawEllipse(0, 0, 30, 30);

    QList<QGraphicsItem*> item = scene()->collidingItems(this);
    if((item.count() > 0) &&(item.count() < 5))
    {
        DObjY *obj=(DObjY*)item.at(0);
        DObjA *objy = (DObjA*)item.at(0);

        if(obj->priznac == 1)
        {
            if(this->tipObj == 1)
            {
                obj->removeObj = true;
                this->removeObj = true;
                emit this->setScore(1);
                delete this;
            }
            if(this->tipObj == 2)
            {
                this->St--;
                obj->removeObj = true;
                color = Qt::red;
                painter->setBrush(color);
                if(this->St < 1)
                {
                    this->removeObj = true;
                    emit this->setScore(2);
                    delete this;
                }
            }
            if(this->tipObj == 3)
            {
                VobjS_2ob *vobj2ob1 = new VobjS_2ob(this->x(), this->y());
                this->sceneIt->addItem(vobj2ob1);
                VobjS_2ob *vobj2ob2 = new VobjS_2ob(this->x()+30, this->y());
                this->sceneIt->addItem(vobj2ob2);
                VobjS_2ob *vobj2ob3 = new VobjS_2ob(this->x()+10, this->y()-5);
                this->sceneIt->addItem(vobj2ob3);
                VobjS_2ob *vobj2ob4 = new VobjS_2ob(this->x()+20, this->y()-10);
                this->sceneIt->addItem(vobj2ob4);
                VobjS_2ob *vobj2ob5 = new VobjS_2ob(this->x()+20, this->y()+5);
                this->sceneIt->addItem(vobj2ob5);
                obj->removeObj = true;
                this->removeObj = true;
                emit this->setScore(4);
                delete this;
            }
            if(this->tipObj == 4)
            {
                obj->removeObj = true;
                this->removeObj = true;
                emit this->setScore(5);
                delete this;
            }
            if(this->tipObj == 5)
            {
                this->St--;
                obj->removeObj = true;
                if(this->St < 1)
                {
                    this->removeObj = true;
                    emit this->setScore(10);
                    delete this;
                }
            }
            if(this->tipObj == 6)
            {
                obj->removeObj = true;
                this->removeObj = true;
                emit this->setScore(12);
                delete this;
            }
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

QRectF VObjS::boundingRect() const
{
    return QRectF(0, -30, 30, 60);
}

void VObjS::advance(int phase)
{
    this->timerV++;
    this->timerVsr++;
    this->dvih();
    if(this->timerV > 100)
    {
        if(this->tipObj == 4)
        {
            VobjS_2ob *vobj2ob = new VobjS_2ob(this->x() + 15, this->y() + 30);
            this->sceneIt->addItem(vobj2ob);
        }
        if(this->tipObj == 6)
        {
            VobjS_2ob *vobj2ob1 = new VobjS_2ob(this->x(), this->y() + 30, 1);
            this->sceneIt->addItem(vobj2ob1);
            VobjS_2ob *vobj2ob2 = new VobjS_2ob(this->x() + 15, this->y() + 30, 0);
            this->sceneIt->addItem(vobj2ob2);
            VobjS_2ob *vobj2ob3 = new VobjS_2ob(this->x() + 30, this->y() + 30, 2);
            this->sceneIt->addItem(vobj2ob3);
        }
        this->timerV=0;
    }
    if(this->tipObj == 5)
    {
        if(this->timerVsr > this->vsr)
        {
            VobjS_2ob *vobj2ob1 = new VobjS_2ob(this->x(), this->y());
            this->sceneIt->addItem(vobj2ob1);
            VobjS_2ob *vobj2ob2 = new VobjS_2ob(this->x()+20, this->y());
            this->sceneIt->addItem(vobj2ob2);
            delete this;
        }
    }
}

QPainterPath VObjS::shape() const
{
    QPainterPath path;
    path.addPolygon(this->polygon);
    return path;
}

void VObjS::dvih()
{
    if(this->tipObj == 1 || this->tipObj == 2)
    {
        this->setY(this->y() + 1);
        if(this->y() > 950)
            delete this;
    }
    if(this->tipObj == 3 || this->tipObj == 4)
    {
        this->setY(this->y() + 1);
        if((this->x() < 720) && (this->x() > 0))
            this->setX(this->x() + this->period * sin(this->d + 5 * this->napravlenie * M_PI / 180.0));
        if(this->x() > 720)
            this->setX(this->x() + this->period * sin(this->d + 5 * this->napravlenie * M_PI / 180.0));
        if(this->x() < 0)
            this->setX(this->x() - this->period * sin(this->d + 5 * this->napravlenie * M_PI / 180.0));
        if(this->y() > 950)
            delete this;
    }
    if(this->tipObj == 5 || this->tipObj == 6)
    {
        this->setY(this->y() + 1);
        if((this->x() < 720) && (this->x() > 0))
            this->setX(this->x() + this->period * sin(this->d + 10 * this->napravlenie * M_PI / 180.0));
        if(this->x() > 720)
            this->setX(this->x() - 1);
        if(this->x() < 0)
            this->setX(this->x() + 1);
        if(this->y() > 950)
            delete this;
    }
}

QPolygonF VObjS::form(int form)
{
    QPolygonF polygon;
    if(form == 1)
    {
        for(int i=0;i<6;i++)
            polygon << QPoint(rand()%7 * i + 7, rand()%7 * i + 7);
        return polygon;
    }
    return polygon;
}
