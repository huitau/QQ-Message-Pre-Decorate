#pragma once
#include "afx.h"

namespace DecorateMessage
{

class CCondition :
	public CObject
{
public:
	CCondition(void);
	virtual ~CCondition(void);

	// ������������ʱ�ַ�����ʼ����ֹλ��, ���POINT ��xy��Ϊ0, �򲻳���
	//  ��ֹλ������ֹ�ַ����±�+1, ���λ��ָ���ַ�����һ��λ��
	virtual POINT Check(LPCTSTR str);

	void Serialize(CArchive& ar);

	DECLARE_SERIAL(CCondition);

};






}// namespace DecorateMessage