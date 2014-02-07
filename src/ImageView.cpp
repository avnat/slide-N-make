#include "ImageView.h"
#define ROWS 3
#define COLUMNS 3

ImageView::ImageView(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(360,580);


    iBg = new QLabel(this);
    iBg->setFixedSize(360, 580);
    iBg->setStyleSheet("background-image: url(:/images/Bg.png);");

    /* List of images */
    iFileList << ":/images/1.png"
              <<  ":/images/2.png"
              <<  ":/images/3.png"
              <<  ":/images/4.png"
              <<  ":/images/5.png"
              <<  ":/images/6.png"
              <<  ":/images/7.png"
              <<  ":/images/8.png"
              <<  ":/images/9.png";

    QGridLayout* g_layout = new QGridLayout;
    g_layout->setMargin(0);
    g_layout->setHorizontalSpacing(1);
    g_layout->setVerticalSpacing(1);

    for(int i=0;i<ROWS*COLUMNS;i++)
    {
        iImagesList.append(new CustomButton(iBg));
        g_layout->addWidget(iImagesList.at(i), i/3, i%3 );
        connect(iImagesList[i], SIGNAL(clicked()), this, SLOT(iImagesList_clicked()));
        iImagesList[i]->index = i;
        iImagesList.at(i)->setText(QString::number(i));
        iImagesList.at(i)->setFixedSize(120,173);
        iImagesList.at(i)->setPixmap(QPixmap(iFileList.at(i)).scaled(iImagesList.at(i)->size()));
        iImagesList.at(i)->setStyleSheet("border: 2px solid rgb(180,0,0);");

    }

    iBackButton = new QPushButton(iBg);
    iBackButton->setFixedSize(360,60);
    iBackButton->setStyleSheet("background-image: url(:/images/back.png); background-color: transparent");
    connect(iBackButton, SIGNAL(clicked()),this,SLOT(iBackButton_clicked()));

    QVBoxLayout* v_layout = new QVBoxLayout(iBg);
    v_layout->setMargin(0);
    v_layout->setContentsMargins(0,0,0,0);
    v_layout->setSpacing(0);
    v_layout->addLayout(g_layout);
    v_layout->addWidget(iBackButton);
}


void ImageView::iImagesList_clicked()
{
    CustomButton* temp = (CustomButton*)ImageView::sender();
    qDebug()<<"clicked"<<temp->index;
    showLevelView(iFileList.at(temp->index));
}

void ImageView::iBackButton_clicked()
{
    showHomeView();
}
