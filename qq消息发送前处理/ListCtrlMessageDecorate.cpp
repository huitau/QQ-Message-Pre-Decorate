// ListCtrlMessageDecorate.cpp : 实现文件
//

#include "stdafx.h"
#include "qq消息发送前处理.h"
#include "ListCtrlMessageDecorate.h"
#include "Decorate.h"
#include "MyDlg.h"

using namespace DecorateMessage;

// CListCtrlMessageDecorate

IMPLEMENT_DYNAMIC(CListCtrlMessageDecorate, CListCtrl)

CListCtrlMessageDecorate::CListCtrlMessageDecorate()
{

}

CListCtrlMessageDecorate::~CListCtrlMessageDecorate()
{
}


BEGIN_MESSAGE_MAP(CListCtrlMessageDecorate, CListCtrl)
	ON_WM_CLOSE()
END_MESSAGE_MAP()



// CListCtrlMessageDecorate 消息处理程序


void CListCtrlMessageDecorate::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类

	SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CRect rt;
	GetClientRect(&rt);

	int iWidth = rt.Width() - 20;

	InsertColumn(0, _T("条件:"));
	InsertColumn(1, _T("动作:"));

	SetColumnWidth(0, iWidth / 2);
	SetColumnWidth(1, iWidth / 2);





	try
	{
		// 加载保存的decorate内容
		CFile file(_T("DecorateSetting"), CFile::modeRead | CFile::shareDenyWrite);
		CArchive ar(&file, CArchive::load);

		gTrace(_T("加载上次修饰方案.\r\n"));

		int iCount;

		ar >> iCount;

		for (int i = 0; i < iCount; ++i)
		{
			CDecorate *p = new CDecorate;
			ar >> *p;
			Add(p);
		}


	}
	catch (CFileException *pException)
	{
		pException->m_cause;
		pException->Delete();


		// 出错 加载初始的decorate数据
		gTrace(_T("加载预置修饰方案.\r\n"));

		CDecorateContent dc;

		// 每行 空4个空格
		dc.iConditionType = CDecorateContent::CONDITION_EACHLINE;
		dc.iPositionType = CDecorateContent::POSITION_BEGIN;
		dc.iActionType = CDecorateContent::ACTION_ADD;
		dc.strAdd = _T("    ");
		Add(new CDecorate(dc));

		dc.iConditionType = CDecorateContent::CONDITION_KEYWORD;
		dc.strKeyword = _T("");
		//POSITION_END = 2,
		//POSITION_LINE_END = 5
		dc.iPositionType = CDecorateContent::POSITION_END;
		dc.iActionType = CDecorateContent::ACTION_ADD;
		dc.strAdd = _T("");





		// 跟在句后
#define D(keyword, add) \
dc.strKeyword = keyword;\
dc.iPositionType = CDecorateContent::POSITION_LINE_END;\
dc.strAdd = add;\
Add(new CDecorate(dc));

		//晚 /月亮
		D(_T("晚"), _T("/月亮"));
		//算了  后 /微笑
		D(_T("算了"), _T("/微笑"));
		//怎么办 /大哭
		D(_T("怎么办"), _T("/大哭"));
		//过来 /勾引
		D(_T("过来"), _T("/勾引"));


		// 跟在词后
#undef D
#define D(keyword, add) \
dc.strKeyword = keyword;\
dc.iPositionType = CDecorateContent::POSITION_END;\
dc.strAdd = add;\
Add(new CDecorate(dc));


		//嘿嘿 后 /可爱
		D(_T("嘿嘿"), _T("/可爱"));

		//呵呵 后 /憨笑
		D(_T("呵呵"), _T("/憨笑"));

		//哈哈 后 /偷笑
		D(_T("哈哈"), _T("/偷笑"));

		//嗯  后 /微笑
		D(_T("嗯"), _T("/微笑"));

		

		//吗 后 /疑问
		D(_T("吗"), _T("/疑问"));

		//么 后 /疑问
		D(_T("么"), _T("/疑问"));

		//…… 后 /白眼
		D(_T("……"), _T("/白眼"));

		//... 后 /白眼
		D(_T("..."), _T("/白眼"));

		// 对不起 后 /大哭
		D(_T("对不起"), _T("/大哭"));

		//抱歉 /难过
		D(_T("抱歉"), _T("/难过"));

		//sorry /难过
		D(_T("sorry"), _T("/难过"));

		//惨了 /流泪
		D(_T("惨了"), _T("/流泪"));

		

		//不会吧 /委屈
		D(_T("不会吧"), _T("/委屈"));

		//啊! /吓
		D(_T("啊!"), _T("/吓"));

		//不错 /强
		D(_T("不错"), _T("/强"));

		//太棒了 /强
		D(_T("太棒了"), _T("/强"));

		//厉害 /强
		D(_T("厉害"), _T("/强"));

		//加油 /奋斗
		D(_T("加油"), _T("/奋斗"));

		//低调 /大兵
		D(_T("低调"), _T("/大兵"));

		//饭 /饭
		D(_T("饭"), _T("/饭"));

		//热 /太阳
		D(_T("热"), _T("/太阳"));

		

		//睡 /月亮
		D(_T("睡"), _T("/月亮"));

		//吼吼 /胜利
		D(_T("吼吼"), _T("/胜利"));

		//哼哼 /胜利
		D(_T("哼哼"), _T("/鼓掌"));

		//佩服 /抱拳
		D(_T("佩服"), _T("/抱拳"));

		

		//困死了 /熬夜
		D(_T("困死了"), _T("/熬夜"));

		//困了 /熬夜
		D(_T("困了"), _T("/熬夜"));

		//困级了 /熬夜
		D(_T("困级了"), _T("/熬夜"));

		//雷 /闪电
		D(_T("雷"), _T("/闪电"));

		//生日 /蛋糕
		D(_T("生日"), _T("/蛋糕"));

		//茶 /咖啡
		D(_T("茶"), _T("/咖啡"));

		//你好 /微笑
		D(_T("你好"), _T("/微笑"));

		//早上好 /调皮
		D(_T("早上好"), _T("/调皮"));

		//上午好 /调皮
		D(_T("上午好"), _T("/调皮"));

		//好啊 /调皮
		D(_T("好啊"), _T("/调皮"));

		//中午好 /太阳
		D(_T("中午好"), _T("/太阳"));

		//下午好 /调皮
		D(_T("下午好"), _T("/调皮"));

		//晚上好 /月亮
		D(_T("晚上好"), _T("/月亮"));

		//深夜 /月亮
		D(_T("深夜"), _T("/月亮"));

		//额 /尴尬
		D(_T("额"), _T("/尴尬"));


#undef D
	}















	CListCtrl::PreSubclassWindow();
}



