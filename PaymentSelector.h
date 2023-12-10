#pragma once
#include "Struct.h"

using namespace structure;

namespace HMI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm1
	/// </summary>
	public ref class PaymentSelector : public System::Windows::Forms::Form
	{
		Payment^ payment;

	public:
		PaymentSelector(void)
		{
			InitializeComponent();
			this->payment = nullptr;
		}
		Payment^ askPayment() {
			this->payment = nullptr;
			this->ShowDialog();
			return this->payment;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PaymentSelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ paymentMeanInput;
	protected:

	private: System::Windows::Forms::NumericUpDown^ paymentDateDayInput;
	private: System::Windows::Forms::NumericUpDown^ paymentDateMonthInput;
	private: System::Windows::Forms::NumericUpDown^ paymentDateYearInput;
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ receptionDateYearInput;

	private: System::Windows::Forms::NumericUpDown^ receptionDateMonthInput;

	private: System::Windows::Forms::NumericUpDown^ receptionDateDayInput;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ confirmButton;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->paymentMeanInput = (gcnew System::Windows::Forms::ComboBox());
			this->paymentDateDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->paymentDateMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->paymentDateYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->receptionDateYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->receptionDateMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->receptionDateDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paymentDateDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paymentDateMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paymentDateYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->receptionDateYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->receptionDateMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->receptionDateDayInput))->BeginInit();
			this->SuspendLayout();
			// 
			// paymentMeanInput
			// 
			this->paymentMeanInput->FormattingEnabled = true;
			this->paymentMeanInput->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Carte Bancaire", L"Especes" });
			this->paymentMeanInput->Location = System::Drawing::Point(153, 137);
			this->paymentMeanInput->Name = L"paymentMeanInput";
			this->paymentMeanInput->Size = System::Drawing::Size(121, 24);
			this->paymentMeanInput->TabIndex = 0;
			this->paymentMeanInput->Text = L"Carte Bancaire";
			// 
			// paymentDateDayInput
			// 
			this->paymentDateDayInput->Location = System::Drawing::Point(153, 17);
			this->paymentDateDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->paymentDateDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->paymentDateDayInput->Name = L"paymentDateDayInput";
			this->paymentDateDayInput->Size = System::Drawing::Size(52, 22);
			this->paymentDateDayInput->TabIndex = 1;
			this->paymentDateDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// paymentDateMonthInput
			// 
			this->paymentDateMonthInput->Location = System::Drawing::Point(228, 17);
			this->paymentDateMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->paymentDateMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->paymentDateMonthInput->Name = L"paymentDateMonthInput";
			this->paymentDateMonthInput->Size = System::Drawing::Size(54, 22);
			this->paymentDateMonthInput->TabIndex = 2;
			this->paymentDateMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// paymentDateYearInput
			// 
			this->paymentDateYearInput->Location = System::Drawing::Point(305, 18);
			this->paymentDateYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->paymentDateYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->paymentDateYearInput->Name = L"paymentDateYearInput";
			this->paymentDateYearInput->Size = System::Drawing::Size(80, 22);
			this->paymentDateYearInput->TabIndex = 3;
			this->paymentDateYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(211, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(11, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"/";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(288, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(11, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"/";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(288, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(11, 16);
			this->label3->TabIndex = 10;
			this->label3->Text = L"/";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(211, 81);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(11, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"/";
			// 
			// receptionDateYearInput
			// 
			this->receptionDateYearInput->Location = System::Drawing::Point(305, 79);
			this->receptionDateYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->receptionDateYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->receptionDateYearInput->Name = L"receptionDateYearInput";
			this->receptionDateYearInput->Size = System::Drawing::Size(80, 22);
			this->receptionDateYearInput->TabIndex = 8;
			this->receptionDateYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// receptionDateMonthInput
			// 
			this->receptionDateMonthInput->Location = System::Drawing::Point(228, 78);
			this->receptionDateMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->receptionDateMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->receptionDateMonthInput->Name = L"receptionDateMonthInput";
			this->receptionDateMonthInput->Size = System::Drawing::Size(54, 22);
			this->receptionDateMonthInput->TabIndex = 7;
			this->receptionDateMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// receptionDateDayInput
			// 
			this->receptionDateDayInput->Location = System::Drawing::Point(153, 78);
			this->receptionDateDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->receptionDateDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->receptionDateDayInput->Name = L"receptionDateDayInput";
			this->receptionDateDayInput->Size = System::Drawing::Size(52, 22);
			this->receptionDateDayInput->TabIndex = 6;
			this->receptionDateDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 17);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(114, 16);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Date de paiement";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(134, 16);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Date d\'encaissement";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(14, 140);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(126, 16);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Moyen de paiement";
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(153, 189);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(105, 23);
			this->confirmButton->TabIndex = 14;
			this->confirmButton->Text = L"Valider";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &PaymentSelector::confirmButton_Click);
			// 
			// PaymentSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(401, 219);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->receptionDateYearInput);
			this->Controls->Add(this->receptionDateMonthInput);
			this->Controls->Add(this->receptionDateDayInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->paymentDateYearInput);
			this->Controls->Add(this->paymentDateMonthInput);
			this->Controls->Add(this->paymentDateDayInput);
			this->Controls->Add(this->paymentMeanInput);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"PaymentSelector";
			this->Text = L"Ajout d\'un paiement";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paymentDateDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paymentDateMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->paymentDateYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->receptionDateYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->receptionDateMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->receptionDateDayInput))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:

		void confirmButton_Click(Object^ sender, EventArgs^ e) {
			this->payment = gcnew Payment();
			this->payment->paymentDate = gcnew DateTime(
				(int)(float)this->paymentDateYearInput->Value, 
				(int)(float)this->paymentDateMonthInput->Value, 
				(int)(float)this->paymentDateDayInput->Value
			);
			this->payment->receptionDate = gcnew DateTime(
				(int)(float)this->receptionDateYearInput->Value,
				(int)(float)this->receptionDateMonthInput->Value,
				(int)(float)this->receptionDateDayInput->Value
			);
			if (!this->paymentMeanInput->Text->CompareTo("Carte Bancaire")) {
				this->payment->mean = PaymentMean::CreditCard;
			}
			else if (!this->paymentMeanInput->Text->CompareTo("Especes")) {
				this->payment->mean = PaymentMean::Cash;
			}
			else {
				this->payment = nullptr;
				return;
			}
			this->Close();
		}
	};
}
