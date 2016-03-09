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
	// ��չptΪ����
	const wchar_t *p = str;
	while (*(p + pt.x) != '\n' && pt.x != 0)// �ݼ�pt.x������
		--pt.x;

	if (pt.x != 0)// ��ǰpt.x��\n��λ��, Ҫ����һ��, ���п�ʼ��
		++pt.x;
	while (*(p + pt.y) != '\r' && *(p + pt.y) != '\0')// ����pt.y����β
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