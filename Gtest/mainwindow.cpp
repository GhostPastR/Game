#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->flag = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    graphicsView = new renderScene(this);
    connect(this->graphicsView, SIGNAL(gameEnd()), this, SLOT(end()));
    graphicsView->setObjectName(QStringLiteral("graphicsView"));
    graphicsView->setGeometry(QRect(0, 0, 800, 1000));
    ui->label->setText("0");
    ui->label_3->setText("0");
    graphicsView->getLabel(ui->label);
    graphicsView->getLabelS(ui->label_3);
    graphicsView->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    delete this->graphicsView;
}

void MainWindow::end()
{
    this->setFocus();
    this->graphicsView->close();
}
