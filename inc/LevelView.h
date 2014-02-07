#ifndef LEVELVIEW_H
#define LEVELVIEW_H

#include <QWidget>
#include "QtGui"

class LevelView : public QWidget
{
    Q_OBJECT
public:
    explicit LevelView(QWidget *parent = 0);

signals:
    void showGamePad(int);
    void showImageView();

public slots:
    void iEasyButton_clicked();
    void iMediumButton_clicked();
    void iHardButton_clicked();
    void iBackButton_clicked();

private:
    QLabel* iBg;
    QPushButton *iEasyButton;
    QPushButton *iMediumButton;
    QPushButton *iHardButton;
    QPushButton *iBackButton;
};

#endif // LEVELVIEW_H
