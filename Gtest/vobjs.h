#ifndef VOBJS_H
#define VOBJS_H

#include <QtGui>
#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include "QPainter"
#include <QGraphicsItem>
#include "QGraphicsView"
#include "dobjy.h"
#include "dobja.h"
#include "QTime"
#include "QColor"
#include "vobjs_2ob.h"
#include "gobject.h"
#include "QPolygonF"

class VObjS : public GObject, public QGraphicsItem
{
public:
    VObjS(int x, int y, int tipObj, QGraphicsScene *scene);
    ~VObjS();
    int priznac;
    bool removeObj;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    QPainterPath shape() const;
    void dvih();
    QPolygonF form(int form);

    int tipObj;
    int St;
    QColor color;
    QGraphicsScene *sceneIt;
    int timerV;
    int timerVsr;
    int vsr;

    QPolygonF polygon;
    double d;
    int napravlenie;
    double period;
};

#endif // VOBJS_H
