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


// str������ȫ���ַ���,
// ��Offsetָ�����������ַ�
// pt��strΪ��ʼֵ
// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
/*virtual*/ UINT CPositionEnd::GetPosition(LPCTSTR str, POINT &pt)
{
	// ���ַ�������
	int iLen = lstrlen(str);

	// �ж��Ƿ�m_iOffset�������ַ�ǰ��
	if (pt.y + m_iOffset < 0)
		return UINT(-1);

	// ����position
	UINT uiPos = pt.y + m_iOffset;

	// �ж�uiPos�Ƿ�Խ��
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