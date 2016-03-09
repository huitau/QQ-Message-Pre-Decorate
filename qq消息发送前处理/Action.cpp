#include "StdAfx.h"
#include "Action.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CAction, CObject, 0x1)

CAction::CAction(void)
{
}

CAction::~CAction(void)
{
}

UINT CAction::Action(CString &str, UINT uiIndex, const POINT &pt)
{
	return 0;
}


void CAction::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CObject::Serialize(ar);
}