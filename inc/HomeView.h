#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QtGui>

class HomeView : public QWidget
{
    Q_OBJECT
public:
    explicit HomeView(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *);

signals:
    void showImageView();
    void showAboutView();
    void showInstructionView();

public slots:

private:
    QLabel* iBg;
    QRect* iNewGame;
};

#endif // HOMEVIEW_H
