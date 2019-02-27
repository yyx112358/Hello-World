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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameHit_planeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameHit_planeClass)
    {
        if (GameHit_planeClass->objectName().isEmpty())
            GameHit_planeClass->setObjectName(QStringLiteral("GameHit_planeClass"));
        GameHit_planeClass->resize(600, 400);
        menuBar = new QMenuBar(GameHit_planeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GameHit_planeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameHit_planeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GameHit_planeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GameHit_planeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GameHit_planeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GameHit_planeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameHit_planeClass->setStatusBar(statusBar);

        retranslateUi(GameHit_planeClass);

        QMetaObject::connectSlotsByName(GameHit_planeClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameHit_planeClass)
    {
        GameHit_planeClass->setWindowTitle(QApplication::translate("GameHit_planeClass", "GameHit_plane", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameHit_planeClass: public Ui_GameHit_planeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEHIT_PLANE_H
