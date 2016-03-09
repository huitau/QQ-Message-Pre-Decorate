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
	// ��չptΪ����
	const wchar_t *p = str;
	while (*(p + pt.x) != '\n' && pt.x != 0)// �ݼ�pt.x������
		--pt.x;

	if (pt.x != 0)// ��ǰpt.x��\n��λ��, Ҫ����һ��, ���п�ʼ��
		++pt.x;
	while (*(p + pt.y) != '\r' && *(p + pt.y) != '\0')// ����pt.y����β
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