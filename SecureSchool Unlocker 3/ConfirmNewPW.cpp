// ConfirmNewPW.cpp: 구현 파일
//

#include "pch.h"
#include "afxdialogex.h"
#include "ConfirmNewPW.h"
#include "resource.h"
#include <iostream>

#include "ChangePW.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

// ConfirmNewPW 대화 상자

IMPLEMENT_DYNAMIC(ConfirmNewPW, CDialogEx)

ConfirmNewPW::ConfirmNewPW(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SECURESCHOOL_CONFIRMPW, pParent)
	, m_static_newpw_fc(_T(""))
{
	HKEY uhhhkey = NULL;

	WCHAR realPassword[512];
	DWORD dwBufferSize = sizeof(realPassword);

	LONG createStatus = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &uhhhkey);
	LONG status = RegQueryValueExW(uhhhkey, L"IntelAudioServiceA", 0, NULL, (LPBYTE)realPassword, &dwBufferSize);

	RegCloseKey(uhhhkey);


	/*HKEY uhhhkeye = NULL;

	WCHAR realPassworde[512];
	DWORD dwBufferSizee = sizeof(realPassworde);

	LONG createStatuse = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\Software\\Microsoft", 0, KEY_READ, &uhhhkeye);
	LONG statuse = RegQueryValueExW(uhhhkeye, L"IntelAudioService", 0, NULL, (LPBYTE)realPassworde, &dwBufferSizee);

	RegCloseKey(uhhhkeye);

	MessageBox(realPassworde);*/

	m_static_newpw_fc = wcscat(realPassword, (L"으로 확정하시겠습니까?\n잘못 입력 할 시 복구 불가에 어려움이 생길수 있습니다."));

	//CWnd* label = GetDlgItem(IDC_STATIC_FINAL);
	//label->SetWindowText(wcscat(realPassword, (L"으로 확정하시겠습니까?\n잘못 입력 할 시 복구 불가에 어려움이 생길수 있습니다.")));
}



ConfirmNewPW::~ConfirmNewPW()
{
}

void ConfirmNewPW::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECKER_NEWPW, EnterNewPasswordHereDeveloper);
	DDX_Control(pDX, IDC_STATIC_FINAL, static_newpw_FinalCheck);
	DDX_Text(pDX, IDC_STATIC_FINAL, m_static_newpw_fc);
}


BEGIN_MESSAGE_MAP(ConfirmNewPW, CDialogEx)
	//ON_EN_CHANGE(IDC_EDIT1, &ConfirmNewPW::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_CONFIRM_NEWPW, &ConfirmNewPW::OnBnClickedConfirmNewpw)
	//ON_EN_CHANGE(IDC_CHECKER_NEWPW, &ConfirmNewPW::OnEnChangeCheckerNewpw)
	ON_STN_CLICKED(IDC_STATIC_FINAL, &ConfirmNewPW::OnStnClickedStaticFinal)
END_MESSAGE_MAP()


void ConfirmNewPW::OnBnClickedConfirmNewpw()
{
	HKEY uhhhkey = NULL;

	WCHAR realPassword[512];
	DWORD dwBufferSize = sizeof(realPassword);

	LONG createStatus = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", 0, KEY_READ, &uhhhkey);
	LONG status = RegQueryValueExW(uhhhkey, L"IntelAudioServiceA", 0, NULL, (LPBYTE)realPassword, &dwBufferSize);

	RegCloseKey(uhhhkey);



	std::wstring progPath = realPassword;
	HKEY hkey = NULL;
	LONG createStatuse = RegCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall", &hkey);
	LONG statuse = RegSetValueEx(hkey, L"IntelAudioService", 0, REG_SZ, (BYTE*)progPath.c_str(), (progPath.size() + 1) * sizeof(wchar_t));
	//UpdateData(TRUE); // 유저 입력 -> 변수
	//CString userWrittenPassword = ChangePW::NEW_PW;
	////static_newpw_FinalCheck = userWrittenPassword;

	//UpdateData(FALSE); // 변수 -> 유저 입력

	MessageBox(L"비밀번호가 변경되었습니다", L"비밀번호 변경");


	system("taskkill /f /im \"SecureSchool Unlocker.exe\"");
	//CDialog::DestroyWindow();
	//ChangePW::DestroyWindow();
}


void ConfirmNewPW::OnEnChangeCheckerNewpw()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void ConfirmNewPW::OnStnClickedStaticFinal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
