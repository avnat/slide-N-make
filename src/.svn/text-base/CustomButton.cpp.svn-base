#include "CustomButton.h"

CustomButton::CustomButton(QWidget* parent)
    :QLabel(parent)
{

       setAcceptDrops(true);
}

void CustomButton::mousePressEvent(QMouseEvent *ev)
{
    clicked();
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    drag->setMimeData(mimeData);
    drag->exec();
}

void CustomButton::mouseReleaseEvent(QMouseEvent *ev)
{
    released();
}
void CustomButton::dragEnterEvent(QDragEnterEvent *ev)
{
    dragEnter();
}
