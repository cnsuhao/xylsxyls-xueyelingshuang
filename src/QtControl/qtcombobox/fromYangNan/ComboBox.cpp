#include "ComboBox.h"
#include <stdint.h>
#include "QssString.h"
#include "CStringManager.h"
#include <qglobal.h>
#include "QssHelper.h"
#include "NoFocusFrameDelegate.h"
#include "ListWidget.h"
#include <QtWidgets/QScrollBar>
#include <QKeyEvent>
//#include "D:\\SendToMessageTest.h"

ComboBox::ComboBox(QWidget* parent) :
ControlBase(parent),
m_listOrigin(0),
m_listWidget(nullptr),
m_dropDownImgNormal(1),
m_dropDownImgDisabled(4),
m_dropDownImgExpandNormal(5),
m_dropDownImgExpandDisabled(8),
m_dropDownImgStateCount(8)
{
	init(L"QComboBox", L"drop-down");
	//�����߿�ֶ���Ϊ0����ΪQListWidget���б߿򣬴�����px��Ч
	m_controlStyle[m_className](1, L"QAbstractItemView").AddKeyValue(L"border", L"none");
	m_listWidget = new ListWidget;
	setModel(m_listWidget->model());
	setView(m_listWidget);
	setItemDelegate(new NoFocusFrameDelegate);
	setBorderWidth(1);
	setMouseTracking(true);

	m_listWidget->verticalScrollBar()->setStyleSheet(
		"QScrollBar:vertical"
		"{"
			"width:3px;"
			"background:rgba(0,0,0,0%);"
			"margin:0px,0px,0px,0px;"
			"padding-top:0px;"
			"padding-bottom:0px;"
		"}"
		"QScrollBar::handle:vertical"
		"{"
			"width:3px;"
			"background:rgba(89,109,170,100%);"
			"border-radius:1px;"
			"min-height:10;"
		"}"
		"QScrollBar::handle:vertical:hover"
		"{"
			"width:3px;"
			"background:rgba(110,139,229,100%);"
			"border-radius:1px;"
			"min-height:10;"
		"}"
		"QScrollBar::add-line:vertical"
		"{"
			"height:0px;"
			"width:3px;"
			"border-image:none;"
			"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical"
		"{"
			"height:0px;"
			"width:3px;"
			"border-image:none;"
			"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:vertical:hover"
		"{"
			"height:0px;"
			"width:3px;"
			"border-image:none;"
			"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical:hover"
		"{"
			"height:0px;"
			"width:3px;"
			"border-image:none;"
			"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical"
		"{"
			"background:rgba(54,68,111,100%);"
			"border-radius:1px;"
		"}"
	);
}

void ComboBox::setBackgroundColor(const QColor& normalColor,
								  const QColor& hoverColor,
								  const QColor& pressedColor,
								  const QColor& disabledColor,
								  bool rePaint)
{
	std::map<int32_t, std::map<int32_t, QColor>> colorStateMap;
	colorStateMap[NORMAL][NORMAL] = normalColor;
	colorStateMap[NORMAL][HOVER] = hoverColor;
	colorStateMap[NORMAL][PRESSED] = pressedColor;
	colorStateMap[NORMAL][DISABLED] = disabledColor;
	ControlBase::setColorStateMap(colorStateMap, L"background-color", false, rePaint);
}

void ComboBox::setDropDownSize(int32_t width, int32_t height, bool rePaint)
{
	ControlBase::setPxValue(L"width", width, true, false);
	ControlBase::setPxValue(L"height", height, true, rePaint);
}

void ComboBox::setDropDownBorderWidth(int32_t width, bool rePaint)
{
	ControlBase::setPxSolidValue(L"border", width, true, rePaint);
}

void ComboBox::setDropDownImage(const QString& dropDownImgPath,
								int32_t dropDownImgStateCount,
								int32_t dropDownImgNormal,
								int32_t dropDownImgHover,
								int32_t dropDownImgDisabled,
								int32_t dropDownImgExpandNormal,
								int32_t dropDownImgExpandDisabled,
								bool rePaint)
{
	std::map<int32_t, std::map<int32_t, int32_t>> imageStateMap;
	imageStateMap[NORMAL][NORMAL] = dropDownImgNormal;
	imageStateMap[NORMAL][HOVER] = dropDownImgHover;
	imageStateMap[NORMAL][PRESSED] = dropDownImgExpandNormal;
	imageStateMap[NORMAL][DISABLED] = dropDownImgDisabled;
	std::wstring wstrImgPath = dropDownImgPath.toStdWString();

	m_imagePath = wstrImgPath;
	m_dropDownImgStateCount = dropDownImgStateCount;
	m_dropDownImgNormal = dropDownImgNormal;
	m_dropDownImgDisabled = dropDownImgDisabled;
	m_dropDownImgExpandNormal = dropDownImgExpandNormal;
	m_dropDownImgExpandDisabled = dropDownImgExpandDisabled;
	
	ControlBase::setImageStateMap(imageStateMap, wstrImgPath, dropDownImgStateCount, L"border-image", L"down-arrow", rePaint);
}

void ComboBox::setDropDownTopRightOrigin(int32_t topOrigin, int32_t rightOrigin, bool rePaint)
{
	ControlBase::setPxValue(L"margin-top", topOrigin, true, false);
	ControlBase::setPxValue(L"margin-right", rightOrigin, true, rePaint);
}

