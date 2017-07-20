#ifndef MAINDOWNMEDIA_H
#define MAINDOWNMEDIA_H

#include <QWidget>
#include <QProcess>
#include <QProgressDialog>

namespace Ui {
class MainDownMedia;
}

class MainDownMedia : public QWidget
{
    Q_OBJECT

public:
    explicit MainDownMedia(QWidget *parent = 0);
    ~MainDownMedia();

private slots:
    void on_btnProcess_clicked();
    void readyRead();


private:
    Ui::MainDownMedia *ui;
    QProcess *process;
    QProgressDialog *progress;
};

#endif // MAINDOWNMEDIA_H
