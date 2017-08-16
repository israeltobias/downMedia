#include "maindownmedia.h"
#include "ui_maindownmedia.h"
#include <iostream>
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QProgressDialog>
#include <QStringList>
using namespace std;

MainDownMedia::MainDownMedia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainDownMedia)
{
    ui->setupUi(this);
}

MainDownMedia::~MainDownMedia()
{
    this->process->close();
    delete ui;
}
/*********************************************
 * SLOTS
 * *******************************/

void MainDownMedia::readyRead(){
    if (!this->process)
        return;

      QString str = process->readAllStandardOutput();
      if(str.contains("%",Qt::CaseInsensitive)){
        QStringList list = str.split(" ");
        foreach (QString item, list) {
            if(item.contains("%",Qt::CaseInsensitive)){
                QStringList percentage = item.split("%");
                float intPercentage = ((QString) percentage.at(0)).toFloat();
                if(intPercentage<100) {
                    this->progress->setValue(intPercentage);
                 }
            }
        }
      }
      if(str.contains("Destination:",Qt::CaseInsensitive)){
          QStringList strFile = str.split("/");
          QString nameFile = strFile.last();
          this->progress->setLabelText(nameFile);
      }
      if(str.contains("[ffmpeg]")){
          this->progress->setWindowTitle("Convirtiendo");
      }
      if(str.contains("Deleting")){
          this->progress->setValue(100);
      }
}

void MainDownMedia::on_btnProcess_clicked()
{
    this->process = new QProcess(this);
    try {
        this->process->setReadChannel(QProcess::StandardOutput);
        this->process->setProcessChannelMode( QProcess::MergedChannels );


        this->progress = new QProgressDialog;
        this->progress->setAttribute(Qt::WA_DeleteOnClose);
        //this->progress->setWindowModality(Qt::WindowModal);
        this->progress->setModal(true);
        this->progress->setMaximumSize(400,130);
        this->progress->setMinimumSize(400,130);
        this->progress->setCancelButtonText("Cancelar");
        this->progress->setWindowTitle("Descargando");
        this->progress->setLabelText("Conectando con YouTube...");
        this->progress->setRange(0,100);
        //connect(this->process, SIGNAL(finished(int)), this->progress, SLOT(close()));
        connect (this->process, SIGNAL(readyReadStandardOutput()), this, SLOT(readyRead()));
        QDir *dir = new QDir();
        dir->cd("youtube-dl");
        qDebug()<<"DIR: "<<dir->absolutePath();
        this->process->setWorkingDirectory(dir->absolutePath());
        this->process->start("python -m youtube_dl -x --audio-format mp3 --audio-quality 128K --rm-cache-dir -o \"/home/israel/Música/%(title)s.%(ext)s\" de63cweypyM", QProcess::Unbuffered | QProcess::ReadWrite);
        //execute
        this->progress->exec();
        dir->cdUp();
        qDebug()<<"DIR: "<<dir->absolutePath();
        this->process->setWorkingDirectory(dir->absolutePath());
        this->process->close();
  //  process->start("sh", QStringList()<<"-c"<<"python -m youtube_dl -x --audio-format mp3 --audio-quality 128K -o '/home/israel/Música/%(title)s.%(ext)s' de63cweypyM");
    } catch (...){
        this->process->close();
        qDebug()<<"Error!";
    }
}
