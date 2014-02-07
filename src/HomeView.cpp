#include "HomeView.h"

HomeView::HomeView(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(360,580);

    iBg = new QLabel(this);
    iBg->setFixedSize(360, 580);
    iBg->setStyleSheet("background-image: url(:/images/HomeScreen.png);");

}

void HomeView::mousePressEvent(QMouseEvent *event)
{

    if (QRect(8, 63, 234, 55).contains(event->pos()))
    {
        showImageView();
    }

    else if(QRect(134,166,222,55).contains(event->pos()))
    {
        showInstructionView();
    }

    else if(QRect(13,283,167,71).contains((event->pos())))
    {
        showAboutView();
    }

    else if(QRect(177,381,167,64).contains((event->pos())))
    {
        int ret = QMessageBox::question(this, "Exit", "Are you sure to exit?", QMessageBox::Yes| QMessageBox::No);
        if (ret == QMessageBox::Yes)
        {
            exit(0);
        }
    }

}
