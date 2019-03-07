/********************************************************************************
** Form generated from reading UI file 'GameHit_plane.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEHIT_PLANE_H
#define UI_GAMEHIT_PLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameHit_planeClass
{
public:
    QAction *actionRestart;
    QAction *actionPause;
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameHit_planeClass)
    {
        if (GameHit_planeClass->objectName().isEmpty())
            GameHit_planeClass->setObjectName(QStringLiteral("GameHit_planeClass"));
        GameHit_planeClass->resize(600, 400);
        actionRestart = new QAction(GameHit_planeClass);
        actionRestart->setObjectName(QStringLiteral("actionRestart"));
        actionPause = new QAction(GameHit_planeClass);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionPause->setCheckable(true);
        actionLoad = new QAction(GameHit_planeClass);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(GameHit_planeClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(GameHit_planeClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(GameHit_planeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        GameHit_planeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GameHit_planeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        GameHit_planeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameHit_planeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GameHit_planeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GameHit_planeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameHit_planeClass->setStatusBar(statusBar);

        mainToolBar->addAction(actionRestart);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionExit);
        mainToolBar->addAction(actionLoad);
        mainToolBar->addAction(actionSave);

        retranslateUi(GameHit_planeClass);

        QMetaObject::connectSlotsByName(GameHit_planeClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameHit_planeClass)
    {
        GameHit_planeClass->setWindowTitle(QApplication::translate("GameHit_planeClass", "GameHit_plane", nullptr));
        actionRestart->setText(QApplication::translate("GameHit_planeClass", "Restart", nullptr));
        actionPause->setText(QApplication::translate("GameHit_planeClass", "Pause", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPause->setShortcut(QApplication::translate("GameHit_planeClass", "P", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad->setText(QApplication::translate("GameHit_planeClass", "Load", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad->setShortcut(QApplication::translate("GameHit_planeClass", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("GameHit_planeClass", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("GameHit_planeClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("GameHit_planeClass", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("GameHit_planeClass", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("GameHit_planeClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameHit_planeClass: public Ui_GameHit_planeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHIT_PLANE_H
