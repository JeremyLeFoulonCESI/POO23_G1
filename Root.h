#pragma once
#include "SupplyManager.h"
#include "StaffManager.h"
#include "CustomerManager.h"
#include "OrderManager.h"
#include "Struct.h"

namespace HMI {

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
		bool is_editing;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox9;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
		   Services::SupplyManager^ supply;
		   Services::StaffManager^ staff;
		   Services::CustomerManager^ customer;
		   Services::OrderManager^ order;
	private: System::Windows::Forms::Label^ customerFirstPurchaseDate;
	private: System::Windows::Forms::NumericUpDown^ customerFPDayInput;
	private: System::Windows::Forms::NumericUpDown^ customerFPYearInput;


	private: System::Windows::Forms::NumericUpDown^ customerFPMonthInput;




	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

		   int mode = 0;
		   List <Address>^ selectInvoiceAddress;
		   List <Address>^ selectDeliveryAddress;
		   List <OrderItem>^ selectOrderItem;
		   List <Payment>^ selectPayments;

	public:
		Root(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->supply = gcnew Services::SupplyManager();
			this->staff = gcnew Services::StaffManager();
			this->customer = gcnew Services::CustomerManager();
			this->order = gcnew Services::OrderManager();
			this->productUHTPriceCurrencySelector->DropDownStyle = ComboBoxStyle::DropDownList;
			this->productPurchasePriceCurrencySelector->DropDownStyle = ComboBoxStyle::DropDownList;
			this->statsGroup->Visible = false;
			this->customerGroup->Visible = false;
			this->ordersGroup->Visible = false;
			this->categoriesGroup->Visible = true;
			this->staffGroup->Visible = false;
			this->productGroup->Visible = false;
			this->visualizeGroup->Visible = false;
			this->backButton->Visible = false;
			this->validateGroup->Visible = false;

			this->is_editing = false;

			this->validateButton->Click += gcnew EventHandler(this, &Root::validateButton_Click);
			this->visualizeDeleteButton->Click += gcnew EventHandler(this, &Root::visualizeDeleteButton_Click);
			this->addRadioButton->Click += gcnew EventHandler(this, &Root::addRadioButton_Selected);
			this->EditRadioButton->Click += gcnew EventHandler(this, &Root::editRadioButton_Selected);

			this->stockCategoryButton->Click += gcnew EventHandler(this, &Root::supplyManagerButton_click);
			this->customersCategoryButton->Click += gcnew EventHandler(this, &Root::customerManagerButton_click);
			this->staffCategoryButton->Click += gcnew EventHandler(this, &Root::staffManagerButton_click);
			this->ordersCategoryButton->Click += gcnew EventHandler(this, &Root::ordersManagerButton_click);
			this->statsCategoryButton->Click += gcnew EventHandler(this, &Root::statsManagerButton_click);
			this->backButton->Click += gcnew EventHandler(this, &Root::backButton_click);
			this->selectInvoiceAddress = gcnew List<Address>;
			this->selectDeliveryAddress = gcnew List<Address>;
			this->selectOrderItem = gcnew List<OrderItem>;
			this->selectPayments = gcnew List<Payment>;
		}