void ComboBox::setListOrigin(int32_t origin)
{
	m_listOrigin = origin;
}

void ComboBox::addItem(const QString& text)
{
	QListWidgetItem* widgetItem = new QListWidgetItem(m_listWidget);
	widgetItem->setText(text);
	widgetItem->setToolTip(text);
}

void ComboBox::addItems(const QStringList& textList)
{
	int32_t index = -1;
	int32_t size = textList.size();
	while (index++ != size - 1)
	{
		QListWidgetItem* widgetItem = new QListWidgetItem(m_listWidget);
		widgetItem->setText(textList[index]);
		widgetItem->setToolTip(textList[index]);
	}
}

void ComboBox::setListBackgroundColor(const QColor& color, bool rePaint)
{
	m_listWidget->setBackgroundColor(color, rePaint);
}

void ComboBox::setListBorderWidth(int32_t width, bool rePaint)
{
	m_listWidget->setBorderWidth(width, rePaint);
}

void ComboBox::setListBorderColor(const QColor& color, bool rePaint)
{
	m_listWidget->setBorderColor(color, rePaint);
}

void ComboBox::setListItemBorderColor(const QColor& normalColor,
									const QColor& hoverColor,
									const QColor& disabledColor,
									bool rePaint)
{
	m_listWidget->setItemBorderColor(normalColor, hoverColor, disabledColor, rePaint);
}

void ComboBox::setListItemBackgroundColor(const QColor& normalColor,
										  const QColor& hoverColor,
										  const QColor& disabledColor,
										  bool rePaint)
{
	m_listWidget->setItemBackgroundColor(normalColor, hoverColor, disabledColor, rePaint);
}

void ComboBox::setListItemBorderWidth(int32_t width, bool rePaint)
{
	m_listWidget->setItemBorderWidth(width, rePaint);
}

void ComboBox::setListItemBorderImage(const QString& borderImgPath,
									int32_t borderImgStateCount,
									int32_t borderImgNormal,
									int32_t borderImgHover,
									int32_t borderImgDisabled,
									bool rePaint)
{
	m_listWidget->setItemBorderImage(borderImgPath, borderImgStateCount, borderImgNormal, borderImgHover, borderImgDisabled, rePaint);
}

void ComboBox::setListItemHeight(int32_t height, bool rePaint)
{
	m_listWidget->setItemHeight(height, rePaint);
}

void ComboBox::setListTextColor(const QColor& normalColor,
							  const QColor& hoverColor,
							  const QColor& disabledColor,
							  bool rePaint)
{
	m_listWidget->setTextColor(normalColor, hoverColor, disabledColor, rePaint);
}

void ComboBox::setListFontFace(const QString& fontName, bool rePaint)
{
	m_listWidget->setFontFace(fontName, rePaint);
}

void ComboBox::setListFontSize(int32_t fontSize, bool rePaint)
{
	m_listWidget->setFontSize(fontSize, rePaint);
}

void ComboBox::setListTextOrigin(int32_t origin, bool rePaint)
{
	m_listWidget->setTextOrigin(origin, rePaint);
}

void ComboBox::setListItemAroundOrigin(int32_t leftOrigin,
								 int32_t topOrigin,
								 int32_t rightOrigin,
								 int32_t bottomOrigin,
								 bool rePaint)
{
	m_listWidget->setItemAroundOrigin(leftOrigin, topOrigin, rightOrigin, bottomOrigin, rePaint);
}

void ComboBox::setListMaxHeight(int32_t maxHeight)
{
	((QWidget*)(this->view()->parent()))->setStyleSheet(QString("max-height:%1px").arg(maxHeight));
}

void ComboBox::showEvent(QShowEvent* eve)
{
	repaint();
}

void ComboBox::mouseReleaseEvent(QMouseEvent* eve)
{
	return;
}

void ComboBox::showPopup()
{
	if (count() == 0)
	{
		hidePopup();
		return;
	}
	m_imageStateMap[NORMAL][NORMAL] = m_dropDownImgExpandNormal;
	m_imageStateMap[NORMAL][DISABLED] = m_dropDownImgExpandDisabled;
	ControlBase::setImageStateMap(m_imageStateMap, m_imagePath, m_dropDownImgStateCount, L"border-image", L"down-arrow", true);
	if (m_listOrigin != 0)
	{
		QRect rect = geometry();
		QRect moveRect = rect;
		moveRect.setBottom(rect.bottom() + m_listOrigin);
		setGeometry(moveRect);
		QComboBox::showPopup();
		setGeometry(rect);
	}
	else
	{
		QComboBox::showPopup();
	}
	return;
}

void ComboBox::hidePopup()
{
	m_imageStateMap[NORMAL][NORMAL] = m_dropDownImgNormal;
	m_imageStateMap[NORMAL][DISABLED] = m_dropDownImgDisabled;
	ControlBase::setImageStateMap(m_imageStateMap, m_imagePath, m_dropDownImgStateCount, L"border-image", L"down-arrow", true);
	QComboBox::hidePopup();
	QComboBox::clearFocus();
	return;
}

void ComboBox::hideEvent(QHideEvent* eve)
{
	QComboBox::hideEvent(eve);
	return;
}

void ComboBox::keyPressEvent(QKeyEvent* eve)
{
	if (eve->key() == 16777221 || eve->key() == 16777220)
	{
		return;
	}
	QComboBox::keyPressEvent(eve);
}

void ComboBox::repaint()
{
	updateStyle();
	m_listWidget->repaint();
}