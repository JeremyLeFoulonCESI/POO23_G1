#pragma once
#include "Struct.h"
#include "SupplyManager.h"


namespace HMI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for OrderItemSelector
	/// </summary>
	public ref class OrderItemSelector : public System::Windows::Forms::Form
	{
		OrderItem^ item;
		Services::SupplyManager^ supply;
		DataTable^ products;

	public:
		OrderItemSelector(Services::SupplyManager^ supply)
		{
			InitializeComponent();
			this->item = nullptr;
			this->supply = supply;
		}

		OrderItem^ askOrderItem() {
			this->productDisplay->DataSource = this->products = this->supply->getAllProducts();
			this->item = nullptr;
			this->ShowDialog();
			return this->item;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OrderItemSelector()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ confirmButton;
	protected:

	protected:



	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ amountInput;
	private: System::Windows::Forms::DataGridView^ productDisplay;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->amountInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productDisplay = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amountInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productDisplay))->BeginInit();
			this->SuspendLayout();
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(274, 117);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(100, 23);
			this->confirmButton->TabIndex = 0;
			this->confirmButton->Text = L"Valider";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &OrderItemSelector::validateButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Quantite voulue:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Choix du produit:";
			// 
			// amountInput
			// 
			this->amountInput->Location = System::Drawing::Point(277, 47);
			this->amountInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60000, 0, 0, 0 });
			this->amountInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->amountInput->Name = L"amountInput";
			this->amountInput->Size = System::Drawing::Size(58, 22);
			this->amountInput->TabIndex = 5;
			this->amountInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// productDisplay
			// 
			this->productDisplay->ColumnHeadersHeight = 9;
			this->productDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->productDisplay->Location = System::Drawing::Point(29, 28);
			this->productDisplay->Name = L"productDisplay";
			this->productDisplay->ReadOnly = true;
			this->productDisplay->RowHeadersWidth = 51;
			this->productDisplay->RowTemplate->Height = 24;
			this->productDisplay->Size = System::Drawing::Size(227, 119);
			this->productDisplay->StandardTab = true;
			this->productDisplay->TabIndex = 6;
			// 
			// OrderItemSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(403, 159);
			this->Controls->Add(this->productDisplay);
			this->Controls->Add(this->amountInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->confirmButton);
			this->Name = L"OrderItemSelector";
			this->Text = L"Ajout d\'un achat";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amountInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productDisplay))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void validateButton_Click(Object^ sender, EventArgs^ e) {
			if (!this->productDisplay->SelectedCells->Count) {
				this->item = nullptr;
				return;
			}

			int row_index = this->productDisplay->SelectedCells[0]->RowIndex;
			Console::WriteLine(this->products->Rows[row_index]->ItemArray[0]);
			SupplyView_FirstItem^ first = safe_cast<SupplyView_FirstItem^>(this->products->Rows[row_index]->ItemArray[0]);
			int product_id = first->product_id;

			ProductData product = this->supply->getProduct(product_id);

			this->item = gcnew OrderItem();
			this->item->productCount = (int)(float)this->amountInput->Value;
			this->item->product = product;
			this->item->discountRatio = product.discountRatio;
			this->item->TaxRatio = product.TVARatio;
			this->item->UHTPrice = product.priceNoTax;
			this->Close();
		}
};
}
