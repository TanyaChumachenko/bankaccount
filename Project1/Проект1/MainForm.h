#pragma once
#include<vcclr.h>
#include <Windows.h>
#include "Account.h"
#include "DefaultAccount.h"
#include "SocialAccount.h"
#include "VipAccount.h"
#include "Exception.h"
#include <fstream>
int i = -1; // для запам'ятовування обраного рахунку
CAccount *pointers[3];
CAccount *destination = nullptr;
namespace Проект1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			pointers[0] = new CDefaultAccount;
			pointers[1] = new CSocialAccount;
			pointers[2] = new CVipAccount;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
				for (int j = 0; j < 3; j++)
				{
					delete pointers[j];
				}

			}
		}
	private: System::Windows::Forms::RadioButton^  RadioButtonDefault;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  ButtonPrintStory;

	private: System::Windows::Forms::Button^  ButtonTransaction;

	private: System::Windows::Forms::Button^  ButtonPayUtilities;

	private: System::Windows::Forms::Button^  ButtonInputMoney;

	private: System::Windows::Forms::Button^  ButtonMoneyOutput;
	private: System::Windows::Forms::TextBox^  EditBalance;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  RadioButtonVip;
	private: System::Windows::Forms::RadioButton^  RadioButtonSocial;
	private: System::Windows::Forms::Button^  ButtonConfirmUtilities;

	private: System::Windows::Forms::TextBox^  EditStory;
	private: System::Windows::Forms::TextBox^  EditPayUtilities;
	private: System::Windows::Forms::TextBox^  EditTransaction;
	private: System::Windows::Forms::Button^  ButtonConfirmTransaction;




	private: System::Windows::Forms::TextBox^  EditMoneyOutput;
	private: System::Windows::Forms::Button^  ButtonConfirmMoneyOutput;
	private: System::Windows::Forms::Button^  ButtonConfirmInputMoney;





	private: System::Windows::Forms::TextBox^  EditMoneyInput;

	private: System::Windows::Forms::GroupBox^  Blok2;
	private: System::Windows::Forms::GroupBox^  PanelTransaction;

	private: System::Windows::Forms::GroupBox^  PanelPayUtilities;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RadioButton^  RadioButtonVipDest;
	private: System::Windows::Forms::RadioButton^  RadioButtonSocialDest;
	private: System::Windows::Forms::RadioButton^  RadioButtonDefaultDest;
	private: System::Windows::Forms::GroupBox^  PanelMoneyOutput;
	private: System::Windows::Forms::GroupBox^  PanelMoneyInput;
	private: System::Windows::Forms::Button^  ButtonCancel;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::TextBox^  PIP;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->RadioButtonDefault = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->PIP = (gcnew System::Windows::Forms::TextBox());
			this->ButtonPrintStory = (gcnew System::Windows::Forms::Button());
			this->ButtonTransaction = (gcnew System::Windows::Forms::Button());
			this->ButtonPayUtilities = (gcnew System::Windows::Forms::Button());
			this->ButtonInputMoney = (gcnew System::Windows::Forms::Button());
			this->ButtonMoneyOutput = (gcnew System::Windows::Forms::Button());
			this->EditBalance = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->RadioButtonVip = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonSocial = (gcnew System::Windows::Forms::RadioButton());
			this->ButtonConfirmUtilities = (gcnew System::Windows::Forms::Button());
			this->EditStory = (gcnew System::Windows::Forms::TextBox());
			this->EditPayUtilities = (gcnew System::Windows::Forms::TextBox());
			this->EditTransaction = (gcnew System::Windows::Forms::TextBox());
			this->ButtonConfirmTransaction = (gcnew System::Windows::Forms::Button());
			this->EditMoneyOutput = (gcnew System::Windows::Forms::TextBox());
			this->ButtonConfirmMoneyOutput = (gcnew System::Windows::Forms::Button());
			this->ButtonConfirmInputMoney = (gcnew System::Windows::Forms::Button());
			this->EditMoneyInput = (gcnew System::Windows::Forms::TextBox());
			this->Blok2 = (gcnew System::Windows::Forms::GroupBox());
			this->ButtonCancel = (gcnew System::Windows::Forms::Button());
			this->PanelTransaction = (gcnew System::Windows::Forms::GroupBox());
			this->RadioButtonVipDest = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RadioButtonSocialDest = (gcnew System::Windows::Forms::RadioButton());
			this->RadioButtonDefaultDest = (gcnew System::Windows::Forms::RadioButton());
			this->PanelPayUtilities = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->PanelMoneyOutput = (gcnew System::Windows::Forms::GroupBox());
			this->PanelMoneyInput = (gcnew System::Windows::Forms::GroupBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->Blok2->SuspendLayout();
			this->PanelTransaction->SuspendLayout();
			this->PanelPayUtilities->SuspendLayout();
			this->PanelMoneyOutput->SuspendLayout();
			this->PanelMoneyInput->SuspendLayout();
			this->SuspendLayout();
			// 
			// RadioButtonDefault
			// 
			this->RadioButtonDefault->AutoSize = true;
			this->RadioButtonDefault->Location = System::Drawing::Point(17, 23);
			this->RadioButtonDefault->Name = L"RadioButtonDefault";
			this->RadioButtonDefault->Size = System::Drawing::Size(75, 17);
			this->RadioButtonDefault->TabIndex = 0;
			this->RadioButtonDefault->TabStop = true;
			this->RadioButtonDefault->Text = L"Базовий";
			this->RadioButtonDefault->UseVisualStyleBackColor = true;
			this->RadioButtonDefault->Click += gcnew System::EventHandler(this, &MainForm::RadioButtonDefault_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->PIP);
			this->groupBox1->Controls->Add(this->ButtonPrintStory);
			this->groupBox1->Controls->Add(this->ButtonTransaction);
			this->groupBox1->Controls->Add(this->ButtonPayUtilities);
			this->groupBox1->Controls->Add(this->ButtonInputMoney);
			this->groupBox1->Controls->Add(this->ButtonMoneyOutput);
			this->groupBox1->Controls->Add(this->EditBalance);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->RadioButtonVip);
			this->groupBox1->Controls->Add(this->RadioButtonSocial);
			this->groupBox1->Controls->Add(this->RadioButtonDefault);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(14, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(326, 182);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Оберіть рахунок";
			// 
			// PIP
			// 
			this->PIP->Location = System::Drawing::Point(123, 11);
			this->PIP->Name = L"PIP";
			this->PIP->Size = System::Drawing::Size(197, 20);
			this->PIP->TabIndex = 10;
			// 
			// ButtonPrintStory
			// 
			this->ButtonPrintStory->Location = System::Drawing::Point(133, 128);
			this->ButtonPrintStory->Name = L"ButtonPrintStory";
			this->ButtonPrintStory->Size = System::Drawing::Size(171, 35);
			this->ButtonPrintStory->TabIndex = 9;
			this->ButtonPrintStory->Text = L"Друк історії транакцій";
			this->ButtonPrintStory->UseVisualStyleBackColor = true;
			this->ButtonPrintStory->Click += gcnew System::EventHandler(this, &MainForm::ButtonPrintStory_Click);
			// 
			// ButtonTransaction
			// 
			this->ButtonTransaction->Location = System::Drawing::Point(221, 87);
			this->ButtonTransaction->Name = L"ButtonTransaction";
			this->ButtonTransaction->Size = System::Drawing::Size(94, 35);
			this->ButtonTransaction->TabIndex = 8;
			this->ButtonTransaction->Text = L"Переказ на карту";
			this->ButtonTransaction->UseVisualStyleBackColor = true;
			this->ButtonTransaction->Click += gcnew System::EventHandler(this, &MainForm::ButtonTransaction_Click);
			// 
			// ButtonPayUtilities
			// 
			this->ButtonPayUtilities->Location = System::Drawing::Point(123, 87);
			this->ButtonPayUtilities->Name = L"ButtonPayUtilities";
			this->ButtonPayUtilities->Size = System::Drawing::Size(95, 35);
			this->ButtonPayUtilities->TabIndex = 7;
			this->ButtonPayUtilities->Text = L"Оплата комунальних";
			this->ButtonPayUtilities->UseVisualStyleBackColor = true;
			this->ButtonPayUtilities->Click += gcnew System::EventHandler(this, &MainForm::ButtonPayUtilities_Click);
			// 
			// ButtonInputMoney
			// 
			this->ButtonInputMoney->Location = System::Drawing::Point(221, 46);
			this->ButtonInputMoney->Name = L"ButtonInputMoney";
			this->ButtonInputMoney->Size = System::Drawing::Size(94, 35);
			this->ButtonInputMoney->TabIndex = 6;
			this->ButtonInputMoney->Text = L"Поповнити рахунок";
			this->ButtonInputMoney->UseVisualStyleBackColor = true;
			this->ButtonInputMoney->Click += gcnew System::EventHandler(this, &MainForm::ButtonInputMoney_Click);
			// 
			// ButtonMoneyOutput
			// 
			this->ButtonMoneyOutput->Location = System::Drawing::Point(123, 46);
			this->ButtonMoneyOutput->Name = L"ButtonMoneyOutput";
			this->ButtonMoneyOutput->Size = System::Drawing::Size(95, 35);
			this->ButtonMoneyOutput->TabIndex = 5;
			this->ButtonMoneyOutput->Text = L"Видача готівки";
			this->ButtonMoneyOutput->UseVisualStyleBackColor = true;
			this->ButtonMoneyOutput->Click += gcnew System::EventHandler(this, &MainForm::ButtonMoneyOutput_Click);
			// 
			// EditBalance
			// 
			this->EditBalance->Location = System::Drawing::Point(12, 128);
			this->EditBalance->Name = L"EditBalance";
			this->EditBalance->Size = System::Drawing::Size(100, 20);
			this->EditBalance->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Баланс";
			// 
			// RadioButtonVip
			// 
			this->RadioButtonVip->AutoSize = true;
			this->RadioButtonVip->Location = System::Drawing::Point(17, 69);
			this->RadioButtonVip->Name = L"RadioButtonVip";
			this->RadioButtonVip->Size = System::Drawing::Size(45, 17);
			this->RadioButtonVip->TabIndex = 2;
			this->RadioButtonVip->TabStop = true;
			this->RadioButtonVip->Text = L"VIP";
			this->RadioButtonVip->UseVisualStyleBackColor = true;
			this->RadioButtonVip->Click += gcnew System::EventHandler(this, &MainForm::RadioButtonDefault_Click);
			// 
			// RadioButtonSocial
			// 
			this->RadioButtonSocial->AutoSize = true;
			this->RadioButtonSocial->Location = System::Drawing::Point(17, 46);
			this->RadioButtonSocial->Name = L"RadioButtonSocial";
			this->RadioButtonSocial->Size = System::Drawing::Size(92, 17);
			this->RadioButtonSocial->TabIndex = 1;
			this->RadioButtonSocial->TabStop = true;
			this->RadioButtonSocial->Text = L"Соціальний";
			this->RadioButtonSocial->UseVisualStyleBackColor = true;
			this->RadioButtonSocial->Click += gcnew System::EventHandler(this, &MainForm::RadioButtonDefault_Click);
			// 
			// ButtonConfirmUtilities
			// 
			this->ButtonConfirmUtilities->Location = System::Drawing::Point(24, 52);
			this->ButtonConfirmUtilities->Name = L"ButtonConfirmUtilities";
			this->ButtonConfirmUtilities->Size = System::Drawing::Size(84, 35);
			this->ButtonConfirmUtilities->TabIndex = 10;
			this->ButtonConfirmUtilities->Text = L"Підтвердити";
			this->ButtonConfirmUtilities->UseVisualStyleBackColor = true;
			this->ButtonConfirmUtilities->Click += gcnew System::EventHandler(this, &MainForm::ButtonConfirmUtilities_Click);
			// 
			// EditStory
			// 
			this->EditStory->Location = System::Drawing::Point(6, 35);
			this->EditStory->Multiline = true;
			this->EditStory->Name = L"EditStory";
			this->EditStory->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->EditStory->Size = System::Drawing::Size(359, 352);
			this->EditStory->TabIndex = 11;
			// 
			// EditPayUtilities
			// 
			this->EditPayUtilities->Location = System::Drawing::Point(15, 18);
			this->EditPayUtilities->Name = L"EditPayUtilities";
			this->EditPayUtilities->Size = System::Drawing::Size(100, 20);
			this->EditPayUtilities->TabIndex = 13;
			// 
			// EditTransaction
			// 
			this->EditTransaction->Location = System::Drawing::Point(101, 30);
			this->EditTransaction->Name = L"EditTransaction";
			this->EditTransaction->Size = System::Drawing::Size(100, 20);
			this->EditTransaction->TabIndex = 14;
			// 
			// ButtonConfirmTransaction
			// 
			this->ButtonConfirmTransaction->Location = System::Drawing::Point(107, 65);
			this->ButtonConfirmTransaction->Name = L"ButtonConfirmTransaction";
			this->ButtonConfirmTransaction->Size = System::Drawing::Size(84, 35);
			this->ButtonConfirmTransaction->TabIndex = 15;
			this->ButtonConfirmTransaction->Text = L"Підтвердити";
			this->ButtonConfirmTransaction->UseVisualStyleBackColor = true;
			this->ButtonConfirmTransaction->Click += gcnew System::EventHandler(this, &MainForm::ButtonConfirmTransaction_Click);
			// 
			// EditMoneyOutput
			// 
			this->EditMoneyOutput->Location = System::Drawing::Point(19, 28);
			this->EditMoneyOutput->Name = L"EditMoneyOutput";
			this->EditMoneyOutput->Size = System::Drawing::Size(100, 20);
			this->EditMoneyOutput->TabIndex = 16;
			// 
			// ButtonConfirmMoneyOutput
			// 
			this->ButtonConfirmMoneyOutput->Location = System::Drawing::Point(28, 54);
			this->ButtonConfirmMoneyOutput->Name = L"ButtonConfirmMoneyOutput";
			this->ButtonConfirmMoneyOutput->Size = System::Drawing::Size(84, 35);
			this->ButtonConfirmMoneyOutput->TabIndex = 17;
			this->ButtonConfirmMoneyOutput->Text = L"Підтвердити";
			this->ButtonConfirmMoneyOutput->UseVisualStyleBackColor = true;
			this->ButtonConfirmMoneyOutput->Click += gcnew System::EventHandler(this, &MainForm::ButtonConfirmMoneyOutput_Click);
			// 
			// ButtonConfirmInputMoney
			// 
			this->ButtonConfirmInputMoney->Location = System::Drawing::Point(35, 54);
			this->ButtonConfirmInputMoney->Name = L"ButtonConfirmInputMoney";
			this->ButtonConfirmInputMoney->Size = System::Drawing::Size(84, 35);
			this->ButtonConfirmInputMoney->TabIndex = 18;
			this->ButtonConfirmInputMoney->Text = L"Підтвердити";
			this->ButtonConfirmInputMoney->UseVisualStyleBackColor = true;
			this->ButtonConfirmInputMoney->Click += gcnew System::EventHandler(this, &MainForm::ButtonConfirmInputMoney_Click);
			// 
			// EditMoneyInput
			// 
			this->EditMoneyInput->Location = System::Drawing::Point(26, 28);
			this->EditMoneyInput->Name = L"EditMoneyInput";
			this->EditMoneyInput->Size = System::Drawing::Size(100, 20);
			this->EditMoneyInput->TabIndex = 19;
			// 
			// Blok2
			// 
			this->Blok2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Blok2.BackgroundImage")));
			this->Blok2->Controls->Add(this->ButtonCancel);
			this->Blok2->Controls->Add(this->EditStory);
			this->Blok2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Blok2->Location = System::Drawing::Point(349, 26);
			this->Blok2->Name = L"Blok2";
			this->Blok2->Size = System::Drawing::Size(371, 393);
			this->Blok2->TabIndex = 20;
			this->Blok2->TabStop = false;
			this->Blok2->Text = L"Історія трансакцій";
			// 
			// ButtonCancel
			// 
			this->ButtonCancel->Location = System::Drawing::Point(174, 371);
			this->ButtonCancel->Name = L"ButtonCancel";
			this->ButtonCancel->Size = System::Drawing::Size(84, 35);
			this->ButtonCancel->TabIndex = 24;
			this->ButtonCancel->Text = L"Скасувати";
			this->ButtonCancel->UseVisualStyleBackColor = true;
			this->ButtonCancel->Visible = false;
			this->ButtonCancel->Click += gcnew System::EventHandler(this, &MainForm::ButtonCancel_Click);
			// 
			// PanelTransaction
			// 
			this->PanelTransaction->Controls->Add(this->RadioButtonVipDest);
			this->PanelTransaction->Controls->Add(this->label2);
			this->PanelTransaction->Controls->Add(this->RadioButtonSocialDest);
			this->PanelTransaction->Controls->Add(this->RadioButtonDefaultDest);
			this->PanelTransaction->Controls->Add(this->ButtonConfirmTransaction);
			this->PanelTransaction->Controls->Add(this->EditTransaction);
			this->PanelTransaction->Location = System::Drawing::Point(124, 203);
			this->PanelTransaction->Name = L"PanelTransaction";
			this->PanelTransaction->Size = System::Drawing::Size(216, 116);
			this->PanelTransaction->TabIndex = 21;
			this->PanelTransaction->TabStop = false;
			// 
			// RadioButtonVipDest
			// 
			this->RadioButtonVipDest->AutoSize = true;
			this->RadioButtonVipDest->Location = System::Drawing::Point(6, 79);
			this->RadioButtonVipDest->Name = L"RadioButtonVipDest";
			this->RadioButtonVipDest->Size = System::Drawing::Size(42, 17);
			this->RadioButtonVipDest->TabIndex = 12;
			this->RadioButtonVipDest->TabStop = true;
			this->RadioButtonVipDest->Text = L"VIP";
			this->RadioButtonVipDest->UseVisualStyleBackColor = true;
			this->RadioButtonVipDest->Click += gcnew System::EventHandler(this, &MainForm::RadioButtonDefaultDest_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(97, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Сума переказу:";
			// 
			// RadioButtonSocialDest
			// 
			this->RadioButtonSocialDest->AutoSize = true;
			this->RadioButtonSocialDest->Location = System::Drawing::Point(6, 56);
			this->RadioButtonSocialDest->Name = L"RadioButtonSocialDest";
			this->RadioButtonSocialDest->Size = System::Drawing::Size(82, 17);
			this->RadioButtonSocialDest->TabIndex = 11;
			this->RadioButtonSocialDest->TabStop = true;
			this->RadioButtonSocialDest->Text = L"Соціальний";
			this->RadioButtonSocialDest->UseVisualStyleBackColor = true;
			this->RadioButtonSocialDest->Click += gcnew System::EventHandler(this, &MainForm::RadioButtonDefaultDest_Click);
			// 
			// RadioButtonDefaultDest
			// 
			this->RadioButtonDefaultDest->AutoSize = true;
			this->RadioButtonDefaultDest->Location = System::Drawing::Point(6, 33);
			this->RadioButtonDefaultDest->Name = L"RadioButtonDefaultDest";
			this->RadioButtonDefaultDest->Size = System::Drawing::Size(68, 17);
			this->RadioButtonDefaultDest->TabIndex = 10;
			this->RadioButtonDefaultDest->TabStop = true;
			this->RadioButtonDefaultDest->Text = L"Базовий";
			this->RadioButtonDefaultDest->UseVisualStyleBackColor = true;
			this->RadioButtonDefaultDest->Click += gcnew System::EventHandler(this, &MainForm::RadioButtonDefaultDest_Click);
			// 
			// PanelPayUtilities
			// 
			this->PanelPayUtilities->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->PanelPayUtilities->Controls->Add(this->label3);
			this->PanelPayUtilities->Controls->Add(this->ButtonConfirmUtilities);
			this->PanelPayUtilities->Controls->Add(this->EditPayUtilities);
			this->PanelPayUtilities->Controls->Add(this->label6);
			this->PanelPayUtilities->Location = System::Drawing::Point(12, 209);
			this->PanelPayUtilities->Name = L"PanelPayUtilities";
			this->PanelPayUtilities->Size = System::Drawing::Size(133, 110);
			this->PanelPayUtilities->TabIndex = 17;
			this->PanelPayUtilities->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(17, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(94, 13);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Оплата послуг";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(37, 22);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Отримувач";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(16, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Сума для видачі:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(5, 3);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(140, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Сума для поповнення:";
			// 
			// PanelMoneyOutput
			// 
			this->PanelMoneyOutput->Controls->Add(this->label4);
			this->PanelMoneyOutput->Controls->Add(this->ButtonConfirmMoneyOutput);
			this->PanelMoneyOutput->Controls->Add(this->EditMoneyOutput);
			this->PanelMoneyOutput->Location = System::Drawing::Point(26, 331);
			this->PanelMoneyOutput->Name = L"PanelMoneyOutput";
			this->PanelMoneyOutput->Size = System::Drawing::Size(130, 110);
			this->PanelMoneyOutput->TabIndex = 24;
			this->PanelMoneyOutput->TabStop = false;
			// 
			// PanelMoneyInput
			// 
			this->PanelMoneyInput->Controls->Add(this->EditMoneyInput);
			this->PanelMoneyInput->Controls->Add(this->label5);
			this->PanelMoneyInput->Controls->Add(this->ButtonConfirmInputMoney);
			this->PanelMoneyInput->Location = System::Drawing::Point(189, 331);
			this->PanelMoneyInput->Name = L"PanelMoneyInput";
			this->PanelMoneyInput->Size = System::Drawing::Size(149, 109);
			this->PanelMoneyInput->TabIndex = 25;
			this->PanelMoneyInput->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(747, 444);
			this->Controls->Add(this->PanelPayUtilities);
			this->Controls->Add(this->PanelMoneyOutput);
			this->Controls->Add(this->Blok2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->PanelTransaction);
			this->Controls->Add(this->PanelMoneyInput);
			this->Name = L"MainForm";
			this->Text = L"Банківський рахунок";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->Blok2->ResumeLayout(false);
			this->Blok2->PerformLayout();
			this->PanelTransaction->ResumeLayout(false);
			this->PanelTransaction->PerformLayout();
			this->PanelPayUtilities->ResumeLayout(false);
			this->PanelPayUtilities->PerformLayout();
			this->PanelMoneyOutput->ResumeLayout(false);
			this->PanelMoneyOutput->PerformLayout();
			this->PanelMoneyInput->ResumeLayout(false);
			this->PanelMoneyInput->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		/*private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		}	*/
	private: System::Void RadioButtonDefault_Click(System::Object^  sender, System::EventArgs^  e) {
		{
			if (RadioButtonDefault->Checked) {
				i = 0;
			}
			else
				if (RadioButtonSocial->Checked) {
					i = 1;
				}
				else
					if (RadioButtonVip->Checked) {
						i = 2;
					}
			// instant відображення історії транзакцій
			EditStory->Text = "";
			EditStory->Text = EditStory->Text + gcnew String(pointers[i]->GetTransactionStory().c_str());
			//EditStory->Text = EditStory->Text + "\r\n"+PIP->Text;
			ButtonMoneyOutput->Enabled = true;
			ButtonInputMoney->Enabled = true;
			ButtonPayUtilities->Enabled = true;
			ButtonTransaction->Enabled = true;
			ButtonPrintStory->Enabled = true;
			EditBalance->Text = System::Convert::ToString(pointers[i]->GetBalance());
			PanelPayUtilities->Enabled = false;
			PanelTransaction->Enabled = false;
			PanelMoneyOutput->Enabled = false;
			PanelMoneyInput->Enabled = false;
		}
	};
			 /*private: System::Void RadioButtonDefault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 };*/
			 /*private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 for (int j = 0; j < 3; j++)
				 {
					 delete pointers[j];
				 }
			 };*/

	private: System::Void ButtonPrintStory_Click(System::Object^  sender, System::EventArgs^  e) {
		std::ofstream outfDefault("DefaultAccountHistory.txt", std::ios::out);
		outfDefault << pointers[0]->GetTransactionStory();
		std::ofstream outfSocial("SocialAccountHistory.txt", std::ios::out);
		outfSocial << pointers[1]->GetTransactionStory();
		std::ofstream outfVip("VIP_AccountHistory.txt", std::ios::out);
		outfVip << pointers[2]->GetTransactionStory();
	}
	private: System::Void ButtonMoneyOutput_Click(System::Object^  sender, System::EventArgs^  e) {
		PanelMoneyOutput->Enabled = true;
		EditMoneyOutput->Focused;    //SetFocus();
		ButtonCancel->Visible = true;
		PanelMoneyInput->Enabled = false;
		PanelPayUtilities->Enabled = false;
		PanelTransaction->Enabled = false;
	}
	private: System::Void ButtonConfirmMoneyOutput_Click(System::Object^  sender, System::EventArgs^  e) {
		pointers[i]->OutputMoney(Convert::ToDouble(EditMoneyOutput->Text));
		EditMoneyOutput->Text = "";
		PanelMoneyOutput->Enabled = false;
		EditBalance->Text = System::Convert::ToString(pointers[i]->GetBalance());
		ButtonCancel->Visible = false;
		EditStory->Text = "";
		EditStory->Text = EditStory->Text + gcnew String(pointers[i]->GetTransactionStory().c_str());    //Lines->Add(pointers[i]->GetTransactionStory().c_str());
	}
	private: System::Void ButtonInputMoney_Click(System::Object^  sender, System::EventArgs^  e) {
		PanelMoneyInput->Enabled = true;
		EditMoneyInput->Focused;
		ButtonCancel->Visible = true;
		PanelMoneyOutput->Enabled = false;
		PanelPayUtilities->Enabled = false;
		PanelTransaction->Enabled = false;
	}
	private: System::Void ButtonConfirmInputMoney_Click(System::Object^  sender, System::EventArgs^  e) {
		double dNumber;
		try {
			if (EditMoneyInput->Text == "") {
				throw CException("Відсутні дані!");
			}
			if (!(Double::TryParse(EditMoneyInput->Text, dNumber)))
			{				
				EditMoneyInput->Text = "";
				throw CException("Неправильний формат даних");
			}
			pointers[i]->InputMoney(Convert::ToDouble(EditMoneyInput->Text));
			EditMoneyInput->Text = "";
			PanelMoneyInput->Enabled = false;
			EditBalance->Text = System::Convert::ToString(pointers[i]->GetBalance());
			ButtonCancel->Visible = false;
			EditStory->Text = "";
			EditStory->Text = EditStory->Text + gcnew String(pointers[i]->GetTransactionStory().c_str());
		}
		catch (CException& exception) {
			String^ str = gcnew String(exception.what());
			MessageBox::Show(str);
		}
	}
	private: System::Void ButtonPayUtilities_Click(System::Object^  sender, System::EventArgs^  e) {
		PanelPayUtilities->Visible = true;
		PanelPayUtilities->Enabled = true;
		EditPayUtilities->Focused;
		ButtonCancel->Visible = true;
		PanelMoneyInput->Enabled = false;
		PanelMoneyOutput->Enabled = false;
		PanelTransaction->Enabled = false;
	}
	private: System::Void ButtonConfirmUtilities_Click(System::Object^  sender, System::EventArgs^  e) {
		pointers[i]->PayUtilities(Convert::ToDouble(EditPayUtilities->Text));
		EditPayUtilities->Text = "";
		PanelPayUtilities->Enabled = false;
		EditBalance->Text = System::Convert::ToString(pointers[i]->GetBalance());
		ButtonCancel->Visible = false;
		EditStory->Text = "";
		EditStory->Text = EditStory->Text + gcnew String(pointers[i]->GetTransactionStory().c_str());
	}
	private: System::Void ButtonTransaction_Click(System::Object^  sender, System::EventArgs^  e) {
		PanelTransaction->Enabled = true;
		PanelPayUtilities->Visible = false;
		EditTransaction->Focused;
		ButtonCancel->Visible = true;
		PanelMoneyInput->Enabled = false;
		PanelPayUtilities->Enabled = false;
		PanelMoneyOutput->Enabled = false;
	}
	private: System::Void ButtonConfirmTransaction_Click(System::Object^  sender, System::EventArgs^  e) {
		if (destination)
		{
			Transaction(pointers[i], destination, Convert::ToDouble(EditTransaction->Text));
			EditTransaction->Text = "";
			PanelTransaction->Enabled = false;
			EditBalance->Text = System::Convert::ToString(pointers[i]->GetBalance());
			PanelPayUtilities->Visible = true;
			ButtonCancel->Visible = false;
			EditStory->Text = "";
			EditStory->Text = EditStory->Text + gcnew String(pointers[i]->GetTransactionStory().c_str());
		}
		else MessageBox::Show("Оберіть, на який рахунок бажаєте перерахувати гроші.", "Перерахунок коштів", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
	private: System::Void RadioButtonDefaultDest_Click(System::Object^  sender, System::EventArgs^  e) {
		if (RadioButtonDefaultDest->Checked) {
			if (i != 0) {
				destination = pointers[0];
			}
			else MessageBox::Show("Неможливо перевести гроші на той самий рахунок");
		}
		else
			if (RadioButtonSocialDest->Checked) {
				if (i != 1) {
					destination = pointers[1];
				}
				else MessageBox::Show("Неможливо перевести гроші на той самий рахунок");
			}
			else
				if (RadioButtonVipDest->Checked) {
					if (i != 2) {
						destination = pointers[2];
					}
					else MessageBox::Show("Неможливо перевести гроші на той самий рахунок");
				}

	}
	private: System::Void ButtonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
		EditTransaction->Text = "";
		PanelTransaction->Enabled = false;
		EditPayUtilities->Text = "";
		PanelPayUtilities->Enabled = false;
		EditMoneyInput->Text = "";
		PanelMoneyInput->Enabled = false;
		EditMoneyOutput->Text = "";
		PanelMoneyOutput->Enabled = false;
		ButtonCancel->Visible = false;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		CSocialAccount * pSocial = dynamic_cast <CSocialAccount*> (pointers[1]);
		if (!pSocial) {
			MessageBox::Show("SYSTEM INFORMATION (!pSocial) - an error occured with dynamic_cast()");
		}
		CVipAccount * pVip = dynamic_cast <CVipAccount*>(pointers[2]);
		if (!pVip) {
			MessageBox::Show("SYSTEM INFORMATION (!pVip) - an error occured with dynamic_cast()");
		}
		if (pSocial && pVip) {
			pSocial->AddPercents();
			pVip->AddPercents();
			if (i == 1 || i == 2) {
				EditStory->Text = "";
				EditStory->Text = EditStory->Text + gcnew String(pointers[i]->GetTransactionStory().c_str());
			}
		}
	}
	/*private: System::Void PIP_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
		pointers[0] = new CDefaultAccount();// (toStringg(PIP->Text));
		pointers[1] = new CSocialAccount;
		pointers[2] = new CVipAccount;
	}*/
};
}