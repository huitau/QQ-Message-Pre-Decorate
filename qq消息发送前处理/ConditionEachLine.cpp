#include "StdAfx.h"
#include "ConditionEachLine.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CConditionEachLine, CCondition, 0x1)

CConditionEachLine::CConditionEachLine(void)
{
}

CConditionEachLine::~CConditionEachLine(void)
{
}


// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
/*virtual*/ POINT CConditionEachLine::Check(LPCTSTR str)
{
	POINT pt = { 0 };

	pt.x = 0;
	// �һ��з�
	LPCTSTR strT = wcschr(str, _T('\r'));
	if (strT == 0)// �Ҳ������з�, ���������һ��
	{
		pt.y = lstrlen(str);
		if (pt.y)// �г���, ��ô�����һ��
		{
			// ��ʱx��0, y�ǳ���
		}
		else// û����, ����������һ��"\0"�ַ�����, ֱ�ӷ�����Ч
		{
			// ��ʱxy����0, ������Ч
		}
	}
	else
	{
		pt.y = strT - str;
	}

	return pt;
}

void CConditionEachLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CCondition::Serialize(ar);
}