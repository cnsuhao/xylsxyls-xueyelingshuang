#ifndef CONTROLBACKGROUND_H__
#define CONTROLBACKGROUND_H__
//#pragma once
#include "ControlBase.h"

template <class QBase>
class ControlBackgroundForNormal : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlBackgroundForNormal();

public:
	/** ���ñ߿���ɫ
	@param [in] color ��̬
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundColor(const QColor& color, bool rePaint = false);

	/** ���ñ߿�ͼƬ
	@param [in] backgroundImgPath ͼƬ·��
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundImage(const QString& backgroundImgPath, bool rePaint = false);
};

template <class QBase>
class ControlBackgroundForNormalHoverDisabled : virtual public ControlBase < QBase >
{

public:
	/** ��������
	*/
	virtual ~ControlBackgroundForNormalHoverDisabled();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��̬��ɫ
	@param [in] hoverColor ��ͣ��ɫ
	@param [in] disabledColor ������ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundColor(const QColor& normalColor,
							const QColor& hoverColor,
							const QColor& disabledColor,
							bool rePaint = false);

	/** ���ýڵ㱳��ͼƬ���ͱ߿���ɫ���ô�
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ����ƽ�ּ���
	@param [in] backgroundImgNormal ��̬ͼƬ�������1��ʾѡ�������һ��
	@param [in] backgroundImgHover ��ͣͼƬ
	@param [in] backgroundImgDisabled ����ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundImage(const QString& backgroundImgPath,
							int32_t backgroundImgStateCount = 4,
							int32_t backgroundImgNormal = 1,
							int32_t backgroundImgHover = 2,
							int32_t backgroundImgDisabled = 4,
							bool rePaint = false);
};

template <class QBase>
class ControlBackgroundForNormalSelectedDisabled : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlBackgroundForNormalSelectedDisabled();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��̬��ɫ
	@param [in] selectedColor ��ͣ��ɫ������list��
	@param [in] disabledColor ������ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundColor(const QColor& normalColor,
							const QColor& selectedColor,
							const QColor& disabledColor,
							bool rePaint = false);

	/** ���ýڵ㱳��ͼƬ���ͱ߿���ɫ���ô�
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ����ƽ�ּ���
	@param [in] backgroundImgNormal ��̬ͼƬ�������1��ʾѡ�������һ��
	@param [in] backgroundImgSelected ��ͣͼƬ������list��
	@param [in] backgroundImgDisabled ����ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundImage(const QString& backgroundImgPath,
							int32_t backgroundImgStateCount = 4,
							int32_t backgroundImgNormal = 1,
							int32_t backgroundImgSelected = 2,
							int32_t backgroundImgDisabled = 4,
							bool rePaint = false);
};

template <class QBase>
class ControlBackgroundForNormalHoverPressedDisabled : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlBackgroundForNormalHoverPressedDisabled();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��̬��ɫ
	@param [in] hoverColor ��ͣ��ɫ
	@param [in] pressedColor ������ɫ
	@param [in] disabledColor ������ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundColor(const QColor& normalColor,
							const QColor& hoverColor,
							const QColor& pressedColor,
							const QColor& disabledColor,
							bool rePaint = false);

	/** ���ýڵ㱳��ͼƬ���ͱ߿���ɫ���ô�
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ����ƽ�ּ���
	@param [in] backgroundImgNormal ��̬ͼƬ�������1��ʾѡ�������һ��
	@param [in] backgroundImgHover ��ͣͼƬ
	@param [in] backgroundImgPressed ����ͼƬ
	@param [in] backgroundImgDisabled ����ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundImage(const QString& backgroundImgPath,
							int32_t backgroundImgStateCount = 4,
							int32_t backgroundImgNormal = 1,
							int32_t backgroundImgHover = 2,
							int32_t backgroundImgPressed = 3,
							int32_t backgroundImgDisabled = 4,
							bool rePaint = false);
};

template <class QBase>
class ControlBackgroundForNormalHoverPressedDisabledAndCheck : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlBackgroundForNormalHoverPressedDisabledAndCheck();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��ѡ�г�̬��ɫ
	@param [in] hoverColor ��ѡ����ͣ��ɫ
	@param [in] pressedColor ��ѡ�а�����ɫ
	@param [in] disabledColor ��ѡ�н�����ɫ
	@param [in] normalCkColor ѡ�г�̬��ɫ
	@param [in] hoverCkColor ѡ����ͣ��ɫ
	@param [in] pressedCkColor ѡ�а�����ɫ
	@param [in] disabledCkColor ѡ�н�����ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundColor(const QColor& normalColor,
							const QColor& hoverColor,
							const QColor& pressedColor,
							const QColor& disabledColor,
							const QColor& normalCkColor,
							const QColor& hoverCkColor,
							const QColor& pressedCkColor,
							const QColor& disabledCkColor,
							bool rePaint = false);

	/** ���ñ���ͼƬ
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ͼƬ�����и����
	@param [in] backgroundImgNormal ��ѡ�г�̬ͼƬ�������1��ʾ��ͼƬ����ָ�4�ݻ�8�ݣ�ѡ������ĵ�һ��
	@param [in] backgroundImgHover ��ѡ����ͣͼƬ
	@param [in] backgroundImgPressed ��ѡ�а���ͼƬ
	@param [in] backgroundImgDisabled ��ѡ�н���ͼƬ
	@param [in] backgroundImgCkNormal ѡ�г�̬ͼƬ
	@param [in] backgroundImgCkHover ѡ����ͣͼƬ
	@param [in] backgroundImgCkPressed ѡ�а���ͼƬ
	@param [in] backgroundImgCkDisabled ѡ�н���ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setBackgroundImage(const QString& backgroundImgPath,
							int32_t backgroundImgStateCount = 8,
							int32_t backgroundImgNormal = 1,
							int32_t backgroundImgHover = 2,
							int32_t backgroundImgPressed = 3,
							int32_t backgroundImgDisabled = 4,
							int32_t backgroundImgCkNormal = 5,
							int32_t backgroundImgCkHover = 6,
							int32_t backgroundImgCkPressed = 7,
							int32_t backgroundImgCkDisabled = 8,
							bool rePaint = false);
};

template <class QBase>
class ControlItemBackgroundForNormal : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlItemBackgroundForNormal();

public:
	/** ���ñ߿���ɫ
	@param [in] color ��̬
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundColor(const QColor& color, bool rePaint = false);

	/** ���ñ߿�ͼƬ
	@param [in] backgroundImgPath ͼƬ·��
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundImage(const QString& backgroundImgPath, bool rePaint = false);
};

template <class QBase>
class ControlItemBackgroundForNormalHoverDisabled : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlItemBackgroundForNormalHoverDisabled();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��̬��ɫ
	@param [in] hoverColor ��ͣ��ɫ
	@param [in] disabledColor ������ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundColor(const QColor& normalColor,
								const QColor& hoverColor,
								const QColor& disabledColor,
								bool rePaint = false);

	/** ���ýڵ㱳��ͼƬ���ͱ߿���ɫ���ô�
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ����ƽ�ּ���
	@param [in] backgroundImgNormal ��̬ͼƬ�������1��ʾѡ�������һ��
	@param [in] backgroundImgHover ��ͣͼƬ
	@param [in] backgroundImgDisabled ����ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundImage(const QString& backgroundImgPath,
								int32_t backgroundImgStateCount = 4,
								int32_t backgroundImgNormal = 1,
								int32_t backgroundImgHover = 2,
								int32_t backgroundImgDisabled = 4,
								bool rePaint = false);
};

template <class QBase>
class ControlItemBackgroundForNormalSelectedDisabled : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlItemBackgroundForNormalSelectedDisabled();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��̬��ɫ
	@param [in] selectedColor ��ͣ��ɫ������list��
	@param [in] disabledColor ������ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundColor(const QColor& normalColor,
								const QColor& selectedColor,
								const QColor& disabledColor,
								bool rePaint = false);

	/** ���ýڵ㱳��ͼƬ���ͱ߿���ɫ���ô�
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ����ƽ�ּ���
	@param [in] backgroundImgNormal ��̬ͼƬ�������1��ʾѡ�������һ��
	@param [in] backgroundImgSelected ��ͣͼƬ������list��
	@param [in] backgroundImgDisabled ����ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundImage(const QString& backgroundImgPath,
								int32_t backgroundImgStateCount = 4,
								int32_t backgroundImgNormal = 1,
								int32_t backgroundImgSelected = 2,
								int32_t backgroundImgDisabled = 4,
								bool rePaint = false);
};

template <class QBase>
class ControlItemBackgroundForNormalHoverPressedDisabled : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlItemBackgroundForNormalHoverPressedDisabled();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��̬��ɫ
	@param [in] hoverColor ��ͣ��ɫ
	@param [in] pressedColor ������ɫ
	@param [in] disabledColor ������ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundColor(const QColor& normalColor,
								const QColor& hoverColor,
								const QColor& pressedColor,
								const QColor& disabledColor,
								bool rePaint = false);

	/** ���ýڵ㱳��ͼƬ���ͱ߿���ɫ���ô�
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ����ƽ�ּ���
	@param [in] backgroundImgNormal ��̬ͼƬ�������1��ʾѡ�������һ��
	@param [in] backgroundImgHover ��ͣͼƬ
	@param [in] backgroundImgPressed ����ͼƬ
	@param [in] backgroundImgDisabled ����ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundImage(const QString& backgroundImgPath,
								int32_t backgroundImgStateCount = 4,
								int32_t backgroundImgNormal = 1,
								int32_t backgroundImgHover = 2,
								int32_t backgroundImgPressed = 3,
								int32_t backgroundImgDisabled = 4,
								bool rePaint = false);
};

template <class QBase>
class ControlItemBackgroundForNormalHoverPressedDisabledAndCheck : virtual public ControlBase < QBase >
{
public:
	/** ��������
	*/
	virtual ~ControlItemBackgroundForNormalHoverPressedDisabledAndCheck();

