#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QtGui>

class CustomButton : public QLabel
{
    Q_OBJECT
public:
    CustomButton(QWidget* parent=0);

    int index;


signals:
    void clicked();
    void released();
    void dragEnter();

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void dragEnterEvent(QDragEnterEvent *);
};

#endif // CUSTOMBUTTON_H

