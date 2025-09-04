#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>

static void RegisterMain(std::wstring data) {
	HKEY hkeydesu = NULL;

	LONG createStatus = RegCreateKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\Software\\Microsoft", &hkeydesu);
	LONG status = RegSetValueEx(hkeydesu, L"IntelAudioService", 0, REG_SZ, (BYTE*)data.c_str(), (data.size() + 1) * sizeof(wchar_t));
}

static void RegisterTemp(LPCTSTR data) {

	//HKEY hkeydesu = NULL;

	//LONG createStatus = RegCreateKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\Software\\Microsoft", &hkeydesu);
	//LONG status = RegSetValueEx(hkeydesu, L"IntelAudioServiceA", 0, REG_SZ, (BYTE*)data.c_str(), (data.size() + 1) * sizeof(wchar_t));
}