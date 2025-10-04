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



int main() {
	ShowWindow(h, SW_HIDE);

	int i = 0;

	while (true) {
		Sleep(100);

		time_t seconds = time(NULL);
		int seconds_int = (int)seconds + 32400;
		int secFromDay = seconds_int % 86400;
		float minFromDay = secFromDay / 60;
		int secFromWeek = (seconds_int + 345600) % 604800;

		(518400 >= secFromWeek && secFromWeek >= 0) ? printf("t1 ") : printf("f1 ");
		(34980 >= secFromDay && secFromDay >= 34500) ? printf("t2\n") : printf("f2\n");
		std::cout << secFromDay << ", " << int(minFromDay * 100) << " .. " << seconds_int << std::endl;

		if (
			(518400 >= secFromWeek && secFromWeek >= 0) // 월~금
			)
		{
			i++;
			if (
				(578 >= minFromDay && minFromDay >= 570) ||
				(578 + 45 * 1 >= minFromDay && minFromDay >= 570 + 45 * 1) ||
				(578 + 45 * 2 >= minFromDay && minFromDay >= 570 + 45 * 2) ||
				(838 >= minFromDay && minFromDay >= 570 + 45 * 3) ||
				(850 + 45 * 1 >= minFromDay && minFromDay >= 840 + 45 * 1)
				) {
				system(i % 2 == 0 ? "taskkill /f /im chrome.exe && PowerShell -Command \"Start-Process -WindowStyle Hidden PowerShell \\\"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('프로그램이 자동 종료 되었습니다', '주중 쉬는 시간 감지됨', 'Ok','Asterisk')\\\"\"" : "taskkill /f /im msedge.exe && PowerShell -Command \"Start-Process -WindowStyle Hidden PowerShell \\\"Add-Type -AssemblyName PresentationFramework;[System.Windows.MessageBox]::Show('프로그램이 자동 종료 되었습니다', '주중 쉬는 시간 감지됨', 'Ok','Asterisk')\\\"\"");
			}

		}
	}
	return 0;
}
