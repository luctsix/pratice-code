
// 个人信息管理系统View.h : C个人信息管理系统View 类的接口
//

#pragma once


class C个人信息管理系统View : public CView
{
protected: // 仅从序列化创建
	C个人信息管理系统View();
	DECLARE_DYNCREATE(C个人信息管理系统View)

// 特性
public:
	C个人信息管理系统Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C个人信息管理系统View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 个人信息管理系统View.cpp 中的调试版本
inline C个人信息管理系统Doc* C个人信息管理系统View::GetDocument() const
   { return reinterpret_cast<C个人信息管理系统Doc*>(m_pDocument); }
#endif

