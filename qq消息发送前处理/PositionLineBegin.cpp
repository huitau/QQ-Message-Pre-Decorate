#include "StdAfx.h"
#include "PositionLineBegin.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPositionLineBegin, CPosition, 0x1)

CPositionLineBegin::CPositionLineBegin(void)
: CPosition(0)
{
}

CPositionLineBegin::CPositionLineBegin(int iOffset)
: CPosition(iOffset)
{
}

CPositionLineBegin::~CPositionLineBegin(void)
{
}


/*virtual*/ UINT CPositionLineBegin::GetPosition(LPCTSTR str, POINT &pt)
{
	// 扩展pt为整行
	const wchar_t *p = str;
	while (*(p + pt.x) != '\n' && pt.x != 0)// 递减pt.x到行首
		--pt.x;

	if (pt.x != 0)// 当前pt.x是\n的位置, 要递增一下, 到行开始处
		++pt.x;
	while (*(p + pt.y) != '\r' && *(p + pt.y) != '\0')// 递增pt.y到行尾
		++pt.y;

	return pt.x;
}

void CPositionLineBegin::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CPosition::Serialize(ar);
}