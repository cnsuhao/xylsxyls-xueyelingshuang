#include "AskDialog.h"
#include "Label.h"

int32_t AskDialog::popAskDialog(int32_t& dialogId,
								const QString& title,
								const QString& tip,
								const QString& acceptText,
								int32_t acceptDone,
								const QString& ignoreText,
								int32_t ignoreDone,
								QWindow* parent,
								int32_t timeOut,
								bool isCountDownVisible)
{
	AskDialog dlg(title, tip, acceptText, acceptDone, ignoreText, ignoreDone);
	dlg.setParentWindow(parent);
	return dlg.exec(dialogId, timeOut, isCountDownVisible);
}

AskDialog::AskDialog(const QString& title,
					 const QString& tip,
					 const QString& acceptText,
					 int32_t acceptDone,
					 const QString& ignoreText,
					 int32_t ignoreDone)
{
	initForExec();
	m_title->setText(title);
	m_title->setFontSize(12);
	m_tip = addTip(tip, QRect(43, 51, width() - 43 * 2, 60), QColor(205, 213, 225, 255));
	m_tip->setFontSize(12);
	m_accept = addButton(acceptText, QRect((width() - 116 * 2) / 3, 127, 116, 22), acceptDone);
	m_ignore = addButton(ignoreText, QRect((width() - 116 * 2) / 3 * 2 + 116, 127, 116, 22), ignoreDone);
}