public:
	/** ���ñ�����ɫ
	@param [in] normalColor ��ѡ�г�̬��ɫ
	@param [in] hoverColor ��ѡ����ͣ��ɫ
	@param [in] pressedColor ��ѡ�а�����ɫ
	@param [in] disabledColor ��ѡ�н�����ɫ
	@param [in] normalCkColor ѡ�г�̬��ɫ
	@param [in] hoverCkColor ѡ����ͣ��ɫ
	@param [in] pressedCkColor ѡ�а�����ɫ
	@param [in] disabledCkColor ѡ�н�����ɫ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundColor(const QColor& normalColor,
								const QColor& hoverColor,
								const QColor& pressedColor,
								const QColor& disabledColor,
								const QColor& normalCkColor,
								const QColor& hoverCkColor,
								const QColor& pressedCkColor,
								const QColor& disabledCkColor,
								bool rePaint = false);

	/** ���ñ���ͼƬ
	@param [in] backgroundImgPath ����ͼƬ·�������·���б���ʹ����б��
	@param [in] backgroundImgStateCount ͼƬ�����и����
	@param [in] backgroundImgNormal ��ѡ�г�̬ͼƬ�������1��ʾ��ͼƬ����ָ�4�ݻ�8�ݣ�ѡ������ĵ�һ��
	@param [in] backgroundImgHover ��ѡ����ͣͼƬ
	@param [in] backgroundImgPressed ��ѡ�а���ͼƬ
	@param [in] backgroundImgDisabled ��ѡ�н���ͼƬ
	@param [in] backgroundImgCkNormal ѡ�г�̬ͼƬ
	@param [in] backgroundImgCkHover ѡ����ͣͼƬ
	@param [in] backgroundImgCkPressed ѡ�а���ͼƬ
	@param [in] backgroundImgCkDisabled ѡ�н���ͼƬ
	@param [in] rePaint �Ƿ������ػ�
	*/
	void setItemBackgroundImage(const QString& backgroundImgPath,
								int32_t backgroundImgStateCount = 8,
								int32_t backgroundImgNormal = 1,
								int32_t backgroundImgHover = 2,
								int32_t backgroundImgPressed = 3,
								int32_t backgroundImgDisabled = 4,
								int32_t backgroundImgCkNormal = 5,
								int32_t backgroundImgCkHover = 6,
								int32_t backgroundImgCkPressed = 7,
								int32_t backgroundImgCkDisabled = 8,
								bool rePaint = false);
};

#include "ControlBackground.inl"

#endif