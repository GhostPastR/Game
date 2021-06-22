#ifndef DOBJA_H
#define DOBJA_H

#include "QObject"
#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include "QPainter"
#include "QGraphicsItem"
#include "gobject.h"
#include "QRadialGradient"
#include "QLinearGradient"
#include "dobjy.h"

class DObjA : public GObject, public QGraphicsItem
{
public:
    DObjA(int x, int y);
    ~DObjA();
    int priznac;
    bool flagyn;

    void newAtac(int score, bool click);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    QPainterPath shape() const;

    QPolygonF polygon1;
    QPolygonF polygon2;
    QPolygonF polygon3;
    DObjY *objy;
};

#endif // DOBJA_H