// 返回index
int CListCtrlMessageDecorate::Add(const CDecorate *p)
{
	CString strCondition, strAction;
	TransToString(*p, strCondition, strAction);

	int i = GetItemCount();
	InsertItem(i, strCondition.GetString());
	SetItemData(i, (DWORD_PTR)p);
	SetItemText(i, 1, strAction.GetString());

	return i;
}

CDecorate *CListCtrlMessageDecorate::Delete(int iIndex)
{
	CDecorate *p = (CDecorate *)GetItemData(iIndex);
	DeleteItem(iIndex);
	return p;
}

CDecorate *CListCtrlMessageDecorate::Get(int iIndex)
{
	return (CDecorate *)GetItemData(iIndex);
}

CDecorate *CListCtrlMessageDecorate::Set(int iIndex, CDecorate *pNew)
{
	CDecorate *p = (CDecorate *)GetItemData(iIndex);

	SetItemData(iIndex, (DWORD_PTR)pNew);

	CString strCondition, strAction;
	TransToString(*pNew, strCondition, strAction);
	SetItemText(iIndex, 0, strCondition.GetString());
	SetItemText(iIndex, 1, strAction.GetString());

	return p;
}

void CListCtrlMessageDecorate::Exchange(int iIndex1, int iIndex2)
{
	// 临时变量
	DWORD_PTR dp;
	CString strCondition, strAction;

	// 保存
	strCondition = GetItemText(iIndex1, 0);
	strAction = GetItemText(iIndex1, 1);
	dp = GetItemData(iIndex1);

	// 置换第一步
	SetItemText(iIndex1, 0,
		GetItemText(iIndex2, 0));
	SetItemText(iIndex1, 1,
		GetItemText(iIndex2, 1));
	SetItemData(iIndex1,
		GetItemData(iIndex2));

	// 置换第二步
	SetItemText(iIndex2, 0, strCondition);
	SetItemText(iIndex2, 1, strAction);
	SetItemData(iIndex2, dp);
}


