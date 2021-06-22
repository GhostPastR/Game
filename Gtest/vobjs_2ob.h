#ifndef VOBJS_2OB_H
#define VOBJS_2OB_H

#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include "QPainter"
#include <QGraphicsItem>
#include "QGraphicsView"
#include "QColor"
#include "vobjs_2ob.h"
#include "dobjy.h"
#include "dobja.h"

class VobjS_2ob : public QGraphicsItem
{
public:
    VobjS_2ob(int x, int y, int tip=0);
    ~VobjS_2ob();

    int priznac;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    QPainterPath shape() const;
    void dvih();

    QColor color;
    bool removeObj;
    int tip;
};

#endif // VOBJS_2OB_H
