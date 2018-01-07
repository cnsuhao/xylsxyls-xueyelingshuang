#include "ShowDialogManager.h"
#include "DialogBase.h"
#include "AskDialog.h"
#include "TipDialog.h"
#include "InputDialog.h"
#include "WaitDialog.h"
#include "TipShowDialog.h"
#include "AskShowDialog.h"
#include "LoginShowDialog.h"
#include <QTime>

ShowDialogManager& ShowDialogManager::instance()
{
	static ShowDialogManager showDialogHelper;
	return showDialogHelper;
}

void ShowDialogManager::showTipDialog(int32_t& dialogId,
									  int32_t userType,
									  const QString& title,
									  const QString& tip,
									  int32_t done,
									  const QString& buttonText,
									  int32_t timeOut,
									  bool isCountDownVisible)
{
	TipShowDialog::showTipDialog(dialogId, userType, title, tip, buttonText, done, timeOut, isCountDownVisible);
}

void ShowDialogManager::showAskDialog(int32_t& dialogId,
									  int32_t userType,
									  const QString& title,
									  const QString& tip,
									  int32_t acceptDone,
									  int32_t ignoreDone,
									  const QString& acceptText,
									  const QString& ignoreText,
									  int32_t timeOut,
									  bool isCountDownVisible)
{
	AskShowDialog::showAskDialog(dialogId,
								 userType,
								 title,
								 tip,
								 acceptText,
								 acceptDone,
								 ignoreText,
								 ignoreDone,
								 timeOut,
								 isCountDownVisible);
}

void ShowDialogManager::showLoginDialog(int32_t& dialogId,
										int32_t userType,
										const QString& title,
										const QString& tip,
										const QString& linkUrl,
										int32_t timeOut,
										bool isUrlButtonVisible,
										bool isCountDownVisible)
{
	QString greeting;
	QTime tm = QTime::currentTime();
	int hour = tm.hour();
	if ((hour > 0) && (hour <= 9))
	{
		greeting = QString::fromStdWString(L"�糿�ã�");
	}
	else if ((hour > 9) && (hour <= 12))
	{
		greeting = QString::fromStdWString(L"���Ϻã�");
	}
	else if ((hour > 12) && (hour <= 18))
	{
		greeting = QString::fromStdWString(L"����ã�");
	}
	else
	{
		greeting = QString::fromStdWString(L"���Ϻã�");
	}

	LoginShowDialog::showLoginDialog(dialogId,
									 userType,
									 title,
									 greeting,
									 tip,
									 QString::fromStdWString(L">>�˽����"),
									 linkUrl,
									 timeOut,
									 isUrlButtonVisible,
									 isCountDownVisible);
}