/*
Stepvoice Recorder
Copyright (C) 2004-2016 Andrey Firsov
*/

#include "stdafx.h"
#include "MySheet.h"
#include "FileUtils.h"
#include <htmlhelp.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CMySheet, CPropertySheet)

/////////////////////////////////////////////////////////////////////////////

CMySheet::CMySheet()
	:CPropertySheet(GetWindowTitle(), AfxGetApp()->GetMainWnd(),
		RegistryConfig::GetOption(_T("General\\DialogIndex"), 0))
{
	this->m_psh.dwFlags |= PSH_NOAPPLYNOW;

	AddPage(&m_pc);
	AddPage(&m_pr);
	AddPage(&m_pa);	
	AddPage(&m_pv);
}
//---------------------------------------------------------------------------

CString CMySheet::GetWindowTitle()
{
	return _T("Options");
}
//---------------------------------------------------------------------------

BOOL CMySheet::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		RegistryConfig::SetOption(_T("General\\DialogIndex"), GetActiveIndex());

	if (LOWORD(wParam == IDHELP))
	{
		using namespace FileUtils;
		CString helpFile = CombinePath(GetProgramFolder(), _T("svrec.chm::/how_to_use/preferences.html"));
		::HtmlHelp(::GetDesktopWindow(), helpFile, HH_DISPLAY_TOPIC, NULL);
	}

	return CPropertySheet::OnCommand(wParam, lParam);
}
//---------------------------------------------------------------------------
