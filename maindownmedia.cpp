#include "maindownmedia.h"
#include "ui_maindownmedia.h"

MainDownMedia::MainDownMedia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainDownMedia)
{
    ui->setupUi(this);
}

MainDownMedia::~MainDownMedia()
{
    delete ui;
}
