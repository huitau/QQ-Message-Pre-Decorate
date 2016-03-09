#include "StdAfx.h"
#include "PositionLineMiddle.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPositionLineMiddle, CPosition, 0x1)

CPositionLineMiddle::CPositionLineMiddle(void)
: CPosition(0)
{
}

CPositionLineMiddle::CPositionLineMiddle(int iOffset)
: CPosition(iOffset)
{
}

CPositionLineMiddle::~CPositionLineMiddle(void)
{
}


/*virtual*/ UINT CPositionLineMiddle::GetPosition(LPCTSTR str, POINT &pt)
{
	// 扩展pt为整行
	const wchar_t *p = str;
	while (*(p + pt.x) != '\n' && pt.x != 0)// 递减pt.x到行首
		--pt.x;

	if (pt.x != 0)// 当前pt.x是\n的位置, 要递增一下, 到行开始处
		++pt.x;
	while (*(p + pt.y) != '\r' && *(p + pt.y) != '\0')// 递增pt.y到行尾
		++pt.y;

	return (pt.x + pt.y) / 2;
}

void CPositionLineMiddle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CPosition::Serialize(ar);
}