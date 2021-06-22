#ifndef RENDERSCENE_H
#define RENDERSCENE_H

#include "QGraphicsView"
#include "QDebug"
#include "QTimer"
#include "dobja.h"
#include "vobjs.h"
#include "QKeyEvent"
#include "dobjy.h"
#include "QVector"
#include "ctime"
#include "QTime"
#include "QLabel"

class renderScene:public QGraphicsView
{
    Q_OBJECT
public:
    renderScene(QWidget* parent);
    ~renderScene();

    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *newtimer;
    QTimer *timerStartD;
    void getLabel(QLabel *label);
    void getLabelS(QLabel *label);

private:
    DObjA *dobj;
    QVector <DObjY*> MDobjY;
    QVector <VObjS*> MVobjS;
    QVector<bool> flag;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int interval;
    bool keyDown;
    int timerEnd;
    QLabel *label;
    QLabel *labelS;
    int score;

signals:
    void gameEnd();

public slots:
    void deleteVObj(VObjS *vobj);
    void nedObj();
    void newDObjY();
    void closeGame();
    void endGame();
    void setScoreI(int score);
};

#endif // RENDERSCENE_H
