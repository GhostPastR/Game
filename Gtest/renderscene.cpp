#include "renderscene.h"

renderScene::renderScene(QWidget *parent):QGraphicsView(parent)
{
    srand(time(NULL));
    scene = new QGraphicsScene(this);
    this->scene->setSceneRect(0, 0, 750, 650);
    this->setScene(scene);

    dobj = new DObjA(350, 600);
    this->scene->addItem(dobj);

    connect(dobj, SIGNAL(closeG()), this, SLOT(closeGame()));

    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this->scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), this, SLOT(endGame()));
    this->timer->start(1000 / 33);

    this->newtimer = new QTimer(this);
    connect(this->newtimer , SIGNAL(timeout()), this, SLOT(nedObj()));
    this->newtimer->start(1000);

    this->timerStartD = new QTimer(this);
    connect(this->timerStartD, SIGNAL(timeout()), this, SLOT(newDObjY()));
    this->timerStartD->start(200);

    int sec = 500;
    this->timerEnd = 40 * (sec + 1);


    interval=0;
    this->keyDown=false;
    this->setFocus();
    this->score = 0;

    for(int i=0;i<3;i++)
        flag.push_back(false);
}

renderScene::~renderScene()
{

}

void renderScene::keyReleaseEvent(QKeyEvent *event)
{
    this->keyDown = false;
    if(event->key() == 16777234)
    {
        flag[0] = false;
    }
    if(event->key() == 16777236)
    {
        flag[1] = false;
    }
    if(event->key() == 32)
    {
        flag[2] = false;
    }
}

void renderScene::keyPressEvent(QKeyEvent *event)
{
    if(dobj != NULL)
    {
        if(event->key() == 16777234)
        {
            flag[0] = true;
        }
        if(event->key() == 16777236)
        {
            flag[1] = true;
        }
        if(event->key() == 32)
        {
            flag[2] = true;
        }

        if(flag[0])
        {
            if(dobj->x() > 0)
                dobj->setX(dobj->x() - 20);
        }
        if(flag[1])
        {
            if(dobj->x() < 720)
                dobj->setX(dobj->x() + 20);
        }
        if(flag[2])
        {
            this->keyDown = true;
        }
    }
}

void renderScene::nedObj()
{
    if(this->MVobjS.count() < 30)
    {
        int x = rand()%700;
        VObjS *obj = new VObjS(x, -50, rand()%6 + 1, this->scene);
        connect(obj, SIGNAL(setScore(int)), this, SLOT(setScoreI(int)));
        this->MVobjS.push_back(obj);
        this->scene->addItem(obj);
    }
    else
    {
        for(int i=0;i<this->MVobjS.count();i++)
        {
            if(this->MVobjS[i]->removeObj)
            {
                this->MVobjS.removeAll(this->MVobjS[i]);
            }
        }
    }
}

void renderScene::newDObjY()
{
    dobj->newAtac(this->score, this->keyDown);
}

void renderScene::deleteVObj(VObjS *vobj)
{
    this->MVobjS.removeAll(vobj);
}

void renderScene::closeGame()
{
    this->close();
    this->timerEnd=0;
    label->setText("0");
    emit gameEnd();
}

void renderScene::endGame()
{
    if(this->timerEnd < 1)
    {
        this->close();
    }
    else
    {
        this->timerEnd--;
        label->setText(QString::number(this->timerEnd / 40));
    }
}

void renderScene::getLabel(QLabel *label)
{
    this->label = label;
}

void renderScene::getLabelS(QLabel *label)
{
    this->labelS = label;
}

void renderScene::setScoreI(int score)
{
    this->score += score;
    this->labelS->setText(QString::number(this->score));
}
