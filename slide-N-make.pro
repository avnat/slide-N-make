# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE56815D8

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

INCLUDEPATH += inc/

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

SOURCES += src/main.cpp \
     src/mainwindow.cpp \
    src/AboutView.cpp \
    src/GamePad.cpp \
    src/ImageView.cpp \
    src/HomeView.cpp \
    src/CustomButton.cpp \
    src/LevelView.cpp \
    src/InstructionView.cpp
HEADERS += inc/mainwindow.h \
    inc/AboutView.h \
    inc/GamePad.h \
    inc/ImageView.h \
    inc/HomeView.h \
    inc/CustomButton.h \
    inc/LevelView.h \
    inc/InstructionView.h
FORMS += mainwindow.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

RESOURCES += \
    images.qrc
