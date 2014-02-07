#include "AboutView.h"

AboutView::AboutView(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(360,580);

    iBg = new QLabel(this);
    iBg->setFixedSize(360, 580);
    iBg->setStyleSheet("background-image: url(:/images/aboutBg.png)");
    iBg->setAlignment(Qt::AlignCenter);


    iBackButton = new QPushButton(iBg);
    iBackButton->setGeometry(0,520,360,60);
    iBackButton->setStyleSheet("background-image: url(:/images/back.png); background-color: transparent;border: transparent;");
    connect(iBackButton, SIGNAL(clicked()),this,SLOT(iBackButton_clicked()));
}

void AboutView::iBackButton_clicked()
{
    showHomeView();
}
