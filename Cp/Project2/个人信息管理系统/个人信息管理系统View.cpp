
// ������Ϣ����ϵͳView.cpp : C������Ϣ����ϵͳView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������Ϣ����ϵͳ.h"
#endif

#include "������Ϣ����ϵͳDoc.h"
#include "������Ϣ����ϵͳView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������Ϣ����ϵͳView

IMPLEMENT_DYNCREATE(C������Ϣ����ϵͳView, CView)

BEGIN_MESSAGE_MAP(C������Ϣ����ϵͳView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C������Ϣ����ϵͳView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C������Ϣ����ϵͳView ����/����

C������Ϣ����ϵͳView::C������Ϣ����ϵͳView()
{
	// TODO: �ڴ˴���ӹ������

}

C������Ϣ����ϵͳView::~C������Ϣ����ϵͳView()
{
}

BOOL C������Ϣ����ϵͳView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������Ϣ����ϵͳView ����

void C������Ϣ����ϵͳView::OnDraw(CDC* /*pDC*/)
{
	C������Ϣ����ϵͳDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������Ϣ����ϵͳView ��ӡ


void C������Ϣ����ϵͳView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C������Ϣ����ϵͳView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������Ϣ����ϵͳView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������Ϣ����ϵͳView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C������Ϣ����ϵͳView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C������Ϣ����ϵͳView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C������Ϣ����ϵͳView ���

#ifdef _DEBUG
void C������Ϣ����ϵͳView::AssertValid() const
{
	CView::AssertValid();
}

void C������Ϣ����ϵͳView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������Ϣ����ϵͳDoc* C������Ϣ����ϵͳView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������Ϣ����ϵͳDoc)));
	return (C������Ϣ����ϵͳDoc*)m_pDocument;
}
#endif //_DEBUG


// C������Ϣ����ϵͳView ��Ϣ�������
