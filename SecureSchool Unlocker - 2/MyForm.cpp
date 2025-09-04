#include "MyForm.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//[STAThreadAttribute]


void main(/*array<System::String^>^ argv*/) {
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::EnableVisualStyles();
	SecureSchoolUnlocker2::MyForm form;
	System::Windows::Forms::Application::Run(% form);
}