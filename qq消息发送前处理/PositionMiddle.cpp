#include "StdAfx.h"
#include "PositionMiddle.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPositionMiddle, CPosition, 0x1)

CPositionMiddle::CPositionMiddle()
: CPosition(0)
{
}

CPositionMiddle::CPositionMiddle(int iOffset)
: CPosition(iOffset)
{
}

CPositionMiddle::~CPositionMiddle(void)
{
}


// str������ȫ���ַ���,
// ��Offsetָ�����������ַ�
// pt��strΪ��ʼֵ
// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
/*virtual*/ UINT CPositionMiddle::GetPosition(LPCTSTR str, POINT &pt)
{
	// ���ַ�������
	int iLen = lstrlen(str);

	int iPoint = (pt.x + pt.y) / 2;

	// �ж��Ƿ�m_iOffset�������ַ�ǰ��
	if (iPoint + m_iOffset < 0)
		return UINT(-1);

	// ����position
	UINT uiPos = iPoint + m_iOffset;

	// �ж�uiPos�Ƿ�Խ��
	if (uiPos > UINT(iLen))
		return UINT(-1);

	return uiPos;
}

void CPositionMiddle::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CPosition::Serialize(ar);
}