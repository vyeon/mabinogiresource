
// LeftView.cpp : CLeftView ���ʵ��
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


// CLeftView ����/����

CLeftView::CLeftView()
{
	// TODO: �ڴ˴����ӹ������
	m_nFolderCloseIcon = 0;
	m_nFolderOpenIcon = 0;
}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CTreeView::PreCreateWindow(cs);
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: ���� GetTreeCtrl() ֱ�ӷ��� TreeView �����ؼ���
	//  �Ӷ������������ TreeView��
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


// CLeftView ���

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CMabinogiPackageToolDoc* CLeftView::GetDocument() // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMabinogiPackageToolDoc)));
	return (CMabinogiPackageToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CLeftView ��Ϣ��������


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