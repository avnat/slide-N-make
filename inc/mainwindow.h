// checksum 0x9a77 version 0x30001
/*
  This file was generated by the Mobile Qt Application wizard of Qt Creator.
  MainWindow is a convenience class containing mobile device specific code
  such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "AboutView.h"
#include "ImageView.h"
#include "GamePad.h"
#include "HomeView.h"
#include "LevelView.h"
#include "InstructionView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void setOrientation(ScreenOrientation orientation);
    void showExpanded();

public slots:
    void activateHomeView();
    void activateImageView();
    void activateAboutView();
    void activateInstructionView();
    void activateLevelView(QString);
    void activateGamePad(int);


private:
    Ui::MainWindow *ui;
    QWidget* iBg;
    QLabel* iTitleBar;
    QStackedWidget* iStackedWidget;
    QString iFilename;

    GamePad* iGamePad;
    AboutView* iAboutView;
    ImageView* iImageView;
    HomeView* iHomeView;
    LevelView* iLevelView;
    InstructionView* iInstructionView;
};

#endif // MAINWINDOW_H
