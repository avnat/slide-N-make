#include "LevelView.h"

LevelView::LevelView(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(360,580);

    iBg = new QLabel(this);
    iBg->setGeometry(0,0,360, 580);
    iBg->setStyleSheet("background-image: url(:/images/Bg.png)");

    iEasyButton = new QPushButton(iBg);
    iEasyButton->setFixedSize(270, 60);
    iEasyButton->setStyleSheet("background-image: url(:/images/easy.png);background-color: transparent; background-repeat: none; border: transparent;");
    connect(iEasyButton,SIGNAL(clicked()),this,SLOT(iEasyButton_clicked()));


    iMediumButton = new QPushButton(iBg);
    iMediumButton->setFixedSize(270, 60);
    iMediumButton->setStyleSheet("background-image: url(:/images/medium.png);background-color: transparent;background-repeat: none;border: transparent;");
    connect(iMediumButton,SIGNAL(clicked()),this,SLOT(iMediumButton_clicked()));

    iHardButton = new QPushButton(iBg);
    iHardButton->setFixedSize(270, 60);
    iHardButton->setStyleSheet("background-image: url(:/images/hard.png); background-color: transparent;background-repeat: none;border: transparent;");
    connect(iHardButton,SIGNAL(clicked()),this,SLOT(iHardButton_clicked()));

    iBackButton = new QPushButton(iBg);
    iBackButton->setFixedSize(320,60);
    iBackButton->setStyleSheet("background-image: url(:/images/backlevel.png); background-color: transparent;background-repeat: none;border: transparent;");
    connect(iBackButton,SIGNAL(clicked()),this,SLOT(iBackButton_clicked()));

    QVBoxLayout* v_layout = new QVBoxLayout(iBg);
    v_layout->setMargin(0);
    v_layout->setContentsMargins(0,0,0,0);
    v_layout->addWidget(iEasyButton, 0, Qt::AlignCenter);
    v_layout->addWidget(iMediumButton, 0, Qt::AlignCenter);
    v_layout->addWidget(iHardButton, 0, Qt::AlignCenter);
    v_layout->addWidget(iBackButton,0,Qt::AlignCenter);

}

void LevelView::iEasyButton_clicked()
{
    showGamePad(0);
}

void LevelView::iMediumButton_clicked()
{
    showGamePad(1);
}

void LevelView::iHardButton_clicked()
{
    showGamePad(2);
}

void LevelView::iBackButton_clicked()
{
    showImageView();
}
