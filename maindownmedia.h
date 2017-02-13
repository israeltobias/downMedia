#ifndef MAINDOWNTUBE_H
#define MAINDOWNTUBE_H

#include <QMainWindow>

namespace Ui {
class MainDownTube;
}

class MainDownTube : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDownTube(QWidget *parent = 0);
    ~MainDownTube();

//Private methods and variables
private:
    Ui::MainDownTube *ui;
};

#endif // MAINDOWNTUBE_H
