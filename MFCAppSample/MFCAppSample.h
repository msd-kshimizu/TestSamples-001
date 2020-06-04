
// MFCAppSample.h : MFCAppSample アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // メイン シンボル


// CMFCAppSampleApp:
// このクラスの実装については、MFCAppSample.cpp を参照してください
//

class CMFCAppSampleApp : public CWinAppEx
{
public:
	CMFCAppSampleApp() noexcept;


// オーバーライド
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 実装
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppSampleApp theApp;
