#ifndef ABOUTVIEW_H
#define ABOUTVIEW_H

#include <QtGui>

class AboutView : public QWidget
{
    Q_OBJECT
public:
    explicit AboutView(QWidget *parent = 0);

signals:
    void showHomeView();

public slots:
    void iBackButton_clicked();

private:
    QLabel* iBg;
    QPushButton *iBackButton;
};

#endif // ABOUTVIEW_H
