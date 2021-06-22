#ifndef GOBJECT_H
#define GOBJECT_H

#include "QObject"

class GObject : public QObject
{
    Q_OBJECT
public:
    GObject();
    ~GObject();

signals:
    void setScore(int score);
    void closeG();
};

#endif // GOBJECT_H
