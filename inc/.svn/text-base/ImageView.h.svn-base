#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QtGui>
#include "CustomButton.h"
#include "GamePad.h"
class ImageView : public QWidget
{
    Q_OBJECT
public:
    explicit ImageView(QWidget *parent = 0);

signals:

    void showHomeView();
    void showLevelView(QString);

public slots:
    void iImagesList_clicked();
    void iBackButton_clicked();

private:
    QLabel* iBg;
    QList<CustomButton*> iImagesList;
    QList<QString> iFileList;
    QPushButton *iBackButton;

};

#endif // IMAGEVIEW_H
