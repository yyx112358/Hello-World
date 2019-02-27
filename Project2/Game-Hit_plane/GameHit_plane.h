#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameHit_plane.h"

class GameHit_plane : public QMainWindow
{
	Q_OBJECT

public:
	GameHit_plane(QWidget *parent = Q_NULLPTR);

private:
	Ui::GameHit_planeClass ui;
};
