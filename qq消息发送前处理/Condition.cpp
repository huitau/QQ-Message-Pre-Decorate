#include "StdAfx.h"
#include "Condition.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CCondition, CObject, 0x1)

CCondition::CCondition(void)
{
}

CCondition::~CCondition(void)
{
}

/*virtual*/ POINT CCondition::Check(LPCTSTR str)
{
	POINT pt = { 0, 0};
	return pt;
}

void CCondition::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CObject::Serialize(ar);
}