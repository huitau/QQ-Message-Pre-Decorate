#include "StdAfx.h"
#include "PositionLineEnd.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPositionLineEnd, CPosition, 0x1)

CPositionLineEnd::CPositionLineEnd(void)
: CPosition(0)
{
}

CPositionLineEnd::CPositionLineEnd(int iOffset)
: CPosition(iOffset)
{
}

CPositionLineEnd::~CPositionLineEnd(void)
{
}


/*virtual*/ UINT CPositionLineEnd::GetPosition(LPCTSTR str, POINT &pt)
{
	// ��չptΪ����
	const wchar_t *p = str;
	while (*(p + pt.x) != '\n' && pt.x != 0)// �ݼ�pt.x������
		--pt.x;

	if (pt.x != 0)// ��ǰpt.x��\n��λ��, Ҫ����һ��, ���п�ʼ��
		++pt.x;
	while (*(p + pt.y) != '\r' && *(p + pt.y) != '\0')// ����pt.y����β
		++pt.y;

	return pt.y;
}

void CPositionLineEnd::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CPosition::Serialize(ar);
}