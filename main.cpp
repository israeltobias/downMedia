#include "maindownmedia.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDownMedia w;
    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.size(),
            a.desktop()->availableGeometry()
        )
    );
    w.show();

    return a.exec();
}
