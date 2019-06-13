
// 个人信息管理系统View.cpp : C个人信息管理系统View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "个人信息管理系统.h"
#endif

#include "个人信息管理系统Doc.h"
#include "个人信息管理系统View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C个人信息管理系统View

IMPLEMENT_DYNCREATE(C个人信息管理系统View, CView)

BEGIN_MESSAGE_MAP(C个人信息管理系统View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C个人信息管理系统View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C个人信息管理系统View 构造/析构

C个人信息管理系统View::C个人信息管理系统View()
{
	// TODO: 在此处添加构造代码

}

C个人信息管理系统View::~C个人信息管理系统View()
{
}

BOOL C个人信息管理系统View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C个人信息管理系统View 绘制

void C个人信息管理系统View::OnDraw(CDC* /*pDC*/)
{
	C个人信息管理系统Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C个人信息管理系统View 打印


void C个人信息管理系统View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C个人信息管理系统View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C个人信息管理系统View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C个人信息管理系统View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C个人信息管理系统View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C个人信息管理系统View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C个人信息管理系统View 诊断

#ifdef _DEBUG
void C个人信息管理系统View::AssertValid() const
{
	CView::AssertValid();
}

void C个人信息管理系统View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C个人信息管理系统Doc* C个人信息管理系统View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C个人信息管理系统Doc)));
	return (C个人信息管理系统Doc*)m_pDocument;
}
#endif //_DEBUG


// C个人信息管理系统View 消息处理程序