// 把DecorateContent转换成字符串
void CListCtrlMessageDecorate::TransToString(const DecorateMessage::CDecorate &decorate,
	CString &strCondition, CString &strAction)
{
	CString strT;
	strCondition.Empty();

	switch (decorate.m_DecorateContent.iConditionType)
	{
	case CDecorateContent::CONDITION_WHOLEMESSAGE:
		strCondition += _T("在全部消息");
		break;
	case CDecorateContent::CONDITION_EACHLINE:
		strCondition += _T("在每行消息");
		break;
	case CDecorateContent::CONDITION_KEYWORD:
		strCondition += _T("在关键词");
		strCondition += decorate.m_DecorateContent.strKeyword;
		break;
	}

	switch (decorate.m_DecorateContent.iPositionType)
	{
	case CDecorateContent::POSITION_BEGIN:
		strCondition += _T("的开始位置");
		break;
	case CDecorateContent::POSITION_END:
		strCondition += _T("的终止位置");
		break;
	case CDecorateContent::POSITION_MIDDLE:
		strCondition += _T("的中间位置");
		break;
	case CDecorateContent::POSITION_LINE_BEGIN:
		strCondition += _T("的行开始位置");
		break;
	case CDecorateContent::POSITION_LINE_END:
		strCondition += _T("的行终止位置");
		break;
	case CDecorateContent::POSITION_LINE_MIDDLE:
		strCondition += _T("的行中间位置");
		break;
	}

	// 判断是否需要加上偏移
	if (decorate.m_DecorateContent.iPositionOffset < 0)
	{
		strCondition += _T("向左偏移");
		strT.Format(_T("%d"), -decorate.m_DecorateContent.iPositionOffset);
		strCondition += strT;
		strCondition += _T("个字符");
	}
	else if (decorate.m_DecorateContent.iPositionOffset > 0)
	{
		strCondition += _T("向右偏移");
		strT.Format(_T("%d"), decorate.m_DecorateContent.iPositionOffset);
		strCondition += strT;
		strCondition += _T("个字符");
	}



	strAction.Empty();

	switch (decorate.m_DecorateContent.iActionType)
	{
	case CDecorateContent::ACTION_ADD:
		strAction += _T("加上");
		strAction += decorate.m_DecorateContent.strAdd;
		break;
	case CDecorateContent::ACTION_DELETE:
		strAction += _T("删掉");
		if (decorate.m_DecorateContent.iDeleteRange < 0)
		{
			strAction += _T("左边");
			strT.Format(_T("%d"), -decorate.m_DecorateContent.iDeleteRange);
			strAction += strT;
			strAction += _T("个字符");
		}
		else
		{
			strAction += _T("右边");
			strT.Format(_T("%d"), decorate.m_DecorateContent.iDeleteRange);
			strAction += strT;
			strAction += _T("个字符");
		}
		break;
	case CDecorateContent::ACTION_REPLACE:
		strAction += _T("替换");
		if (decorate.m_DecorateContent.iReplaceRange < 0)
		{
			strAction += _T("左边");
			strT.Format(_T("%d"), -decorate.m_DecorateContent.iReplaceRange);
			strAction += strT;
			strAction += _T("个字符成");
			strAction += decorate.m_DecorateContent.strReplace;
		}
		else
		{
			strAction += _T("右边");
			strT.Format(_T("%d"), decorate.m_DecorateContent.iReplaceRange);
			strAction += strT;
			strAction += _T("个字符成");
			strAction += decorate.m_DecorateContent.strReplace;
		}
		break;
	}

}

void CListCtrlMessageDecorate::OnClose()
{
	CFile file(_T("DecorateSetting"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);


	int iCount = GetItemCount();

	ar << iCount;

	for (int i = 0; i < iCount; ++i)
	{
		CDecorate *p = Get(i);
		ar << *p;
	}
}