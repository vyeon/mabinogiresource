
// LeftView.cpp : CLeftView 类的实现
//

#include "stdafx.h"
#include "MabinogiPackageTool.h"

#include "MabinogiPackageToolDoc.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
END_MESSAGE_MAP()


// CLeftView 构造/析构

CLeftView::CLeftView()
{
	// TODO: 在此处添加构造代码
	m_nFolderCloseIcon = 0;
	m_nFolderOpenIcon = 0;
}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式

	return CTreeView::PreCreateWindow(cs);
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 调用 GetTreeCtrl() 直接访问 TreeView 的树控件，
	//  从而可以用项填充 TreeView。
	GetTreeCtrl().LockWindowUpdate();
	for (size_t i = 0;i < GetDocument()->m_pResourceSet->GetResourceCount();i++)
	{
		IResource * pResource = GetDocument()->m_pResourceSet->GetResource(i);
		GetTreeCtrl().InsertItem(pResource->GetName());

		pResource->Release();
		pResource = NULL;
	}

	GetTreeCtrl().UnlockWindowUpdate();
	
}


// CLeftView 诊断

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CMabinogiPackageToolDoc* CLeftView::GetDocument() // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMabinogiPackageToolDoc)));
	return (CMabinogiPackageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CLeftView 消息处理程序


HTREEITEM CLeftView::CreateTreeNode(HTREEITEM root, CString path)
{
	HTREEITEM result = root;
	static const LPCTSTR token = TEXT("\\/");
	int curPos = 0;
	CString splite = path.Tokenize(token, curPos);
	while (!splite.IsEmpty())
	{
		HTREEITEM finded = m_treeNodeMap[splite];

	}
}


void CLeftView::FillData(void)
{
}
