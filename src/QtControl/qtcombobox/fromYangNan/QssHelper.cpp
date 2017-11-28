#include "QssHelper.h"
#include "CStringManager.h"
#include <QPixmap>

std::wstring QssHelper::QColorToWString(const QColor& color)
{
	return CStringManager::Format(L"rgba(%d,%d,%d,%d)", color.red(), color.green(), color.blue(), color.alpha());
}

bool QssHelper::GetPicHeight(const std::wstring& path, int32_t count, std::vector<int32_t>& vecHeight)
{
	QString imgPath = QString::fromStdWString(path.c_str());
	QPixmap imgPixmap;
	if (imgPixmap.load(imgPath) == false)
	{
		return false;
	}

	int32_t imgHeight = imgPixmap.height();
	int32_t stepHeight = imgHeight / count;

	if (imgHeight % count != 0)
	{
		return false;
	}

	int32_t height = 0;
	vecHeight.clear();
	while (height != imgHeight)
	{
		vecHeight.push_back(height);
		height += stepHeight;
	}

	if (vecHeight.size() != count)
	{
		return false;
	}

	return true;
}