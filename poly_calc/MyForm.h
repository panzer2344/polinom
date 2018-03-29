#pragma once
#include "../Polinom/TPolinom.h"
#include "../Polinom/TPolinom.cpp"
#include <msclr\marshal_cppstd.h>
#include <string>

namespace poly_calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnPlus;
	protected:
	private: System::Windows::Forms::Button^  btnMinus;
	private: System::Windows::Forms::Button^  btnMulty;
	private: System::Windows::Forms::TextBox^  tbArg1;
	private: System::Windows::Forms::TextBox^  tbArg2;
	private: System::Windows::Forms::Label^  lblResult;
	private: System::Windows::Forms::Label^  lblEquel;
	private: System::Windows::Forms::TextBox^  tbArgLittle;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnPlus = (gcnew System::Windows::Forms::Button());
			this->btnMinus = (gcnew System::Windows::Forms::Button());
			this->btnMulty = (gcnew System::Windows::Forms::Button());
			this->tbArg1 = (gcnew System::Windows::Forms::TextBox());
			this->tbArg2 = (gcnew System::Windows::Forms::TextBox());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->lblEquel = (gcnew System::Windows::Forms::Label());
			this->tbArgLittle = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnPlus
			// 
			this->btnPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnPlus->Location = System::Drawing::Point(427, 10);
			this->btnPlus->Name = L"btnPlus";
			this->btnPlus->Size = System::Drawing::Size(75, 23);
			this->btnPlus->TabIndex = 0;
			this->btnPlus->Text = L"+";
			this->btnPlus->UseVisualStyleBackColor = true;
			this->btnPlus->Click += gcnew System::EventHandler(this, &MyForm::btnPlus_Click);
			// 
			// btnMinus
			// 
			this->btnMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnMinus->Location = System::Drawing::Point(427, 39);
			this->btnMinus->Name = L"btnMinus";
			this->btnMinus->Size = System::Drawing::Size(75, 23);
			this->btnMinus->TabIndex = 1;
			this->btnMinus->Text = L"-";
			this->btnMinus->UseVisualStyleBackColor = true;
			this->btnMinus->Click += gcnew System::EventHandler(this, &MyForm::btnMinus_Click);
			// 
			// btnMulty
			// 
			this->btnMulty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnMulty->Location = System::Drawing::Point(152, 65);
			this->btnMulty->Name = L"btnMulty";
			this->btnMulty->Size = System::Drawing::Size(75, 23);
			this->btnMulty->TabIndex = 2;
			this->btnMulty->Text = L"*";
			this->btnMulty->UseVisualStyleBackColor = true;
			this->btnMulty->Click += gcnew System::EventHandler(this, &MyForm::btnMulty_Click);
			// 
			// tbArg1
			// 
			this->tbArg1->Location = System::Drawing::Point(13, 12);
			this->tbArg1->Name = L"tbArg1";
			this->tbArg1->Size = System::Drawing::Size(408, 20);
			this->tbArg1->TabIndex = 3;
			// 
			// tbArg2
			// 
			this->tbArg2->Location = System::Drawing::Point(13, 41);
			this->tbArg2->Name = L"tbArg2";
			this->tbArg2->Size = System::Drawing::Size(408, 20);
			this->tbArg2->TabIndex = 4;
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Location = System::Drawing::Point(48, 95);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(0, 13);
			this->lblResult->TabIndex = 5;
			// 
			// lblEquel
			// 
			this->lblEquel->AutoSize = true;
			this->lblEquel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblEquel->Location = System::Drawing::Point(12, 90);
			this->lblEquel->Name = L"lblEquel";
			this->lblEquel->Size = System::Drawing::Size(19, 20);
			this->lblEquel->TabIndex = 6;
			this->lblEquel->Text = L"=";
			// 
			// tbArgLittle
			// 
			this->tbArgLittle->Location = System::Drawing::Point(13, 67);
			this->tbArgLittle->Name = L"tbArgLittle";
			this->tbArgLittle->Size = System::Drawing::Size(133, 20);
			this->tbArgLittle->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(514, 146);
			this->Controls->Add(this->tbArgLittle);
			this->Controls->Add(this->lblEquel);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->tbArg2);
			this->Controls->Add(this->tbArg1);
			this->Controls->Add(this->btnMulty);
			this->Controls->Add(this->btnMinus);
			this->Controls->Add(this->btnPlus);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnPlus_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string strArg1 = msclr::interop::marshal_as<std::string>(tbArg1->Text);
	std::string strArg2 = msclr::interop::marshal_as<std::string>(tbArg2->Text);

	if (strArg1 == "" || strArg2 == "") return;

	TPolinom P(strArg1);
	TPolinom Q(strArg2);
	TPolinom Result;

	Result = P + Q;

	std::string resultStr = Result.ToString();
	lblResult->Text = msclr::interop::marshal_as<String^>(resultStr);
}

private: System::Void btnMinus_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string strArg1 = msclr::interop::marshal_as<std::string>(tbArg1->Text);
	std::string strArg2 = msclr::interop::marshal_as<std::string>(tbArg2->Text);

	if (strArg1 == "" || strArg2 == "") return;

	TPolinom P(strArg1);
	TPolinom Q(strArg2);
	TPolinom Result;

	Result = P - Q;

	std::string resultStr = Result.ToString();
	lblResult->Text = msclr::interop::marshal_as<String^>(resultStr);
}

private: System::Void btnMulty_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string strArg1 = msclr::interop::marshal_as<std::string>(tbArg1->Text);
	std::string strArg2 = msclr::interop::marshal_as<std::string>(tbArgLittle->Text);

	if (strArg1 == "" || strArg2 == "") return;

	TPolinom P(strArg1);
	TMonom Q(strArg2);
	TPolinom Result;

	Result = P * Q;

	std::string resultStr = Result.ToString();
	lblResult->Text = msclr::interop::marshal_as<String^>(resultStr);

}

};
}
