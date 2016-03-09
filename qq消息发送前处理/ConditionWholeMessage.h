#pragma once

#include "Condition.h"

namespace DecorateMessage
{

class CConditionWholeMessage :
	public CCondition
{
public:
	CConditionWholeMessage(void);
	~CConditionWholeMessage(void);

	// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CConditionWholeMessage);
};








}// namespace DecorateMessage