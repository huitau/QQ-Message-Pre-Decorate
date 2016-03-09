#include "StdAfx.h"
#include "PositionEnd.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPositionEnd, CPosition, 0x1)

CPositionEnd::CPositionEnd()
: CPosition(0)
{
}

CPositionEnd::CPositionEnd(int iOffset)
: CPosition(iOffset)
{
}

CPositionEnd::~CPositionEnd(void)
{
}


// str保存了全部字符串,
// 由Offset指定跳过多少字符
// pt以str为起始值
// 返回值以str为起始值, 若函数出错, 返回UINT(-1)
/*virtual*/ UINT CPositionEnd::GetPosition(LPCTSTR str, POINT &pt)
{
	// 求字符串长度
	int iLen = lstrlen(str);

	// 判断是否m_iOffset跳到了字符前面
	if (pt.y + m_iOffset < 0)
		return UINT(-1);

	// 计算position
	UINT uiPos = pt.y + m_iOffset;

	// 判断uiPos是否越界
	if (uiPos > UINT(iLen))
		return UINT(-1);

	return uiPos;
}

void CPositionEnd::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CPosition::Serialize(ar);
}