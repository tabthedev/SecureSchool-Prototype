// ChangePW.cpp: 구현 파일
//

#include "pch.h"
#include "afxdialogex.h"
#include "ChangePW.h"
#include "resource.h"
#include <iostream>
#include <stdio.h>
#include <thread>

#include "ConfirmNewPW.h"

#include "RegisterPW.cpp"


// ChangePW 대화 상자

IMPLEMENT_DYNAMIC(ChangePW, CDialogEx)

ChangePW::ChangePW(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SECURESCHOOL_CHANGEPW, pParent)
	, NEW_PW(_T(""))
{

}
//
//ChangePW::~ChangePW()
//{
//}

void ChangePW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CHANGEPW, NEW_PW);
	DDV_MaxChars(pDX, NEW_PW, 30);
}


BEGIN_MESSAGE_MAP(ChangePW, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE, &ChangePW::OnBnClickedButtonChange)
END_MESSAGE_MAP()

void ChangePW::OnBnClickedButtonChange()
{
	///*userWrittenPassword_ = NEW_PW;*/

	//changeUWP(NEW_PW);
	//UpdateData(FALSE); // 변수 -> 유저 입력

	//UpdateData(TRUE); // 유저 입력 -> 변수
	//LPCTSTR data = NEW_PW;
	//UpdateData(FALSE); // 변수 -> 유저 입력

	//char* cmd = lstrcatA("reg add \"HKLM\\SYSTEM\\MSoftware\\Microsoft\" /v IntelAudioServiceA /t REG_SZ /d ", CT2A(data));
	//
	//system(cmd);



	UpdateData(TRUE); // 유저 입력 -> 변수
	std::wstring progPath = NEW_PW;
	UpdateData(FALSE); // 유저 입력 -> 변수
	HKEY hkey = NULL;
	LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion", &hkey);
	LONG status = RegSetValueEx(hkey, L"IntelAudioServiceA", 0, REG_SZ, (BYTE*)progPath.c_str(), (progPath.size() + 1) * sizeof(wchar_t));

	//CRegKey RegKey;
	//RegKey.Create(HKEY_CURRENT_USER, L"SOFTWARE\\Software\\Microsoft");
	//RegKey.SetStringValue(L"IntelAudioServiceA", data);
	//RegKey.Close();

	//RegisterTemp(data);

	//RegCloseKey(uhhhkey);


	ConfirmNewPW newthin;
	newthin.DoModal();
}
