
// SecureSchool Unlocker 3Dlg.cpp: 구현 파일
//

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include "pch.h"
#include "framework.h"
#include "SecureSchool Unlocker 3.h"
#include "SecureSchool Unlocker 3Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <thread>
#include <time.h>
#include <strsafe.h>

#include "ChangePW.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

std::string ConvertLPCWSTRToString(LPCWSTR lpcwszStr)
{
	// Determine the length of the converted string 
	int strLength
		= WideCharToMultiByte(CP_UTF8, 0, lpcwszStr, -1,
			nullptr, 0, nullptr, nullptr);

	// Create a std::string with the determined length 
	std::string str(strLength, 0);

	// Perform the conversion from LPCWSTR to std::string 
	WideCharToMultiByte(CP_UTF8, 0, lpcwszStr, -1, &str[0],
		strLength, nullptr, nullptr);

	// Return the converted std::string 
	return str;
}

// CSecureSchoolUnlocker3Dlg 대화 상자
CSecureSchoolUnlocker3Dlg::CSecureSchoolUnlocker3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SECURESCHOOL_UNLOCKER_3_DIALOG, pParent)
	, PWInputR(_T(""))
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSecureSchoolUnlocker3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, PWInputR);
	DDV_MaxChars(pDX, PWInputR, 30);
}

BEGIN_MESSAGE_MAP(CSecureSchoolUnlocker3Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_TRAYICON_MSG, TrayIconMessage)
	ON_BN_CLICKED(IDC_BUTTON1, &CSecureSchoolUnlocker3Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CSecureSchoolUnlocker3Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSecureSchoolUnlocker3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &CSecureSchoolUnlocker3Dlg::OnBnClickedCancelButton)
END_MESSAGE_MAP()


// CSecureSchoolUnlocker3Dlg 메시지 처리기

BOOL CSecureSchoolUnlocker3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ShowWindow(SW_HIDE);

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	m_bTrayStatus = true;

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSecureSchoolUnlocker3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CSecureSchoolUnlocker3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSecureSchoolUnlocker3Dlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	LPCWSTR userWrittenPassword = PWInputR;
	UpdateData(FALSE);

	HKEY uhhhkey = NULL;

	WCHAR realPassword[512];
	DWORD dwBufferSize = sizeof(realPassword);

	LONG createStatus = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion", 0, KEY_READ, &uhhhkey);
	LONG status = RegQueryValueExW(uhhhkey, L"IntelAudioService", 0, NULL, (LPBYTE)realPassword, &dwBufferSize);

	if (ConvertLPCWSTRToString((LPCWSTR)realPassword) == ConvertLPCWSTRToString((LPCWSTR)userWrittenPassword)) {
		MessageBox(L"비밀번호 일치!\nSecureSchool이 10분 동안 해제됩니다.", L"SecureSchool");
		CSecureSchoolUnlocker3Dlg::EndDialog(NULL);
		//CDialogEx::DestroyWindow();

		time_t old_seconds = time(NULL);

		system("PowerShell -Command \"taskkill /f /im cmd.exe\"");
		system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\battery\\killLoop.bat\\\"\"");
		while (true) {
			Sleep(1000);
			time_t new_seconds = time(NULL);
			if ((new_seconds - old_seconds) >= 600) {
				break;
			}
		}
		system("PowerShell -Command \"taskkill /f /im cmd.exe\"");
		system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\IntelAudioService.exe\\\"\"");
		MessageBox(L"SecureSchool 잠금이 다시 활성화 되었습니다.", L"SecureSchool");
	}
	else {
		MessageBox(L"비밀번호 불일치.", L"SecureSchool");
	}
}

void CSecureSchoolUnlocker3Dlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	LPCWSTR userWrittenPassword = PWInputR;
	UpdateData(FALSE);

	HKEY uhhhkey = NULL;

	WCHAR realPassword[512];
	DWORD dwBufferSize = sizeof(realPassword);

	LONG createStatus = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion", 0, KEY_READ, &uhhhkey);
	LONG status = RegQueryValueExW(uhhhkey, L"IntelAudioService", 0, NULL, (LPBYTE)realPassword, &dwBufferSize);


	RegCloseKey(uhhhkey);

	if (ConvertLPCWSTRToString((LPCWSTR)realPassword) == ConvertLPCWSTRToString((LPCWSTR)userWrittenPassword)) {
		MessageBox(L"비밀번호 일치!\nSecureSchool 비밀번호 변경 작업 시작", L"SecureSchool");

		CSecureSchoolUnlocker3Dlg::EndDialog(NULL);
		ChangePW newthin;
		newthin.DoModal();
	}
	else {
		MessageBox(L"비밀번호 불일치.", L"SecureSchool");
	}
}


void CSecureSchoolUnlocker3Dlg::OnEnChangeEdit1()
{
	return;
}

void CSecureSchoolUnlocker3Dlg::OnBnClickedCancelButton() {
	//CSecureSchoolUnlocker3Dlg.DoModal();
	//CSecureSchoolUnlocker3App.DoModal();
	/*ChangePW a;
	a.DoModal();*/
	ShowWindow(SW_HIDE);
	TraySetting();
}

void CSecureSchoolUnlocker3Dlg::InitTray(void) {
}


void CSecureSchoolUnlocker3Dlg::TraySetting(void)
{
	NOTIFYICONDATA nid = {};

	nid.cbSize = sizeof(nid);
	nid.hWnd = m_hWnd;
	nid.uID = IDR_MAINFRAME; // 아이콘 리소스 ID
	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP; // 플래그 설정
	nid.uCallbackMessage = WM_TRAYICON_MSG; // 콜백메시지 설정
	nid.hIcon = AfxGetApp()->LoadIconW(IDR_MAINFRAME);
	StringCchCopy(nid.szTip, ARRAYSIZE(nid.szTip), L"SecureSchool Alpha 실행 중.\n2024-2025 개발 : tabthedev\n클릭하여 잠금해제 ");

	Shell_NotifyIcon(NIM_ADD, &nid);
	m_bTrayStatus = true;
}

LRESULT CSecureSchoolUnlocker3Dlg::TrayIconMessage(WPARAM wParam, LPARAM lParam)
{
	// 등록된 트레이 아이콘을 클릭하면 다이얼로그를 볼수있게 한다.
	if (lParam == WM_LBUTTONDBLCLK) {
		ShowWindow(SW_SHOW);

		NOTIFYICONDATA nid = {};
		nid.cbSize = sizeof(nid);
		nid.hWnd = m_hWnd; // 메인 윈도우 핸들
		nid.uID = IDR_MAINFRAME;
		Shell_NotifyIcon(NIM_DELETE, &nid);
	}

	else if (lParam == WM_RBUTTONUP) {
		CMenu menu, * pSubMenu;

		if (!menu.LoadMenu(IDD_SECURESCHOOL_UNLOCKER_3_DIALOG))
			return 0;
		if (!(pSubMenu = menu.GetSubMenu(0)))
			return 0;

		CPoint pos;
		GetCursorPos(&pos);
		SetForegroundWindow();

		// 컨텍스트 메뉴 출력
		pSubMenu->TrackPopupMenu(TPM_RIGHTALIGN, pos.x, pos.y, this);
		menu.DestroyMenu();
	}
	return 0L;
}

void CSecureSchoolUnlocker3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_CLOSE)
	{
		OnBnClickedCancelButton();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}