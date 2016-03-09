#pragma once
#include "afx.h"

#include "Condition.h"
#include "ConditionWholeMessage.h"
#include "ConditionEachLine.h"
#include "ConditionKeyWord.h"

#include "Position.h"
#include "PositionBegin.h"
#include "PositionEnd.h"
#include "PositionMiddle.h"
#include "PositionLineBegin.h"
#include "PositionLineEnd.h"
#include "PositionLineMiddle.h"

#include "Action.h"
#include "ActionAdd.h"
#include "ActionDelete.h"
#include "ActionReplace.h"


namespace DecorateMessage
{




class CDecorateContent
{
public:
	CDecorateContent();

	// ����
	enum
	{
		CONDITION_WHOLEMESSAGE = 0,
		CONDITION_EACHLINE = 1,
		CONDITION_KEYWORD = 2
	};
	int iConditionType;
	CString strKeyword;

	// λ��
	enum
	{
		POSITION_BEGIN = 0,
		POSITION_MIDDLE = 1,
		POSITION_END = 2,
		POSITION_LINE_BEGIN = 3,
		POSITION_LINE_MIDDLE = 4,
		POSITION_LINE_END = 5
	};
	int iPositionType;
	int iPositionOffset;

	// ����
	enum
	{
		ACTION_ADD = 0,
		ACTION_DELETE = 1,
		ACTION_REPLACE = 2
	};
	int iActionType;
	CString strAdd;
	CString strReplace;
	int iDeleteRange;
	int iReplaceRange;

	void Serialize(CArchive& ar);

};

CArchive &operator << (CArchive &ar, CDecorateContent &de);
CArchive &operator >> (CArchive &ar, CDecorateContent &de);




class CDecorate
{
public:
	CDecorate();
	CDecorate(const CDecorateContent &DecorateContent);
	~CDecorate(void);

	void Serialize(CArchive& ar);


private:
	// Ϊָ�븳ֵ
	void Construct(const CDecorateContent &DecorateContent);
public:
	// �����б������ݿ��ܱ��޸�, ��˼�һ�����¹���ĺ���
	void ReConstruct(const CDecorateContent &DecorateContent);

	// ���ش����˶��ٸ��ַ�
	UINT Decorate(CString &str);

	CDecorateContent m_DecorateContent;
private:
	CCondition *m_pCondition;
	CPosition *m_pPosition;
	CAction *m_pAction;
	CDecorate &operator = (const CDecorate &);
};



CArchive &operator << (CArchive &ar, CDecorate &de);
CArchive &operator >> (CArchive &ar, CDecorate &de);





}// namespace DecorateMessage