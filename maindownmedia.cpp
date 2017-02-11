#include "maindownmedia.h"
#include "ui_maindowntube.h"

MainDownTube::MainDownTube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDownTube)
{
    ui->setupUi(this);
}

MainDownTube::~MainDownTube()
{
    delete ui;
}

