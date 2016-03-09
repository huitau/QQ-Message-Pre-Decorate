#include "StdAfx.h"
#include "ConditionWholeMessage.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CConditionWholeMessage, CCondition, 0x1)

CConditionWholeMessage::CConditionWholeMessage(void)
{
}

CConditionWholeMessage::~CConditionWholeMessage(void)
{
}


// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
/*virtual*/ POINT CConditionWholeMessage::Check(LPCTSTR str)
{
	// ������ȫ����, ��ô��ѡ��ȫ�����־ͺ���
	POINT pt = { 0 };
	pt.x = 0;
	pt.y = lstrlen(str);
	return pt;
}

void CConditionWholeMessage::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CCondition::Serialize(ar);
}