#pragma once
#include "DialogShow.h"

/** 输入弹出框
*/
class InputDialog : protected DialogShow
{
	Q_OBJECT
public:
	/** 弹出输入框
	@param [out] dialogId 窗口ID值
	@param [in] title 标题
	@param [in] editTip 提示内容
	@param [in] buttonText 按钮内容
	@param [in] done 按钮按下后的返回值
	@param [in,out] editText 输入框默认文字
	@param [in] isPassword 是否将输入框换为密码框
	@param [in] maxLength 输入最大长度，-1表示不限制
	@param [in] parent 父窗口指针
	@param [in] timeOut 超时自动关闭，单位秒
	@param [in] isCountDownVisible 超时自动关闭提示是否可见
	@return 关闭窗口时给的返回值
	*/
	static int32_t popInputDialog(int32_t& dialogId,
								  const QString& title,
								  const QString& editTip,
								  const QString& buttonText,
								  int32_t done,
								  QString& editText,
								  bool isPassword = false,
								  int32_t maxLength = -1,
								  QWindow* parent = nullptr,
								  int32_t timeOut = -1,
								  bool isCountDownVisible = false);
private:
	InputDialog(const QString& title,
				const QString& editTip,
				const QString& buttonText,
				int32_t done,
				QString& editText,
				bool isPassword = false,
				int32_t maxLength = -1);

	void done(int result);

private slots:
	void inputAccept();

private:
	Label* m_editTip;
	COriginalButton* m_accept;
	LineEdit* m_edit;
	QString& m_editText;
};