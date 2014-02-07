#include "GamePad.h"


GamePad::GamePad(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(360,580);
    mPad = new QLabel(this);
    mPad->setGeometry(0,0,360,520);

    /* QLabel to setup the Original Image */
    mPad_original = new QLabel(this);
    mPad_original->setGeometry(0,0,360,520);
    mPad_original->hide();

    /* QLabel to display Done */
    mPad_solved= new QLabel(this);
    mPad_solved->setGeometry(0,0,360,520);
    mPad_solved->setStyleSheet("background-image: url(:/images/done.png);background-color: transparent;");
    mPad_solved->hide();


    /* Control buttons */
    iBackButton = new QPushButton(this);
    iBackButton->setGeometry(0,520, 120, 60);
    iBackButton->setStyleSheet("background-image: url(:/images/label.png); background-color: transparent;border: transparent; color: rgb(128,0,0);");
    iBackButton->setText("Back");
    connect(iBackButton, SIGNAL(clicked()), this, SLOT(iBackButton_clicked()));

    iMoves = new QPushButton(this);
    iMoves->setGeometry(120,520, 120, 60);
    iMoves->setStyleSheet("background-image: url(:/images/label.png); background-color: transparent; border: transparent; color: rgb(128,0,0);");
    iMoves->setText("Moves: 0");

    iSeeOrgButton = new QPushButton(this);
    iSeeOrgButton->setGeometry(240,520, 120, 60);
    iSeeOrgButton->setStyleSheet("background-image: url(:/images/label.png); background-color: transparent; border: transparent;  color: rgb(128,0,0);");
    iSeeOrgButton->setText("Original\nImage");
    connect(iSeeOrgButton, SIGNAL(pressed()), this, SLOT(iSeeOrgButton_clicked()));
    connect(iSeeOrgButton, SIGNAL(released()), this, SLOT(iSeeOrgButton_released()));

    iCounter=0;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

}


GamePad::~GamePad()
{
}


/* Random number generator */
int GamePad::random()
{

    y = qrand();
    x = y % (ROWS*COLUMNS);

    if(mIntList.contains(x) || x==1 || x==0)
    {

        x=random();

    }
    mIntList.append(x);
    return x;
}


void GamePad::mLabelList_clicked()
{
    CustomButton* temp = (CustomButton*)GamePad::sender();
}

void GamePad::mLabelList_released()
{
    CustomButton* temp = (CustomButton*)GamePad::sender();
}

void GamePad::mLabelList_dragEnter()
{
    CustomButton* temp = (CustomButton*)GamePad::sender();

    if (temp->index == iLastDragged)
    {
        return;
    }
    else
    {
        if (check_if_adjacent(iLastDragged, temp->index))
        {

            if (compare_pixmap(tmp_pix, *mLabelList[iLastDragged]->pixmap()) || compare_pixmap(tmp_pix, *mLabelList[temp->index]->pixmap()) || compare_pixmap(tmp_pix1, *mLabelList[iLastDragged]->pixmap()) || compare_pixmap(tmp_pix1, *mLabelList[temp->index]->pixmap()))
            {
                /* Slide tiles */
                QPixmap temp_pix;

                temp_pix = *mLabelList[iLastDragged]->pixmap();
                mLabelList[iLastDragged]->setPixmap(*mLabelList[temp->index]->pixmap());
                mLabelList[temp->index]->setPixmap(temp_pix);

                int temp_int;
                temp_int = mRandomPixmapIntList[iLastDragged];
                mRandomPixmapIntList[iLastDragged]=mRandomPixmapIntList[temp->index];
                mRandomPixmapIntList[temp->index]=temp_int;

                iCounter++;
                iMoves->setText("Moves: " + QString::number(iCounter));
            }
        }


        if (check_if_solved())
        {            
            mPad_solved->show();
            iSeeOrgButton->setText("New\nGame");
        }

        iLastDragged = temp->index;
    }
}

/* Check if the tiles are adjacent */
bool GamePad::check_if_adjacent(int index1, int index2)
{
    if (index1<0 || index2<0)
    {
        return false;
    }

    if(index1-index2 == COLUMNS || index2-index1==COLUMNS || index1-index2==1 || index1-index2==-1)
    {
        return true;
    }
    return false;
}

