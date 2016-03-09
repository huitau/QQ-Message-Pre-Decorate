#include "StdAfx.h"
#include "Position.h"

using namespace DecorateMessage;

IMPLEMENT_SERIAL(CPosition, CObject, 0x1)

CPosition::CPosition()
: m_iOffset(0)
{
}

CPosition::CPosition(int iOffset)
: m_iOffset(iOffset)
{
}

CPosition::~CPosition(void)
{
}

/*virtual*/ UINT CPosition::GetPosition(LPCTSTR str, POINT &pt)
{
	return 0;
}

void CPosition::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_iOffset;
	}
	else
	{
		ar >> m_iOffset;
	}

	CObject::Serialize(ar);
}