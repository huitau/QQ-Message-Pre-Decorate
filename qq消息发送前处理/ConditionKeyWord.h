#pragma once

#include "Condition.h"

namespace DecorateMessage
{

class CConditionKeyWord :
	public CCondition
{
public:
	CConditionKeyWord();
	CConditionKeyWord(LPCTSTR strKey);
	~CConditionKeyWord(void);

	// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CConditionKeyWord);

private:
	CString m_strKey;
};











}// namespace DecorateMessage