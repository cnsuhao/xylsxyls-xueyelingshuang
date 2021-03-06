#pragma once
#include <QtWidgets/QComboBox>
#include <stdint.h>
#include "ControlFont.h"
#include "ControlSelf.h"
#include "ControlBorder.h"
#include "ControlBackground.h"

class QListWidgetItem;
class ListWidget;
class ComboBox : 
	public ControlShow < QComboBox >,
	public ControlFont < QComboBox >,
	public ControlSelf < QComboBox >,
	public ControlBorderForNormalHoverPressedDisabled < QComboBox >,
	public ControlBackgroundForNormalHoverPressedDisabled < QComboBox >
{
	Q_OBJECT
public:
	/** 构造函数
	@param [in] parent 父窗口指针
	*/
	ComboBox(QWidget* parent = nullptr);

	/** 析构函数
	*/
	virtual ~ComboBox();

public:
	/** 设置默认值
	*/
	void setDefault();

	/** 设置下拉箭头的尺寸
	@param [in] width 下拉箭头宽度
	@param [in] height 下拉箭头高度
	@param [in] rePaint 是否立即重画
	*/
	void setDropDownSize(int32_t width, int32_t height = -1, bool rePaint = false);

	/** 设置下拉箭头的边框宽度
	@param [in] width 下拉箭头宽度
	@param [in] rePaint 是否立即重画
	*/
	void setDropDownBorderWidth(int32_t width, bool rePaint = false);

	/** 设置下拉箭头的图片
	@param [in] dropDownImgPath 背景图片路径，如果路径中必须使用正斜杠
	@param [in] dropDownImgStateCount 上下平分几份
	@param [in] dropDownImgNormal 非选中常态图片，如果填1表示将图片纵向分割4份或8份，选最上面的第一份
	@param [in] dropDownImgHover 非选中悬停图片
	@param [in] dropDownImgDisabled 非选中禁用图片
	@param [in] dropDownImgCkNormal 选中常态图片
	@param [in] dropDownImgCkDisabled 选中禁用图片
	@param [in] rePaint 是否立即重画
	*/
	void setDropDownImage(const QString& dropDownImgPath,
						  int32_t dropDownImgStateCount = 8,
						  int32_t dropDownImgNormal = 1,
						  int32_t dropDownImgHover = 2,
						  int32_t dropDownImgDisabled = 4,
						  int32_t dropDownImgExpandNormal = 5,
						  int32_t dropDownImgExpandDisabled = 8,
						  bool rePaint = false);

	/** 设置下拉箭头距离右上角的边距
	@param [in] topOrigin 上侧偏移量
	@param [in] rightOrigin 右侧偏移量
	@param [in] rePaint 是否立即重画
	*/
	void setDropDownTopRightOrigin(int32_t topOrigin, int32_t rightOrigin = -1, bool rePaint = false);

	/** 设置下拉框弹出时距离点击框的纵向偏移量
	@param [in] origin 纵向偏移量
	*/
	void setListOrigin(int32_t origin);

	/** 增加一行
	@param [in] text 文本
	*/
	void addItem(const QString& text);

	/** 增加整串
	@param [in] textList 文本列表
	*/
	void addItems(const QStringList& textList);

	/** 设置指定节点文字
	@param [in] index 索引值
	@param [in] text 文本
	*/
	void setItemText(int32_t index, const QString& text);

	/** 设置背景颜色
	@param [in] color 背景颜色
	@param [in] rePaint 是否立即重画
	*/
	void setListBackgroundColor(const QColor& color, bool rePaint = false);

	/** 设置下拉框边框粗度
	@param [in] width 边框粗度
	@param [in] rePaint 是否立即重画
	*/
	void setListBorderWidth(int32_t width, bool rePaint = false);

	/** 设置下拉框边框颜色
	@param [in] color 常态
	@param [in] rePaint 是否立即重画
	*/
	void setListBorderColor(const QColor& color, bool rePaint = false);

	/** 设置下拉框节点边框颜色（list控件没有按下属性）
	@param [in] normalColor 常态颜色
	@param [in] hoverColor 悬停颜色
	@param [in] disabledColor 禁用颜色
	@param [in] rePaint 是否立即重画
	*/
	void setListItemBorderColor(const QColor& normalColor,
								const QColor& hoverColor = QColor(0, 0, 0, 0),
								const QColor& disabledColor = QColor(0, 0, 0, 0),
								bool rePaint = false);

	/** 设置下拉框节点背景颜色（list控件没有按下属性）
	@param [in] normalColor 常态颜色
	@param [in] hoverColor 悬停颜色
	@param [in] disabledColor 禁用颜色
	@param [in] rePaint 是否立即重画
	*/
	void setListItemBackgroundColor(const QColor& normalColor,
									const QColor& hoverColor = QColor(0, 0, 0, 0),
									const QColor& disabledColor = QColor(0, 0, 0, 0),
									bool rePaint = false);

	/** 设置下拉框节点边框粗度
	@param [in] width 边框粗度
	@param [in] rePaint 是否立即重画
	*/
	void setListItemBorderWidth(int32_t width, bool rePaint = false);

	/** 设置下拉框节点背景图片，和边框颜色不用存
	@param [in] borderImgPath 背景图片路径，如果路径中必须使用正斜杠
	@param [in] borderImgStateCount 上下平分几份
	@param [in] borderImgNormal 非选中常态图片，如果填1表示将图片纵向分割4份或8份，选最上面的第一份
	@param [in] borderImgHover 非选中悬停图片
	@param [in] borderImgDisabled 非选中禁用图片
	@param [in] rePaint 是否立即重画
	*/
	void setListItemBorderImage(const QString& borderImgPath,
								int32_t borderImgStateCount = 4,
								int32_t borderImgNormal = 1,
								int32_t borderImgHover = 2,
								int32_t borderImgDisabled = 4,
								bool rePaint = false);

	/** 设置下拉框节点高度
	@param [in] height 节点高度
	@param [in] rePaint 是否立即重画
	*/
	void setListItemHeight(int32_t height, bool rePaint = false);

	/** 设置下拉框文字颜色
	@param [in] normalColor 常态颜色
	@param [in] hoverColor 悬停颜色
	@param [in] disabledColor 禁用颜色
	@param [in] rePaint 是否立即重画
	*/
	void setListTextColor(const QColor& normalColor,
						  const QColor& hoverColor = QColor(0, 0, 0, 0),
						  const QColor& disabledColor = QColor(0, 0, 0, 0),
						  bool rePaint = false);

	/** 设置下拉框字体
	@param [in] fontName 字体名
	@param [in] rePaint 是否立即重画
	*/
	void setListFontFace(const QString& fontName, bool rePaint = false);

	/** 设置下拉框字体大小
	@param [in] fontSize 字体大小
	@param [in] rePaint 是否立即重画
	*/
	void setListFontSize(int32_t fontSize, bool rePaint = false);

	/** 设置下拉框文本偏移量
	@param [in] origin 文本偏移量
	@param [in] rePaint 是否立即重画
	*/
	void setListTextOrigin(int32_t origin, bool rePaint = false);

	/** 节点到下拉框窗口的四个外边距
	@param [in] leftOrigin 左侧偏移量
	@param [in] topOrigin 上侧偏移量
	@param [in] rightOrigin 右侧偏移量
	@param [in] bottomOrigin 下侧偏移量
	@param [in] rePaint 是否立即重画
	*/
	void setListItemAroundOrigin(int32_t leftOrigin,
								 int32_t topOrigin = -1,
								 int32_t rightOrigin = -1,
								 int32_t bottomOrigin = -1,
								 bool rePaint = false);

	/** 设置下拉框最大高度
	@param [in] maxHeight 最大高度
	*/
	void setListMaxHeight(int32_t maxHeight);

	/** 设置下拉箭头是否隐藏
	@param [in] enable 是否隐藏
	@param [in] rePaint 是否立即重画
	*/
	void setDropDownVisible(bool enable, bool rePaint = false);

	/** 重画
	*/
	virtual void repaint();

Q_SIGNALS:
	/** 节点被按下之后发送信号
	@param [in] index 节点索引值
	*/
	void itemPressed(int index);

private:
	virtual void showEvent(QShowEvent* eve);
	virtual void mouseReleaseEvent(QMouseEvent* eve);
	virtual void mouseMoveEvent(QMouseEvent* eve);
	virtual void showPopup();
	virtual void hidePopup();
	virtual void hideEvent(QHideEvent* eve);
	virtual void keyPressEvent(QKeyEvent* eve);

private slots:
	void listItemEntered(QListWidgetItem* item);
	void listItemPressed(QListWidgetItem* item);

protected:
	ListWidget* m_listWidget;
	int32_t m_hoverIndex;

private:
	int32_t m_dropDownImgNormal;
	int32_t m_dropDownImgDisabled;
	int32_t m_dropDownImgExpandNormal;
	int32_t m_dropDownImgExpandDisabled;
	int32_t m_dropDownImgStateCount;
	std::map<int32_t, std::map<int32_t, int32_t>> m_imageStateMap;
	std::wstring m_imagePath;
	int32_t m_listOrigin;
	int32_t m_dropDownWidth;
	int32_t m_dropDownHeight;
	int32_t m_dropDownBorderWidth;
	bool m_dropDownVisible;
};
