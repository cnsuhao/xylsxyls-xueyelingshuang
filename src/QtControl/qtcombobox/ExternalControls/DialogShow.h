#pragma once
#include "DialogBase.h"
#include <QPropertyAnimation>

/** 窗口基本模型，实现通用部分
*/
class DialogShow : public DialogBase
{
	Q_OBJECT
public:
	/** 构造函数
	*/
	DialogShow();

	/** 设置默认控件，含有关闭按钮，标题，分割线，框大小，背景颜色，背景边框
	*/
	void initForExec();

	/** 设置默认控件，含有标题栏
	@param [in] dialogWidth 宽度
	@param [in] dialogHeight 高度
	@param [in] typeName 类型名
	*/
	void initForShow(int32_t dialogWidth, int32_t dialogHeight, const std::string& typeName);

	/** 设置关闭按钮是否可见，如果对话框中关闭按钮不可见则同时会取消Esc和Alt+F4的使用
	@param [in] visible 是否可见
	*/
	void setExitVisible(bool visible);

Q_SIGNALS:
	void dialogDone(int32_t dialogId, int32_t result, int32_t userType);

protected:
	void paintEvent(QPaintEvent* eve);
	void mousePressEvent(QMouseEvent* eve);
	void mouseMoveEvent(QMouseEvent* eve);
	void mouseReleaseEvent(QMouseEvent* eve);
	void keyPressEvent(QKeyEvent* eve);
	void closeEvent(QCloseEvent* eve);
	bool nativeEvent(const QByteArray& eventType, void* message, long* result);
	void showEvent(QShowEvent* eve);

	void done(int result);
	void end();

private slots:
	void timeUpdate(int32_t timeOut);

private:
	void ncActiveChanged(int32_t wParam);
	
protected:
	COriginalButton* m_exit;
	Label* m_title;
	Label* m_separator;
	Label* m_time;
	Label* m_titleBar;
	Label* m_icon;
	int32_t m_userType;

private:
	bool m_bPressed;
	bool m_highLight;
	QPoint m_point;
	bool m_cancelEscAltF4;
	bool m_isExec;
	QPropertyAnimation m_animation;
	int32_t m_result;
	QRect m_beginRect;
	QRect m_endRect;
};