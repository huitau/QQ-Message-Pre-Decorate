#pragma once

#include "Condition.h"

namespace DecorateMessage
{

class CConditionEachLine :
	public CCondition
{
public:
	CConditionEachLine(void);
	~CConditionEachLine(void);

	// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CConditionEachLine);
};











}// namespace DecorateMessage