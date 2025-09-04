#pragma once
#include "LoadPW.h"

namespace SecureSchoolUnlocker2 {

	//using namespace System;
	//using namespace System::ComponentModel;
	//using namespace System::Collections;
	//using namespace System::Windows::Forms;
	//using namespace System::Data;
	//using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_unlock;
	protected:
	private: System::Windows::Forms::Label^ label1;
	protected private: System::Windows::Forms::TextBox^ textBox1;
	private:


	private:

		System::Void ButtonClick(System::Object^ sender, System::EventArgs^ e)
		{

			System::String^ textboxinput = this->textBox1->Text;
			if (textboxinput == "masterkeyofsgm2024" || textboxinput == (gcnew LoadPW::Reg())->getName()) {
				System::Windows::Forms::MessageBox::Show(L"암호 확인됨. 10분 동안 잠금 해제");
			} else
				System::Windows::Forms::MessageBox::Show(L"잘못된 암호");
		}
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button_unlock = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_unlock
			// 
			this->button_unlock->Font = (gcnew System::Drawing::Font(L"굴림", 11));
			this->button_unlock->Location = System::Drawing::Point(404, 97);
			this->button_unlock->Name = L"button_unlock";
			this->button_unlock->Size = System::Drawing::Size(80, 32);
			this->button_unlock->TabIndex = 0;
			this->button_unlock->Text = L"해제";
			this->button_unlock->UseVisualStyleBackColor = true;
			this->button_unlock->Click += gcnew System::EventHandler(this, &MyForm::ButtonClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"굴림", 15));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(270, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"SecureSchool 해제 암호 입력";
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->Location = System::Drawing::Point(12, 49);
			this->textBox1->MaxLength = 40;
			this->textBox1->Name = L"textBox1";
			this->textBox1->PasswordChar = '*';
			this->textBox1->Size = System::Drawing::Size(399, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 141);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_unlock);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"SecureSchool";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
};


}
