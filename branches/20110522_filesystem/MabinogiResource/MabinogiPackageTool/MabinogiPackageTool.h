
// MabinogiPackageTool.h : MabinogiPackageTool Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMabinogiPackageToolApp:
// �йش����ʵ�֣������ MabinogiPackageTool.cpp
//

class CMabinogiPackageToolApp : public CWinAppEx
{
public:
	CMabinogiPackageToolApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMabinogiPackageToolApp theApp;