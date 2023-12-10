#pragma once
#include "Struct.h"

namespace HMI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace structure;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class AddressSelector : public System::Windows::Forms::Form
	{

		Address^ data;
		Services::StaffManager^ staff;

	public:
		AddressSelector(Services::StaffManager^ staff)
		{
			InitializeComponent();

			this->cityNameInput->DropDownStyle = ComboBoxStyle::DropDownList;

			this->data = nullptr;
			this->confirmButton->Click += gcnew EventHandler(this, &AddressSelector::confirmButton_click);
			this->staff = staff;
		}

		Address^ askAddress() {
			this->data = nullptr;
			this->cityNameInput->Items->Clear();
			this->ShowDialog();
			return this->data;
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~AddressSelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ streetNumberInput;
	protected:


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ streetNameInput;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ cityCodeInput;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ cityNameInput;
	private: System::Windows::Forms::Button^ confirmButton;



	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->streetNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->streetNameInput = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->cityCodeInput = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->cityNameInput = (gcnew System::Windows::Forms::ComboBox());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Numéro :";
			// 
			// streetNumberInput
			// 
			this->streetNumberInput->Location = System::Drawing::Point(99, 16);
			this->streetNumberInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->streetNumberInput->Name = L"streetNumberInput";
			this->streetNumberInput->Size = System::Drawing::Size(142, 22);
			this->streetNumberInput->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(281, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Voie :";
			// 
			// streetNameInput
			// 
			this->streetNameInput->Location = System::Drawing::Point(343, 17);
			this->streetNameInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->streetNameInput->Name = L"streetNameInput";
			this->streetNameInput->Size = System::Drawing::Size(170, 22);
			this->streetNameInput->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 67);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(108, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Code postal :";
			// 
			// cityCodeInput
			// 
			this->cityCodeInput->Location = System::Drawing::Point(131, 70);
			this->cityCodeInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cityCodeInput->Name = L"cityCodeInput";
			this->cityCodeInput->Size = System::Drawing::Size(110, 22);
			this->cityCodeInput->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(281, 70);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 20);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Ville :";
			// 
			// cityNameInput
			// 
			this->cityNameInput->FormattingEnabled = true;
			this->cityNameInput->Location = System::Drawing::Point(340, 69);
			this->cityNameInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->cityNameInput->Name = L"cityNameInput";
			this->cityNameInput->Size = System::Drawing::Size(173, 24);
			this->cityNameInput->TabIndex = 8;
			this->cityNameInput->DropDown += gcnew System::EventHandler(this, &AddressSelector::cityNameInput_DropDown);
			// 
			// confirmButton
			// 
			this->confirmButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F));
			this->confirmButton->Location = System::Drawing::Point(240, 104);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(93, 30);
			this->confirmButton->TabIndex = 9;
			this->confirmButton->Text = L"Confirmer";
			this->confirmButton->UseVisualStyleBackColor = true;
			// 
			// AddressSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 139);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->cityNameInput);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->cityCodeInput);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->streetNameInput);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->streetNumberInput);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AddressSelector";
			this->Text = L"Configuration d\'une addresse";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void confirmButton_click(Object^ sender, EventArgs^ e) {
			this->data = gcnew Address();
			this->data->streetNum = this->streetNumberInput->Text;
			this->data->streetName = this->streetNameInput->Text;
			this->data->cityName = this->cityNameInput->Text;
			this->data->cityCode = this->cityCodeInput->Text;
			this->Close();
		}
		void cityNameInput_DropDown(Object^ sender, EventArgs^ e) {
			String^ city_code = this->cityCodeInput->Text;
			this->cityNameInput->Items->Clear();

			for each (DataRow ^ city_row in this->staff->findCitiesByCode(city_code)->Rows) {
				this->cityNameInput->Items->Add(city_row->ItemArray[0]->ToString());
			}
		}
};
}
