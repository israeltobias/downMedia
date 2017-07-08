#include "maindownmedia.h"
#include "ui_maindownmedia.h"
#include <iostream>
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QProgressDialog>
using namespace std;
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


void MainDownMedia::on_btnProcess_clicked()
{
    QProcess *process = new QProcess(this);
    try {
        process->setReadChannel(QProcess::StandardOutput);
        process->setProcessChannelMode( QProcess::MergedChannels );


        QProgressDialog *progress = new QProgressDialog;
        progress->setAttribute(Qt::WA_DeleteOnClose);
        progress->setWindowModality(Qt::WindowModal);
        progress->setCancelButtonText("Cancelar");
        progress->setRange(0,0);
        connect(process, SIGNAL(finished(int)), progress, SLOT(close()));

        QDir *dir = new QDir();
        dir->cd("youtube-dl");
        qDebug()<<"DIR: "<<dir->absolutePath();
        process->setWorkingDirectory(dir->absolutePath());
        process->start("python -m youtube_dl -x --audio-format mp3 --audio-quality 128K --rm-cache-dir -o \"/home/israel/Música/%(title)s.%(ext)s\" de63cweypyM", QProcess::Unbuffered | QProcess::ReadWrite);

        progress->exec();


        dir->cdUp();
        qDebug()<<"DIR: "<<dir->absolutePath();
        process->setWorkingDirectory(dir->absolutePath());
        process->close();
  //  process->start("sh", QStringList()<<"-c"<<"python -m youtube_dl -x --audio-format mp3 --audio-quality 128K -o '/home/israel/Música/%(title)s.%(ext)s' de63cweypyM");
    } catch (...){
        process->close();
        qDebug()<<"Error!";
    }
}
