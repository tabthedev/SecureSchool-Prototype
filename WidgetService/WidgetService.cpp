#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include <thread>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <strsafe.h>

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

HWND h = GetConsoleWindow();

void SystemTray() {
	NOTIFYICONDATAW nid = {};

	nid.cbSize = sizeof(nid);
	nid.hWnd = h;
	nid.uFlags = NIF_ICON | NIF_TIP;
	nid.hIcon = (HICON)LoadImageW(NULL, s2ws("C:\\Program Files (x86)\\Common Files\\System\\image\\icon1.ico").c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_SHARED);
	StringCchCopy(nid.szTip, ARRAYSIZE(nid.szTip), L"SecureSchool Alpha 실행 중.\n2024-2025 개발 : tabthedev");

	Shell_NotifyIcon(NIM_ADD, &nid);

	int r = _getch();

	Shell_NotifyIcon(NIM_DELETE, &nid);
}



int main() {
	ShowWindow(h, SW_HIDE);

	std::thread a(SystemTray);
	a.detach();

	int i = 0;

	while (true) {
		Sleep(1000);

		time_t seconds = time(NULL);
		int seconds_int = (int)seconds + 32400;
		int secFromDay = seconds_int % 86400;
		int secFromWeek = (seconds_int + 345600) % 604800;

		(518400 >= secFromWeek && secFromWeek >= 0) ? printf("t1 ") : printf("f1 ");
		(34980 >= secFromDay && secFromDay >= 34500) ? printf("t2\n") : printf("f2\n");
		printf("%i  ..  %i\n", secFromDay, secFromWeek);

		if (
			(518400 >= secFromWeek && secFromWeek >= 0) // 월~금

			&&

			((34980 >= secFromDay && secFromDay >= 34985) || //1교시 후 5초
				(38280 >= secFromDay && secFromDay >= 38285) || //2교시 후 5초
				(41580 >= secFromDay && secFromDay >= 41585) || //3교시 후 5초
				(47280 >= secFromDay && secFromDay >= 47285) || //4교시 후 5초
				(50580 >= secFromDay && secFromDay >= 50585)) //5교시 후 5초
			)
		{
			i++;
			i % 2 == 0 ? system("taskkill /f /im chrome.exe && PowerShell -Command \"Start-Process -WindowStyle Hidden PowerShell \\\"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('프로그램이 자동 종료 되었습니다', '週中 쉬는 시간 감지됨', 'Ok','Asterisk')\\\"\"") : system("taskkill /f /im msedge.exe && PowerShell -Command \"Start-Process -WindowStyle Hidden PowerShell \\\"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('프로그램이 자동 종료 되었습니다', '週中 쉬는 시간 감지됨', 'Ok','Asterisk')\\\"\"");

		}
		else if (
			(518400 >= secFromWeek && secFromWeek >= 0) // 월~금

			&&

			((34980 >= secFromDay && secFromDay >= 34500) || //1교시~2교시 사이 8분 -> 예비종 제외
				(38280 >= secFromDay && secFromDay >= 37800) || //2~3 사이 8분 -> ''
				(41580 >= secFromDay && secFromDay >= 41100) || //3~4 사이 8분
				(50580 >= secFromDay && secFromDay >= 50100)) //5~6 사이 10분
			)
		{
			i++;
			i % 2 == 0 ? system("taskkill /f /im chrome.exe && PowerShell -Command \"Start-Process -WindowStyle Hidden PowerShell \\\"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('담임선생님의 허락 없이는 실행할 수 없습니다.', '週中 쉬는 시간 감지됨', 'Ok','Error')\\\"\"") : system("taskkill /f /im msedge.exe && PowerShell -Command \"Start-Process -WindowStyle Hidden PowerShell \\\"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('담임선생님의 허락 없이는 실행할 수 없습니다.', '週中 쉬는 시간 감지됨', 'Ok','Error')\\\"\"");

		}
	}
	return 0;
}