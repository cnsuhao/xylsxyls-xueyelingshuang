#ifndef GAMEINFOWIDGETAPP_H
#define GAMEINFOWIDGETAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_gameinfowidgetapp.h"

class GameInfoWidgetApp : public QMainWindow
{
	Q_OBJECT

public:
	GameInfoWidgetApp(QWidget *parent = 0);
	~GameInfoWidgetApp();

private slots:
	void save();
	void changed(const QString& str);
	void changed2(const QString& str);
	void prepare();
	void cancelPrepare();
	void onJudgeChanged(bool judge);

private:
	Ui::GameInfoWidgetAppClass ui;
};

#endif // GAMEINFOWIDGETAPP_H