/* Compares the integer-list to check if the QPixmaps are set */
bool GamePad::check_if_solved()
{
    for(int i=0;i<(ROWS*COLUMNS); i++)

    {
//        if(i==0 && mPixmapIntList[i]==0 && mRandomPixmapIntList[i]==1)
//        {
//            continue;
//        }
//        if(i==1 && mPixmapIntList[i]==1 && mRandomPixmapIntList[i]==0)
//        {
//            continue;
//        }
//        if(i==0 && mPixmapIntList[i]==1 && mRandomPixmapIntList[i]==1)
//        {
//            continue;
//        }
//        if(i==1 && mPixmapIntList[i]==0 && mRandomPixmapIntList[i]==0)
//        {
//            continue;
//        }

        if(i==0 || i ==1)
        {
            continue;
        }
        if(mPixmapIntList.at(i)== mRandomPixmapIntList.at(i))
        {
            continue;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}

/* Comparing two QPixmaps */
bool GamePad::compare_pixmap(QPixmap pix1, QPixmap pix2)
{

    if (pix1.toImage()== pix2.toImage())
    {
        return true;
    }
    return false;
}


/* Setting up the game */
void GamePad::setGame(QString aFilename, int aLevel)
{
    /* Deletion of lists */
    for(int i =0;i<mLabelList.count();i++)
    {
        delete mLabelList[i];
        delete mOrgLabelList[i];
    }
    mLabelList.clear();
    mOrgLabelList.clear();

    /*Level setting */
    if (aLevel == 0)
    {
        ROWS = 3;
        COLUMNS = 3;
    }
    else if (aLevel == 1)
    {
        ROWS = 4;
        COLUMNS = 4;
    }
    else if (aLevel == 2)
    {
        ROWS = 5;
        COLUMNS = 5;
    }

    LabelWidth=360/COLUMNS;
    LabelHeight=520/ROWS;

    for(int i=0; i<(ROWS*COLUMNS); i++)
    {
        mLabelList.append(new CustomButton(mPad));
        connect(mLabelList[i], SIGNAL(clicked()), this, SLOT(mLabelList_clicked()));
        connect(mLabelList[i], SIGNAL(released()), this, SLOT(mLabelList_released()));
        connect(mLabelList[i], SIGNAL(dragEnter()), this, SLOT(mLabelList_dragEnter()));
        mLabelList[i]->index = i;
        mLabelList[i]->show();
        mLabelList[i]->setGeometry(QRect((i%COLUMNS)*LabelWidth,(i/COLUMNS)*LabelHeight,LabelWidth,LabelHeight));
    }


    mRandomPixmapIntList.clear();
    mPixmapList.clear();
    mPixmapIntList.clear();
    mIntList.clear();

    QPixmap pix(aFilename);
    mPad_original->setPixmap(aFilename);



    for(int i=0; i<(ROWS*COLUMNS); i++)
    {
        QPixmap temp = pix.copy((i%COLUMNS)*LabelWidth,(i/COLUMNS)*LabelHeight,LabelWidth,LabelHeight);
        mPixmapList.append(temp);
        mPixmapIntList.append(i);
    }

    /* Setting up Original Image QPixmaps */
    for(int i = 0; i<(ROWS*COLUMNS);i++)
    {
        mOrgLabelList.append(new CustomButton(mPad_original));
        mOrgLabelList[i]->setGeometry(QRect((i%COLUMNS)*LabelWidth,(i/COLUMNS)*LabelHeight,LabelWidth,LabelHeight));
        mOrgLabelList[i]->setStyleSheet("border: 1px solid white");
        mOrgLabelList[i]->setPixmap(mPixmapList[i]);
    }


    int random_no; /* Stores the random no */

    /* Black QPixmap - 1 */
    QPixmap local_pix(LabelWidth, LabelHeight);
    local_pix.fill(Qt::black);
    mLabelList[0]->setPixmap(local_pix);
    tmp_pix = local_pix;
    mRandomPixmapIntList.append(0);

    /* Black QPixmap - 2 */
    QPixmap local_pix1(LabelWidth,LabelHeight);
    local_pix1.fill(Qt::black);
    mLabelList[1]->setPixmap(local_pix1);
    tmp_pix1 = local_pix1;
    mRandomPixmapIntList.append(1);

    /* Setting the QPixmaps in a random order to the QLabels */
    for(int i=2; i<(ROWS*COLUMNS); i++)
    {
        random_no=random();
        mLabelList[i]->setPixmap(mPixmapList[random_no]);
        mRandomPixmapIntList.append(random_no);
    }

    iLastDragged = -1;
}

/* Original Image Button - Clicked */
void GamePad::iSeeOrgButton_clicked()
{
    if (iSeeOrgButton->text() == "Original\nImage")
    {
        mPad_original->show();
    }
    else
    {
        showImageView();
        iSeeOrgButton->setText("Original\nImage");
        iCounter =0;
        iMoves->setText("Moves: 0");
        mPad_solved->hide();
    }

}

/* Original Image Button - Released */
void GamePad::iSeeOrgButton_released()
{
    mPad_original->hide();
}

void GamePad::iBackButton_clicked()
{
    iCounter =0;
    iMoves->setText("Moves: 0");
    iSeeOrgButton->setText("Original\nImage");
    mPad_solved->hide();
    showImageView();
}
