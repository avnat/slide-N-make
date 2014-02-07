#include "InstructionView.h"

InstructionView::InstructionView(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(360,580);

    iBg = new QLabel(this);
    iBg->setFixedSize(360, 580);
    iBg->setStyleSheet("background-image: url(:/images/instructionsBg.png)");
    iBg->setAlignment(Qt::AlignCenter);


    iBackButton = new QPushButton(iBg);
    iBackButton->setGeometry(0,520,360,60);
    iBackButton->setStyleSheet("background-image: url(:/images/back.png); background-color: transparent;border: transparent;");    
    connect(iBackButton, SIGNAL(clicked()),this,SLOT(iBackButton_clicked()));
}

void InstructionView::iBackButton_clicked()
{
    showHomeView();
}
