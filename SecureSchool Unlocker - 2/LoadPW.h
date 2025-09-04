#include <windows.h>
#include <iostream>
#include <stdio.h>
#pragma once

System::String^ GetReg() {
	System::String^ defaultPW = "abcd";
	System::String^ setPW_;

	HKEY uhhhkey = NULL;
	DWORD setPW = NULL;

	LONG createStatus = RegCreateKey(HKEY_LOCAL_MACHINE, L"SYSTEM\\Software\\Microsoft", &uhhhkey);
	LONG status = RegGetValueA(uhhhkey, "IntelAudioService", 0, RRF_RT_REG_SZ, &setPW, NULL, NULL);

	setPW_ = setPW.ToString();

	return setPW_;
	//return (System::String^)"abc";
}

namespace LoadPW {
	public ref class Reg {
	private:
		System::String^ value;

	public:
		Reg(/*System::String^ value*/) {
			//this->value = value;
			this->value = GetReg();
		}

		System::String^ getName() {
			return value;
		}
		void setName(System::String^ name) {
			this->value = value;
		}
	};
}