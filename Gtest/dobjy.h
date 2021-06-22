#ifndef DOBJY_H
#define DOBJY_H

#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include "QPainter"
#include <QGraphicsItem>
#include "QGraphicsView"
#include "QObject"

class DObjY : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    DObjY(int x, int y, int tip=2);
    ~DObjY();
    int priznac;
    bool removeObj;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    void advance(int phase);
    QPainterPath shape() const;
    void dvih();

    int tip;
signals:
    void deletD(DObjY *obj);
    void scoreY(int sc);
};

#endif // DOBJY_H
