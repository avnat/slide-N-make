#ifndef GamePad_H
#define GamePad_H

#include <QtGui>
#include "CustomButton.h"


class GamePad : public QWidget
{
    Q_OBJECT

public:
    explicit GamePad(QWidget *parent = 0);
    ~GamePad();

    // functions
public:
    int random();
    bool check_if_adjacent(int index1, int index2);
    bool check_if_solved();
    bool compare_pixmap(QPixmap pix1, QPixmap pix2);
    QPixmap tmp_pix; /* Black QPixmap - 1 */
    QPixmap tmp_pix1; /* Black QPixmap - 2 */
    void setGame(QString aFilename, int aLevel);

public slots:
    void mLabelList_clicked();
    void mLabelList_released();
    void mLabelList_dragEnter();
    void iSeeOrgButton_clicked();
    void iSeeOrgButton_released();
    void iBackButton_clicked();

signals:
    void showImageView();

private:
    /* QLabels to setup the Qpixmaps */
    QLabel *mLabel;
    QLabel *mPad;
    QLabel *mPad_original;
    QLabel *mPad_solved;

    /* QPushButtons */
    QPushButton *iBackButton;
    QPushButton *iSeeOrgButton;
    QPushButton *iMoves;

    int iCounter; /* Counter-variable to count the number moves */
    int x;
    int y;

    /* QLists */

    /* List of CustomButtons */
    QList<CustomButton*> mLabelList;

    /* List of CustomButtons */
    QList<CustomButton*> mOrgLabelList;

    /* List of QPixmaps */
    QList<QPixmap> mPixmapList;

    /* Integer-List */
    QList<int> mPixmapIntList;

    /* Random-Integer-List */
    QList<int> mRandomPixmapIntList;

    /* Random-Integer-List */
    QList<int> mIntList;


    int iLastDragged;

    /* To store width of label */
    double LabelWidth;

    /* To store height of label */
    double LabelHeight;

    bool icreatedOnce;

    /* Number of COLUMNS */
    int COLUMNS;

    /* Number of ROWS */
    int ROWS;

};

#endif // GamePad_H
