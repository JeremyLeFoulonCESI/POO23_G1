#pragma once
#include "SupplyManager.h"
#include "Struct.h"

namespace A2POOProjet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Root
	/// </summary>
	public ref class Root : public System::Windows::Forms::Form
	{
		Services::SupplyManager^ supply;

	public:
		Root(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->supply = gcnew Services::SupplyManager();
			this->productUHTPriceCurrencySelector->DropDownStyle = ComboBoxStyle::DropDownList;
			this->productPurchasePriceCurrencySelector->DropDownStyle = ComboBoxStyle::DropDownList;
			this->statsGroup->Visible = false;
			this->customerGroup->Visible = false;
			this->ordersGroup->Visible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Root()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ categoriesGroup;
	private: System::Windows::Forms::Button^ staffCategoryButton;
	private: System::Windows::Forms::Button^ statsCategoryButton;
	protected:


	protected:

	protected:







	private: System::Windows::Forms::Button^ ordersCategoryButton;

	private: System::Windows::Forms::Button^ customersCategoryButton;

	private: System::Windows::Forms::Button^ stockCategoryButton;
	private: System::Windows::Forms::GroupBox^ visualizeGroup;
	private: System::Windows::Forms::DataGridView^ visualizeGrid;




	private: System::Windows::Forms::GroupBox^ validateGroup;
	private: System::Windows::Forms::RadioButton^ EditRadioButton;


	private: System::Windows::Forms::RadioButton^ addRadioButton;

	private: System::Windows::Forms::Button^ validateButton;
	private: System::Windows::Forms::GroupBox^ customerGroup;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ customerMailDotLabel;

	private: System::Windows::Forms::Label^ customerMailAtLabel;
	private: System::Windows::Forms::ComboBox^ customerMailExtInput;


	private: System::Windows::Forms::TextBox^ customerMailDomainInput;



	private: System::Windows::Forms::TextBox^ customerMailNameInput;


	private: System::Windows::Forms::Label^ customerMailLabel;


	private: System::Windows::Forms::Label^ customerBirthLabel;


	private: System::Windows::Forms::Label^ customerFNameLabel;
	private: System::Windows::Forms::Label^ customerLNameLabel;
	private: System::Windows::Forms::TextBox^ customerFNameInput;



private: System::Windows::Forms::TextBox^ customerLNameInput;

	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::GroupBox^ ordersGroup;
private: System::Windows::Forms::ListBox^ ordersClientSelector;
private: System::Windows::Forms::GroupBox^ ordersPaymentGroup;
private: System::Windows::Forms::Button^ ordersRemovePayment;

private: System::Windows::Forms::Button^ ordersNewPayment;

private: System::Windows::Forms::DataGridView^ ordersPaymentDisplay;
private: System::Windows::Forms::Label^ ordersEmitLabel;


private: System::Windows::Forms::Label^ ordersDeliveryLabel;

	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::GroupBox^ groupBox11;
private: System::Windows::Forms::GroupBox^ customerDeliveryGroup;
private: System::Windows::Forms::Button^ CustomerRemoveDeliveryButton;

private: System::Windows::Forms::Button^ customerNewDeliveryButton;

private: System::Windows::Forms::DataGridView^ customerDeliveryDisplay;


private: System::Windows::Forms::GroupBox^ customerInvoiceGroup;
private: System::Windows::Forms::Button^ customerRemoveInvoiceButton;


private: System::Windows::Forms::Button^ CustomerNewInvoiceButton;

private: System::Windows::Forms::DataGridView^ customerInvoiceDisplay;

private: System::Windows::Forms::GroupBox^ staffGroup;
private: System::Windows::Forms::Label^ staffSuperiorLabel;
private: System::Windows::Forms::ListBox^ staffSuperiorSelector;

private: System::Windows::Forms::GroupBox^ staffAddressGroup;
private: System::Windows::Forms::ComboBox^ staffAddressCityInput;
private: System::Windows::Forms::TextBox^ staffAddressCityCodeInput;
private: System::Windows::Forms::Label^ staffAddressCityCodeLabel;

private: System::Windows::Forms::Label^ staffAddressCityLabel;

private: System::Windows::Forms::Label^ staffAddressStreetLabel;
private: System::Windows::Forms::TextBox^ staffAddressStreetInput;

private: System::Windows::Forms::TextBox^ staffAddressNumberInput;

private: System::Windows::Forms::Label^ staffAddressNumberLabel;

private: System::Windows::Forms::Label^ staffHiredLabel;

private: System::Windows::Forms::Label^ staffFNameLabel;

private: System::Windows::Forms::Label^ staffLNameLabel;
private: System::Windows::Forms::TextBox^ staffFNameInput;

private: System::Windows::Forms::TextBox^ staffLNameInput;


private: System::Windows::Forms::GroupBox^ groupBox16;
private: System::Windows::Forms::NumericUpDown^ staffHiredYearInput;

private: System::Windows::Forms::NumericUpDown^ staffHiredMonthInput;

private: System::Windows::Forms::NumericUpDown^ staffHiredDayInput;
private: System::Windows::Forms::Label^ staffHiredSlash2;


private: System::Windows::Forms::Label^ staffHiredSlash1;

private: System::Windows::Forms::NumericUpDown^ customerBirthYearInput;

private: System::Windows::Forms::NumericUpDown^ customerBirthMonthInput;

private: System::Windows::Forms::Label^ customerBirthSlash2;



private: System::Windows::Forms::Label^ customerBirthSlash1;
private: System::Windows::Forms::NumericUpDown^ ordersEmitYearInput;

private: System::Windows::Forms::NumericUpDown^ ordersEmitMonthInput;

private: System::Windows::Forms::NumericUpDown^ ordersEmitDayInput;
private: System::Windows::Forms::Label^ ordersEmitSlash2;


private: System::Windows::Forms::Label^ ordersEmitSlash1;

private: System::Windows::Forms::NumericUpDown^ ordersDeliveryYearInput;

private: System::Windows::Forms::NumericUpDown^ ordersDeliveryMonthInput;

private: System::Windows::Forms::NumericUpDown^ ordersDeliveryDayInput;
private: System::Windows::Forms::Label^ ordersDdeliverySlash2;



private: System::Windows::Forms::Label^ ordersDeliverySlash1;

private: System::Windows::Forms::Button^ vlisualizeDeleteButton;
private: System::Windows::Forms::Button^ statsAverageBasketButton;
private: System::Windows::Forms::Button^ statsTurnoverButton;
private: System::Windows::Forms::Label^ statsMonthLabel;

private: System::Windows::Forms::Button^ statsTotalAmountButton;
private: System::Windows::Forms::Label^ statsCustomerNameLabel;
private: System::Windows::Forms::TextBox^ statsCustomerNameTextbox;
private: System::Windows::Forms::Label^ statsCustomerFirstnameLabel;
private: System::Windows::Forms::TextBox^ statsCustomerFirtsnameTextbox;
private: System::Windows::Forms::NumericUpDown^ statsMonthChoiceTurnover;


private: System::Windows::Forms::Button^ statsStockMarketingValueButton;
private: System::Windows::Forms::Button^ statsStockPurchaseValueButton;
private: System::Windows::Forms::Button^ statsSimulationButton;
private: System::Windows::Forms::GroupBox^ statsGroup;
private: System::Windows::Forms::Label^ statsTVAValueLabel;
private: System::Windows::Forms::Label^ statsTVAPercentLabel;


private: System::Windows::Forms::NumericUpDown^ statsTVAValueNumericUpDown;

private: System::Windows::Forms::Label^ statsUnknownMarkdownLabel;

private: System::Windows::Forms::Label^ statsComDiscountValueLabel;

private: System::Windows::Forms::Label^ statsComMarginValueLabel;
private: System::Windows::Forms::Label^ statsComDiscountPercentLabel;


private: System::Windows::Forms::NumericUpDown^ statsComDiscountValueNumericUpDown;
private: System::Windows::Forms::Label^ statsComMarginPercentLabel;


private: System::Windows::Forms::NumericUpDown^ statsComMarginValueNumericUpDown;
private: System::Windows::Forms::Label^ statsUnknownMarkdownPercentLabel;


private: System::Windows::Forms::NumericUpDown^ statsUnknownMarkdownNumericUpDown;
private: System::Windows::Forms::GroupBox^ groupBox19;
private: System::Windows::Forms::Label^ productNameLabel;
private: System::Windows::Forms::TextBox^ productNameInput;
private: System::Windows::Forms::Label^ productUHTPriceLabel;
private: System::Windows::Forms::ComboBox^ productUHTPriceCurrencySelector;
private: System::Windows::Forms::Label^ productPurchasePriceLabel;
private: System::Windows::Forms::ComboBox^ productPurchasePriceCurrencySelector;
private: System::Windows::Forms::NumericUpDown^ productUHTPriceInput;
private: System::Windows::Forms::NumericUpDown^ productPurchasePriceInput;
private: System::Windows::Forms::NumericUpDown^ productStockInput;
private: System::Windows::Forms::Label^ productStockLabel;
private: System::Windows::Forms::Label^ productTaxesLabel;
private: System::Windows::Forms::NumericUpDown^ productTaxesInput;
private: System::Windows::Forms::Label^ productTaxesPercent;
private: System::Windows::Forms::GroupBox^ productDiscountGroup;
private: System::Windows::Forms::Label^ productBaseDiscountPercent;
private: System::Windows::Forms::NumericUpDown^ productCountWeightInput;
private: System::Windows::Forms::NumericUpDown^ productBaseDiscountInput;
private: System::Windows::Forms::Label^ productCountWeightLabel;
private: System::Windows::Forms::Label^ productBaseDiscountLabel;
private: System::Windows::Forms::Label^ productRestockThresholdLabel;
private: System::Windows::Forms::NumericUpDown^ productRestockThresholdInput;
private: System::Windows::Forms::GroupBox^ productGroup;
private: System::Windows::Forms::NumericUpDown^ customerBirthDayInput;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::GroupBox^ groupBox1;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::GroupBox^ groupBox6;
private: System::Windows::Forms::DataGridView^ dataGridView2;
private: System::Windows::Forms::GroupBox^ groupBox8;
private: System::Windows::Forms::DataGridView^ dataGridView3;
private: System::Windows::Forms::GroupBox^ groupBox5;
private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label1;




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
			this->categoriesGroup = (gcnew System::Windows::Forms::GroupBox());
			this->statsCategoryButton = (gcnew System::Windows::Forms::Button());
			this->ordersCategoryButton = (gcnew System::Windows::Forms::Button());
			this->customersCategoryButton = (gcnew System::Windows::Forms::Button());
			this->stockCategoryButton = (gcnew System::Windows::Forms::Button());
			this->staffCategoryButton = (gcnew System::Windows::Forms::Button());
			this->visualizeGroup = (gcnew System::Windows::Forms::GroupBox());
			this->vlisualizeDeleteButton = (gcnew System::Windows::Forms::Button());
			this->visualizeGrid = (gcnew System::Windows::Forms::DataGridView());
			this->validateGroup = (gcnew System::Windows::Forms::GroupBox());
			this->EditRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->addRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->validateButton = (gcnew System::Windows::Forms::Button());
			this->customerGroup = (gcnew System::Windows::Forms::GroupBox());
			this->customerBirthDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerBirthYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerBirthMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerBirthSlash2 = (gcnew System::Windows::Forms::Label());
			this->customerBirthSlash1 = (gcnew System::Windows::Forms::Label());
			this->customerInvoiceGroup = (gcnew System::Windows::Forms::GroupBox());
			this->customerRemoveInvoiceButton = (gcnew System::Windows::Forms::Button());
			this->CustomerNewInvoiceButton = (gcnew System::Windows::Forms::Button());
			this->customerInvoiceDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->customerDeliveryGroup = (gcnew System::Windows::Forms::GroupBox());
			this->CustomerRemoveDeliveryButton = (gcnew System::Windows::Forms::Button());
			this->customerNewDeliveryButton = (gcnew System::Windows::Forms::Button());
			this->customerDeliveryDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->customerMailDotLabel = (gcnew System::Windows::Forms::Label());
			this->customerMailAtLabel = (gcnew System::Windows::Forms::Label());
			this->customerMailExtInput = (gcnew System::Windows::Forms::ComboBox());
			this->customerMailDomainInput = (gcnew System::Windows::Forms::TextBox());
			this->customerMailNameInput = (gcnew System::Windows::Forms::TextBox());
			this->customerMailLabel = (gcnew System::Windows::Forms::Label());
			this->customerBirthLabel = (gcnew System::Windows::Forms::Label());
			this->customerFNameLabel = (gcnew System::Windows::Forms::Label());
			this->customerLNameLabel = (gcnew System::Windows::Forms::Label());
			this->customerFNameInput = (gcnew System::Windows::Forms::TextBox());
			this->customerLNameInput = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->ordersGroup = (gcnew System::Windows::Forms::GroupBox());
			this->ordersEmitYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersEmitMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersEmitDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersEmitSlash2 = (gcnew System::Windows::Forms::Label());
			this->ordersEmitSlash1 = (gcnew System::Windows::Forms::Label());
			this->ordersDeliveryYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersDeliveryMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersDeliveryDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersDdeliverySlash2 = (gcnew System::Windows::Forms::Label());
			this->ordersDeliverySlash1 = (gcnew System::Windows::Forms::Label());
			this->ordersClientSelector = (gcnew System::Windows::Forms::ListBox());
			this->ordersPaymentGroup = (gcnew System::Windows::Forms::GroupBox());
			this->ordersRemovePayment = (gcnew System::Windows::Forms::Button());
			this->ordersNewPayment = (gcnew System::Windows::Forms::Button());
			this->ordersPaymentDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->ordersEmitLabel = (gcnew System::Windows::Forms::Label());
			this->ordersDeliveryLabel = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->staffGroup = (gcnew System::Windows::Forms::GroupBox());
			this->staffHiredYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->staffHiredMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->staffHiredDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->staffHiredSlash2 = (gcnew System::Windows::Forms::Label());
			this->staffHiredSlash1 = (gcnew System::Windows::Forms::Label());
			this->staffSuperiorLabel = (gcnew System::Windows::Forms::Label());
			this->staffSuperiorSelector = (gcnew System::Windows::Forms::ListBox());
			this->staffAddressGroup = (gcnew System::Windows::Forms::GroupBox());
			this->staffAddressCityInput = (gcnew System::Windows::Forms::ComboBox());
			this->staffAddressCityCodeInput = (gcnew System::Windows::Forms::TextBox());
			this->staffAddressCityCodeLabel = (gcnew System::Windows::Forms::Label());
			this->staffAddressCityLabel = (gcnew System::Windows::Forms::Label());
			this->staffAddressStreetLabel = (gcnew System::Windows::Forms::Label());
			this->staffAddressStreetInput = (gcnew System::Windows::Forms::TextBox());
			this->staffAddressNumberInput = (gcnew System::Windows::Forms::TextBox());
			this->staffAddressNumberLabel = (gcnew System::Windows::Forms::Label());
			this->staffHiredLabel = (gcnew System::Windows::Forms::Label());
			this->staffFNameLabel = (gcnew System::Windows::Forms::Label());
			this->staffLNameLabel = (gcnew System::Windows::Forms::Label());
			this->staffFNameInput = (gcnew System::Windows::Forms::TextBox());
			this->staffLNameInput = (gcnew System::Windows::Forms::TextBox());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->statsAverageBasketButton = (gcnew System::Windows::Forms::Button());
			this->statsTurnoverButton = (gcnew System::Windows::Forms::Button());
			this->statsMonthLabel = (gcnew System::Windows::Forms::Label());
			this->statsTotalAmountButton = (gcnew System::Windows::Forms::Button());
			this->statsCustomerNameLabel = (gcnew System::Windows::Forms::Label());
			this->statsCustomerNameTextbox = (gcnew System::Windows::Forms::TextBox());
			this->statsCustomerFirstnameLabel = (gcnew System::Windows::Forms::Label());
			this->statsCustomerFirtsnameTextbox = (gcnew System::Windows::Forms::TextBox());
			this->statsMonthChoiceTurnover = (gcnew System::Windows::Forms::NumericUpDown());
			this->statsStockMarketingValueButton = (gcnew System::Windows::Forms::Button());
			this->statsStockPurchaseValueButton = (gcnew System::Windows::Forms::Button());
			this->statsSimulationButton = (gcnew System::Windows::Forms::Button());
			this->statsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->statsTVAValueLabel = (gcnew System::Windows::Forms::Label());
			this->statsComMarginValueLabel = (gcnew System::Windows::Forms::Label());
			this->statsComDiscountValueLabel = (gcnew System::Windows::Forms::Label());
			this->statsUnknownMarkdownPercentLabel = (gcnew System::Windows::Forms::Label());
			this->statsUnknownMarkdownLabel = (gcnew System::Windows::Forms::Label());
			this->statsComDiscountPercentLabel = (gcnew System::Windows::Forms::Label());
			this->statsUnknownMarkdownNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->statsComMarginPercentLabel = (gcnew System::Windows::Forms::Label());
			this->statsTVAValueNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->statsTVAPercentLabel = (gcnew System::Windows::Forms::Label());
			this->statsComMarginValueNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->statsComDiscountValueNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->productNameLabel = (gcnew System::Windows::Forms::Label());
			this->productNameInput = (gcnew System::Windows::Forms::TextBox());
			this->productUHTPriceLabel = (gcnew System::Windows::Forms::Label());
			this->productUHTPriceCurrencySelector = (gcnew System::Windows::Forms::ComboBox());
			this->productPurchasePriceLabel = (gcnew System::Windows::Forms::Label());
			this->productPurchasePriceCurrencySelector = (gcnew System::Windows::Forms::ComboBox());
			this->productUHTPriceInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productPurchasePriceInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productStockInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productStockLabel = (gcnew System::Windows::Forms::Label());
			this->productTaxesLabel = (gcnew System::Windows::Forms::Label());
			this->productTaxesInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productTaxesPercent = (gcnew System::Windows::Forms::Label());
			this->productDiscountGroup = (gcnew System::Windows::Forms::GroupBox());
			this->productBaseDiscountPercent = (gcnew System::Windows::Forms::Label());
			this->productCountWeightInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productBaseDiscountInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productCountWeightLabel = (gcnew System::Windows::Forms::Label());
			this->productBaseDiscountLabel = (gcnew System::Windows::Forms::Label());
			this->productRestockThresholdLabel = (gcnew System::Windows::Forms::Label());
			this->productRestockThresholdInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productGroup = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->categoriesGroup->SuspendLayout();
			this->visualizeGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualizeGrid))->BeginInit();
			this->validateGroup->SuspendLayout();
			this->customerGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthMonthInput))->BeginInit();
			this->customerInvoiceGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerInvoiceDisplay))->BeginInit();
			this->customerDeliveryGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerDeliveryDisplay))->BeginInit();
			this->ordersGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryDayInput))->BeginInit();
			this->ordersPaymentGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersPaymentDisplay))->BeginInit();
			this->staffGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredDayInput))->BeginInit();
			this->staffAddressGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsMonthChoiceTurnover))->BeginInit();
			this->statsGroup->SuspendLayout();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsUnknownMarkdownNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsTVAValueNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsComMarginValueNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsComDiscountValueNumericUpDown))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productUHTPriceInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productPurchasePriceInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productStockInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productTaxesInput))->BeginInit();
			this->productDiscountGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productCountWeightInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productBaseDiscountInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productRestockThresholdInput))->BeginInit();
			this->productGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// categoriesGroup
			// 
			this->categoriesGroup->Controls->Add(this->statsCategoryButton);
			this->categoriesGroup->Controls->Add(this->ordersCategoryButton);
			this->categoriesGroup->Controls->Add(this->customersCategoryButton);
			this->categoriesGroup->Controls->Add(this->stockCategoryButton);
			this->categoriesGroup->Controls->Add(this->staffCategoryButton);
			this->categoriesGroup->Location = System::Drawing::Point(12, 514);
			this->categoriesGroup->Name = L"categoriesGroup";
			this->categoriesGroup->Size = System::Drawing::Size(536, 480);
			this->categoriesGroup->TabIndex = 0;
			this->categoriesGroup->TabStop = false;
			this->categoriesGroup->Text = L"Menu principal";
			// 
			// statsCategoryButton
			// 
			this->statsCategoryButton->Location = System::Drawing::Point(143, 390);
			this->statsCategoryButton->Name = L"statsCategoryButton";
			this->statsCategoryButton->Size = System::Drawing::Size(250, 35);
			this->statsCategoryButton->TabIndex = 104;
			this->statsCategoryButton->TabStop = false;
			this->statsCategoryButton->Text = L"Statistiques";
			this->statsCategoryButton->UseVisualStyleBackColor = true;
			// 
			// ordersCategoryButton
			// 
			this->ordersCategoryButton->Location = System::Drawing::Point(143, 305);
			this->ordersCategoryButton->Name = L"ordersCategoryButton";
			this->ordersCategoryButton->Size = System::Drawing::Size(250, 35);
			this->ordersCategoryButton->TabIndex = 103;
			this->ordersCategoryButton->TabStop = false;
			this->ordersCategoryButton->Text = L"Gestion des commandes";
			this->ordersCategoryButton->UseVisualStyleBackColor = true;
			// 
			// customersCategoryButton
			// 
			this->customersCategoryButton->Location = System::Drawing::Point(143, 220);
			this->customersCategoryButton->Name = L"customersCategoryButton";
			this->customersCategoryButton->Size = System::Drawing::Size(250, 35);
			this->customersCategoryButton->TabIndex = 102;
			this->customersCategoryButton->TabStop = false;
			this->customersCategoryButton->Text = L"Gestion des clients";
			this->customersCategoryButton->UseVisualStyleBackColor = true;
			// 
			// stockCategoryButton
			// 
			this->stockCategoryButton->Location = System::Drawing::Point(143, 135);
			this->stockCategoryButton->Name = L"stockCategoryButton";
			this->stockCategoryButton->Size = System::Drawing::Size(250, 35);
			this->stockCategoryButton->TabIndex = 101;
			this->stockCategoryButton->TabStop = false;
			this->stockCategoryButton->Text = L"Gestion du stock";
			this->stockCategoryButton->UseVisualStyleBackColor = true;
			// 
			// staffCategoryButton
			// 
			this->staffCategoryButton->Location = System::Drawing::Point(143, 50);
			this->staffCategoryButton->Name = L"staffCategoryButton";
			this->staffCategoryButton->Size = System::Drawing::Size(250, 35);
			this->staffCategoryButton->TabIndex = 100;
			this->staffCategoryButton->TabStop = false;
			this->staffCategoryButton->Text = L"Gestion du personnel";
			this->staffCategoryButton->UseVisualStyleBackColor = true;
			// 
			// visualizeGroup
			// 
			this->visualizeGroup->Controls->Add(this->vlisualizeDeleteButton);
			this->visualizeGroup->Controls->Add(this->visualizeGrid);
			this->visualizeGroup->Cursor = System::Windows::Forms::Cursors::Hand;
			this->visualizeGroup->Location = System::Drawing::Point(515, 8);
			this->visualizeGroup->Name = L"visualizeGroup";
			this->visualizeGroup->Size = System::Drawing::Size(390, 487);
			this->visualizeGroup->TabIndex = 2;
			this->visualizeGroup->TabStop = false;
			this->visualizeGroup->Text = L"Visualisation des données";
			// 
			// vlisualizeDeleteButton
			// 
			this->vlisualizeDeleteButton->Location = System::Drawing::Point(136, 449);
			this->vlisualizeDeleteButton->Name = L"vlisualizeDeleteButton";
			this->vlisualizeDeleteButton->Size = System::Drawing::Size(114, 23);
			this->vlisualizeDeleteButton->TabIndex = 10;
			this->vlisualizeDeleteButton->Text = L"Supprimer";
			this->vlisualizeDeleteButton->UseVisualStyleBackColor = true;
			// 
			// visualizeGrid
			// 
			this->visualizeGrid->AllowUserToAddRows = false;
			this->visualizeGrid->AllowUserToDeleteRows = false;
			this->visualizeGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->visualizeGrid->Location = System::Drawing::Point(6, 21);
			this->visualizeGrid->Name = L"visualizeGrid";
			this->visualizeGrid->RowHeadersWidth = 51;
			this->visualizeGrid->RowTemplate->Height = 24;
			this->visualizeGrid->Size = System::Drawing::Size(378, 424);
			this->visualizeGrid->TabIndex = 9;
			// 
			// validateGroup
			// 
			this->validateGroup->Controls->Add(this->EditRadioButton);
			this->validateGroup->Controls->Add(this->addRadioButton);
			this->validateGroup->Controls->Add(this->validateButton);
			this->validateGroup->Location = System::Drawing::Point(113, 439);
			this->validateGroup->Name = L"validateGroup";
			this->validateGroup->Size = System::Drawing::Size(396, 56);
			this->validateGroup->TabIndex = 3;
			this->validateGroup->TabStop = false;
			this->validateGroup->Text = L"Validation";
			// 
			// EditRadioButton
			// 
			this->EditRadioButton->AutoSize = true;
			this->EditRadioButton->Location = System::Drawing::Point(283, 21);
			this->EditRadioButton->Name = L"EditRadioButton";
			this->EditRadioButton->Size = System::Drawing::Size(76, 20);
			this->EditRadioButton->TabIndex = 8;
			this->EditRadioButton->Text = L"Modifier";
			this->EditRadioButton->UseVisualStyleBackColor = true;
			// 
			// addRadioButton
			// 
			this->addRadioButton->AutoCheck = false;
			this->addRadioButton->AutoSize = true;
			this->addRadioButton->Checked = true;
			this->addRadioButton->Location = System::Drawing::Point(152, 21);
			this->addRadioButton->Name = L"addRadioButton";
			this->addRadioButton->Size = System::Drawing::Size(70, 20);
			this->addRadioButton->TabIndex = 7;
			this->addRadioButton->Text = L"Ajouter";
			this->addRadioButton->UseVisualStyleBackColor = true;
			// 
			// validateButton
			// 
			this->validateButton->Location = System::Drawing::Point(39, 21);
			this->validateButton->Name = L"validateButton";
			this->validateButton->Size = System::Drawing::Size(75, 23);
			this->validateButton->TabIndex = 6;
			this->validateButton->Text = L"Valider";
			this->validateButton->UseVisualStyleBackColor = true;
			// 
			// customerGroup
			// 
			this->customerGroup->Controls->Add(this->customerBirthDayInput);
			this->customerGroup->Controls->Add(this->customerBirthYearInput);
			this->customerGroup->Controls->Add(this->customerBirthMonthInput);
			this->customerGroup->Controls->Add(this->customerBirthSlash2);
			this->customerGroup->Controls->Add(this->customerBirthSlash1);
			this->customerGroup->Controls->Add(this->customerInvoiceGroup);
			this->customerGroup->Controls->Add(this->customerDeliveryGroup);
			this->customerGroup->Controls->Add(this->label10);
			this->customerGroup->Controls->Add(this->textBox9);
			this->customerGroup->Controls->Add(this->customerMailDotLabel);
			this->customerGroup->Controls->Add(this->customerMailAtLabel);
			this->customerGroup->Controls->Add(this->customerMailExtInput);
			this->customerGroup->Controls->Add(this->customerMailDomainInput);
			this->customerGroup->Controls->Add(this->customerMailNameInput);
			this->customerGroup->Controls->Add(this->customerMailLabel);
			this->customerGroup->Controls->Add(this->customerBirthLabel);
			this->customerGroup->Controls->Add(this->customerFNameLabel);
			this->customerGroup->Controls->Add(this->customerLNameLabel);
			this->customerGroup->Controls->Add(this->customerFNameInput);
			this->customerGroup->Controls->Add(this->customerLNameInput);
			this->customerGroup->Controls->Add(this->groupBox7);
			this->customerGroup->Location = System::Drawing::Point(954, 12);
			this->customerGroup->Name = L"customerGroup";
			this->customerGroup->Size = System::Drawing::Size(536, 425);
			this->customerGroup->TabIndex = 4;
			this->customerGroup->TabStop = false;
			this->customerGroup->Text = L"Edition des données client";
			// 
			// customerBirthDayInput
			// 
			this->customerBirthDayInput->Location = System::Drawing::Point(199, 84);
			this->customerBirthDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->customerBirthDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthDayInput->Name = L"customerBirthDayInput";
			this->customerBirthDayInput->Size = System::Drawing::Size(50, 22);
			this->customerBirthDayInput->TabIndex = 42;
			this->customerBirthDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// customerBirthYearInput
			// 
			this->customerBirthYearInput->Location = System::Drawing::Point(344, 84);
			this->customerBirthYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->customerBirthYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->customerBirthYearInput->Name = L"customerBirthYearInput";
			this->customerBirthYearInput->Size = System::Drawing::Size(70, 22);
			this->customerBirthYearInput->TabIndex = 38;
			this->customerBirthYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// customerBirthMonthInput
			// 
			this->customerBirthMonthInput->Location = System::Drawing::Point(271, 84);
			this->customerBirthMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->customerBirthMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthMonthInput->Name = L"customerBirthMonthInput";
			this->customerBirthMonthInput->Size = System::Drawing::Size(50, 22);
			this->customerBirthMonthInput->TabIndex = 37;
			this->customerBirthMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// customerBirthSlash2
			// 
			this->customerBirthSlash2->AutoSize = true;
			this->customerBirthSlash2->Location = System::Drawing::Point(327, 87);
			this->customerBirthSlash2->Name = L"customerBirthSlash2";
			this->customerBirthSlash2->Size = System::Drawing::Size(11, 16);
			this->customerBirthSlash2->TabIndex = 35;
			this->customerBirthSlash2->Text = L"/";
			// 
			// customerBirthSlash1
			// 
			this->customerBirthSlash1->AutoSize = true;
			this->customerBirthSlash1->Location = System::Drawing::Point(254, 87);
			this->customerBirthSlash1->Name = L"customerBirthSlash1";
			this->customerBirthSlash1->Size = System::Drawing::Size(11, 16);
			this->customerBirthSlash1->TabIndex = 34;
			this->customerBirthSlash1->Text = L"/";
			// 
			// customerInvoiceGroup
			// 
			this->customerInvoiceGroup->Controls->Add(this->customerRemoveInvoiceButton);
			this->customerInvoiceGroup->Controls->Add(this->CustomerNewInvoiceButton);
			this->customerInvoiceGroup->Controls->Add(this->customerInvoiceDisplay);
			this->customerInvoiceGroup->Location = System::Drawing::Point(6, 245);
			this->customerInvoiceGroup->Name = L"customerInvoiceGroup";
			this->customerInvoiceGroup->Size = System::Drawing::Size(249, 115);
			this->customerInvoiceGroup->TabIndex = 25;
			this->customerInvoiceGroup->TabStop = false;
			this->customerInvoiceGroup->Text = L"Adresses de facturation";
			// 
			// customerRemoveInvoiceButton
			// 
			this->customerRemoveInvoiceButton->Location = System::Drawing::Point(128, 87);
			this->customerRemoveInvoiceButton->Name = L"customerRemoveInvoiceButton";
			this->customerRemoveInvoiceButton->Size = System::Drawing::Size(115, 23);
			this->customerRemoveInvoiceButton->TabIndex = 2;
			this->customerRemoveInvoiceButton->Text = L"Retirer";
			this->customerRemoveInvoiceButton->UseVisualStyleBackColor = true;
			// 
			// CustomerNewInvoiceButton
			// 
			this->CustomerNewInvoiceButton->Location = System::Drawing::Point(6, 87);
			this->CustomerNewInvoiceButton->Name = L"CustomerNewInvoiceButton";
			this->CustomerNewInvoiceButton->Size = System::Drawing::Size(123, 23);
			this->CustomerNewInvoiceButton->TabIndex = 1;
			this->CustomerNewInvoiceButton->Text = L"Nouveau";
			this->CustomerNewInvoiceButton->UseVisualStyleBackColor = true;
			// 
			// customerInvoiceDisplay
			// 
			this->customerInvoiceDisplay->BackgroundColor = System::Drawing::SystemColors::Control;
			this->customerInvoiceDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->customerInvoiceDisplay->Location = System::Drawing::Point(6, 21);
			this->customerInvoiceDisplay->Name = L"customerInvoiceDisplay";
			this->customerInvoiceDisplay->RowHeadersWidth = 51;
			this->customerInvoiceDisplay->RowTemplate->Height = 24;
			this->customerInvoiceDisplay->Size = System::Drawing::Size(237, 66);
			this->customerInvoiceDisplay->TabIndex = 0;
			// 
			// customerDeliveryGroup
			// 
			this->customerDeliveryGroup->Controls->Add(this->CustomerRemoveDeliveryButton);
			this->customerDeliveryGroup->Controls->Add(this->customerNewDeliveryButton);
			this->customerDeliveryGroup->Controls->Add(this->customerDeliveryDisplay);
			this->customerDeliveryGroup->Location = System::Drawing::Point(276, 245);
			this->customerDeliveryGroup->Name = L"customerDeliveryGroup";
			this->customerDeliveryGroup->Size = System::Drawing::Size(254, 115);
			this->customerDeliveryGroup->TabIndex = 24;
			this->customerDeliveryGroup->TabStop = false;
			this->customerDeliveryGroup->Text = L"Adresses de livraison";
			// 
			// CustomerRemoveDeliveryButton
			// 
			this->CustomerRemoveDeliveryButton->Location = System::Drawing::Point(126, 87);
			this->CustomerRemoveDeliveryButton->Name = L"CustomerRemoveDeliveryButton";
			this->CustomerRemoveDeliveryButton->Size = System::Drawing::Size(122, 23);
			this->CustomerRemoveDeliveryButton->TabIndex = 2;
			this->CustomerRemoveDeliveryButton->Text = L"Retirer";
			this->CustomerRemoveDeliveryButton->UseVisualStyleBackColor = true;
			// 
			// customerNewDeliveryButton
			// 
			this->customerNewDeliveryButton->Location = System::Drawing::Point(6, 87);
			this->customerNewDeliveryButton->Name = L"customerNewDeliveryButton";
			this->customerNewDeliveryButton->Size = System::Drawing::Size(121, 23);
			this->customerNewDeliveryButton->TabIndex = 1;
			this->customerNewDeliveryButton->Text = L"Nouveau";
			this->customerNewDeliveryButton->UseVisualStyleBackColor = true;
			// 
			// customerDeliveryDisplay
			// 
			this->customerDeliveryDisplay->BackgroundColor = System::Drawing::SystemColors::Control;
			this->customerDeliveryDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->customerDeliveryDisplay->Location = System::Drawing::Point(6, 21);
			this->customerDeliveryDisplay->Name = L"customerDeliveryDisplay";
			this->customerDeliveryDisplay->RowHeadersWidth = 51;
			this->customerDeliveryDisplay->RowTemplate->Height = 24;
			this->customerDeliveryDisplay->Size = System::Drawing::Size(242, 66);
			this->customerDeliveryDisplay->TabIndex = 0;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(59, 182);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(76, 16);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Téléphone:";
			// 
			// textBox9
			// 
			this->textBox9->AcceptsTab = true;
			this->textBox9->Location = System::Drawing::Point(214, 179);
			this->textBox9->MaxLength = 10;
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(124, 22);
			this->textBox9->TabIndex = 8;
			// 
			// customerMailDotLabel
			// 
			this->customerMailDotLabel->AutoSize = true;
			this->customerMailDotLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->customerMailDotLabel->Location = System::Drawing::Point(373, 133);
			this->customerMailDotLabel->Name = L"customerMailDotLabel";
			this->customerMailDotLabel->Size = System::Drawing::Size(10, 16);
			this->customerMailDotLabel->TabIndex = 16;
			this->customerMailDotLabel->Text = L".";
			// 
			// customerMailAtLabel
			// 
			this->customerMailAtLabel->AutoSize = true;
			this->customerMailAtLabel->Location = System::Drawing::Point(248, 133);
			this->customerMailAtLabel->Name = L"customerMailAtLabel";
			this->customerMailAtLabel->Size = System::Drawing::Size(21, 16);
			this->customerMailAtLabel->TabIndex = 15;
			this->customerMailAtLabel->Text = L"@";
			// 
			// customerMailExtInput
			// 
			this->customerMailExtInput->FormattingEnabled = true;
			this->customerMailExtInput->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"be", L"com", L"de", L"en", L"eu",
					L"fr", L"ie", L"it", L"net", L"tv", L"us"
			});
			this->customerMailExtInput->Location = System::Drawing::Point(389, 130);
			this->customerMailExtInput->MaxLength = 3;
			this->customerMailExtInput->Name = L"customerMailExtInput";
			this->customerMailExtInput->Size = System::Drawing::Size(55, 24);
			this->customerMailExtInput->TabIndex = 7;
			this->customerMailExtInput->TabStop = false;
			// 
			// customerMailDomainInput
			// 
			this->customerMailDomainInput->AcceptsTab = true;
			this->customerMailDomainInput->Location = System::Drawing::Point(271, 130);
			this->customerMailDomainInput->MaxLength = 4;
			this->customerMailDomainInput->Name = L"customerMailDomainInput";
			this->customerMailDomainInput->Size = System::Drawing::Size(100, 22);
			this->customerMailDomainInput->TabIndex = 6;
			// 
			// customerMailNameInput
			// 
			this->customerMailNameInput->AcceptsTab = true;
			this->customerMailNameInput->Location = System::Drawing::Point(134, 130);
			this->customerMailNameInput->Name = L"customerMailNameInput";
			this->customerMailNameInput->Size = System::Drawing::Size(113, 22);
			this->customerMailNameInput->TabIndex = 5;
			this->customerMailNameInput->TabStop = false;
			// 
			// customerMailLabel
			// 
			this->customerMailLabel->AutoSize = true;
			this->customerMailLabel->Location = System::Drawing::Point(59, 133);
			this->customerMailLabel->Name = L"customerMailLabel";
			this->customerMailLabel->Size = System::Drawing::Size(35, 16);
			this->customerMailLabel->TabIndex = 11;
			this->customerMailLabel->Text = L"Mail:";
			// 
			// customerBirthLabel
			// 
			this->customerBirthLabel->AutoSize = true;
			this->customerBirthLabel->Location = System::Drawing::Point(59, 84);
			this->customerBirthLabel->Name = L"customerBirthLabel";
			this->customerBirthLabel->Size = System::Drawing::Size(58, 16);
			this->customerBirthLabel->TabIndex = 8;
			this->customerBirthLabel->Text = L"Né(e) le:";
			// 
			// customerFNameLabel
			// 
			this->customerFNameLabel->AutoSize = true;
			this->customerFNameLabel->Location = System::Drawing::Point(290, 37);
			this->customerFNameLabel->Name = L"customerFNameLabel";
			this->customerFNameLabel->Size = System::Drawing::Size(57, 16);
			this->customerFNameLabel->TabIndex = 7;
			this->customerFNameLabel->Text = L"Prénom:";
			// 
			// customerLNameLabel
			// 
			this->customerLNameLabel->AutoSize = true;
			this->customerLNameLabel->Location = System::Drawing::Point(59, 37);
			this->customerLNameLabel->Name = L"customerLNameLabel";
			this->customerLNameLabel->Size = System::Drawing::Size(39, 16);
			this->customerLNameLabel->TabIndex = 6;
			this->customerLNameLabel->Text = L"Nom:";
			// 
			// customerFNameInput
			// 
			this->customerFNameInput->AcceptsTab = true;
			this->customerFNameInput->Location = System::Drawing::Point(349, 34);
			this->customerFNameInput->Name = L"customerFNameInput";
			this->customerFNameInput->Size = System::Drawing::Size(123, 22);
			this->customerFNameInput->TabIndex = 1;
			this->customerFNameInput->TabStop = false;
			// 
			// customerLNameInput
			// 
			this->customerLNameInput->AcceptsTab = true;
			this->customerLNameInput->Location = System::Drawing::Point(101, 34);
			this->customerLNameInput->Name = L"customerLNameInput";
			this->customerLNameInput->Size = System::Drawing::Size(123, 22);
			this->customerLNameInput->TabIndex = 0;
			this->customerLNameInput->TabStop = false;
			// 
			// groupBox7
			// 
			this->groupBox7->Location = System::Drawing::Point(0, 431);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(390, 49);
			this->groupBox7->TabIndex = 3;
			this->groupBox7->TabStop = false;
			// 
			// ordersGroup
			// 
			this->ordersGroup->Controls->Add(this->ordersEmitYearInput);
			this->ordersGroup->Controls->Add(this->ordersEmitMonthInput);
			this->ordersGroup->Controls->Add(this->ordersEmitDayInput);
			this->ordersGroup->Controls->Add(this->ordersEmitSlash2);
			this->ordersGroup->Controls->Add(this->ordersEmitSlash1);
			this->ordersGroup->Controls->Add(this->ordersDeliveryYearInput);
			this->ordersGroup->Controls->Add(this->ordersDeliveryMonthInput);
			this->ordersGroup->Controls->Add(this->ordersDeliveryDayInput);
			this->ordersGroup->Controls->Add(this->ordersDdeliverySlash2);
			this->ordersGroup->Controls->Add(this->ordersDeliverySlash1);
			this->ordersGroup->Controls->Add(this->ordersClientSelector);
			this->ordersGroup->Controls->Add(this->ordersPaymentGroup);
			this->ordersGroup->Controls->Add(this->ordersEmitLabel);
			this->ordersGroup->Controls->Add(this->ordersDeliveryLabel);
			this->ordersGroup->Controls->Add(this->label23);
			this->ordersGroup->Controls->Add(this->groupBox11);
			this->ordersGroup->Location = System::Drawing::Point(950, 443);
			this->ordersGroup->Name = L"ordersGroup";
			this->ordersGroup->Size = System::Drawing::Size(540, 425);
			this->ordersGroup->TabIndex = 5;
			this->ordersGroup->TabStop = false;
			this->ordersGroup->Text = L"Edition de commandes";
			// 
			// ordersEmitYearInput
			// 
			this->ordersEmitYearInput->Location = System::Drawing::Point(402, 368);
			this->ordersEmitYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->ordersEmitYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->ordersEmitYearInput->Name = L"ordersEmitYearInput";
			this->ordersEmitYearInput->Size = System::Drawing::Size(70, 22);
			this->ordersEmitYearInput->TabIndex = 48;
			this->ordersEmitYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// ordersEmitMonthInput
			// 
			this->ordersEmitMonthInput->Location = System::Drawing::Point(329, 368);
			this->ordersEmitMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ordersEmitMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersEmitMonthInput->Name = L"ordersEmitMonthInput";
			this->ordersEmitMonthInput->Size = System::Drawing::Size(50, 22);
			this->ordersEmitMonthInput->TabIndex = 47;
			this->ordersEmitMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersEmitDayInput
			// 
			this->ordersEmitDayInput->Location = System::Drawing::Point(256, 368);
			this->ordersEmitDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->ordersEmitDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersEmitDayInput->Name = L"ordersEmitDayInput";
			this->ordersEmitDayInput->Size = System::Drawing::Size(50, 22);
			this->ordersEmitDayInput->TabIndex = 46;
			this->ordersEmitDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersEmitSlash2
			// 
			this->ordersEmitSlash2->AutoSize = true;
			this->ordersEmitSlash2->Location = System::Drawing::Point(385, 371);
			this->ordersEmitSlash2->Name = L"ordersEmitSlash2";
			this->ordersEmitSlash2->Size = System::Drawing::Size(11, 16);
			this->ordersEmitSlash2->TabIndex = 45;
			this->ordersEmitSlash2->Text = L"/";
			// 
			// ordersEmitSlash1
			// 
			this->ordersEmitSlash1->AutoSize = true;
			this->ordersEmitSlash1->Location = System::Drawing::Point(312, 371);
			this->ordersEmitSlash1->Name = L"ordersEmitSlash1";
			this->ordersEmitSlash1->Size = System::Drawing::Size(11, 16);
			this->ordersEmitSlash1->TabIndex = 44;
			this->ordersEmitSlash1->Text = L"/";
			// 
			// ordersDeliveryYearInput
			// 
			this->ordersDeliveryYearInput->Location = System::Drawing::Point(402, 310);
			this->ordersDeliveryYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->ordersDeliveryYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->ordersDeliveryYearInput->Name = L"ordersDeliveryYearInput";
			this->ordersDeliveryYearInput->Size = System::Drawing::Size(70, 22);
			this->ordersDeliveryYearInput->TabIndex = 43;
			this->ordersDeliveryYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// ordersDeliveryMonthInput
			// 
			this->ordersDeliveryMonthInput->Location = System::Drawing::Point(329, 310);
			this->ordersDeliveryMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ordersDeliveryMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersDeliveryMonthInput->Name = L"ordersDeliveryMonthInput";
			this->ordersDeliveryMonthInput->Size = System::Drawing::Size(50, 22);
			this->ordersDeliveryMonthInput->TabIndex = 42;
			this->ordersDeliveryMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersDeliveryDayInput
			// 
			this->ordersDeliveryDayInput->Location = System::Drawing::Point(256, 310);
			this->ordersDeliveryDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->ordersDeliveryDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersDeliveryDayInput->Name = L"ordersDeliveryDayInput";
			this->ordersDeliveryDayInput->Size = System::Drawing::Size(50, 22);
			this->ordersDeliveryDayInput->TabIndex = 41;
			this->ordersDeliveryDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersDdeliverySlash2
			// 
			this->ordersDdeliverySlash2->AutoSize = true;
			this->ordersDdeliverySlash2->Location = System::Drawing::Point(385, 313);
			this->ordersDdeliverySlash2->Name = L"ordersDdeliverySlash2";
			this->ordersDdeliverySlash2->Size = System::Drawing::Size(11, 16);
			this->ordersDdeliverySlash2->TabIndex = 40;
			this->ordersDdeliverySlash2->Text = L"/";
			// 
			// ordersDeliverySlash1
			// 
			this->ordersDeliverySlash1->AutoSize = true;
			this->ordersDeliverySlash1->Location = System::Drawing::Point(312, 313);
			this->ordersDeliverySlash1->Name = L"ordersDeliverySlash1";
			this->ordersDeliverySlash1->Size = System::Drawing::Size(11, 16);
			this->ordersDeliverySlash1->TabIndex = 39;
			this->ordersDeliverySlash1->Text = L"/";
			// 
			// ordersClientSelector
			// 
			this->ordersClientSelector->FormattingEnabled = true;
			this->ordersClientSelector->ItemHeight = 16;
			this->ordersClientSelector->Location = System::Drawing::Point(59, 40);
			this->ordersClientSelector->Name = L"ordersClientSelector";
			this->ordersClientSelector->Size = System::Drawing::Size(415, 84);
			this->ordersClientSelector->TabIndex = 24;
			// 
			// ordersPaymentGroup
			// 
			this->ordersPaymentGroup->Controls->Add(this->ordersRemovePayment);
			this->ordersPaymentGroup->Controls->Add(this->ordersNewPayment);
			this->ordersPaymentGroup->Controls->Add(this->ordersPaymentDisplay);
			this->ordersPaymentGroup->Location = System::Drawing::Point(59, 133);
			this->ordersPaymentGroup->Name = L"ordersPaymentGroup";
			this->ordersPaymentGroup->Size = System::Drawing::Size(415, 144);
			this->ordersPaymentGroup->TabIndex = 23;
			this->ordersPaymentGroup->TabStop = false;
			this->ordersPaymentGroup->Text = L"Paiements";
			// 
			// ordersRemovePayment
			// 
			this->ordersRemovePayment->Location = System::Drawing::Point(208, 116);
			this->ordersRemovePayment->Name = L"ordersRemovePayment";
			this->ordersRemovePayment->Size = System::Drawing::Size(201, 23);
			this->ordersRemovePayment->TabIndex = 2;
			this->ordersRemovePayment->Text = L"Retirer";
			this->ordersRemovePayment->UseVisualStyleBackColor = true;
			// 
			// ordersNewPayment
			// 
			this->ordersNewPayment->Location = System::Drawing::Point(6, 116);
			this->ordersNewPayment->Name = L"ordersNewPayment";
			this->ordersNewPayment->Size = System::Drawing::Size(196, 23);
			this->ordersNewPayment->TabIndex = 1;
			this->ordersNewPayment->Text = L"Nouveau";
			this->ordersNewPayment->UseVisualStyleBackColor = true;
			// 
			// ordersPaymentDisplay
			// 
			this->ordersPaymentDisplay->BackgroundColor = System::Drawing::SystemColors::Control;
			this->ordersPaymentDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ordersPaymentDisplay->Location = System::Drawing::Point(6, 21);
			this->ordersPaymentDisplay->Name = L"ordersPaymentDisplay";
			this->ordersPaymentDisplay->RowHeadersWidth = 51;
			this->ordersPaymentDisplay->RowTemplate->Height = 24;
			this->ordersPaymentDisplay->Size = System::Drawing::Size(403, 95);
			this->ordersPaymentDisplay->TabIndex = 0;
			// 
			// ordersEmitLabel
			// 
			this->ordersEmitLabel->AutoSize = true;
			this->ordersEmitLabel->Location = System::Drawing::Point(56, 371);
			this->ordersEmitLabel->Name = L"ordersEmitLabel";
			this->ordersEmitLabel->Size = System::Drawing::Size(107, 16);
			this->ordersEmitLabel->TabIndex = 22;
			this->ordersEmitLabel->Text = L"Date d\'émission:";
			// 
			// ordersDeliveryLabel
			// 
			this->ordersDeliveryLabel->AutoSize = true;
			this->ordersDeliveryLabel->Location = System::Drawing::Point(56, 313);
			this->ordersDeliveryLabel->Name = L"ordersDeliveryLabel";
			this->ordersDeliveryLabel->Size = System::Drawing::Size(156, 16);
			this->ordersDeliveryLabel->TabIndex = 16;
			this->ordersDeliveryLabel->Text = L"Date prévue de livraison:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(56, 21);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(95, 16);
			this->label23->TabIndex = 5;
			this->label23->Text = L"Choix du client:";
			// 
			// groupBox11
			// 
			this->groupBox11->Location = System::Drawing::Point(0, 431);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Size = System::Drawing::Size(390, 49);
			this->groupBox11->TabIndex = 3;
			this->groupBox11->TabStop = false;
			// 
			// staffGroup
			// 
			this->staffGroup->Controls->Add(this->staffHiredYearInput);
			this->staffGroup->Controls->Add(this->staffHiredMonthInput);
			this->staffGroup->Controls->Add(this->staffHiredDayInput);
			this->staffGroup->Controls->Add(this->staffHiredSlash2);
			this->staffGroup->Controls->Add(this->staffHiredSlash1);
			this->staffGroup->Controls->Add(this->staffSuperiorLabel);
			this->staffGroup->Controls->Add(this->staffSuperiorSelector);
			this->staffGroup->Controls->Add(this->staffAddressGroup);
			this->staffGroup->Controls->Add(this->staffHiredLabel);
			this->staffGroup->Controls->Add(this->staffFNameLabel);
			this->staffGroup->Controls->Add(this->staffLNameLabel);
			this->staffGroup->Controls->Add(this->staffFNameInput);
			this->staffGroup->Controls->Add(this->staffLNameInput);
			this->staffGroup->Controls->Add(this->groupBox16);
			this->staffGroup->Location = System::Drawing::Point(1496, 12);
			this->staffGroup->Name = L"staffGroup";
			this->staffGroup->Size = System::Drawing::Size(536, 425);
			this->staffGroup->TabIndex = 6;
			this->staffGroup->TabStop = false;
			this->staffGroup->Text = L"Edition du personnel";
			// 
			// staffHiredYearInput
			// 
			this->staffHiredYearInput->Location = System::Drawing::Point(394, 112);
			this->staffHiredYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->staffHiredYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->staffHiredYearInput->Name = L"staffHiredYearInput";
			this->staffHiredYearInput->Size = System::Drawing::Size(70, 22);
			this->staffHiredYearInput->TabIndex = 33;
			this->staffHiredYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// staffHiredMonthInput
			// 
			this->staffHiredMonthInput->Location = System::Drawing::Point(321, 112);
			this->staffHiredMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->staffHiredMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->staffHiredMonthInput->Name = L"staffHiredMonthInput";
			this->staffHiredMonthInput->Size = System::Drawing::Size(50, 22);
			this->staffHiredMonthInput->TabIndex = 32;
			this->staffHiredMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// staffHiredDayInput
			// 
			this->staffHiredDayInput->Location = System::Drawing::Point(248, 112);
			this->staffHiredDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->staffHiredDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->staffHiredDayInput->Name = L"staffHiredDayInput";
			this->staffHiredDayInput->Size = System::Drawing::Size(50, 22);
			this->staffHiredDayInput->TabIndex = 31;
			this->staffHiredDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// staffHiredSlash2
			// 
			this->staffHiredSlash2->AutoSize = true;
			this->staffHiredSlash2->Location = System::Drawing::Point(377, 115);
			this->staffHiredSlash2->Name = L"staffHiredSlash2";
			this->staffHiredSlash2->Size = System::Drawing::Size(11, 16);
			this->staffHiredSlash2->TabIndex = 30;
			this->staffHiredSlash2->Text = L"/";
			// 
			// staffHiredSlash1
			// 
			this->staffHiredSlash1->AutoSize = true;
			this->staffHiredSlash1->Location = System::Drawing::Point(304, 115);
			this->staffHiredSlash1->Name = L"staffHiredSlash1";
			this->staffHiredSlash1->Size = System::Drawing::Size(11, 16);
			this->staffHiredSlash1->TabIndex = 29;
			this->staffHiredSlash1->Text = L"/";
			// 
			// staffSuperiorLabel
			// 
			this->staffSuperiorLabel->AutoSize = true;
			this->staffSuperiorLabel->Location = System::Drawing::Point(76, 277);
			this->staffSuperiorLabel->Name = L"staffSuperiorLabel";
			this->staffSuperiorLabel->Size = System::Drawing::Size(145, 16);
			this->staffSuperiorLabel->TabIndex = 26;
			this->staffSuperiorLabel->Text = L"Supérieur hiérarchique:";
			// 
			// staffSuperiorSelector
			// 
			this->staffSuperiorSelector->FormattingEnabled = true;
			this->staffSuperiorSelector->ItemHeight = 16;
			this->staffSuperiorSelector->Location = System::Drawing::Point(62, 306);
			this->staffSuperiorSelector->Name = L"staffSuperiorSelector";
			this->staffSuperiorSelector->Size = System::Drawing::Size(407, 84);
			this->staffSuperiorSelector->TabIndex = 25;
			// 
			// staffAddressGroup
			// 
			this->staffAddressGroup->Controls->Add(this->staffAddressCityInput);
			this->staffAddressGroup->Controls->Add(this->staffAddressCityCodeInput);
			this->staffAddressGroup->Controls->Add(this->staffAddressCityCodeLabel);
			this->staffAddressGroup->Controls->Add(this->staffAddressCityLabel);
			this->staffAddressGroup->Controls->Add(this->staffAddressStreetLabel);
			this->staffAddressGroup->Controls->Add(this->staffAddressStreetInput);
			this->staffAddressGroup->Controls->Add(this->staffAddressNumberInput);
			this->staffAddressGroup->Controls->Add(this->staffAddressNumberLabel);
			this->staffAddressGroup->Location = System::Drawing::Point(53, 158);
			this->staffAddressGroup->Name = L"staffAddressGroup";
			this->staffAddressGroup->Size = System::Drawing::Size(413, 100);
			this->staffAddressGroup->TabIndex = 18;
			this->staffAddressGroup->TabStop = false;
			this->staffAddressGroup->Text = L"Adresse";
			// 
			// staffAddressCityInput
			// 
			this->staffAddressCityInput->FormattingEnabled = true;
			this->staffAddressCityInput->Location = System::Drawing::Point(61, 57);
			this->staffAddressCityInput->Name = L"staffAddressCityInput";
			this->staffAddressCityInput->Size = System::Drawing::Size(115, 24);
			this->staffAddressCityInput->TabIndex = 8;
			// 
			// staffAddressCityCodeInput
			// 
			this->staffAddressCityCodeInput->Location = System::Drawing::Point(303, 57);
			this->staffAddressCityCodeInput->MaxLength = 6;
			this->staffAddressCityCodeInput->Name = L"staffAddressCityCodeInput";
			this->staffAddressCityCodeInput->Size = System::Drawing::Size(76, 22);
			this->staffAddressCityCodeInput->TabIndex = 7;
			// 
			// staffAddressCityCodeLabel
			// 
			this->staffAddressCityCodeLabel->AutoSize = true;
			this->staffAddressCityCodeLabel->Location = System::Drawing::Point(214, 60);
			this->staffAddressCityCodeLabel->Name = L"staffAddressCityCodeLabel";
			this->staffAddressCityCodeLabel->Size = System::Drawing::Size(83, 16);
			this->staffAddressCityCodeLabel->TabIndex = 5;
			this->staffAddressCityCodeLabel->Text = L"Code postal:";
			// 
			// staffAddressCityLabel
			// 
			this->staffAddressCityLabel->AutoSize = true;
			this->staffAddressCityLabel->Location = System::Drawing::Point(18, 60);
			this->staffAddressCityLabel->Name = L"staffAddressCityLabel";
			this->staffAddressCityLabel->Size = System::Drawing::Size(36, 16);
			this->staffAddressCityLabel->TabIndex = 4;
			this->staffAddressCityLabel->Text = L"Ville:";
			// 
			// staffAddressStreetLabel
			// 
			this->staffAddressStreetLabel->AutoSize = true;
			this->staffAddressStreetLabel->Location = System::Drawing::Point(212, 28);
			this->staffAddressStreetLabel->Name = L"staffAddressStreetLabel";
			this->staffAddressStreetLabel->Size = System::Drawing::Size(80, 16);
			this->staffAddressStreetLabel->TabIndex = 3;
			this->staffAddressStreetLabel->Text = L"Nom de rue:";
			// 
			// staffAddressStreetInput
			// 
			this->staffAddressStreetInput->Location = System::Drawing::Point(298, 25);
			this->staffAddressStreetInput->Name = L"staffAddressStreetInput";
			this->staffAddressStreetInput->Size = System::Drawing::Size(100, 22);
			this->staffAddressStreetInput->TabIndex = 2;
			// 
			// staffAddressNumberInput
			// 
			this->staffAddressNumberInput->Location = System::Drawing::Point(121, 25);
			this->staffAddressNumberInput->Name = L"staffAddressNumberInput";
			this->staffAddressNumberInput->Size = System::Drawing::Size(45, 22);
			this->staffAddressNumberInput->TabIndex = 1;
			// 
			// staffAddressNumberLabel
			// 
			this->staffAddressNumberLabel->AutoSize = true;
			this->staffAddressNumberLabel->Location = System::Drawing::Point(18, 28);
			this->staffAddressNumberLabel->Name = L"staffAddressNumberLabel";
			this->staffAddressNumberLabel->Size = System::Drawing::Size(97, 16);
			this->staffAddressNumberLabel->TabIndex = 0;
			this->staffAddressNumberLabel->Text = L"N° de bâtiment:";
			// 
			// staffHiredLabel
			// 
			this->staffHiredLabel->AutoSize = true;
			this->staffHiredLabel->Location = System::Drawing::Point(59, 112);
			this->staffHiredLabel->Name = L"staffHiredLabel";
			this->staffHiredLabel->Size = System::Drawing::Size(117, 16);
			this->staffHiredLabel->TabIndex = 17;
			this->staffHiredLabel->Text = L"Date d\'embauche:";
			// 
			// staffFNameLabel
			// 
			this->staffFNameLabel->AutoSize = true;
			this->staffFNameLabel->Location = System::Drawing::Point(284, 53);
			this->staffFNameLabel->Name = L"staffFNameLabel";
			this->staffFNameLabel->Size = System::Drawing::Size(57, 16);
			this->staffFNameLabel->TabIndex = 11;
			this->staffFNameLabel->Text = L"Prénom:";
			// 
			// staffLNameLabel
			// 
			this->staffLNameLabel->AutoSize = true;
			this->staffLNameLabel->Location = System::Drawing::Point(59, 53);
			this->staffLNameLabel->Name = L"staffLNameLabel";
			this->staffLNameLabel->Size = System::Drawing::Size(39, 16);
			this->staffLNameLabel->TabIndex = 10;
			this->staffLNameLabel->Text = L"Nom:";
			// 
			// staffFNameInput
			// 
			this->staffFNameInput->AcceptsTab = true;
			this->staffFNameInput->Location = System::Drawing::Point(343, 50);
			this->staffFNameInput->Name = L"staffFNameInput";
			this->staffFNameInput->Size = System::Drawing::Size(123, 22);
			this->staffFNameInput->TabIndex = 9;
			this->staffFNameInput->TabStop = false;
			// 
			// staffLNameInput
			// 
			this->staffLNameInput->AcceptsTab = true;
			this->staffLNameInput->Location = System::Drawing::Point(101, 50);
			this->staffLNameInput->Name = L"staffLNameInput";
			this->staffLNameInput->Size = System::Drawing::Size(123, 22);
			this->staffLNameInput->TabIndex = 8;
			this->staffLNameInput->TabStop = false;
			// 
			// groupBox16
			// 
			this->groupBox16->Location = System::Drawing::Point(0, 431);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Size = System::Drawing::Size(390, 49);
			this->groupBox16->TabIndex = 3;
			this->groupBox16->TabStop = false;
			// 
			// statsAverageBasketButton
			// 
			this->statsAverageBasketButton->Location = System::Drawing::Point(22, 89);
			this->statsAverageBasketButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsAverageBasketButton->Name = L"statsAverageBasketButton";
			this->statsAverageBasketButton->Size = System::Drawing::Size(110, 41);
			this->statsAverageBasketButton->TabIndex = 4;
			this->statsAverageBasketButton->Text = L"Panier moyen";
			this->statsAverageBasketButton->UseVisualStyleBackColor = true;
			// 
			// statsTurnoverButton
			// 
			this->statsTurnoverButton->Location = System::Drawing::Point(23, 56);
			this->statsTurnoverButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsTurnoverButton->Name = L"statsTurnoverButton";
			this->statsTurnoverButton->Size = System::Drawing::Size(74, 23);
			this->statsTurnoverButton->TabIndex = 5;
			this->statsTurnoverButton->Text = L"Calculer";
			this->statsTurnoverButton->UseVisualStyleBackColor = true;
			this->statsTurnoverButton->Click += gcnew System::EventHandler(this, &Root::statsTurnoverButton_Click);
			// 
			// statsMonthLabel
			// 
			this->statsMonthLabel->AutoSize = true;
			this->statsMonthLabel->Location = System::Drawing::Point(38, 22);
			this->statsMonthLabel->Name = L"statsMonthLabel";
			this->statsMonthLabel->Size = System::Drawing::Size(42, 16);
			this->statsMonthLabel->TabIndex = 7;
			this->statsMonthLabel->Text = L"Mois: ";
			this->statsMonthLabel->Click += gcnew System::EventHandler(this, &Root::label1_Click);
			// 
			// statsTotalAmountButton
			// 
			this->statsTotalAmountButton->Location = System::Drawing::Point(9, 75);
			this->statsTotalAmountButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsTotalAmountButton->Name = L"statsTotalAmountButton";
			this->statsTotalAmountButton->Size = System::Drawing::Size(97, 24);
			this->statsTotalAmountButton->TabIndex = 9;
			this->statsTotalAmountButton->Text = L"Calculer";
			this->statsTotalAmountButton->UseVisualStyleBackColor = true;
			// 
			// statsCustomerNameLabel
			// 
			this->statsCustomerNameLabel->AutoSize = true;
			this->statsCustomerNameLabel->Location = System::Drawing::Point(6, 41);
			this->statsCustomerNameLabel->Name = L"statsCustomerNameLabel";
			this->statsCustomerNameLabel->Size = System::Drawing::Size(76, 16);
			this->statsCustomerNameLabel->TabIndex = 10;
			this->statsCustomerNameLabel->Text = L"Nom client: ";
			// 
			// statsCustomerNameTextbox
			// 
			this->statsCustomerNameTextbox->Location = System::Drawing::Point(103, 15);
			this->statsCustomerNameTextbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsCustomerNameTextbox->Name = L"statsCustomerNameTextbox";
			this->statsCustomerNameTextbox->Size = System::Drawing::Size(123, 22);
			this->statsCustomerNameTextbox->TabIndex = 11;
			// 
			// statsCustomerFirstnameLabel
			// 
			this->statsCustomerFirstnameLabel->AutoSize = true;
			this->statsCustomerFirstnameLabel->Location = System::Drawing::Point(3, 18);
			this->statsCustomerFirstnameLabel->Name = L"statsCustomerFirstnameLabel";
			this->statsCustomerFirstnameLabel->Size = System::Drawing::Size(94, 16);
			this->statsCustomerFirstnameLabel->TabIndex = 12;
			this->statsCustomerFirstnameLabel->Text = L"Prenom client: ";
			// 
			// statsCustomerFirtsnameTextbox
			// 
			this->statsCustomerFirtsnameTextbox->Location = System::Drawing::Point(105, 41);
			this->statsCustomerFirtsnameTextbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsCustomerFirtsnameTextbox->Name = L"statsCustomerFirtsnameTextbox";
			this->statsCustomerFirtsnameTextbox->Size = System::Drawing::Size(121, 22);
			this->statsCustomerFirtsnameTextbox->TabIndex = 13;
			// 
			// statsMonthChoiceTurnover
			// 
			this->statsMonthChoiceTurnover->Location = System::Drawing::Point(112, 20);
			this->statsMonthChoiceTurnover->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsMonthChoiceTurnover->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->statsMonthChoiceTurnover->Name = L"statsMonthChoiceTurnover";
			this->statsMonthChoiceTurnover->Size = System::Drawing::Size(89, 22);
			this->statsMonthChoiceTurnover->TabIndex = 14;
			// 
			// statsStockMarketingValueButton
			// 
			this->statsStockMarketingValueButton->Location = System::Drawing::Point(22, 26);
			this->statsStockMarketingValueButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsStockMarketingValueButton->Name = L"statsStockMarketingValueButton";
			this->statsStockMarketingValueButton->Size = System::Drawing::Size(110, 40);
			this->statsStockMarketingValueButton->TabIndex = 17;
			this->statsStockMarketingValueButton->Text = L"Valeur commerciale stock";
			this->statsStockMarketingValueButton->UseVisualStyleBackColor = true;
			// 
			// statsStockPurchaseValueButton
			// 
			this->statsStockPurchaseValueButton->Location = System::Drawing::Point(22, 158);
			this->statsStockPurchaseValueButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsStockPurchaseValueButton->Name = L"statsStockPurchaseValueButton";
			this->statsStockPurchaseValueButton->Size = System::Drawing::Size(112, 40);
			this->statsStockPurchaseValueButton->TabIndex = 18;
			this->statsStockPurchaseValueButton->Text = L"Valeur achat stock";
			this->statsStockPurchaseValueButton->UseVisualStyleBackColor = true;
			// 
			// statsSimulationButton
			// 
			this->statsSimulationButton->Location = System::Drawing::Point(43, 176);
			this->statsSimulationButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsSimulationButton->Name = L"statsSimulationButton";
			this->statsSimulationButton->Size = System::Drawing::Size(170, 31);
			this->statsSimulationButton->TabIndex = 19;
			this->statsSimulationButton->Text = L"Simuler";
			this->statsSimulationButton->UseVisualStyleBackColor = true;
			// 
			// statsGroup
			// 
			this->statsGroup->Controls->Add(this->groupBox6);
			this->statsGroup->Controls->Add(this->groupBox8);
			this->statsGroup->Controls->Add(this->groupBox5);
			this->statsGroup->Controls->Add(this->groupBox4);
			this->statsGroup->Controls->Add(this->groupBox3);
			this->statsGroup->Controls->Add(this->groupBox2);
			this->statsGroup->Controls->Add(this->groupBox1);
			this->statsGroup->Location = System::Drawing::Point(1522, 498);
			this->statsGroup->Name = L"statsGroup";
			this->statsGroup->Size = System::Drawing::Size(150, 144);
			this->statsGroup->TabIndex = 0;
			this->statsGroup->TabStop = false;
			this->statsGroup->Text = L"Statistiques";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->dataGridView2);
			this->groupBox6->Location = System::Drawing::Point(16, 240);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(239, 195);
			this->groupBox6->TabIndex = 36;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"10 articles les moins vendus";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(6, 22);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(227, 167);
			this->dataGridView2->TabIndex = 0;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->dataGridView3);
			this->groupBox8->Location = System::Drawing::Point(506, 240);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(395, 195);
			this->groupBox8->TabIndex = 36;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Produits sous leur seuil de réapprovisionnement";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(6, 22);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(389, 167);
			this->dataGridView3->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->dataGridView1);
			this->groupBox5->Location = System::Drawing::Point(261, 240);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(239, 195);
			this->groupBox5->TabIndex = 36;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"10 articles les plus vendus";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 22);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(227, 167);
			this->dataGridView1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label3);
			this->groupBox4->Controls->Add(this->label2);
			this->groupBox4->Controls->Add(this->label1);
			this->groupBox4->Controls->Add(this->statsStockPurchaseValueButton);
			this->groupBox4->Controls->Add(this->statsAverageBasketButton);
			this->groupBox4->Controls->Add(this->statsStockMarketingValueButton);
			this->groupBox4->Location = System::Drawing::Point(261, 21);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(379, 213);
			this->groupBox4->TabIndex = 35;
			this->groupBox4->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(149, 171);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 16);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Résultat:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(149, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 16);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Résultat:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(149, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 16);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Résultat:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->statsTVAValueLabel);
			this->groupBox3->Controls->Add(this->statsComMarginValueLabel);
			this->groupBox3->Controls->Add(this->statsComDiscountValueLabel);
			this->groupBox3->Controls->Add(this->statsSimulationButton);
			this->groupBox3->Controls->Add(this->statsUnknownMarkdownPercentLabel);
			this->groupBox3->Controls->Add(this->statsUnknownMarkdownLabel);
			this->groupBox3->Controls->Add(this->statsComDiscountPercentLabel);
			this->groupBox3->Controls->Add(this->statsUnknownMarkdownNumericUpDown);
			this->groupBox3->Controls->Add(this->statsComMarginPercentLabel);
			this->groupBox3->Controls->Add(this->statsTVAValueNumericUpDown);
			this->groupBox3->Controls->Add(this->statsTVAPercentLabel);
			this->groupBox3->Controls->Add(this->statsComMarginValueNumericUpDown);
			this->groupBox3->Controls->Add(this->statsComDiscountValueNumericUpDown);
			this->groupBox3->Location = System::Drawing::Point(651, 21);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(250, 213);
			this->groupBox3->TabIndex = 34;
			this->groupBox3->TabStop = false;
			// 
			// statsTVAValueLabel
			// 
			this->statsTVAValueLabel->AutoSize = true;
			this->statsTVAValueLabel->Location = System::Drawing::Point(6, 35);
			this->statsTVAValueLabel->Name = L"statsTVAValueLabel";
			this->statsTVAValueLabel->Size = System::Drawing::Size(70, 16);
			this->statsTVAValueLabel->TabIndex = 22;
			this->statsTVAValueLabel->Text = L"Taux TVA:";
			this->statsTVAValueLabel->Click += gcnew System::EventHandler(this, &Root::label1_Click_1);
			// 
			// statsComMarginValueLabel
			// 
			this->statsComMarginValueLabel->AutoSize = true;
			this->statsComMarginValueLabel->Location = System::Drawing::Point(6, 66);
			this->statsComMarginValueLabel->Name = L"statsComMarginValueLabel";
			this->statsComMarginValueLabel->Size = System::Drawing::Size(130, 16);
			this->statsComMarginValueLabel->TabIndex = 23;
			this->statsComMarginValueLabel->Text = L"Marge commerciale:";
			this->statsComMarginValueLabel->Click += gcnew System::EventHandler(this, &Root::label2_Click);
			// 
			// statsComDiscountValueLabel
			// 
			this->statsComDiscountValueLabel->AutoSize = true;
			this->statsComDiscountValueLabel->Location = System::Drawing::Point(6, 100);
			this->statsComDiscountValueLabel->Name = L"statsComDiscountValueLabel";
			this->statsComDiscountValueLabel->Size = System::Drawing::Size(138, 16);
			this->statsComDiscountValueLabel->TabIndex = 24;
			this->statsComDiscountValueLabel->Text = L"Remise commerciale:";
			// 
			// statsUnknownMarkdownPercentLabel
			// 
			this->statsUnknownMarkdownPercentLabel->AutoSize = true;
			this->statsUnknownMarkdownPercentLabel->Location = System::Drawing::Point(209, 137);
			this->statsUnknownMarkdownPercentLabel->Name = L"statsUnknownMarkdownPercentLabel";
			this->statsUnknownMarkdownPercentLabel->Size = System::Drawing::Size(19, 16);
			this->statsUnknownMarkdownPercentLabel->TabIndex = 31;
			this->statsUnknownMarkdownPercentLabel->Text = L"%";
			// 
			// statsUnknownMarkdownLabel
			// 
			this->statsUnknownMarkdownLabel->AutoSize = true;
			this->statsUnknownMarkdownLabel->Location = System::Drawing::Point(6, 137);
			this->statsUnknownMarkdownLabel->Name = L"statsUnknownMarkdownLabel";
			this->statsUnknownMarkdownLabel->Size = System::Drawing::Size(131, 16);
			this->statsUnknownMarkdownLabel->TabIndex = 25;
			this->statsUnknownMarkdownLabel->Text = L"Démarque inconnue:";
			this->statsUnknownMarkdownLabel->Click += gcnew System::EventHandler(this, &Root::label4_Click);
			// 
			// statsComDiscountPercentLabel
			// 
			this->statsComDiscountPercentLabel->AutoSize = true;
			this->statsComDiscountPercentLabel->Location = System::Drawing::Point(208, 100);
			this->statsComDiscountPercentLabel->Name = L"statsComDiscountPercentLabel";
			this->statsComDiscountPercentLabel->Size = System::Drawing::Size(19, 16);
			this->statsComDiscountPercentLabel->TabIndex = 29;
			this->statsComDiscountPercentLabel->Text = L"%";
			// 
			// statsUnknownMarkdownNumericUpDown
			// 
			this->statsUnknownMarkdownNumericUpDown->Location = System::Drawing::Point(150, 133);
			this->statsUnknownMarkdownNumericUpDown->Name = L"statsUnknownMarkdownNumericUpDown";
			this->statsUnknownMarkdownNumericUpDown->Size = System::Drawing::Size(53, 22);
			this->statsUnknownMarkdownNumericUpDown->TabIndex = 30;
			this->statsUnknownMarkdownNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// statsComMarginPercentLabel
			// 
			this->statsComMarginPercentLabel->AutoSize = true;
			this->statsComMarginPercentLabel->Location = System::Drawing::Point(209, 66);
			this->statsComMarginPercentLabel->Name = L"statsComMarginPercentLabel";
			this->statsComMarginPercentLabel->Size = System::Drawing::Size(19, 16);
			this->statsComMarginPercentLabel->TabIndex = 27;
			this->statsComMarginPercentLabel->Text = L"%";
			// 
			// statsTVAValueNumericUpDown
			// 
			this->statsTVAValueNumericUpDown->Location = System::Drawing::Point(150, 32);
			this->statsTVAValueNumericUpDown->Name = L"statsTVAValueNumericUpDown";
			this->statsTVAValueNumericUpDown->Size = System::Drawing::Size(53, 22);
			this->statsTVAValueNumericUpDown->TabIndex = 22;
			this->statsTVAValueNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// statsTVAPercentLabel
			// 
			this->statsTVAPercentLabel->AutoSize = true;
			this->statsTVAPercentLabel->Location = System::Drawing::Point(209, 36);
			this->statsTVAPercentLabel->Name = L"statsTVAPercentLabel";
			this->statsTVAPercentLabel->Size = System::Drawing::Size(19, 16);
			this->statsTVAPercentLabel->TabIndex = 22;
			this->statsTVAPercentLabel->Text = L"%";
			// 
			// statsComMarginValueNumericUpDown
			// 
			this->statsComMarginValueNumericUpDown->Location = System::Drawing::Point(150, 64);
			this->statsComMarginValueNumericUpDown->Name = L"statsComMarginValueNumericUpDown";
			this->statsComMarginValueNumericUpDown->Size = System::Drawing::Size(53, 22);
			this->statsComMarginValueNumericUpDown->TabIndex = 26;
			this->statsComMarginValueNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// statsComDiscountValueNumericUpDown
			// 
			this->statsComDiscountValueNumericUpDown->Location = System::Drawing::Point(150, 98);
			this->statsComDiscountValueNumericUpDown->Name = L"statsComDiscountValueNumericUpDown";
			this->statsComDiscountValueNumericUpDown->Size = System::Drawing::Size(53, 22);
			this->statsComDiscountValueNumericUpDown->TabIndex = 28;
			this->statsComDiscountValueNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->statsCustomerFirstnameLabel);
			this->groupBox2->Controls->Add(this->statsCustomerNameLabel);
			this->groupBox2->Controls->Add(this->statsCustomerNameTextbox);
			this->groupBox2->Controls->Add(this->statsCustomerFirtsnameTextbox);
			this->groupBox2->Controls->Add(this->statsTotalAmountButton);
			this->groupBox2->Location = System::Drawing::Point(16, 112);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(239, 122);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Montant total achat client";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->statsTurnoverButton);
			this->groupBox1->Controls->Add(this->statsMonthChoiceTurnover);
			this->groupBox1->Controls->Add(this->statsMonthLabel);
			this->groupBox1->Location = System::Drawing::Point(16, 21);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(239, 85);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Chiffre d\'affaires";
			// 
			// groupBox19
			// 
			this->groupBox19->Location = System::Drawing::Point(0, 431);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(390, 49);
			this->groupBox19->TabIndex = 3;
			this->groupBox19->TabStop = false;
			// 
			// productNameLabel
			// 
			this->productNameLabel->AutoSize = true;
			this->productNameLabel->Location = System::Drawing::Point(98, 37);
			this->productNameLabel->Name = L"productNameLabel";
			this->productNameLabel->Size = System::Drawing::Size(39, 16);
			this->productNameLabel->TabIndex = 4;
			this->productNameLabel->Text = L"Nom:";
			// 
			// productNameInput
			// 
			this->productNameInput->Location = System::Drawing::Point(248, 34);
			this->productNameInput->Name = L"productNameInput";
			this->productNameInput->Size = System::Drawing::Size(145, 22);
			this->productNameInput->TabIndex = 5;
			// 
			// productUHTPriceLabel
			// 
			this->productUHTPriceLabel->AutoSize = true;
			this->productUHTPriceLabel->Location = System::Drawing::Point(89, 84);
			this->productUHTPriceLabel->Name = L"productUHTPriceLabel";
			this->productUHTPriceLabel->Size = System::Drawing::Size(142, 16);
			this->productUHTPriceLabel->TabIndex = 6;
			this->productUHTPriceLabel->Text = L"Prix unitaire hors taxes:";
			// 
			// productUHTPriceCurrencySelector
			// 
			this->productUHTPriceCurrencySelector->FormattingEnabled = true;
			this->productUHTPriceCurrencySelector->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->productUHTPriceCurrencySelector->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"€", L"$" });
			this->productUHTPriceCurrencySelector->Location = System::Drawing::Point(366, 81);
			this->productUHTPriceCurrencySelector->Name = L"productUHTPriceCurrencySelector";
			this->productUHTPriceCurrencySelector->Size = System::Drawing::Size(55, 24);
			this->productUHTPriceCurrencySelector->TabIndex = 8;
			this->productUHTPriceCurrencySelector->Text = L"€";
			// 
			// productPurchasePriceLabel
			// 
			this->productPurchasePriceLabel->AutoSize = true;
			this->productPurchasePriceLabel->Location = System::Drawing::Point(87, 138);
			this->productPurchasePriceLabel->Name = L"productPurchasePriceLabel";
			this->productPurchasePriceLabel->Size = System::Drawing::Size(125, 16);
			this->productPurchasePriceLabel->TabIndex = 9;
			this->productPurchasePriceLabel->Text = L"Prix unitaire d\'achat:";
			// 
			// productPurchasePriceCurrencySelector
			// 
			this->productPurchasePriceCurrencySelector->FormattingEnabled = true;
			this->productPurchasePriceCurrencySelector->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->productPurchasePriceCurrencySelector->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"€", L"$" });
			this->productPurchasePriceCurrencySelector->Location = System::Drawing::Point(390, 136);
			this->productPurchasePriceCurrencySelector->Name = L"productPurchasePriceCurrencySelector";
			this->productPurchasePriceCurrencySelector->Size = System::Drawing::Size(55, 24);
			this->productPurchasePriceCurrencySelector->TabIndex = 11;
			this->productPurchasePriceCurrencySelector->Text = L"€";
			// 
			// productUHTPriceInput
			// 
			this->productUHTPriceInput->DecimalPlaces = 3;
			this->productUHTPriceInput->Location = System::Drawing::Point(237, 82);
			this->productUHTPriceInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productUHTPriceInput->Name = L"productUHTPriceInput";
			this->productUHTPriceInput->Size = System::Drawing::Size(120, 22);
			this->productUHTPriceInput->TabIndex = 12;
			this->productUHTPriceInput->ThousandsSeparator = true;
			// 
			// productPurchasePriceInput
			// 
			this->productPurchasePriceInput->DecimalPlaces = 3;
			this->productPurchasePriceInput->Location = System::Drawing::Point(262, 137);
			this->productPurchasePriceInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productPurchasePriceInput->Name = L"productPurchasePriceInput";
			this->productPurchasePriceInput->Size = System::Drawing::Size(120, 22);
			this->productPurchasePriceInput->TabIndex = 13;
			this->productPurchasePriceInput->ThousandsSeparator = true;
			// 
			// productStockInput
			// 
			this->productStockInput->Location = System::Drawing::Point(276, 187);
			this->productStockInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productStockInput->Name = L"productStockInput";
			this->productStockInput->Size = System::Drawing::Size(84, 22);
			this->productStockInput->TabIndex = 14;
			this->productStockInput->ThousandsSeparator = true;
			// 
			// productStockLabel
			// 
			this->productStockLabel->AutoSize = true;
			this->productStockLabel->Location = System::Drawing::Point(85, 189);
			this->productStockLabel->Name = L"productStockLabel";
			this->productStockLabel->Size = System::Drawing::Size(112, 16);
			this->productStockLabel->TabIndex = 15;
			this->productStockLabel->Text = L"Quantité en stock:";
			// 
			// productTaxesLabel
			// 
			this->productTaxesLabel->AutoSize = true;
			this->productTaxesLabel->Location = System::Drawing::Point(87, 292);
			this->productTaxesLabel->Name = L"productTaxesLabel";
			this->productTaxesLabel->Size = System::Drawing::Size(89, 16);
			this->productTaxesLabel->TabIndex = 16;
			this->productTaxesLabel->Text = L"Taux de TVA:";
			// 
			// productTaxesInput
			// 
			this->productTaxesInput->Location = System::Drawing::Point(262, 290);
			this->productTaxesInput->Name = L"productTaxesInput";
			this->productTaxesInput->Size = System::Drawing::Size(53, 22);
			this->productTaxesInput->TabIndex = 17;
			this->productTaxesInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// productTaxesPercent
			// 
			this->productTaxesPercent->AutoSize = true;
			this->productTaxesPercent->Location = System::Drawing::Point(321, 294);
			this->productTaxesPercent->Name = L"productTaxesPercent";
			this->productTaxesPercent->Size = System::Drawing::Size(19, 16);
			this->productTaxesPercent->TabIndex = 18;
			this->productTaxesPercent->Text = L"%";
			// 
			// productDiscountGroup
			// 
			this->productDiscountGroup->Controls->Add(this->productBaseDiscountPercent);
			this->productDiscountGroup->Controls->Add(this->productCountWeightInput);
			this->productDiscountGroup->Controls->Add(this->productBaseDiscountInput);
			this->productDiscountGroup->Controls->Add(this->productCountWeightLabel);
			this->productDiscountGroup->Controls->Add(this->productBaseDiscountLabel);
			this->productDiscountGroup->Location = System::Drawing::Point(62, 332);
			this->productDiscountGroup->Name = L"productDiscountGroup";
			this->productDiscountGroup->Size = System::Drawing::Size(414, 72);
			this->productDiscountGroup->TabIndex = 19;
			this->productDiscountGroup->TabStop = false;
			this->productDiscountGroup->Text = L"Remise";
			// 
			// productBaseDiscountPercent
			// 
			this->productBaseDiscountPercent->AutoSize = true;
			this->productBaseDiscountPercent->Location = System::Drawing::Point(259, 18);
			this->productBaseDiscountPercent->Name = L"productBaseDiscountPercent";
			this->productBaseDiscountPercent->Size = System::Drawing::Size(19, 16);
			this->productBaseDiscountPercent->TabIndex = 20;
			this->productBaseDiscountPercent->Text = L"%";
			// 
			// productCountWeightInput
			// 
			this->productCountWeightInput->DecimalPlaces = 2;
			this->productCountWeightInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->productCountWeightInput->Location = System::Drawing::Point(283, 44);
			this->productCountWeightInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->productCountWeightInput->Name = L"productCountWeightInput";
			this->productCountWeightInput->Size = System::Drawing::Size(59, 22);
			this->productCountWeightInput->TabIndex = 19;
			// 
			// productBaseDiscountInput
			// 
			this->productBaseDiscountInput->Location = System::Drawing::Point(197, 16);
			this->productBaseDiscountInput->Name = L"productBaseDiscountInput";
			this->productBaseDiscountInput->Size = System::Drawing::Size(56, 22);
			this->productBaseDiscountInput->TabIndex = 18;
			this->productBaseDiscountInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// productCountWeightLabel
			// 
			this->productCountWeightLabel->AutoSize = true;
			this->productCountWeightLabel->Location = System::Drawing::Point(16, 44);
			this->productCountWeightLabel->Name = L"productCountWeightLabel";
			this->productCountWeightLabel->Size = System::Drawing::Size(220, 16);
			this->productCountWeightLabel->TabIndex = 1;
			this->productCountWeightLabel->Text = L"Poids du nombre d\'articles achetés:";
			// 
			// productBaseDiscountLabel
			// 
			this->productBaseDiscountLabel->AutoSize = true;
			this->productBaseDiscountLabel->Location = System::Drawing::Point(16, 18);
			this->productBaseDiscountLabel->Name = L"productBaseDiscountLabel";
			this->productBaseDiscountLabel->Size = System::Drawing::Size(93, 16);
			this->productBaseDiscountLabel->TabIndex = 0;
			this->productBaseDiscountLabel->Text = L"Taux de base:";
			// 
			// productRestockThresholdLabel
			// 
			this->productRestockThresholdLabel->AutoSize = true;
			this->productRestockThresholdLabel->Location = System::Drawing::Point(85, 245);
			this->productRestockThresholdLabel->Name = L"productRestockThresholdLabel";
			this->productRestockThresholdLabel->Size = System::Drawing::Size(189, 16);
			this->productRestockThresholdLabel->TabIndex = 20;
			this->productRestockThresholdLabel->Text = L"Seuil de réapprovisionnement:";
			// 
			// productRestockThresholdInput
			// 
			this->productRestockThresholdInput->Location = System::Drawing::Point(301, 243);
			this->productRestockThresholdInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productRestockThresholdInput->Name = L"productRestockThresholdInput";
			this->productRestockThresholdInput->Size = System::Drawing::Size(84, 22);
			this->productRestockThresholdInput->TabIndex = 21;
			this->productRestockThresholdInput->ThousandsSeparator = true;
			// 
			// productGroup
			// 
			this->productGroup->Controls->Add(this->productRestockThresholdInput);
			this->productGroup->Controls->Add(this->productRestockThresholdLabel);
			this->productGroup->Controls->Add(this->productDiscountGroup);
			this->productGroup->Controls->Add(this->productTaxesPercent);
			this->productGroup->Controls->Add(this->productTaxesInput);
			this->productGroup->Controls->Add(this->productTaxesLabel);
			this->productGroup->Controls->Add(this->productStockLabel);
			this->productGroup->Controls->Add(this->productStockInput);
			this->productGroup->Controls->Add(this->productPurchasePriceInput);
			this->productGroup->Controls->Add(this->productUHTPriceInput);
			this->productGroup->Controls->Add(this->productPurchasePriceCurrencySelector);
			this->productGroup->Controls->Add(this->productPurchasePriceLabel);
			this->productGroup->Controls->Add(this->productUHTPriceCurrencySelector);
			this->productGroup->Controls->Add(this->productUHTPriceLabel);
			this->productGroup->Controls->Add(this->productNameInput);
			this->productGroup->Controls->Add(this->productNameLabel);
			this->productGroup->Controls->Add(this->groupBox19);
			this->productGroup->Location = System::Drawing::Point(12, 8);
			this->productGroup->Name = L"productGroup";
			this->productGroup->Size = System::Drawing::Size(497, 429);
			this->productGroup->TabIndex = 7;
			this->productGroup->TabStop = false;
			this->productGroup->Text = L"Edition d\'articles";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 443);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 49);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Retour";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Root
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->productGroup);
			this->Controls->Add(this->staffGroup);
			this->Controls->Add(this->ordersGroup);
			this->Controls->Add(this->customerGroup);
			this->Controls->Add(this->validateGroup);
			this->Controls->Add(this->visualizeGroup);
			this->Controls->Add(this->statsGroup);
			this->Controls->Add(this->categoriesGroup);
			this->Name = L"Root";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Root";
			this->Load += gcnew System::EventHandler(this, &Root::Root_Load);
			this->categoriesGroup->ResumeLayout(false);
			this->visualizeGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualizeGrid))->EndInit();
			this->validateGroup->ResumeLayout(false);
			this->validateGroup->PerformLayout();
			this->customerGroup->ResumeLayout(false);
			this->customerGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthMonthInput))->EndInit();
			this->customerInvoiceGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerInvoiceDisplay))->EndInit();
			this->customerDeliveryGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerDeliveryDisplay))->EndInit();
			this->ordersGroup->ResumeLayout(false);
			this->ordersGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryDayInput))->EndInit();
			this->ordersPaymentGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersPaymentDisplay))->EndInit();
			this->staffGroup->ResumeLayout(false);
			this->staffGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredDayInput))->EndInit();
			this->staffAddressGroup->ResumeLayout(false);
			this->staffAddressGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsMonthChoiceTurnover))->EndInit();
			this->statsGroup->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->groupBox5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsUnknownMarkdownNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsTVAValueNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsComMarginValueNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statsComDiscountValueNumericUpDown))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productUHTPriceInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productPurchasePriceInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productStockInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productTaxesInput))->EndInit();
			this->productDiscountGroup->ResumeLayout(false);
			this->productDiscountGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productCountWeightInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productBaseDiscountInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productRestockThresholdInput))->EndInit();
			this->productGroup->ResumeLayout(false);
			this->productGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Root_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void statsTurnoverButton_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		void validateButton_Click(Object^ sender, EventArgs^ e) {
			ProductData product = ProductData();
			product.name = this->productNameInput->Text;
			product.priceNoTax = (float)this->productUHTPriceInput->Value;
			product.purchaseValue = (float)this->productPurchasePriceInput->Value;
			product.amount = (int)this->productStockInput->Value;
			product.TVARatio = (float)this->productTaxesInput->Value;
			product.discountRatio = (float)this->productBaseDiscountInput->Value;
			product.restockThreshold = (int)this->productRestockThresholdInput->Value;

			product = this->supply->addProduct(product);
		}
	};
		
}
