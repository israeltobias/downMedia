#ifndef MAINDOWNMEDIA_H
#define MAINDOWNMEDIA_H

#include <QWidget>

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


private:
    Ui::MainDownMedia *ui;
};

#endif // MAINDOWNMEDIA_H
