#include "ListWidget.h"

ListWidget::ListWidget(QWidget* parent) :
ControlShow(parent)
{
	ControlBase::setControlShow(this);
	INIT(L"item");
}

ListWidget::~ListWidget()
{

}

void ListWidget::setMaxHeight(int32_t maxHeight, bool rePaint)
{
	ControlBase::setPxValue(L"max-height", maxHeight, false, rePaint);
}