		void refreshGrid() {
			Console::WriteLine("Refresh");
			if (mode == 1) {
				this->visualizeGrid->DataSource = this->staff->getAllStaff();
			}
			if (mode == 2) {
				this->visualizeGrid->DataSource = this->supply->getAllProducts();
			}
			if (mode == 3) {
				this->visualizeGrid->DataSource = this->customer->getAllCustomers();
			}
			if (mode == 4) {
				this->visualizeGrid->DataSource = this->order->getAllOrders();
			}
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
private: System::Windows::Forms::TextBox^ customerPhoneNumberInput;

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
private: System::Windows::Forms::Button^ visualizeDeleteButton;


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
private: System::Windows::Forms::Button^ backButton;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->statsCategoryButton = (gcnew System::Windows::Forms::Button());
			this->ordersCategoryButton = (gcnew System::Windows::Forms::Button());
			this->customersCategoryButton = (gcnew System::Windows::Forms::Button());
			this->stockCategoryButton = (gcnew System::Windows::Forms::Button());
			this->staffCategoryButton = (gcnew System::Windows::Forms::Button());
			this->productGroup = (gcnew System::Windows::Forms::GroupBox());
			this->productRestockThresholdInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productRestockThresholdLabel = (gcnew System::Windows::Forms::Label());
			this->productDiscountGroup = (gcnew System::Windows::Forms::GroupBox());
			this->productBaseDiscountPercent = (gcnew System::Windows::Forms::Label());
			this->productCountWeightInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productBaseDiscountInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productCountWeightLabel = (gcnew System::Windows::Forms::Label());
			this->productBaseDiscountLabel = (gcnew System::Windows::Forms::Label());
			this->productTaxesPercent = (gcnew System::Windows::Forms::Label());
			this->productTaxesInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productTaxesLabel = (gcnew System::Windows::Forms::Label());
			this->productStockLabel = (gcnew System::Windows::Forms::Label());
			this->productStockInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productPurchasePriceInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productUHTPriceInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->productPurchasePriceCurrencySelector = (gcnew System::Windows::Forms::ComboBox());
			this->productPurchasePriceLabel = (gcnew System::Windows::Forms::Label());
			this->productUHTPriceCurrencySelector = (gcnew System::Windows::Forms::ComboBox());
			this->productUHTPriceLabel = (gcnew System::Windows::Forms::Label());
			this->productNameInput = (gcnew System::Windows::Forms::TextBox());
			this->productNameLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->visualizeGroup = (gcnew System::Windows::Forms::GroupBox());
			this->visualizeDeleteButton = (gcnew System::Windows::Forms::Button());
			this->visualizeGrid = (gcnew System::Windows::Forms::DataGridView());
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
			this->validateGroup = (gcnew System::Windows::Forms::GroupBox());
			this->EditRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->addRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->validateButton = (gcnew System::Windows::Forms::Button());
			this->customerGroup = (gcnew System::Windows::Forms::GroupBox());
			this->customerFPDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerFPYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerFPMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->customerFirstPurchaseDate = (gcnew System::Windows::Forms::Label());
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
			this->customerPhoneNumberInput = (gcnew System::Windows::Forms::TextBox());
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
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
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
			this->label5 = (gcnew System::Windows::Forms::Label());
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
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->categoriesGroup->SuspendLayout();
			this->productGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productRestockThresholdInput))->BeginInit();
			this->productDiscountGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productCountWeightInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productBaseDiscountInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productTaxesInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productStockInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productPurchasePriceInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productUHTPriceInput))->BeginInit();
			this->visualizeGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualizeGrid))->BeginInit();
			this->staffGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredDayInput))->BeginInit();
			this->staffAddressGroup->SuspendLayout();
			this->validateGroup->SuspendLayout();
			this->customerGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerFPDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerFPYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerFPMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthMonthInput))->BeginInit();
			this->customerInvoiceGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerInvoiceDisplay))->BeginInit();
			this->customerDeliveryGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerDeliveryDisplay))->BeginInit();
			this->ordersGroup->SuspendLayout();
			this->groupBox9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryDayInput))->BeginInit();
			this->ordersPaymentGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersPaymentDisplay))->BeginInit();
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
			this->SuspendLayout();
			// 
			// categoriesGroup
			// 
			this->categoriesGroup->Controls->Add(this->label4);
			this->categoriesGroup->Controls->Add(this->statsCategoryButton);
			this->categoriesGroup->Controls->Add(this->ordersCategoryButton);
			this->categoriesGroup->Controls->Add(this->customersCategoryButton);
			this->categoriesGroup->Controls->Add(this->stockCategoryButton);
			this->categoriesGroup->Controls->Add(this->staffCategoryButton);
			this->categoriesGroup->Location = System::Drawing::Point(14, 10);
			this->categoriesGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->categoriesGroup->Name = L"categoriesGroup";
			this->categoriesGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->categoriesGroup->Size = System::Drawing::Size(1161, 777);
			this->categoriesGroup->TabIndex = 0;
			this->categoriesGroup->TabStop = false;
			this->categoriesGroup->Text = L"Menu principal";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(390, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(444, 87);
			this->label4->TabIndex = 105;
			this->label4->Text = L"Bienvenue dans votre centre de controle\r\n    Veuillez selectionner une categorie "
				L":\r\n\r\n";
			this->label4->Click += gcnew System::EventHandler(this, &Root::label4_Click_1);
			// 
			// statsCategoryButton
			// 
			this->statsCategoryButton->Location = System::Drawing::Point(453, 587);
			this->statsCategoryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->statsCategoryButton->Name = L"statsCategoryButton";
			this->statsCategoryButton->Size = System::Drawing::Size(281, 44);
			this->statsCategoryButton->TabIndex = 104;
			this->statsCategoryButton->TabStop = false;
			this->statsCategoryButton->Text = L"Statistiques";
			this->statsCategoryButton->UseVisualStyleBackColor = true;
			// 
			// ordersCategoryButton
			// 
			this->ordersCategoryButton->Location = System::Drawing::Point(453, 505);
			this->ordersCategoryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersCategoryButton->Name = L"ordersCategoryButton";
			this->ordersCategoryButton->Size = System::Drawing::Size(281, 44);
			this->ordersCategoryButton->TabIndex = 103;
			this->ordersCategoryButton->TabStop = false;
			this->ordersCategoryButton->Text = L"Gestion des commandes";
			this->ordersCategoryButton->UseVisualStyleBackColor = true;
			// 
			// customersCategoryButton
			// 
			this->customersCategoryButton->Location = System::Drawing::Point(453, 423);
			this->customersCategoryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customersCategoryButton->Name = L"customersCategoryButton";
			this->customersCategoryButton->Size = System::Drawing::Size(281, 44);
			this->customersCategoryButton->TabIndex = 102;
			this->customersCategoryButton->TabStop = false;
			this->customersCategoryButton->Text = L"Gestion des clients";
			this->customersCategoryButton->UseVisualStyleBackColor = true;
			// 
			// stockCategoryButton
			// 
			this->stockCategoryButton->Location = System::Drawing::Point(453, 345);
			this->stockCategoryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->stockCategoryButton->Name = L"stockCategoryButton";
			this->stockCategoryButton->Size = System::Drawing::Size(281, 44);
			this->stockCategoryButton->TabIndex = 101;
			this->stockCategoryButton->TabStop = false;
			this->stockCategoryButton->Text = L"Gestion du stock";
			this->stockCategoryButton->UseVisualStyleBackColor = true;
			// 
			// staffCategoryButton
			// 
			this->staffCategoryButton->Location = System::Drawing::Point(453, 271);
			this->staffCategoryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffCategoryButton->Name = L"staffCategoryButton";
			this->staffCategoryButton->Size = System::Drawing::Size(281, 44);
			this->staffCategoryButton->TabIndex = 100;
			this->staffCategoryButton->TabStop = false;
			this->staffCategoryButton->Text = L"Gestion du personnel";
			this->staffCategoryButton->UseVisualStyleBackColor = true;
			// 
			// productGroup
			// 
			this->productGroup->Controls->Add(this->productRestockThresholdInput);
			this->productGroup->Controls->Add(this->productRestockThresholdLabel);
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
			this->productGroup->Location = System::Drawing::Point(14, 10);
			this->productGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productGroup->Name = L"productGroup";
			this->productGroup->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productGroup->Size = System::Drawing::Size(658, 670);
			this->productGroup->TabIndex = 7;
			this->productGroup->TabStop = false;
			this->productGroup->Text = L"Edition d\'articles";
			// 
			// productRestockThresholdInput
			// 
			this->productRestockThresholdInput->Location = System::Drawing::Point(346, 375);
			this->productRestockThresholdInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productRestockThresholdInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productRestockThresholdInput->Name = L"productRestockThresholdInput";
			this->productRestockThresholdInput->Size = System::Drawing::Size(106, 26);
			this->productRestockThresholdInput->TabIndex = 21;
			this->productRestockThresholdInput->ThousandsSeparator = true;
			// 
			// productRestockThresholdLabel
			// 
			this->productRestockThresholdLabel->AutoSize = true;
			this->productRestockThresholdLabel->Location = System::Drawing::Point(74, 382);
			this->productRestockThresholdLabel->Name = L"productRestockThresholdLabel";
			this->productRestockThresholdLabel->Size = System::Drawing::Size(222, 20);
			this->productRestockThresholdLabel->TabIndex = 20;
			this->productRestockThresholdLabel->Text = L"Seuil de réapprovisionnement:";
			// 
			// productDiscountGroup
			// 
			this->productDiscountGroup->Controls->Add(this->productBaseDiscountPercent);
			this->productDiscountGroup->Controls->Add(this->productCountWeightInput);
			this->productDiscountGroup->Controls->Add(this->productBaseDiscountInput);
			this->productDiscountGroup->Controls->Add(this->productCountWeightLabel);
			this->productDiscountGroup->Controls->Add(this->productBaseDiscountLabel);
			this->productDiscountGroup->Location = System::Drawing::Point(79, 519);
			this->productDiscountGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productDiscountGroup->Name = L"productDiscountGroup";
			this->productDiscountGroup->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productDiscountGroup->Size = System::Drawing::Size(524, 112);
			this->productDiscountGroup->TabIndex = 19;
			this->productDiscountGroup->TabStop = false;
			this->productDiscountGroup->Text = L"Remise";
			// 
			// productBaseDiscountPercent
			// 
			this->productBaseDiscountPercent->AutoSize = true;
			this->productBaseDiscountPercent->Location = System::Drawing::Point(342, 28);
			this->productBaseDiscountPercent->Name = L"productBaseDiscountPercent";
			this->productBaseDiscountPercent->Size = System::Drawing::Size(23, 20);
			this->productBaseDiscountPercent->TabIndex = 20;
			this->productBaseDiscountPercent->Text = L"%";
			// 
			// productCountWeightInput
			// 
			this->productCountWeightInput->DecimalPlaces = 2;
			this->productCountWeightInput->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->productCountWeightInput->Location = System::Drawing::Point(358, 69);
			this->productCountWeightInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productCountWeightInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->productCountWeightInput->Name = L"productCountWeightInput";
			this->productCountWeightInput->Size = System::Drawing::Size(74, 26);
			this->productCountWeightInput->TabIndex = 19;
			// 
			// productBaseDiscountInput
			// 
			this->productBaseDiscountInput->Location = System::Drawing::Point(268, 25);
			this->productBaseDiscountInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productBaseDiscountInput->Name = L"productBaseDiscountInput";
			this->productBaseDiscountInput->Size = System::Drawing::Size(71, 26);
			this->productBaseDiscountInput->TabIndex = 18;
			this->productBaseDiscountInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// productCountWeightLabel
			// 
			this->productCountWeightLabel->AutoSize = true;
			this->productCountWeightLabel->Location = System::Drawing::Point(20, 69);
			this->productCountWeightLabel->Name = L"productCountWeightLabel";
			this->productCountWeightLabel->Size = System::Drawing::Size(259, 20);
			this->productCountWeightLabel->TabIndex = 1;
			this->productCountWeightLabel->Text = L"Poids du nombre d\'articles achetés:";
			// 
			// productBaseDiscountLabel
			// 
			this->productBaseDiscountLabel->AutoSize = true;
			this->productBaseDiscountLabel->Location = System::Drawing::Point(20, 28);
			this->productBaseDiscountLabel->Name = L"productBaseDiscountLabel";
			this->productBaseDiscountLabel->Size = System::Drawing::Size(108, 20);
			this->productBaseDiscountLabel->TabIndex = 0;
			this->productBaseDiscountLabel->Text = L"Taux de base:";
			// 
			// productTaxesPercent
			// 
			this->productTaxesPercent->AutoSize = true;
			this->productTaxesPercent->Location = System::Drawing::Point(421, 455);
			this->productTaxesPercent->Name = L"productTaxesPercent";
			this->productTaxesPercent->Size = System::Drawing::Size(23, 20);
			this->productTaxesPercent->TabIndex = 18;
			this->productTaxesPercent->Text = L"%";
			// 
			// productTaxesInput
			// 
			this->productTaxesInput->Location = System::Drawing::Point(346, 452);
			this->productTaxesInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productTaxesInput->Name = L"productTaxesInput";
			this->productTaxesInput->Size = System::Drawing::Size(68, 26);
			this->productTaxesInput->TabIndex = 17;
			this->productTaxesInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// productTaxesLabel
			// 
			this->productTaxesLabel->AutoSize = true;
			this->productTaxesLabel->Location = System::Drawing::Point(74, 455);
			this->productTaxesLabel->Name = L"productTaxesLabel";
			this->productTaxesLabel->Size = System::Drawing::Size(104, 20);
			this->productTaxesLabel->TabIndex = 16;
			this->productTaxesLabel->Text = L"Taux de TVA:";
			// 
			// productStockLabel
			// 
			this->productStockLabel->AutoSize = true;
			this->productStockLabel->Location = System::Drawing::Point(74, 294);
			this->productStockLabel->Name = L"productStockLabel";
			this->productStockLabel->Size = System::Drawing::Size(138, 20);
			this->productStockLabel->TabIndex = 15;
			this->productStockLabel->Text = L"Quantité en stock:";
			// 
			// productStockInput
			// 
			this->productStockInput->Location = System::Drawing::Point(346, 298);
			this->productStockInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productStockInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productStockInput->Name = L"productStockInput";
			this->productStockInput->Size = System::Drawing::Size(106, 26);
			this->productStockInput->TabIndex = 14;
			this->productStockInput->ThousandsSeparator = true;
			// 
			// productPurchasePriceInput
			// 
			this->productPurchasePriceInput->DecimalPlaces = 3;
			this->productPurchasePriceInput->Location = System::Drawing::Point(300, 210);
			this->productPurchasePriceInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productPurchasePriceInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productPurchasePriceInput->Name = L"productPurchasePriceInput";
			this->productPurchasePriceInput->Size = System::Drawing::Size(152, 26);
			this->productPurchasePriceInput->TabIndex = 13;
			this->productPurchasePriceInput->ThousandsSeparator = true;
			// 
			// productUHTPriceInput
			// 
			this->productUHTPriceInput->DecimalPlaces = 3;
			this->productUHTPriceInput->Location = System::Drawing::Point(300, 128);
			this->productUHTPriceInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productUHTPriceInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->productUHTPriceInput->Name = L"productUHTPriceInput";
			this->productUHTPriceInput->Size = System::Drawing::Size(152, 26);
			this->productUHTPriceInput->TabIndex = 12;
			this->productUHTPriceInput->ThousandsSeparator = true;
			// 
			// productPurchasePriceCurrencySelector
			// 
			this->productPurchasePriceCurrencySelector->FormattingEnabled = true;
			this->productPurchasePriceCurrencySelector->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->productPurchasePriceCurrencySelector->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"", L"$", L"", L"$" });
			this->productPurchasePriceCurrencySelector->Location = System::Drawing::Point(464, 210);
			this->productPurchasePriceCurrencySelector->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productPurchasePriceCurrencySelector->Name = L"productPurchasePriceCurrencySelector";
			this->productPurchasePriceCurrencySelector->Size = System::Drawing::Size(68, 28);
			this->productPurchasePriceCurrencySelector->TabIndex = 11;
			this->productPurchasePriceCurrencySelector->Text = L"";
			// 
			// productPurchasePriceLabel
			// 
			this->productPurchasePriceLabel->AutoSize = true;
			this->productPurchasePriceLabel->Location = System::Drawing::Point(74, 212);
			this->productPurchasePriceLabel->Name = L"productPurchasePriceLabel";
			this->productPurchasePriceLabel->Size = System::Drawing::Size(150, 20);
			this->productPurchasePriceLabel->TabIndex = 9;
			this->productPurchasePriceLabel->Text = L"Prix unitaire d\'achat:";
			// 
			// productUHTPriceCurrencySelector
			// 
			this->productUHTPriceCurrencySelector->FormattingEnabled = true;
			this->productUHTPriceCurrencySelector->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->productUHTPriceCurrencySelector->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"", L"$", L"", L"$" });
			this->productUHTPriceCurrencySelector->Location = System::Drawing::Point(464, 126);
			this->productUHTPriceCurrencySelector->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productUHTPriceCurrencySelector->Name = L"productUHTPriceCurrencySelector";
			this->productUHTPriceCurrencySelector->Size = System::Drawing::Size(68, 28);
			this->productUHTPriceCurrencySelector->TabIndex = 8;
			this->productUHTPriceCurrencySelector->Text = L"";
			// 
			// productUHTPriceLabel
			// 
			this->productUHTPriceLabel->AutoSize = true;
			this->productUHTPriceLabel->Location = System::Drawing::Point(71, 130);
			this->productUHTPriceLabel->Name = L"productUHTPriceLabel";
			this->productUHTPriceLabel->Size = System::Drawing::Size(171, 20);
			this->productUHTPriceLabel->TabIndex = 6;
			this->productUHTPriceLabel->Text = L"Prix unitaire hors taxes:";
			// 
			// productNameInput
			// 
			this->productNameInput->Location = System::Drawing::Point(133, 49);
			this->productNameInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->productNameInput->Name = L"productNameInput";
			this->productNameInput->Size = System::Drawing::Size(470, 26);
			this->productNameInput->TabIndex = 5;
			// 
			// productNameLabel
			// 
			this->productNameLabel->AutoSize = true;
			this->productNameLabel->Location = System::Drawing::Point(74, 52);
			this->productNameLabel->Name = L"productNameLabel";
			this->productNameLabel->Size = System::Drawing::Size(46, 20);
			this->productNameLabel->TabIndex = 4;
			this->productNameLabel->Text = L"Nom:";
			// 
			// groupBox19
			// 
			this->groupBox19->Location = System::Drawing::Point(0, 674);
			this->groupBox19->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->groupBox19->Size = System::Drawing::Size(494, 76);
			this->groupBox19->TabIndex = 3;
			this->groupBox19->TabStop = false;
			// 
			// visualizeGroup
			// 
			this->visualizeGroup->Controls->Add(this->visualizeDeleteButton);
			this->visualizeGroup->Controls->Add(this->visualizeGrid);
			this->visualizeGroup->Cursor = System::Windows::Forms::Cursors::Hand;
			this->visualizeGroup->Location = System::Drawing::Point(681, 12);
			this->visualizeGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->visualizeGroup->Name = L"visualizeGroup";
			this->visualizeGroup->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->visualizeGroup->Size = System::Drawing::Size(494, 761);
			this->visualizeGroup->TabIndex = 2;
			this->visualizeGroup->TabStop = false;
			this->visualizeGroup->Text = L"Visualisation des données";
			// 
			// visualizeDeleteButton
			// 
			this->visualizeDeleteButton->Location = System::Drawing::Point(172, 701);
			this->visualizeDeleteButton->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->visualizeDeleteButton->Name = L"visualizeDeleteButton";
			this->visualizeDeleteButton->Size = System::Drawing::Size(144, 36);
			this->visualizeDeleteButton->TabIndex = 10;
			this->visualizeDeleteButton->Text = L"Supprimer";
			this->visualizeDeleteButton->UseVisualStyleBackColor = true;
			// 
			// visualizeGrid
			// 
			this->visualizeGrid->AllowUserToAddRows = false;
			this->visualizeGrid->AllowUserToDeleteRows = false;
			this->visualizeGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->visualizeGrid->Location = System::Drawing::Point(8, 32);
			this->visualizeGrid->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->visualizeGrid->Name = L"visualizeGrid";
			this->visualizeGrid->RowHeadersWidth = 51;
			this->visualizeGrid->RowTemplate->Height = 24;
			this->visualizeGrid->Size = System::Drawing::Size(478, 662);
			this->visualizeGrid->TabIndex = 9;
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
			this->staffGroup->Location = System::Drawing::Point(14, 10);
			this->staffGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->staffGroup->Name = L"staffGroup";
			this->staffGroup->Padding = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->staffGroup->Size = System::Drawing::Size(658, 664);
			this->staffGroup->TabIndex = 6;
			this->staffGroup->TabStop = false;
			this->staffGroup->Text = L"Edition du personnel";
			// 
			// staffHiredYearInput
			// 
			this->staffHiredYearInput->Location = System::Drawing::Point(498, 175);
			this->staffHiredYearInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->staffHiredYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->staffHiredYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->staffHiredYearInput->Name = L"staffHiredYearInput";
			this->staffHiredYearInput->Size = System::Drawing::Size(89, 26);
			this->staffHiredYearInput->TabIndex = 33;
			this->staffHiredYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// staffHiredMonthInput
			// 
			this->staffHiredMonthInput->Location = System::Drawing::Point(406, 175);
			this->staffHiredMonthInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->staffHiredMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->staffHiredMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->staffHiredMonthInput->Name = L"staffHiredMonthInput";
			this->staffHiredMonthInput->Size = System::Drawing::Size(63, 26);
			this->staffHiredMonthInput->TabIndex = 32;
			this->staffHiredMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// staffHiredDayInput
			// 
			this->staffHiredDayInput->Location = System::Drawing::Point(314, 175);
			this->staffHiredDayInput->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->staffHiredDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->staffHiredDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->staffHiredDayInput->Name = L"staffHiredDayInput";
			this->staffHiredDayInput->Size = System::Drawing::Size(63, 26);
			this->staffHiredDayInput->TabIndex = 31;
			this->staffHiredDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// staffHiredSlash2
			// 
			this->staffHiredSlash2->AutoSize = true;
			this->staffHiredSlash2->Location = System::Drawing::Point(477, 180);
			this->staffHiredSlash2->Name = L"staffHiredSlash2";
			this->staffHiredSlash2->Size = System::Drawing::Size(13, 20);
			this->staffHiredSlash2->TabIndex = 30;
			this->staffHiredSlash2->Text = L"/";
			// 
			// staffHiredSlash1
			// 
			this->staffHiredSlash1->AutoSize = true;
			this->staffHiredSlash1->Location = System::Drawing::Point(385, 180);
			this->staffHiredSlash1->Name = L"staffHiredSlash1";
			this->staffHiredSlash1->Size = System::Drawing::Size(13, 20);
			this->staffHiredSlash1->TabIndex = 29;
			this->staffHiredSlash1->Text = L"/";
			// 
			// staffSuperiorLabel
			// 
			this->staffSuperiorLabel->AutoSize = true;
			this->staffSuperiorLabel->Location = System::Drawing::Point(71, 358);
			this->staffSuperiorLabel->Name = L"staffSuperiorLabel";
			this->staffSuperiorLabel->Size = System::Drawing::Size(173, 20);
			this->staffSuperiorLabel->TabIndex = 26;
			this->staffSuperiorLabel->Text = L"Superieur hierarchique:";
			// 
			// staffSuperiorSelector
			// 
			this->staffSuperiorSelector->FormattingEnabled = true;
			this->staffSuperiorSelector->ItemHeight = 20;
			this->staffSuperiorSelector->Location = System::Drawing::Point(70, 382);
			this->staffSuperiorSelector->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffSuperiorSelector->Name = L"staffSuperiorSelector";
			this->staffSuperiorSelector->Size = System::Drawing::Size(457, 104);
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
			this->staffAddressGroup->Location = System::Drawing::Point(60, 198);
			this->staffAddressGroup->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffAddressGroup->Name = L"staffAddressGroup";
			this->staffAddressGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffAddressGroup->Size = System::Drawing::Size(465, 125);
			this->staffAddressGroup->TabIndex = 18;
			this->staffAddressGroup->TabStop = false;
			this->staffAddressGroup->Text = L"Adresse";
			// 
			// staffAddressCityInput
			// 
			this->staffAddressCityInput->FormattingEnabled = true;
			this->staffAddressCityInput->Location = System::Drawing::Point(69, 71);
			this->staffAddressCityInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffAddressCityInput->Name = L"staffAddressCityInput";
			this->staffAddressCityInput->Size = System::Drawing::Size(129, 28);
			this->staffAddressCityInput->TabIndex = 8;
			// 
			// staffAddressCityCodeInput
			// 
			this->staffAddressCityCodeInput->Location = System::Drawing::Point(341, 71);
			this->staffAddressCityCodeInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffAddressCityCodeInput->MaxLength = 6;
			this->staffAddressCityCodeInput->Name = L"staffAddressCityCodeInput";
			this->staffAddressCityCodeInput->Size = System::Drawing::Size(119, 26);
			this->staffAddressCityCodeInput->TabIndex = 7;
			// 
			// staffAddressCityCodeLabel
			// 
			this->staffAddressCityCodeLabel->AutoSize = true;
			this->staffAddressCityCodeLabel->Location = System::Drawing::Point(241, 75);
			this->staffAddressCityCodeLabel->Name = L"staffAddressCityCodeLabel";
			this->staffAddressCityCodeLabel->Size = System::Drawing::Size(98, 20);
			this->staffAddressCityCodeLabel->TabIndex = 5;
			this->staffAddressCityCodeLabel->Text = L"Code postal:";
			// 
			// staffAddressCityLabel
			// 
			this->staffAddressCityLabel->AutoSize = true;
			this->staffAddressCityLabel->Location = System::Drawing::Point(20, 75);
			this->staffAddressCityLabel->Name = L"staffAddressCityLabel";
			this->staffAddressCityLabel->Size = System::Drawing::Size(42, 20);
			this->staffAddressCityLabel->TabIndex = 4;
			this->staffAddressCityLabel->Text = L"Ville:";
			// 
			// staffAddressStreetLabel
			// 
			this->staffAddressStreetLabel->AutoSize = true;
			this->staffAddressStreetLabel->Location = System::Drawing::Point(238, 35);
			this->staffAddressStreetLabel->Name = L"staffAddressStreetLabel";
			this->staffAddressStreetLabel->Size = System::Drawing::Size(95, 20);
			this->staffAddressStreetLabel->TabIndex = 3;
			this->staffAddressStreetLabel->Text = L"Nom de rue:";
			// 
			// staffAddressStreetInput
			// 
			this->staffAddressStreetInput->Location = System::Drawing::Point(335, 31);
			this->staffAddressStreetInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffAddressStreetInput->Name = L"staffAddressStreetInput";
			this->staffAddressStreetInput->Size = System::Drawing::Size(112, 26);
			this->staffAddressStreetInput->TabIndex = 2;
			// 
			// staffAddressNumberInput
			// 
			this->staffAddressNumberInput->Location = System::Drawing::Point(136, 31);
			this->staffAddressNumberInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffAddressNumberInput->Name = L"staffAddressNumberInput";
			this->staffAddressNumberInput->Size = System::Drawing::Size(69, 26);
			this->staffAddressNumberInput->TabIndex = 1;
			// 
			// staffAddressNumberLabel
			// 
			this->staffAddressNumberLabel->AutoSize = true;
			this->staffAddressNumberLabel->Location = System::Drawing::Point(20, 35);
			this->staffAddressNumberLabel->Name = L"staffAddressNumberLabel";
			this->staffAddressNumberLabel->Size = System::Drawing::Size(117, 20);
			this->staffAddressNumberLabel->TabIndex = 0;
			this->staffAddressNumberLabel->Text = L"N° de batiment:";
			// 
			// staffHiredLabel
			// 
			this->staffHiredLabel->AutoSize = true;
			this->staffHiredLabel->Location = System::Drawing::Point(66, 140);
			this->staffHiredLabel->Name = L"staffHiredLabel";
			this->staffHiredLabel->Size = System::Drawing::Size(139, 20);
			this->staffHiredLabel->TabIndex = 17;
			this->staffHiredLabel->Text = L"Date d\'embauche:";
			// 
			// staffFNameLabel
			// 
			this->staffFNameLabel->AutoSize = true;
			this->staffFNameLabel->Location = System::Drawing::Point(351, 82);
			this->staffFNameLabel->Name = L"staffFNameLabel";
			this->staffFNameLabel->Size = System::Drawing::Size(68, 20);
			this->staffFNameLabel->TabIndex = 11;
			this->staffFNameLabel->Text = L"Prenom:";
			// 
			// staffLNameLabel
			// 
			this->staffLNameLabel->AutoSize = true;
			this->staffLNameLabel->Location = System::Drawing::Point(66, 66);
			this->staffLNameLabel->Name = L"staffLNameLabel";
			this->staffLNameLabel->Size = System::Drawing::Size(46, 20);
			this->staffLNameLabel->TabIndex = 10;
			this->staffLNameLabel->Text = L"Nom:";
			// 
			// staffFNameInput
			// 
			this->staffFNameInput->AcceptsTab = true;
			this->staffFNameInput->Location = System::Drawing::Point(386, 62);
			this->staffFNameInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffFNameInput->Name = L"staffFNameInput";
			this->staffFNameInput->Size = System::Drawing::Size(138, 26);
			this->staffFNameInput->TabIndex = 9;
			this->staffFNameInput->TabStop = false;
			// 
			// staffLNameInput
			// 
			this->staffLNameInput->AcceptsTab = true;
			this->staffLNameInput->Location = System::Drawing::Point(114, 62);
			this->staffLNameInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->staffLNameInput->Name = L"staffLNameInput";
			this->staffLNameInput->Size = System::Drawing::Size(138, 26);
			this->staffLNameInput->TabIndex = 8;
			this->staffLNameInput->TabStop = false;
			// 
			// groupBox16
			// 
			this->groupBox16->Location = System::Drawing::Point(0, 539);
			this->groupBox16->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox16->Name = L"groupBox16";
			this->groupBox16->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox16->Size = System::Drawing::Size(439, 61);
			this->groupBox16->TabIndex = 3;
			this->groupBox16->TabStop = false;
			// 
			// validateGroup
			// 
			this->validateGroup->Controls->Add(this->EditRadioButton);
			this->validateGroup->Controls->Add(this->addRadioButton);
			this->validateGroup->Controls->Add(this->validateButton);
			this->validateGroup->Location = System::Drawing::Point(160, 691);
			this->validateGroup->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->validateGroup->Name = L"validateGroup";
			this->validateGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->validateGroup->Size = System::Drawing::Size(446, 70);
			this->validateGroup->TabIndex = 3;
			this->validateGroup->TabStop = false;
			this->validateGroup->Text = L"Validation";
			// 
			// EditRadioButton
			// 
			this->EditRadioButton->AutoSize = true;
			this->EditRadioButton->Location = System::Drawing::Point(318, 26);
			this->EditRadioButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->EditRadioButton->Name = L"EditRadioButton";
			this->EditRadioButton->Size = System::Drawing::Size(90, 24);
			this->EditRadioButton->TabIndex = 8;
			this->EditRadioButton->Text = L"Modifier";
			this->EditRadioButton->UseVisualStyleBackColor = true;
			// 
			// addRadioButton
			// 
			this->addRadioButton->AutoCheck = false;
			this->addRadioButton->AutoSize = true;
			this->addRadioButton->Checked = true;
			this->addRadioButton->Location = System::Drawing::Point(171, 26);
			this->addRadioButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->addRadioButton->Name = L"addRadioButton";
			this->addRadioButton->Size = System::Drawing::Size(85, 24);
			this->addRadioButton->TabIndex = 7;
			this->addRadioButton->Text = L"Ajouter";
			this->addRadioButton->UseVisualStyleBackColor = true;
			// 
			// validateButton
			// 
			this->validateButton->Location = System::Drawing::Point(44, 26);
			this->validateButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->validateButton->Name = L"validateButton";
			this->validateButton->Size = System::Drawing::Size(84, 29);
			this->validateButton->TabIndex = 6;
			this->validateButton->Text = L"Valider";
			this->validateButton->UseVisualStyleBackColor = true;
			// 
			// customerGroup
			// 
			this->customerGroup->Controls->Add(this->customerFPDayInput);
			this->customerGroup->Controls->Add(this->customerFPYearInput);
			this->customerGroup->Controls->Add(this->productDiscountGroup);
			this->customerGroup->Controls->Add(this->customerFPMonthInput);
			this->customerGroup->Controls->Add(this->label7);
			this->customerGroup->Controls->Add(this->label8);
			this->customerGroup->Controls->Add(this->customerFirstPurchaseDate);
			this->customerGroup->Controls->Add(this->customerBirthDayInput);
			this->customerGroup->Controls->Add(this->customerBirthYearInput);
			this->customerGroup->Controls->Add(this->customerBirthMonthInput);
			this->customerGroup->Controls->Add(this->customerBirthSlash2);
			this->customerGroup->Controls->Add(this->customerBirthSlash1);
			this->customerGroup->Controls->Add(this->customerInvoiceGroup);
			this->customerGroup->Controls->Add(this->customerDeliveryGroup);
			this->customerGroup->Controls->Add(this->label10);
			this->customerGroup->Controls->Add(this->customerPhoneNumberInput);
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
			this->customerGroup->Location = System::Drawing::Point(14, 10);
			this->customerGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->customerGroup->Name = L"customerGroup";
			this->customerGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerGroup->Size = System::Drawing::Size(585, 531);
			this->customerGroup->TabIndex = 4;
			this->customerGroup->TabStop = false;
			this->customerGroup->Text = L"Edition des données client";
			this->customerGroup->Enter += gcnew System::EventHandler(this, &Root::customerGroup_Enter);
			// 
			// customerFPDayInput
			// 
			this->customerFPDayInput->Location = System::Drawing::Point(224, 238);
			this->customerFPDayInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerFPDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->customerFPDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerFPDayInput->Name = L"customerFPDayInput";
			this->customerFPDayInput->Size = System::Drawing::Size(56, 26);
			this->customerFPDayInput->TabIndex = 48;
			this->customerFPDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// customerFPYearInput
			// 
			this->customerFPYearInput->Location = System::Drawing::Point(386, 238);
			this->customerFPYearInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerFPYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->customerFPYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->customerFPYearInput->Name = L"customerFPYearInput";
			this->customerFPYearInput->Size = System::Drawing::Size(79, 26);
			this->customerFPYearInput->TabIndex = 47;
			this->customerFPYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// customerFPMonthInput
			// 
			this->customerFPMonthInput->Location = System::Drawing::Point(305, 238);
			this->customerFPMonthInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerFPMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->customerFPMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerFPMonthInput->Name = L"customerFPMonthInput";
			this->customerFPMonthInput->Size = System::Drawing::Size(56, 26);
			this->customerFPMonthInput->TabIndex = 46;
			this->customerFPMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(367, 240);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 20);
			this->label7->TabIndex = 45;
			this->label7->Text = L"/";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(286, 240);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 20);
			this->label8->TabIndex = 44;
			this->label8->Text = L"/";
			// 
			// customerFirstPurchaseDate
			// 
			this->customerFirstPurchaseDate->AutoSize = true;
			this->customerFirstPurchaseDate->Location = System::Drawing::Point(69, 240);
			this->customerFirstPurchaseDate->Name = L"customerFirstPurchaseDate";
			this->customerFirstPurchaseDate->Size = System::Drawing::Size(123, 20);
			this->customerFirstPurchaseDate->TabIndex = 43;
			this->customerFirstPurchaseDate->Text = L"Date 1er achat :";
			this->customerFirstPurchaseDate->Click += gcnew System::EventHandler(this, &Root::label6_Click);
			// 
			// customerBirthDayInput
			// 
			this->customerBirthDayInput->Location = System::Drawing::Point(224, 86);
			this->customerBirthDayInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerBirthDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->customerBirthDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthDayInput->Name = L"customerBirthDayInput";
			this->customerBirthDayInput->Size = System::Drawing::Size(56, 26);
			this->customerBirthDayInput->TabIndex = 42;
			this->customerBirthDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthDayInput->ValueChanged += gcnew System::EventHandler(this, &Root::customerBirthDayInput_ValueChanged);
			// 
			// customerBirthYearInput
			// 
			this->customerBirthYearInput->Location = System::Drawing::Point(386, 86);
			this->customerBirthYearInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerBirthYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->customerBirthYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->customerBirthYearInput->Name = L"customerBirthYearInput";
			this->customerBirthYearInput->Size = System::Drawing::Size(79, 26);
			this->customerBirthYearInput->TabIndex = 38;
			this->customerBirthYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			this->customerBirthYearInput->ValueChanged += gcnew System::EventHandler(this, &Root::customerBirthYearInput_ValueChanged);
			// 
			// customerBirthMonthInput
			// 
			this->customerBirthMonthInput->Location = System::Drawing::Point(305, 86);
			this->customerBirthMonthInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerBirthMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->customerBirthMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthMonthInput->Name = L"customerBirthMonthInput";
			this->customerBirthMonthInput->Size = System::Drawing::Size(56, 26);
			this->customerBirthMonthInput->TabIndex = 37;
			this->customerBirthMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthMonthInput->ValueChanged += gcnew System::EventHandler(this, &Root::customerBirthMonthInput_ValueChanged);
			// 
			// customerBirthSlash2
			// 
			this->customerBirthSlash2->AutoSize = true;
			this->customerBirthSlash2->Location = System::Drawing::Point(367, 88);
			this->customerBirthSlash2->Name = L"customerBirthSlash2";
			this->customerBirthSlash2->Size = System::Drawing::Size(13, 20);
			this->customerBirthSlash2->TabIndex = 35;
			this->customerBirthSlash2->Text = L"/";
			this->customerBirthSlash2->Click += gcnew System::EventHandler(this, &Root::customerBirthSlash2_Click);
			// 
			// customerBirthSlash1
			// 
			this->customerBirthSlash1->AutoSize = true;
			this->customerBirthSlash1->Location = System::Drawing::Point(286, 88);
			this->customerBirthSlash1->Name = L"customerBirthSlash1";
			this->customerBirthSlash1->Size = System::Drawing::Size(13, 20);
			this->customerBirthSlash1->TabIndex = 34;
			this->customerBirthSlash1->Text = L"/";
			this->customerBirthSlash1->Click += gcnew System::EventHandler(this, &Root::customerBirthSlash1_Click);
			// 
			// customerInvoiceGroup
			// 
			this->customerInvoiceGroup->Controls->Add(this->customerRemoveInvoiceButton);
			this->customerInvoiceGroup->Controls->Add(this->CustomerNewInvoiceButton);
			this->customerInvoiceGroup->Controls->Add(this->customerInvoiceDisplay);
			this->customerInvoiceGroup->Location = System::Drawing::Point(7, 306);
			this->customerInvoiceGroup->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerInvoiceGroup->Name = L"customerInvoiceGroup";
			this->customerInvoiceGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerInvoiceGroup->Size = System::Drawing::Size(280, 144);
			this->customerInvoiceGroup->TabIndex = 25;
			this->customerInvoiceGroup->TabStop = false;
			this->customerInvoiceGroup->Text = L"Adresses de facturation";
			// 
			// customerRemoveInvoiceButton
			// 
			this->customerRemoveInvoiceButton->Location = System::Drawing::Point(144, 109);
			this->customerRemoveInvoiceButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerRemoveInvoiceButton->Name = L"customerRemoveInvoiceButton";
			this->customerRemoveInvoiceButton->Size = System::Drawing::Size(129, 29);
			this->customerRemoveInvoiceButton->TabIndex = 2;
			this->customerRemoveInvoiceButton->Text = L"Retirer";
			this->customerRemoveInvoiceButton->UseVisualStyleBackColor = true;
			// 
			// CustomerNewInvoiceButton
			// 
			this->CustomerNewInvoiceButton->Location = System::Drawing::Point(7, 109);
			this->CustomerNewInvoiceButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->CustomerNewInvoiceButton->Name = L"CustomerNewInvoiceButton";
			this->CustomerNewInvoiceButton->Size = System::Drawing::Size(138, 29);
			this->CustomerNewInvoiceButton->TabIndex = 1;
			this->CustomerNewInvoiceButton->Text = L"Nouveau";
			this->CustomerNewInvoiceButton->UseVisualStyleBackColor = true;
			// 
			// customerInvoiceDisplay
			// 
			this->customerInvoiceDisplay->BackgroundColor = System::Drawing::SystemColors::Control;
			this->customerInvoiceDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->customerInvoiceDisplay->Location = System::Drawing::Point(7, 26);
			this->customerInvoiceDisplay->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerInvoiceDisplay->Name = L"customerInvoiceDisplay";
			this->customerInvoiceDisplay->RowHeadersWidth = 51;
			this->customerInvoiceDisplay->RowTemplate->Height = 24;
			this->customerInvoiceDisplay->Size = System::Drawing::Size(267, 82);
			this->customerInvoiceDisplay->TabIndex = 0;
			// 
			// customerDeliveryGroup
			// 
			this->customerDeliveryGroup->Controls->Add(this->CustomerRemoveDeliveryButton);
			this->customerDeliveryGroup->Controls->Add(this->customerNewDeliveryButton);
			this->customerDeliveryGroup->Controls->Add(this->customerDeliveryDisplay);
			this->customerDeliveryGroup->Location = System::Drawing::Point(292, 306);
			this->customerDeliveryGroup->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerDeliveryGroup->Name = L"customerDeliveryGroup";
			this->customerDeliveryGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerDeliveryGroup->Size = System::Drawing::Size(286, 144);
			this->customerDeliveryGroup->TabIndex = 24;
			this->customerDeliveryGroup->TabStop = false;
			this->customerDeliveryGroup->Text = L"Adresses de livraison";
			// 
			// CustomerRemoveDeliveryButton
			// 
			this->CustomerRemoveDeliveryButton->Location = System::Drawing::Point(142, 109);
			this->CustomerRemoveDeliveryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->CustomerRemoveDeliveryButton->Name = L"CustomerRemoveDeliveryButton";
			this->CustomerRemoveDeliveryButton->Size = System::Drawing::Size(137, 29);
			this->CustomerRemoveDeliveryButton->TabIndex = 2;
			this->CustomerRemoveDeliveryButton->Text = L"Retirer";
			this->CustomerRemoveDeliveryButton->UseVisualStyleBackColor = true;
			// 
			// customerNewDeliveryButton
			// 
			this->customerNewDeliveryButton->Location = System::Drawing::Point(7, 109);
			this->customerNewDeliveryButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerNewDeliveryButton->Name = L"customerNewDeliveryButton";
			this->customerNewDeliveryButton->Size = System::Drawing::Size(136, 29);
			this->customerNewDeliveryButton->TabIndex = 1;
			this->customerNewDeliveryButton->Text = L"Nouveau";
			this->customerNewDeliveryButton->UseVisualStyleBackColor = true;
			// 
			// customerDeliveryDisplay
			// 
			this->customerDeliveryDisplay->BackgroundColor = System::Drawing::SystemColors::Control;
			this->customerDeliveryDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->customerDeliveryDisplay->Location = System::Drawing::Point(7, 26);
			this->customerDeliveryDisplay->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerDeliveryDisplay->Name = L"customerDeliveryDisplay";
			this->customerDeliveryDisplay->RowHeadersWidth = 51;
			this->customerDeliveryDisplay->RowTemplate->Height = 24;
			this->customerDeliveryDisplay->Size = System::Drawing::Size(272, 82);
			this->customerDeliveryDisplay->TabIndex = 0;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(69, 189);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 20);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Telephone:";
			// 
			// customerPhoneNumberInput
			// 
			this->customerPhoneNumberInput->AcceptsTab = true;
			this->customerPhoneNumberInput->Location = System::Drawing::Point(174, 186);
			this->customerPhoneNumberInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerPhoneNumberInput->MaxLength = 10;
			this->customerPhoneNumberInput->Name = L"customerPhoneNumberInput";
			this->customerPhoneNumberInput->Size = System::Drawing::Size(325, 26);
			this->customerPhoneNumberInput->TabIndex = 8;
			// 
			// customerMailDotLabel
			// 
			this->customerMailDotLabel->AutoSize = true;
			this->customerMailDotLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->customerMailDotLabel->Location = System::Drawing::Point(420, 166);
			this->customerMailDotLabel->Name = L"customerMailDotLabel";
			this->customerMailDotLabel->Size = System::Drawing::Size(13, 20);
			this->customerMailDotLabel->TabIndex = 16;
			this->customerMailDotLabel->Text = L".";
			// 
			// customerMailAtLabel
			// 
			this->customerMailAtLabel->AutoSize = true;
			this->customerMailAtLabel->Location = System::Drawing::Point(284, 138);
			this->customerMailAtLabel->Name = L"customerMailAtLabel";
			this->customerMailAtLabel->Size = System::Drawing::Size(25, 20);
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
			this->customerMailExtInput->Location = System::Drawing::Point(438, 134);
			this->customerMailExtInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerMailExtInput->MaxLength = 3;
			this->customerMailExtInput->Name = L"customerMailExtInput";
			this->customerMailExtInput->Size = System::Drawing::Size(61, 28);
			this->customerMailExtInput->TabIndex = 7;
			this->customerMailExtInput->TabStop = false;
			// 
			// customerMailDomainInput
			// 
			this->customerMailDomainInput->AcceptsTab = true;
			this->customerMailDomainInput->Location = System::Drawing::Point(315, 134);
			this->customerMailDomainInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerMailDomainInput->MaxLength = 64;
			this->customerMailDomainInput->Name = L"customerMailDomainInput";
			this->customerMailDomainInput->Size = System::Drawing::Size(112, 26);
			this->customerMailDomainInput->TabIndex = 6;
			// 
			// customerMailNameInput
			// 
			this->customerMailNameInput->AcceptsTab = true;
			this->customerMailNameInput->Location = System::Drawing::Point(151, 134);
			this->customerMailNameInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerMailNameInput->Name = L"customerMailNameInput";
			this->customerMailNameInput->Size = System::Drawing::Size(127, 26);
			this->customerMailNameInput->TabIndex = 5;
			this->customerMailNameInput->TabStop = false;
			// 
			// customerMailLabel
			// 
			this->customerMailLabel->AutoSize = true;
			this->customerMailLabel->Location = System::Drawing::Point(69, 138);
			this->customerMailLabel->Name = L"customerMailLabel";
			this->customerMailLabel->Size = System::Drawing::Size(41, 20);
			this->customerMailLabel->TabIndex = 11;
			this->customerMailLabel->Text = L"Mail:";
			// 
			// customerBirthLabel
			// 
			this->customerBirthLabel->AutoSize = true;
			this->customerBirthLabel->Location = System::Drawing::Point(69, 88);
			this->customerBirthLabel->Name = L"customerBirthLabel";
			this->customerBirthLabel->Size = System::Drawing::Size(68, 20);
			this->customerBirthLabel->TabIndex = 8;
			this->customerBirthLabel->Text = L"Ne(e) le:";
			// 
			// customerFNameLabel
			// 
			this->customerFNameLabel->AutoSize = true;
			this->customerFNameLabel->Location = System::Drawing::Point(274, 46);
			this->customerFNameLabel->Name = L"customerFNameLabel";
			this->customerFNameLabel->Size = System::Drawing::Size(68, 20);
			this->customerFNameLabel->TabIndex = 7;
			this->customerFNameLabel->Text = L"Prenom:";
			// 
			// customerLNameLabel
			// 
			this->customerLNameLabel->AutoSize = true;
			this->customerLNameLabel->Location = System::Drawing::Point(69, 46);
			this->customerLNameLabel->Name = L"customerLNameLabel";
			this->customerLNameLabel->Size = System::Drawing::Size(46, 20);
			this->customerLNameLabel->TabIndex = 6;
			this->customerLNameLabel->Text = L"Nom:";
			// 
			// customerFNameInput
			// 
			this->customerFNameInput->AcceptsTab = true;
			this->customerFNameInput->Location = System::Drawing::Point(346, 42);
			this->customerFNameInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerFNameInput->Name = L"customerFNameInput";
			this->customerFNameInput->Size = System::Drawing::Size(152, 26);
			this->customerFNameInput->TabIndex = 1;
			this->customerFNameInput->TabStop = false;
			// 
			// customerLNameInput
			// 
			this->customerLNameInput->AcceptsTab = true;
			this->customerLNameInput->Location = System::Drawing::Point(118, 42);
			this->customerLNameInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->customerLNameInput->Name = L"customerLNameInput";
			this->customerLNameInput->Size = System::Drawing::Size(140, 26);
			this->customerLNameInput->TabIndex = 0;
			this->customerLNameInput->TabStop = false;
			// 
			// groupBox7
			// 
			this->groupBox7->Location = System::Drawing::Point(0, 539);
			this->groupBox7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox7->Size = System::Drawing::Size(439, 61);
			this->groupBox7->TabIndex = 3;
			this->groupBox7->TabStop = false;
			// 
			// ordersGroup
			// 
			this->ordersGroup->Controls->Add(this->groupBox9);
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
			this->ordersGroup->Location = System::Drawing::Point(14, 10);
			this->ordersGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->ordersGroup->Name = L"ordersGroup";
			this->ordersGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersGroup->Size = System::Drawing::Size(578, 531);
			this->ordersGroup->TabIndex = 5;
			this->ordersGroup->TabStop = false;
			this->ordersGroup->Text = L"Edition de commandes";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->button1);
			this->groupBox9->Controls->Add(this->button2);
			this->groupBox9->Controls->Add(this->dataGridView4);
			this->groupBox9->Location = System::Drawing::Point(294, 166);
			this->groupBox9->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox9->Size = System::Drawing::Size(237, 218);
			this->groupBox9->TabIndex = 24;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Articles";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(117, 179);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 29);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Retirer";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 179);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Nouveau";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// dataGridView4
			// 
			this->dataGridView4->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Location = System::Drawing::Point(7, 26);
			this->dataGridView4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->RowTemplate->Height = 24;
			this->dataGridView4->Size = System::Drawing::Size(220, 150);
			this->dataGridView4->TabIndex = 0;
			// 
			// ordersEmitYearInput
			// 
			this->ordersEmitYearInput->Location = System::Drawing::Point(452, 460);
			this->ordersEmitYearInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersEmitYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->ordersEmitYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->ordersEmitYearInput->Name = L"ordersEmitYearInput";
			this->ordersEmitYearInput->Size = System::Drawing::Size(79, 26);
			this->ordersEmitYearInput->TabIndex = 48;
			this->ordersEmitYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// ordersEmitMonthInput
			// 
			this->ordersEmitMonthInput->Location = System::Drawing::Point(370, 460);
			this->ordersEmitMonthInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersEmitMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ordersEmitMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersEmitMonthInput->Name = L"ordersEmitMonthInput";
			this->ordersEmitMonthInput->Size = System::Drawing::Size(56, 26);
			this->ordersEmitMonthInput->TabIndex = 47;
			this->ordersEmitMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersEmitDayInput
			// 
			this->ordersEmitDayInput->Location = System::Drawing::Point(288, 460);
			this->ordersEmitDayInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersEmitDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->ordersEmitDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersEmitDayInput->Name = L"ordersEmitDayInput";
			this->ordersEmitDayInput->Size = System::Drawing::Size(56, 26);
			this->ordersEmitDayInput->TabIndex = 46;
			this->ordersEmitDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersEmitSlash2
			// 
			this->ordersEmitSlash2->AutoSize = true;
			this->ordersEmitSlash2->Location = System::Drawing::Point(433, 464);
			this->ordersEmitSlash2->Name = L"ordersEmitSlash2";
			this->ordersEmitSlash2->Size = System::Drawing::Size(13, 20);
			this->ordersEmitSlash2->TabIndex = 45;
			this->ordersEmitSlash2->Text = L"/";
			// 
			// ordersEmitSlash1
			// 
			this->ordersEmitSlash1->AutoSize = true;
			this->ordersEmitSlash1->Location = System::Drawing::Point(351, 464);
			this->ordersEmitSlash1->Name = L"ordersEmitSlash1";
			this->ordersEmitSlash1->Size = System::Drawing::Size(13, 20);
			this->ordersEmitSlash1->TabIndex = 44;
			this->ordersEmitSlash1->Text = L"/";
			// 
			// ordersDeliveryYearInput
			// 
			this->ordersDeliveryYearInput->Location = System::Drawing::Point(452, 408);
			this->ordersDeliveryYearInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersDeliveryYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->ordersDeliveryYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->ordersDeliveryYearInput->Name = L"ordersDeliveryYearInput";
			this->ordersDeliveryYearInput->Size = System::Drawing::Size(79, 26);
			this->ordersDeliveryYearInput->TabIndex = 43;
			this->ordersDeliveryYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// ordersDeliveryMonthInput
			// 
			this->ordersDeliveryMonthInput->Location = System::Drawing::Point(370, 408);
			this->ordersDeliveryMonthInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersDeliveryMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ordersDeliveryMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersDeliveryMonthInput->Name = L"ordersDeliveryMonthInput";
			this->ordersDeliveryMonthInput->Size = System::Drawing::Size(56, 26);
			this->ordersDeliveryMonthInput->TabIndex = 42;
			this->ordersDeliveryMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersDeliveryDayInput
			// 
			this->ordersDeliveryDayInput->Location = System::Drawing::Point(289, 408);
			this->ordersDeliveryDayInput->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersDeliveryDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->ordersDeliveryDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersDeliveryDayInput->Name = L"ordersDeliveryDayInput";
			this->ordersDeliveryDayInput->Size = System::Drawing::Size(56, 26);
			this->ordersDeliveryDayInput->TabIndex = 41;
			this->ordersDeliveryDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersDdeliverySlash2
			// 
			this->ordersDdeliverySlash2->AutoSize = true;
			this->ordersDdeliverySlash2->Location = System::Drawing::Point(433, 409);
			this->ordersDdeliverySlash2->Name = L"ordersDdeliverySlash2";
			this->ordersDdeliverySlash2->Size = System::Drawing::Size(13, 20);
			this->ordersDdeliverySlash2->TabIndex = 40;
			this->ordersDdeliverySlash2->Text = L"/";
			// 
			// ordersDeliverySlash1
			// 
			this->ordersDeliverySlash1->AutoSize = true;
			this->ordersDeliverySlash1->Location = System::Drawing::Point(351, 411);
			this->ordersDeliverySlash1->Name = L"ordersDeliverySlash1";
			this->ordersDeliverySlash1->Size = System::Drawing::Size(13, 20);
			this->ordersDeliverySlash1->TabIndex = 39;
			this->ordersDeliverySlash1->Text = L"/";
			// 
			// ordersClientSelector
			// 
			this->ordersClientSelector->FormattingEnabled = true;
			this->ordersClientSelector->ItemHeight = 20;
			this->ordersClientSelector->Location = System::Drawing::Point(40, 50);
			this->ordersClientSelector->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersClientSelector->Name = L"ordersClientSelector";
			this->ordersClientSelector->Size = System::Drawing::Size(491, 104);
			this->ordersClientSelector->TabIndex = 24;
			// 
			// ordersPaymentGroup
			// 
			this->ordersPaymentGroup->Controls->Add(this->ordersRemovePayment);
			this->ordersPaymentGroup->Controls->Add(this->ordersNewPayment);
			this->ordersPaymentGroup->Controls->Add(this->ordersPaymentDisplay);
			this->ordersPaymentGroup->Location = System::Drawing::Point(40, 166);
			this->ordersPaymentGroup->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersPaymentGroup->Name = L"ordersPaymentGroup";
			this->ordersPaymentGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersPaymentGroup->Size = System::Drawing::Size(237, 218);
			this->ordersPaymentGroup->TabIndex = 23;
			this->ordersPaymentGroup->TabStop = false;
			this->ordersPaymentGroup->Text = L"Paiements";
			// 
			// ordersRemovePayment
			// 
			this->ordersRemovePayment->Location = System::Drawing::Point(117, 179);
			this->ordersRemovePayment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersRemovePayment->Name = L"ordersRemovePayment";
			this->ordersRemovePayment->Size = System::Drawing::Size(110, 29);
			this->ordersRemovePayment->TabIndex = 2;
			this->ordersRemovePayment->Text = L"Retirer";
			this->ordersRemovePayment->UseVisualStyleBackColor = true;
			// 
			// ordersNewPayment
			// 
			this->ordersNewPayment->Location = System::Drawing::Point(7, 179);
			this->ordersNewPayment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersNewPayment->Name = L"ordersNewPayment";
			this->ordersNewPayment->Size = System::Drawing::Size(104, 29);
			this->ordersNewPayment->TabIndex = 1;
			this->ordersNewPayment->Text = L"Nouveau";
			this->ordersNewPayment->UseVisualStyleBackColor = true;
			// 
			// ordersPaymentDisplay
			// 
			this->ordersPaymentDisplay->BackgroundColor = System::Drawing::SystemColors::Control;
			this->ordersPaymentDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ordersPaymentDisplay->Location = System::Drawing::Point(7, 26);
			this->ordersPaymentDisplay->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->ordersPaymentDisplay->Name = L"ordersPaymentDisplay";
			this->ordersPaymentDisplay->RowHeadersWidth = 51;
			this->ordersPaymentDisplay->RowTemplate->Height = 24;
			this->ordersPaymentDisplay->Size = System::Drawing::Size(220, 150);
			this->ordersPaymentDisplay->TabIndex = 0;
			// 
			// ordersEmitLabel
			// 
			this->ordersEmitLabel->AutoSize = true;
			this->ordersEmitLabel->Location = System::Drawing::Point(63, 464);
			this->ordersEmitLabel->Name = L"ordersEmitLabel";
			this->ordersEmitLabel->Size = System::Drawing::Size(126, 20);
			this->ordersEmitLabel->TabIndex = 22;
			this->ordersEmitLabel->Text = L"Date d\'emission:";
			// 
			// ordersDeliveryLabel
			// 
			this->ordersDeliveryLabel->AutoSize = true;
			this->ordersDeliveryLabel->Location = System::Drawing::Point(63, 409);
			this->ordersDeliveryLabel->Name = L"ordersDeliveryLabel";
			this->ordersDeliveryLabel->Size = System::Drawing::Size(130, 20);
			this->ordersDeliveryLabel->TabIndex = 16;
			this->ordersDeliveryLabel->Text = L"Date de livraison:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(37, 26);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(115, 20);
			this->label23->TabIndex = 5;
			this->label23->Text = L"Choix du client:";
			// 
			// groupBox11
			// 
			this->groupBox11->Location = System::Drawing::Point(0, 539);
			this->groupBox11->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox11->Name = L"groupBox11";
			this->groupBox11->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox11->Size = System::Drawing::Size(439, 61);
			this->groupBox11->TabIndex = 3;
			this->groupBox11->TabStop = false;
			// 
			// statsAverageBasketButton
			// 
			this->statsAverageBasketButton->Location = System::Drawing::Point(25, 111);
			this->statsAverageBasketButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsAverageBasketButton->Name = L"statsAverageBasketButton";
			this->statsAverageBasketButton->Size = System::Drawing::Size(124, 51);
			this->statsAverageBasketButton->TabIndex = 4;
			this->statsAverageBasketButton->Text = L"Panier moyen";
			this->statsAverageBasketButton->UseVisualStyleBackColor = true;
			// 
			// statsTurnoverButton
			// 
			this->statsTurnoverButton->Location = System::Drawing::Point(26, 70);
			this->statsTurnoverButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsTurnoverButton->Name = L"statsTurnoverButton";
			this->statsTurnoverButton->Size = System::Drawing::Size(83, 29);
			this->statsTurnoverButton->TabIndex = 5;
			this->statsTurnoverButton->Text = L"Calculer";
			this->statsTurnoverButton->UseVisualStyleBackColor = true;
			this->statsTurnoverButton->Click += gcnew System::EventHandler(this, &Root::statsTurnoverButton_Click);
			// 
			// statsMonthLabel
			// 
			this->statsMonthLabel->AutoSize = true;
			this->statsMonthLabel->Location = System::Drawing::Point(43, 28);
			this->statsMonthLabel->Name = L"statsMonthLabel";
			this->statsMonthLabel->Size = System::Drawing::Size(50, 20);
			this->statsMonthLabel->TabIndex = 7;
			this->statsMonthLabel->Text = L"Mois: ";
			this->statsMonthLabel->Click += gcnew System::EventHandler(this, &Root::label1_Click);
			// 
			// statsTotalAmountButton
			// 
			this->statsTotalAmountButton->Location = System::Drawing::Point(10, 94);
			this->statsTotalAmountButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsTotalAmountButton->Name = L"statsTotalAmountButton";
			this->statsTotalAmountButton->Size = System::Drawing::Size(109, 30);
			this->statsTotalAmountButton->TabIndex = 9;
			this->statsTotalAmountButton->Text = L"Calculer";
			this->statsTotalAmountButton->UseVisualStyleBackColor = true;
			// 
			// statsCustomerNameLabel
			// 
			this->statsCustomerNameLabel->AutoSize = true;
			this->statsCustomerNameLabel->Location = System::Drawing::Point(7, 51);
			this->statsCustomerNameLabel->Name = L"statsCustomerNameLabel";
			this->statsCustomerNameLabel->Size = System::Drawing::Size(91, 20);
			this->statsCustomerNameLabel->TabIndex = 10;
			this->statsCustomerNameLabel->Text = L"Nom client: ";
			// 
			// statsCustomerNameTextbox
			// 
			this->statsCustomerNameTextbox->Location = System::Drawing::Point(116, 19);
			this->statsCustomerNameTextbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsCustomerNameTextbox->Name = L"statsCustomerNameTextbox";
			this->statsCustomerNameTextbox->Size = System::Drawing::Size(138, 26);
			this->statsCustomerNameTextbox->TabIndex = 11;
			// 
			// statsCustomerFirstnameLabel
			// 
			this->statsCustomerFirstnameLabel->AutoSize = true;
			this->statsCustomerFirstnameLabel->Location = System::Drawing::Point(3, 22);
			this->statsCustomerFirstnameLabel->Name = L"statsCustomerFirstnameLabel";
			this->statsCustomerFirstnameLabel->Size = System::Drawing::Size(113, 20);
			this->statsCustomerFirstnameLabel->TabIndex = 12;
			this->statsCustomerFirstnameLabel->Text = L"Prenom client: ";
			// 
			// statsCustomerFirtsnameTextbox
			// 
			this->statsCustomerFirtsnameTextbox->Location = System::Drawing::Point(118, 51);
			this->statsCustomerFirtsnameTextbox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsCustomerFirtsnameTextbox->Name = L"statsCustomerFirtsnameTextbox";
			this->statsCustomerFirtsnameTextbox->Size = System::Drawing::Size(136, 26);
			this->statsCustomerFirtsnameTextbox->TabIndex = 13;
			// 
			// statsMonthChoiceTurnover
			// 
			this->statsMonthChoiceTurnover->Location = System::Drawing::Point(126, 25);
			this->statsMonthChoiceTurnover->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsMonthChoiceTurnover->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->statsMonthChoiceTurnover->Name = L"statsMonthChoiceTurnover";
			this->statsMonthChoiceTurnover->Size = System::Drawing::Size(100, 26);
			this->statsMonthChoiceTurnover->TabIndex = 14;
			// 
			// statsStockMarketingValueButton
			// 
			this->statsStockMarketingValueButton->Location = System::Drawing::Point(25, 32);
			this->statsStockMarketingValueButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsStockMarketingValueButton->Name = L"statsStockMarketingValueButton";
			this->statsStockMarketingValueButton->Size = System::Drawing::Size(124, 50);
			this->statsStockMarketingValueButton->TabIndex = 17;
			this->statsStockMarketingValueButton->Text = L"Valeur commerciale stock";
			this->statsStockMarketingValueButton->UseVisualStyleBackColor = true;
			// 
			// statsStockPurchaseValueButton
			// 
			this->statsStockPurchaseValueButton->Location = System::Drawing::Point(25, 198);
			this->statsStockPurchaseValueButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsStockPurchaseValueButton->Name = L"statsStockPurchaseValueButton";
			this->statsStockPurchaseValueButton->Size = System::Drawing::Size(126, 50);
			this->statsStockPurchaseValueButton->TabIndex = 18;
			this->statsStockPurchaseValueButton->Text = L"Valeur achat stock";
			this->statsStockPurchaseValueButton->UseVisualStyleBackColor = true;
			// 
			// statsSimulationButton
			// 
			this->statsSimulationButton->Location = System::Drawing::Point(7, 221);
			this->statsSimulationButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->statsSimulationButton->Name = L"statsSimulationButton";
			this->statsSimulationButton->Size = System::Drawing::Size(136, 39);
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
			this->statsGroup->Location = System::Drawing::Point(16, 12);
			this->statsGroup->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->statsGroup->Name = L"statsGroup";
			this->statsGroup->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->statsGroup->Size = System::Drawing::Size(1035, 539);
			this->statsGroup->TabIndex = 0;
			this->statsGroup->TabStop = false;
			this->statsGroup->Text = L"Statistiques";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->dataGridView2);
			this->groupBox6->Location = System::Drawing::Point(18, 300);
			this->groupBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox6->Size = System::Drawing::Size(269, 244);
			this->groupBox6->TabIndex = 36;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"10 articles les moins vendus";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(7, 28);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(255, 209);
			this->dataGridView2->TabIndex = 0;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->dataGridView3);
			this->groupBox8->Location = System::Drawing::Point(569, 300);
			this->groupBox8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox8->Size = System::Drawing::Size(453, 244);
			this->groupBox8->TabIndex = 36;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Produits sous leur seuil de réapprovisionnement";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(7, 28);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(474, 209);
			this->dataGridView3->TabIndex = 0;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->dataGridView1);
			this->groupBox5->Location = System::Drawing::Point(294, 300);
			this->groupBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox5->Size = System::Drawing::Size(269, 244);
			this->groupBox5->TabIndex = 36;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"10 articles les plus vendus";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(7, 28);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(255, 209);
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
			this->groupBox4->Location = System::Drawing::Point(294, 26);
			this->groupBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox4->Size = System::Drawing::Size(426, 266);
			this->groupBox4->TabIndex = 35;
			this->groupBox4->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(168, 214);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 20);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Resultat:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(168, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Resultat:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(168, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 20);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Resultat:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label5);
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
			this->groupBox3->Location = System::Drawing::Point(732, 26);
			this->groupBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox3->Size = System::Drawing::Size(290, 266);
			this->groupBox3->TabIndex = 34;
			this->groupBox3->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(156, 230);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 20);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Résultat:";
			// 
			// statsTVAValueLabel
			// 
			this->statsTVAValueLabel->AutoSize = true;
			this->statsTVAValueLabel->Location = System::Drawing::Point(7, 44);
			this->statsTVAValueLabel->Name = L"statsTVAValueLabel";
			this->statsTVAValueLabel->Size = System::Drawing::Size(82, 20);
			this->statsTVAValueLabel->TabIndex = 22;
			this->statsTVAValueLabel->Text = L"Taux TVA:";
			this->statsTVAValueLabel->Click += gcnew System::EventHandler(this, &Root::label1_Click_1);
			// 
			// statsComMarginValueLabel
			// 
			this->statsComMarginValueLabel->AutoSize = true;
			this->statsComMarginValueLabel->Location = System::Drawing::Point(7, 82);
			this->statsComMarginValueLabel->Name = L"statsComMarginValueLabel";
			this->statsComMarginValueLabel->Size = System::Drawing::Size(151, 20);
			this->statsComMarginValueLabel->TabIndex = 23;
			this->statsComMarginValueLabel->Text = L"Marge commerciale:";
			this->statsComMarginValueLabel->Click += gcnew System::EventHandler(this, &Root::label2_Click);
			// 
			// statsComDiscountValueLabel
			// 
			this->statsComDiscountValueLabel->AutoSize = true;
			this->statsComDiscountValueLabel->Location = System::Drawing::Point(7, 125);
			this->statsComDiscountValueLabel->Name = L"statsComDiscountValueLabel";
			this->statsComDiscountValueLabel->Size = System::Drawing::Size(160, 20);
			this->statsComDiscountValueLabel->TabIndex = 24;
			this->statsComDiscountValueLabel->Text = L"Remise commerciale:";
			// 
			// statsUnknownMarkdownPercentLabel
			// 
			this->statsUnknownMarkdownPercentLabel->AutoSize = true;
			this->statsUnknownMarkdownPercentLabel->Location = System::Drawing::Point(235, 171);
			this->statsUnknownMarkdownPercentLabel->Name = L"statsUnknownMarkdownPercentLabel";
			this->statsUnknownMarkdownPercentLabel->Size = System::Drawing::Size(23, 20);
			this->statsUnknownMarkdownPercentLabel->TabIndex = 31;
			this->statsUnknownMarkdownPercentLabel->Text = L"%";
			// 
			// statsUnknownMarkdownLabel
			// 
			this->statsUnknownMarkdownLabel->AutoSize = true;
			this->statsUnknownMarkdownLabel->Location = System::Drawing::Point(7, 171);
			this->statsUnknownMarkdownLabel->Name = L"statsUnknownMarkdownLabel";
			this->statsUnknownMarkdownLabel->Size = System::Drawing::Size(157, 20);
			this->statsUnknownMarkdownLabel->TabIndex = 25;
			this->statsUnknownMarkdownLabel->Text = L"Démarque inconnue:";
			this->statsUnknownMarkdownLabel->Click += gcnew System::EventHandler(this, &Root::label4_Click);
			// 
			// statsComDiscountPercentLabel
			// 
			this->statsComDiscountPercentLabel->AutoSize = true;
			this->statsComDiscountPercentLabel->Location = System::Drawing::Point(234, 125);
			this->statsComDiscountPercentLabel->Name = L"statsComDiscountPercentLabel";
			this->statsComDiscountPercentLabel->Size = System::Drawing::Size(23, 20);
			this->statsComDiscountPercentLabel->TabIndex = 29;
			this->statsComDiscountPercentLabel->Text = L"%";
			// 
			// statsUnknownMarkdownNumericUpDown
			// 
			this->statsUnknownMarkdownNumericUpDown->Location = System::Drawing::Point(169, 166);
			this->statsUnknownMarkdownNumericUpDown->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->statsUnknownMarkdownNumericUpDown->Name = L"statsUnknownMarkdownNumericUpDown";
			this->statsUnknownMarkdownNumericUpDown->Size = System::Drawing::Size(60, 26);
			this->statsUnknownMarkdownNumericUpDown->TabIndex = 30;
			this->statsUnknownMarkdownNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// statsComMarginPercentLabel
			// 
			this->statsComMarginPercentLabel->AutoSize = true;
			this->statsComMarginPercentLabel->Location = System::Drawing::Point(235, 82);
			this->statsComMarginPercentLabel->Name = L"statsComMarginPercentLabel";
			this->statsComMarginPercentLabel->Size = System::Drawing::Size(23, 20);
			this->statsComMarginPercentLabel->TabIndex = 27;
			this->statsComMarginPercentLabel->Text = L"%";
			// 
			// statsTVAValueNumericUpDown
			// 
			this->statsTVAValueNumericUpDown->Location = System::Drawing::Point(169, 40);
			this->statsTVAValueNumericUpDown->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->statsTVAValueNumericUpDown->Name = L"statsTVAValueNumericUpDown";
			this->statsTVAValueNumericUpDown->Size = System::Drawing::Size(60, 26);
			this->statsTVAValueNumericUpDown->TabIndex = 22;
			this->statsTVAValueNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// statsTVAPercentLabel
			// 
			this->statsTVAPercentLabel->AutoSize = true;
			this->statsTVAPercentLabel->Location = System::Drawing::Point(235, 45);
			this->statsTVAPercentLabel->Name = L"statsTVAPercentLabel";
			this->statsTVAPercentLabel->Size = System::Drawing::Size(23, 20);
			this->statsTVAPercentLabel->TabIndex = 22;
			this->statsTVAPercentLabel->Text = L"%";
			// 
			// statsComMarginValueNumericUpDown
			// 
			this->statsComMarginValueNumericUpDown->Location = System::Drawing::Point(169, 80);
			this->statsComMarginValueNumericUpDown->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->statsComMarginValueNumericUpDown->Name = L"statsComMarginValueNumericUpDown";
			this->statsComMarginValueNumericUpDown->Size = System::Drawing::Size(60, 26);
			this->statsComMarginValueNumericUpDown->TabIndex = 26;
			this->statsComMarginValueNumericUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// statsComDiscountValueNumericUpDown
			// 
			this->statsComDiscountValueNumericUpDown->Location = System::Drawing::Point(169, 122);
			this->statsComDiscountValueNumericUpDown->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->statsComDiscountValueNumericUpDown->Name = L"statsComDiscountValueNumericUpDown";
			this->statsComDiscountValueNumericUpDown->Size = System::Drawing::Size(60, 26);
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
			this->groupBox2->Location = System::Drawing::Point(18, 140);
			this->groupBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox2->Size = System::Drawing::Size(269, 152);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Montant total achat client";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->statsTurnoverButton);
			this->groupBox1->Controls->Add(this->statsMonthChoiceTurnover);
			this->groupBox1->Controls->Add(this->statsMonthLabel);
			this->groupBox1->Location = System::Drawing::Point(18, 26);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Size = System::Drawing::Size(269, 106);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Chiffre d\'affaires";
			// 
			// backButton
			// 
			this->backButton->Location = System::Drawing::Point(17, 699);
			this->backButton->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(133, 61);
			this->backButton->TabIndex = 8;
			this->backButton->Text = L"Retour";
			this->backButton->UseVisualStyleBackColor = true;
			// 
			// Root
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2564, 1410);
			this->Controls->Add(this->categoriesGroup);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->validateGroup);
			this->Controls->Add(this->visualizeGroup);
			this->Controls->Add(this->ordersGroup);
			this->Controls->Add(this->statsGroup);
			this->Controls->Add(this->customerGroup);
			this->Controls->Add(this->productGroup);
			this->Controls->Add(this->staffGroup);
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->Name = L"Root";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Root";
			this->Load += gcnew System::EventHandler(this, &Root::Root_Load);
			this->categoriesGroup->ResumeLayout(false);
			this->categoriesGroup->PerformLayout();
			this->productGroup->ResumeLayout(false);
			this->productGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productRestockThresholdInput))->EndInit();
			this->productDiscountGroup->ResumeLayout(false);
			this->productDiscountGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productCountWeightInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productBaseDiscountInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productTaxesInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productStockInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productPurchasePriceInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->productUHTPriceInput))->EndInit();
			this->visualizeGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualizeGrid))->EndInit();
			this->staffGroup->ResumeLayout(false);
			this->staffGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredDayInput))->EndInit();
			this->staffAddressGroup->ResumeLayout(false);
			this->staffAddressGroup->PerformLayout();
			this->validateGroup->ResumeLayout(false);
			this->validateGroup->PerformLayout();
			this->customerGroup->ResumeLayout(false);
			this->customerGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerFPDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerFPYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerFPMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthMonthInput))->EndInit();
			this->customerInvoiceGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerInvoiceDisplay))->EndInit();
			this->customerDeliveryGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerDeliveryDisplay))->EndInit();
			this->ordersGroup->ResumeLayout(false);
			this->ordersGroup->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryDayInput))->EndInit();
			this->ordersPaymentGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersPaymentDisplay))->EndInit();
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
			if (mode == 2) {
				ProductData product = ProductData();
				product.name = this->productNameInput->Text;
				product.priceNoTax = (float)this->productUHTPriceInput->Value;
				product.purchaseValue = (float)this->productPurchasePriceInput->Value;
				product.amount = (int)this->productStockInput->Value;
				product.TVARatio = (float)this->productTaxesInput->Value;  // TODO: change this to convert from % to in range [0, 1]
				product.discountRatio = (float)this->productBaseDiscountInput->Value;  // TODO: same as above
				product.restockThreshold = (int)this->productRestockThresholdInput->Value;

				if (this->is_editing) {
					int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
					auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
					int selected_id = Int32::Parse(selected_row[0]->ToString());
					product = this->supply->editProduct(selected_id, product);

				}
				else {
					product = this->supply->addProduct(product);
				}
				this->refreshGrid();
			}

			if (mode == 1) {
				StaffMemberData infos = StaffMemberData();
				infos.firstName = this->staffFNameInput->Text;
				infos.lastName = this->staffLNameInput->Text;
				infos.hireDate = gcnew DateTime(Convert::ToInt32(this->staffHiredYearInput->Value), Convert::ToInt32(this->staffHiredMonthInput->Value), Convert::ToInt32(this->staffHiredDayInput->Value));
				int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
				auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
				int selected_id = Int32::Parse(selected_row[0]->ToString());
				infos.superior = selected_id;
				infos.address.streetNum = this->staffAddressNumberInput->Text;
				infos.address.streetName = this->staffAddressStreetInput->Text;
				infos.address.cityName = this->staffAddressCityInput->Text;
				infos.address.cityCode = this->staffAddressCityCodeInput->Text;

				if (this->is_editing) {
					int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
					auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
					int selected_id = Int32::Parse(selected_row[0]->ToString());
					infos = this->staff->editStaff(selected_id, infos);
				}
				else {
					infos = this->staff->addStaff(infos);
				}
				this->refreshGrid();
			}

			if (mode == 3) {
				CustomerData data = CustomerData();
				data.firstName = this->customerFNameInput->Text;
				data.lastName = this->customerLNameInput->Text;
				data.birth = gcnew DateTime(Convert::ToInt32(this->customerBirthYearInput->Value), Convert::ToInt32(this->customerBirthMonthInput->Value), Convert::ToInt32(this->customerBirthDayInput->Value));
				data.email = this->customerMailNameInput->Text + "@" + this->customerMailDomainInput->Text + "." + this->customerMailExtInput->ValueMember;
				data.phoneNumber = this->customerPhoneNumberInput->Text;
				data.firstPurchase = gcnew DateTime(Convert::ToInt32(this->customerFPYearInput->Value), Convert::ToInt32(this->customerFPMonthInput->Value), Convert::ToInt32(this->customerFPDayInput->Value));
				data.invoiceAdresses = selectInvoiceAddress->ToArray();
				selectInvoiceAddress->Clear();
				data.deliveryAddresses = selectDeliveryAddress->ToArray();
				selectDeliveryAddress->Clear();

				if (this->is_editing) {
					int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
					auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
					int selected_id = Int32::Parse(selected_row[0]->ToString());
					data = this->customer->editCustomer(selected_id, data);
				}
				else {
					data = this->customer->addCustomer(data);
				}
				this->refreshGrid();
			}

			if (mode == 4) {
				OrderData order = OrderData();
				int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
				auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
				String^ selected_ref = Convert::ToString(selected_row[1]);
				order.ref = selected_ref;
				order.deliveryDate = gcnew DateTime(Convert::ToInt32(this->ordersDeliveryYearInput->Value), Convert::ToInt32(this->ordersDeliveryMonthInput->Value), Convert::ToInt32(this->ordersDeliveryDayInput->Value));
				order.emissionDate = gcnew DateTime(Convert::ToInt32(this->ordersEmitYearInput->Value), Convert::ToInt32(this->ordersEmitMonthInput->Value), Convert::ToInt32(this->ordersEmitDayInput->Value));
				order.items = selectOrderItem->ToArray();
				selectOrderItem->Clear();
				order.payments = selectPayments->ToArray();
				selectPayments->Clear();
				int row_index2 = this->visualizeGrid->SelectedCells[0]->RowIndex;
				auto selected_customer = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index2]->ItemArray;
				int customer_id = Int32::Parse(selected_customer[9]->ToString());
				order.customer = this->customer->getCustomer(customer_id);

				if (this->is_editing) {
					int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
					auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
					int selected_id = Int32::Parse(selected_row[0]->ToString());
					order = this->order->editOrder(selected_id, order);
				}
				else {
					order = this->order->addOrder(order);
				}
				this->refreshGrid();
			}
		}

		void visualizeDeleteButton_Click(Object^ sender, EventArgs^ e) {
			int row_index = this->visualizeGrid->SelectedCells[0]->RowIndex;
			auto selected_row = safe_cast<DataTable^>(this->visualizeGrid->DataSource)->Rows[row_index]->ItemArray;
			int selected_id = Int32::Parse(selected_row[0]->ToString());
			this->supply->removeProduct(selected_id);
			this->refreshGrid();
		}
		void addRadioButton_Selected(Object^ sender, EventArgs^ e) {
			this->EditRadioButton->Checked = false;
			this->addRadioButton->Checked = true;
			this->is_editing = false;
		}
		void editRadioButton_Selected(Object^ sender, EventArgs^ e) {
			this->addRadioButton->Checked = false;
			this->EditRadioButton->Checked = true;
			this->is_editing = true;
		}

		void staffManagerButton_click(Object^ sender, EventArgs^ e) {
			this->categoriesGroup->Visible = false;
			this->visualizeGroup->Visible = true;
			this->backButton->Visible = true;
			this->validateGroup->Visible = true;
			this->staffGroup->Visible = true;
			mode = 1;
			for each(DataRow^ row in this->staff->getAllStaff()->Rows) {

			this->staffSuperiorSelector->Items->Add("nomSup, prenomSup");
			}
			this->refreshGrid();
		}

		void supplyManagerButton_click(Object^ sender, EventArgs^ e) {
			this->categoriesGroup->Visible = false;
			this->visualizeGroup->Visible = true;
			this->backButton->Visible = true;
			this->validateGroup->Visible = true;
			this->productGroup->Visible = true;
			mode = 2;
			this->refreshGrid();
		}

		void customerManagerButton_click(Object^ sender, EventArgs^ e) {
			this->categoriesGroup->Visible = false;
			this->visualizeGroup->Visible = true;
			this->backButton->Visible = true;
			this->validateGroup->Visible = true;
			this->customerGroup->Visible = true;
			mode = 3;
			this->refreshGrid();
		}

		void ordersManagerButton_click(Object^ sender, EventArgs^ e) {
			this->categoriesGroup->Visible = false;
			this->visualizeGroup->Visible = true;
			this->backButton->Visible = true;
			this->validateGroup->Visible = true;
			this->ordersGroup->Visible = true;
			mode = 4;
			this->refreshGrid();
		}

		void statsManagerButton_click(Object^ sender, EventArgs^ e) {
			this->categoriesGroup->Visible = false;
			this->backButton->Visible = true;
			this->statsGroup->Visible = true;
		}

		void backButton_click(Object^ sender, EventArgs^ e) {
			this->visualizeGroup->Visible = false;
			this->backButton->Visible = false;
			this->validateGroup->Visible = false;
			this->productGroup->Visible = false;
			this->customerGroup->Visible = false;
			this->staffGroup->Visible = false;
			this->ordersGroup->Visible = false;
			this->statsGroup->Visible = false;
			this->categoriesGroup->Visible = true;
		}
	private: System::Void label4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void customerGroup_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customerBirthDayInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customerBirthSlash2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customerBirthSlash1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customerBirthMonthInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customerBirthYearInput_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
		
}
