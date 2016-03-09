#include "StdAfx.h"
#include "PositionBegin.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPositionBegin, CPosition, 0x1)

CPositionBegin::CPositionBegin()
: CPosition(0)
{
}

CPositionBegin::CPositionBegin(int iOffset)
: CPosition(iOffset)
{
}

CPositionBegin::~CPositionBegin(void)
{
}


// str������ȫ���ַ���,
// ��Offsetָ�����������ַ�
// pt��strΪ��ʼֵ
// ����ֵ��strΪ��ʼֵ, ����������, ����UINT(-1)
/*virtual*/ UINT CPositionBegin::GetPosition(LPCTSTR str, POINT &pt)
{
	// ���ַ�������
	int iLen = lstrlen(str);

	// �ж��Ƿ�m_iOffset�������ַ�ǰ��
	if (pt.x + m_iOffset < 0)
		return UINT(-1);

	// ����position
	UINT uiPos = pt.x + m_iOffset;

	// �ж�uiPos�Ƿ�Խ��
	if (uiPos > UINT(iLen))
		return UINT(-1);

	return uiPos;
}

void CPositionBegin::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CPosition::Serialize(ar);
}