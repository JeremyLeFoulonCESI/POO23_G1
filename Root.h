#pragma once

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
	public:
		Root(void)
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
	private: System::Windows::Forms::GroupBox^ clientGroup;




















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

private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::ListBox^ listBox3;
private: System::Windows::Forms::GroupBox^ staffAddressGroup;

private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::TextBox^ textBox22;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::TextBox^ textBox24;
private: System::Windows::Forms::TextBox^ textBox25;
private: System::Windows::Forms::Label^ label31;
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

























private: System::Windows::Forms::NumericUpDown^ customerBirthDayInput;
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

private: System::Windows::Forms::GroupBox^ stockGroup;

private: System::Windows::Forms::NumericUpDown^ numericUpDown20;
private: System::Windows::Forms::Label^ label37;
private: System::Windows::Forms::GroupBox^ groupBox18;
private: System::Windows::Forms::Label^ label38;
private: System::Windows::Forms::NumericUpDown^ numericUpDown21;
private: System::Windows::Forms::NumericUpDown^ numericUpDown22;
private: System::Windows::Forms::Label^ label39;
private: System::Windows::Forms::Label^ label40;
private: System::Windows::Forms::Label^ label41;
private: System::Windows::Forms::NumericUpDown^ numericUpDown23;
private: System::Windows::Forms::Label^ label42;
private: System::Windows::Forms::Label^ label43;
private: System::Windows::Forms::NumericUpDown^ numericUpDown24;
private: System::Windows::Forms::NumericUpDown^ numericUpDown25;
private: System::Windows::Forms::NumericUpDown^ numericUpDown26;
private: System::Windows::Forms::ComboBox^ comboBox5;
private: System::Windows::Forms::Label^ label44;
private: System::Windows::Forms::ComboBox^ comboBox6;
private: System::Windows::Forms::Label^ label45;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::Label^ label46;
private: System::Windows::Forms::GroupBox^ groupBox19;
private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::GroupBox^ statsGroup;
private: System::Windows::Forms::Button^ vlisualizeDeleteButton;












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
			this->staffCategoryButton = (gcnew System::Windows::Forms::Button());
			this->stockCategoryButton = (gcnew System::Windows::Forms::Button());
			this->customersCategoryButton = (gcnew System::Windows::Forms::Button());
			this->ordersCategoryButton = (gcnew System::Windows::Forms::Button());
			this->statsCategoryButton = (gcnew System::Windows::Forms::Button());
			this->visualizeGroup = (gcnew System::Windows::Forms::GroupBox());
			this->visualizeGrid = (gcnew System::Windows::Forms::DataGridView());
			this->validateGroup = (gcnew System::Windows::Forms::GroupBox());
			this->validateButton = (gcnew System::Windows::Forms::Button());
			this->addRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->EditRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->clientGroup = (gcnew System::Windows::Forms::GroupBox());
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
			this->ordersClientSelector = (gcnew System::Windows::Forms::ListBox());
			this->ordersPaymentGroup = (gcnew System::Windows::Forms::GroupBox());
			this->ordersRemovePayment = (gcnew System::Windows::Forms::Button());
			this->ordersNewPayment = (gcnew System::Windows::Forms::Button());
			this->ordersPaymentDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->ordersEmitLabel = (gcnew System::Windows::Forms::Label());
			this->ordersDeliveryLabel = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->groupBox11 = (gcnew System::Windows::Forms::GroupBox());
			this->customerDeliveryGroup = (gcnew System::Windows::Forms::GroupBox());
			this->CustomerRemoveDeliveryButton = (gcnew System::Windows::Forms::Button());
			this->customerNewDeliveryButton = (gcnew System::Windows::Forms::Button());
			this->customerDeliveryDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->customerInvoiceGroup = (gcnew System::Windows::Forms::GroupBox());
			this->customerRemoveInvoiceButton = (gcnew System::Windows::Forms::Button());
			this->CustomerNewInvoiceButton = (gcnew System::Windows::Forms::Button());
			this->customerInvoiceDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->staffGroup = (gcnew System::Windows::Forms::GroupBox());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->staffAddressGroup = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->staffHiredLabel = (gcnew System::Windows::Forms::Label());
			this->staffFNameLabel = (gcnew System::Windows::Forms::Label());
			this->staffLNameLabel = (gcnew System::Windows::Forms::Label());
			this->staffFNameInput = (gcnew System::Windows::Forms::TextBox());
			this->staffLNameInput = (gcnew System::Windows::Forms::TextBox());
			this->groupBox16 = (gcnew System::Windows::Forms::GroupBox());
			this->staffHiredYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->staffHiredMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->staffHiredDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->staffHiredSlash2 = (gcnew System::Windows::Forms::Label());
			this->staffHiredSlash1 = (gcnew System::Windows::Forms::Label());
			this->customerBirthYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerBirthMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerBirthDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->customerBirthSlash2 = (gcnew System::Windows::Forms::Label());
			this->customerBirthSlash1 = (gcnew System::Windows::Forms::Label());
			this->ordersDeliveryYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersDeliveryMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersDeliveryDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersDdeliverySlash2 = (gcnew System::Windows::Forms::Label());
			this->ordersDeliverySlash1 = (gcnew System::Windows::Forms::Label());
			this->ordersEmitYearInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersEmitMonthInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersEmitDayInput = (gcnew System::Windows::Forms::NumericUpDown());
			this->ordersEmitSlash2 = (gcnew System::Windows::Forms::Label());
			this->ordersEmitSlash1 = (gcnew System::Windows::Forms::Label());
			this->stockGroup = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDown20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->groupBox18 = (gcnew System::Windows::Forms::GroupBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown21 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown22 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown23 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown24 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown25 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown26 = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->groupBox19 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->statsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->vlisualizeDeleteButton = (gcnew System::Windows::Forms::Button());
			this->categoriesGroup->SuspendLayout();
			this->visualizeGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->visualizeGrid))->BeginInit();
			this->validateGroup->SuspendLayout();
			this->clientGroup->SuspendLayout();
			this->ordersGroup->SuspendLayout();
			this->ordersPaymentGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersPaymentDisplay))->BeginInit();
			this->customerDeliveryGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerDeliveryDisplay))->BeginInit();
			this->customerInvoiceGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerInvoiceDisplay))->BeginInit();
			this->staffGroup->SuspendLayout();
			this->staffAddressGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryDayInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitYearInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitMonthInput))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitDayInput))->BeginInit();
			this->stockGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown20))->BeginInit();
			this->groupBox18->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown26))->BeginInit();
			this->statsGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// categoriesGroup
			// 
			this->categoriesGroup->Controls->Add(this->statsCategoryButton);
			this->categoriesGroup->Controls->Add(this->ordersCategoryButton);
			this->categoriesGroup->Controls->Add(this->customersCategoryButton);
			this->categoriesGroup->Controls->Add(this->stockCategoryButton);
			this->categoriesGroup->Controls->Add(this->staffCategoryButton);
			this->categoriesGroup->Location = System::Drawing::Point(12, 12);
			this->categoriesGroup->Name = L"categoriesGroup";
			this->categoriesGroup->Size = System::Drawing::Size(140, 480);
			this->categoriesGroup->TabIndex = 0;
			this->categoriesGroup->TabStop = false;
			this->categoriesGroup->Text = L"Catégories";
			// 
			// staffCategoryButton
			// 
			this->staffCategoryButton->Location = System::Drawing::Point(10, 50);
			this->staffCategoryButton->Name = L"staffCategoryButton";
			this->staffCategoryButton->Size = System::Drawing::Size(120, 35);
			this->staffCategoryButton->TabIndex = 100;
			this->staffCategoryButton->TabStop = false;
			this->staffCategoryButton->Text = L"Personnel";
			this->staffCategoryButton->UseVisualStyleBackColor = true;
			// 
			// stockCategoryButton
			// 
			this->stockCategoryButton->Location = System::Drawing::Point(10, 135);
			this->stockCategoryButton->Name = L"stockCategoryButton";
			this->stockCategoryButton->Size = System::Drawing::Size(120, 35);
			this->stockCategoryButton->TabIndex = 101;
			this->stockCategoryButton->TabStop = false;
			this->stockCategoryButton->Text = L"Stock";
			this->stockCategoryButton->UseVisualStyleBackColor = true;
			// 
			// customersCategoryButton
			// 
			this->customersCategoryButton->Location = System::Drawing::Point(10, 220);
			this->customersCategoryButton->Name = L"customersCategoryButton";
			this->customersCategoryButton->Size = System::Drawing::Size(120, 35);
			this->customersCategoryButton->TabIndex = 102;
			this->customersCategoryButton->TabStop = false;
			this->customersCategoryButton->Text = L"Clients";
			this->customersCategoryButton->UseVisualStyleBackColor = true;
			// 
			// ordersCategoryButton
			// 
			this->ordersCategoryButton->Location = System::Drawing::Point(10, 305);
			this->ordersCategoryButton->Name = L"ordersCategoryButton";
			this->ordersCategoryButton->Size = System::Drawing::Size(120, 35);
			this->ordersCategoryButton->TabIndex = 103;
			this->ordersCategoryButton->TabStop = false;
			this->ordersCategoryButton->Text = L"Commandes";
			this->ordersCategoryButton->UseVisualStyleBackColor = true;
			// 
			// statsCategoryButton
			// 
			this->statsCategoryButton->Location = System::Drawing::Point(10, 390);
			this->statsCategoryButton->Name = L"statsCategoryButton";
			this->statsCategoryButton->Size = System::Drawing::Size(120, 35);
			this->statsCategoryButton->TabIndex = 104;
			this->statsCategoryButton->TabStop = false;
			this->statsCategoryButton->Text = L"Statistiques";
			this->statsCategoryButton->UseVisualStyleBackColor = true;
			// 
			// visualizeGroup
			// 
			this->visualizeGroup->Controls->Add(this->vlisualizeDeleteButton);
			this->visualizeGroup->Controls->Add(this->visualizeGrid);
			this->visualizeGroup->Cursor = System::Windows::Forms::Cursors::Hand;
			this->visualizeGroup->Location = System::Drawing::Point(554, 12);
			this->visualizeGroup->Name = L"visualizeGroup";
			this->visualizeGroup->Size = System::Drawing::Size(390, 480);
			this->visualizeGroup->TabIndex = 2;
			this->visualizeGroup->TabStop = false;
			this->visualizeGroup->Text = L"Visualisation des données";
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
			this->validateGroup->Location = System::Drawing::Point(158, 436);
			this->validateGroup->Name = L"validateGroup";
			this->validateGroup->Size = System::Drawing::Size(390, 56);
			this->validateGroup->TabIndex = 3;
			this->validateGroup->TabStop = false;
			this->validateGroup->Text = L"Validation";
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
			// clientGroup
			// 
			this->clientGroup->Controls->Add(this->customerBirthYearInput);
			this->clientGroup->Controls->Add(this->customerBirthMonthInput);
			this->clientGroup->Controls->Add(this->customerBirthDayInput);
			this->clientGroup->Controls->Add(this->customerBirthSlash2);
			this->clientGroup->Controls->Add(this->customerBirthSlash1);
			this->clientGroup->Controls->Add(this->customerInvoiceGroup);
			this->clientGroup->Controls->Add(this->customerDeliveryGroup);
			this->clientGroup->Controls->Add(this->label10);
			this->clientGroup->Controls->Add(this->textBox9);
			this->clientGroup->Controls->Add(this->customerMailDotLabel);
			this->clientGroup->Controls->Add(this->customerMailAtLabel);
			this->clientGroup->Controls->Add(this->customerMailExtInput);
			this->clientGroup->Controls->Add(this->customerMailDomainInput);
			this->clientGroup->Controls->Add(this->customerMailNameInput);
			this->clientGroup->Controls->Add(this->customerMailLabel);
			this->clientGroup->Controls->Add(this->customerBirthLabel);
			this->clientGroup->Controls->Add(this->customerFNameLabel);
			this->clientGroup->Controls->Add(this->customerLNameLabel);
			this->clientGroup->Controls->Add(this->customerFNameInput);
			this->clientGroup->Controls->Add(this->customerLNameInput);
			this->clientGroup->Controls->Add(this->groupBox7);
			this->clientGroup->Location = System::Drawing::Point(997, 12);
			this->clientGroup->Name = L"clientGroup";
			this->clientGroup->Size = System::Drawing::Size(390, 425);
			this->clientGroup->TabIndex = 4;
			this->clientGroup->TabStop = false;
			this->clientGroup->Text = L"Edition des données client";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(21, 182);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(76, 16);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Téléphone:";
			// 
			// textBox9
			// 
			this->textBox9->AcceptsTab = true;
			this->textBox9->Location = System::Drawing::Point(100, 179);
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
			this->customerMailDotLabel->Location = System::Drawing::Point(301, 133);
			this->customerMailDotLabel->Name = L"customerMailDotLabel";
			this->customerMailDotLabel->Size = System::Drawing::Size(10, 16);
			this->customerMailDotLabel->TabIndex = 16;
			this->customerMailDotLabel->Text = L".";
			// 
			// customerMailAtLabel
			// 
			this->customerMailAtLabel->AutoSize = true;
			this->customerMailAtLabel->Location = System::Drawing::Point(176, 133);
			this->customerMailAtLabel->Name = L"customerMailAtLabel";
			this->customerMailAtLabel->Size = System::Drawing::Size(21, 16);
			this->customerMailAtLabel->TabIndex = 15;
			this->customerMailAtLabel->Text = L"@";
			// 
			// customerMailExtInput
			// 
			this->customerMailExtInput->FormattingEnabled = true;
			this->customerMailExtInput->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"com", L"net", L"fr", L"be", L"de",
					L"it", L"en", L"us", L"tv", L"ie", L"eu"
			});
			this->customerMailExtInput->Location = System::Drawing::Point(317, 130);
			this->customerMailExtInput->MaxLength = 3;
			this->customerMailExtInput->Name = L"customerMailExtInput";
			this->customerMailExtInput->Size = System::Drawing::Size(55, 24);
			this->customerMailExtInput->TabIndex = 7;
			this->customerMailExtInput->TabStop = false;
			// 
			// customerMailDomainInput
			// 
			this->customerMailDomainInput->AcceptsTab = true;
			this->customerMailDomainInput->Location = System::Drawing::Point(199, 130);
			this->customerMailDomainInput->MaxLength = 4;
			this->customerMailDomainInput->Name = L"customerMailDomainInput";
			this->customerMailDomainInput->Size = System::Drawing::Size(100, 22);
			this->customerMailDomainInput->TabIndex = 6;
			// 
			// customerMailNameInput
			// 
			this->customerMailNameInput->AcceptsTab = true;
			this->customerMailNameInput->Location = System::Drawing::Point(62, 130);
			this->customerMailNameInput->Name = L"customerMailNameInput";
			this->customerMailNameInput->Size = System::Drawing::Size(113, 22);
			this->customerMailNameInput->TabIndex = 5;
			this->customerMailNameInput->TabStop = false;
			// 
			// customerMailLabel
			// 
			this->customerMailLabel->AutoSize = true;
			this->customerMailLabel->Location = System::Drawing::Point(21, 133);
			this->customerMailLabel->Name = L"customerMailLabel";
			this->customerMailLabel->Size = System::Drawing::Size(35, 16);
			this->customerMailLabel->TabIndex = 11;
			this->customerMailLabel->Text = L"Mail:";
			// 
			// customerBirthLabel
			// 
			this->customerBirthLabel->AutoSize = true;
			this->customerBirthLabel->Location = System::Drawing::Point(20, 84);
			this->customerBirthLabel->Name = L"customerBirthLabel";
			this->customerBirthLabel->Size = System::Drawing::Size(58, 16);
			this->customerBirthLabel->TabIndex = 8;
			this->customerBirthLabel->Text = L"Né(e) le:";
			// 
			// customerFNameLabel
			// 
			this->customerFNameLabel->AutoSize = true;
			this->customerFNameLabel->Location = System::Drawing::Point(188, 37);
			this->customerFNameLabel->Name = L"customerFNameLabel";
			this->customerFNameLabel->Size = System::Drawing::Size(57, 16);
			this->customerFNameLabel->TabIndex = 7;
			this->customerFNameLabel->Text = L"Prénom:";
			// 
			// customerLNameLabel
			// 
			this->customerLNameLabel->AutoSize = true;
			this->customerLNameLabel->Location = System::Drawing::Point(17, 37);
			this->customerLNameLabel->Name = L"customerLNameLabel";
			this->customerLNameLabel->Size = System::Drawing::Size(39, 16);
			this->customerLNameLabel->TabIndex = 6;
			this->customerLNameLabel->Text = L"Nom:";
			// 
			// customerFNameInput
			// 
			this->customerFNameInput->AcceptsTab = true;
			this->customerFNameInput->Location = System::Drawing::Point(247, 34);
			this->customerFNameInput->Name = L"customerFNameInput";
			this->customerFNameInput->Size = System::Drawing::Size(123, 22);
			this->customerFNameInput->TabIndex = 1;
			this->customerFNameInput->TabStop = false;
			// 
			// customerLNameInput
			// 
			this->customerLNameInput->AcceptsTab = true;
			this->customerLNameInput->Location = System::Drawing::Point(59, 34);
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
			this->ordersGroup->Location = System::Drawing::Point(997, 443);
			this->ordersGroup->Name = L"ordersGroup";
			this->ordersGroup->Size = System::Drawing::Size(390, 425);
			this->ordersGroup->TabIndex = 5;
			this->ordersGroup->TabStop = false;
			this->ordersGroup->Text = L"Edition de commandes";
			// 
			// ordersClientSelector
			// 
			this->ordersClientSelector->FormattingEnabled = true;
			this->ordersClientSelector->ItemHeight = 16;
			this->ordersClientSelector->Location = System::Drawing::Point(14, 40);
			this->ordersClientSelector->Name = L"ordersClientSelector";
			this->ordersClientSelector->Size = System::Drawing::Size(346, 84);
			this->ordersClientSelector->TabIndex = 24;
			// 
			// ordersPaymentGroup
			// 
			this->ordersPaymentGroup->Controls->Add(this->ordersRemovePayment);
			this->ordersPaymentGroup->Controls->Add(this->ordersNewPayment);
			this->ordersPaymentGroup->Controls->Add(this->ordersPaymentDisplay);
			this->ordersPaymentGroup->Location = System::Drawing::Point(14, 156);
			this->ordersPaymentGroup->Name = L"ordersPaymentGroup";
			this->ordersPaymentGroup->Size = System::Drawing::Size(346, 144);
			this->ordersPaymentGroup->TabIndex = 23;
			this->ordersPaymentGroup->TabStop = false;
			this->ordersPaymentGroup->Text = L"Paiements";
			// 
			// ordersRemovePayment
			// 
			this->ordersRemovePayment->Location = System::Drawing::Point(171, 116);
			this->ordersRemovePayment->Name = L"ordersRemovePayment";
			this->ordersRemovePayment->Size = System::Drawing::Size(165, 23);
			this->ordersRemovePayment->TabIndex = 2;
			this->ordersRemovePayment->Text = L"Retirer";
			this->ordersRemovePayment->UseVisualStyleBackColor = true;
			// 
			// ordersNewPayment
			// 
			this->ordersNewPayment->Location = System::Drawing::Point(6, 116);
			this->ordersNewPayment->Name = L"ordersNewPayment";
			this->ordersNewPayment->Size = System::Drawing::Size(165, 23);
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
			this->ordersPaymentDisplay->Size = System::Drawing::Size(330, 95);
			this->ordersPaymentDisplay->TabIndex = 0;
			// 
			// ordersEmitLabel
			// 
			this->ordersEmitLabel->AutoSize = true;
			this->ordersEmitLabel->Location = System::Drawing::Point(6, 390);
			this->ordersEmitLabel->Name = L"ordersEmitLabel";
			this->ordersEmitLabel->Size = System::Drawing::Size(107, 16);
			this->ordersEmitLabel->TabIndex = 22;
			this->ordersEmitLabel->Text = L"Date d\'émission:";
			// 
			// ordersDeliveryLabel
			// 
			this->ordersDeliveryLabel->AutoSize = true;
			this->ordersDeliveryLabel->Location = System::Drawing::Point(6, 337);
			this->ordersDeliveryLabel->Name = L"ordersDeliveryLabel";
			this->ordersDeliveryLabel->Size = System::Drawing::Size(156, 16);
			this->ordersDeliveryLabel->TabIndex = 16;
			this->ordersDeliveryLabel->Text = L"Date prévue de livraison:";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(11, 21);
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
			// customerDeliveryGroup
			// 
			this->customerDeliveryGroup->Controls->Add(this->CustomerRemoveDeliveryButton);
			this->customerDeliveryGroup->Controls->Add(this->customerNewDeliveryButton);
			this->customerDeliveryGroup->Controls->Add(this->customerDeliveryDisplay);
			this->customerDeliveryGroup->Location = System::Drawing::Point(23, 167);
			this->customerDeliveryGroup->Name = L"customerDeliveryGroup";
			this->customerDeliveryGroup->Size = System::Drawing::Size(346, 115);
			this->customerDeliveryGroup->TabIndex = 24;
			this->customerDeliveryGroup->TabStop = false;
			this->customerDeliveryGroup->Text = L"Adresses de livraison";
			// 
			// CustomerRemoveDeliveryButton
			// 
			this->CustomerRemoveDeliveryButton->Location = System::Drawing::Point(171, 87);
			this->CustomerRemoveDeliveryButton->Name = L"CustomerRemoveDeliveryButton";
			this->CustomerRemoveDeliveryButton->Size = System::Drawing::Size(165, 23);
			this->CustomerRemoveDeliveryButton->TabIndex = 2;
			this->CustomerRemoveDeliveryButton->Text = L"Retirer";
			this->CustomerRemoveDeliveryButton->UseVisualStyleBackColor = true;
			// 
			// customerNewDeliveryButton
			// 
			this->customerNewDeliveryButton->Location = System::Drawing::Point(7, 87);
			this->customerNewDeliveryButton->Name = L"customerNewDeliveryButton";
			this->customerNewDeliveryButton->Size = System::Drawing::Size(165, 23);
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
			this->customerDeliveryDisplay->Size = System::Drawing::Size(330, 66);
			this->customerDeliveryDisplay->TabIndex = 0;
			// 
			// customerInvoiceGroup
			// 
			this->customerInvoiceGroup->Controls->Add(this->customerRemoveInvoiceButton);
			this->customerInvoiceGroup->Controls->Add(this->CustomerNewInvoiceButton);
			this->customerInvoiceGroup->Controls->Add(this->customerInvoiceDisplay);
			this->customerInvoiceGroup->Location = System::Drawing::Point(20, 294);
			this->customerInvoiceGroup->Name = L"customerInvoiceGroup";
			this->customerInvoiceGroup->Size = System::Drawing::Size(346, 115);
			this->customerInvoiceGroup->TabIndex = 25;
			this->customerInvoiceGroup->TabStop = false;
			this->customerInvoiceGroup->Text = L"Adresses de facturation";
			// 
			// customerRemoveInvoiceButton
			// 
			this->customerRemoveInvoiceButton->Location = System::Drawing::Point(171, 87);
			this->customerRemoveInvoiceButton->Name = L"customerRemoveInvoiceButton";
			this->customerRemoveInvoiceButton->Size = System::Drawing::Size(165, 23);
			this->customerRemoveInvoiceButton->TabIndex = 2;
			this->customerRemoveInvoiceButton->Text = L"Retirer";
			this->customerRemoveInvoiceButton->UseVisualStyleBackColor = true;
			// 
			// CustomerNewInvoiceButton
			// 
			this->CustomerNewInvoiceButton->Location = System::Drawing::Point(7, 87);
			this->CustomerNewInvoiceButton->Name = L"CustomerNewInvoiceButton";
			this->CustomerNewInvoiceButton->Size = System::Drawing::Size(165, 23);
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
			this->customerInvoiceDisplay->Size = System::Drawing::Size(330, 66);
			this->customerInvoiceDisplay->TabIndex = 0;
			// 
			// staffGroup
			// 
			this->staffGroup->Controls->Add(this->staffHiredYearInput);
			this->staffGroup->Controls->Add(this->staffHiredMonthInput);
			this->staffGroup->Controls->Add(this->staffHiredDayInput);
			this->staffGroup->Controls->Add(this->staffHiredSlash2);
			this->staffGroup->Controls->Add(this->staffHiredSlash1);
			this->staffGroup->Controls->Add(this->label27);
			this->staffGroup->Controls->Add(this->listBox3);
			this->staffGroup->Controls->Add(this->staffAddressGroup);
			this->staffGroup->Controls->Add(this->staffHiredLabel);
			this->staffGroup->Controls->Add(this->staffFNameLabel);
			this->staffGroup->Controls->Add(this->staffLNameLabel);
			this->staffGroup->Controls->Add(this->staffFNameInput);
			this->staffGroup->Controls->Add(this->staffLNameInput);
			this->staffGroup->Controls->Add(this->groupBox16);
			this->staffGroup->Location = System::Drawing::Point(1393, 12);
			this->staffGroup->Name = L"staffGroup";
			this->staffGroup->Size = System::Drawing::Size(390, 425);
			this->staffGroup->TabIndex = 6;
			this->staffGroup->TabStop = false;
			this->staffGroup->Text = L"Edition du personnel";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(24, 312);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(145, 16);
			this->label27->TabIndex = 26;
			this->label27->Text = L"Supérieur hiérarchique:";
			// 
			// listBox3
			// 
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 16;
			this->listBox3->Location = System::Drawing::Point(24, 334);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(346, 84);
			this->listBox3->TabIndex = 25;
			// 
			// staffAddressGroup
			// 
			this->staffAddressGroup->Controls->Add(this->comboBox3);
			this->staffAddressGroup->Controls->Add(this->textBox22);
			this->staffAddressGroup->Controls->Add(this->label28);
			this->staffAddressGroup->Controls->Add(this->label29);
			this->staffAddressGroup->Controls->Add(this->label30);
			this->staffAddressGroup->Controls->Add(this->textBox24);
			this->staffAddressGroup->Controls->Add(this->textBox25);
			this->staffAddressGroup->Controls->Add(this->label31);
			this->staffAddressGroup->Location = System::Drawing::Point(15, 182);
			this->staffAddressGroup->Name = L"staffAddressGroup";
			this->staffAddressGroup->Size = System::Drawing::Size(359, 100);
			this->staffAddressGroup->TabIndex = 18;
			this->staffAddressGroup->TabStop = false;
			this->staffAddressGroup->Text = L"Adresse";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(52, 60);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(115, 24);
			this->comboBox3->TabIndex = 8;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(272, 62);
			this->textBox22->MaxLength = 6;
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(76, 22);
			this->textBox22->TabIndex = 7;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(177, 63);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(83, 16);
			this->label28->TabIndex = 5;
			this->label28->Text = L"Code postal:";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(9, 63);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(36, 16);
			this->label29->TabIndex = 4;
			this->label29->Text = L"Ville:";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(167, 29);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(80, 16);
			this->label30->TabIndex = 3;
			this->label30->Text = L"Nom de rue:";
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(253, 26);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(100, 22);
			this->textBox24->TabIndex = 2;
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(109, 26);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(45, 22);
			this->textBox25->TabIndex = 1;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(6, 29);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(97, 16);
			this->label31->TabIndex = 0;
			this->label31->Text = L"N° de bâtiment:";
			// 
			// staffHiredLabel
			// 
			this->staffHiredLabel->AutoSize = true;
			this->staffHiredLabel->Location = System::Drawing::Point(24, 130);
			this->staffHiredLabel->Name = L"staffHiredLabel";
			this->staffHiredLabel->Size = System::Drawing::Size(117, 16);
			this->staffHiredLabel->TabIndex = 17;
			this->staffHiredLabel->Text = L"Date d\'embauche:";
			// 
			// staffFNameLabel
			// 
			this->staffFNameLabel->AutoSize = true;
			this->staffFNameLabel->Location = System::Drawing::Point(192, 53);
			this->staffFNameLabel->Name = L"staffFNameLabel";
			this->staffFNameLabel->Size = System::Drawing::Size(57, 16);
			this->staffFNameLabel->TabIndex = 11;
			this->staffFNameLabel->Text = L"Prénom:";
			// 
			// staffLNameLabel
			// 
			this->staffLNameLabel->AutoSize = true;
			this->staffLNameLabel->Location = System::Drawing::Point(21, 53);
			this->staffLNameLabel->Name = L"staffLNameLabel";
			this->staffLNameLabel->Size = System::Drawing::Size(39, 16);
			this->staffLNameLabel->TabIndex = 10;
			this->staffLNameLabel->Text = L"Nom:";
			// 
			// staffFNameInput
			// 
			this->staffFNameInput->AcceptsTab = true;
			this->staffFNameInput->Location = System::Drawing::Point(251, 50);
			this->staffFNameInput->Name = L"staffFNameInput";
			this->staffFNameInput->Size = System::Drawing::Size(123, 22);
			this->staffFNameInput->TabIndex = 9;
			this->staffFNameInput->TabStop = false;
			// 
			// staffLNameInput
			// 
			this->staffLNameInput->AcceptsTab = true;
			this->staffLNameInput->Location = System::Drawing::Point(63, 50);
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
			// staffHiredYearInput
			// 
			this->staffHiredYearInput->Location = System::Drawing::Point(293, 128);
			this->staffHiredYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->staffHiredYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->staffHiredYearInput->Name = L"staffHiredYearInput";
			this->staffHiredYearInput->Size = System::Drawing::Size(70, 22);
			this->staffHiredYearInput->TabIndex = 33;
			this->staffHiredYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// staffHiredMonthInput
			// 
			this->staffHiredMonthInput->Location = System::Drawing::Point(220, 128);
			this->staffHiredMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->staffHiredMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->staffHiredMonthInput->Name = L"staffHiredMonthInput";
			this->staffHiredMonthInput->Size = System::Drawing::Size(50, 22);
			this->staffHiredMonthInput->TabIndex = 32;
			this->staffHiredMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// staffHiredDayInput
			// 
			this->staffHiredDayInput->Location = System::Drawing::Point(147, 128);
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
			this->staffHiredSlash2->Location = System::Drawing::Point(276, 131);
			this->staffHiredSlash2->Name = L"staffHiredSlash2";
			this->staffHiredSlash2->Size = System::Drawing::Size(11, 16);
			this->staffHiredSlash2->TabIndex = 30;
			this->staffHiredSlash2->Text = L"/";
			// 
			// staffHiredSlash1
			// 
			this->staffHiredSlash1->AutoSize = true;
			this->staffHiredSlash1->Location = System::Drawing::Point(203, 131);
			this->staffHiredSlash1->Name = L"staffHiredSlash1";
			this->staffHiredSlash1->Size = System::Drawing::Size(11, 16);
			this->staffHiredSlash1->TabIndex = 29;
			this->staffHiredSlash1->Text = L"/";
			// 
			// customerBirthYearInput
			// 
			this->customerBirthYearInput->Location = System::Drawing::Point(229, 82);
			this->customerBirthYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->customerBirthYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->customerBirthYearInput->Name = L"customerBirthYearInput";
			this->customerBirthYearInput->Size = System::Drawing::Size(70, 22);
			this->customerBirthYearInput->TabIndex = 38;
			this->customerBirthYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// customerBirthMonthInput
			// 
			this->customerBirthMonthInput->Location = System::Drawing::Point(156, 82);
			this->customerBirthMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->customerBirthMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthMonthInput->Name = L"customerBirthMonthInput";
			this->customerBirthMonthInput->Size = System::Drawing::Size(50, 22);
			this->customerBirthMonthInput->TabIndex = 37;
			this->customerBirthMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// customerBirthDayInput
			// 
			this->customerBirthDayInput->Location = System::Drawing::Point(83, 82);
			this->customerBirthDayInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 31, 0, 0, 0 });
			this->customerBirthDayInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->customerBirthDayInput->Name = L"customerBirthDayInput";
			this->customerBirthDayInput->Size = System::Drawing::Size(50, 22);
			this->customerBirthDayInput->TabIndex = 36;
			this->customerBirthDayInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// customerBirthSlash2
			// 
			this->customerBirthSlash2->AutoSize = true;
			this->customerBirthSlash2->Location = System::Drawing::Point(212, 85);
			this->customerBirthSlash2->Name = L"customerBirthSlash2";
			this->customerBirthSlash2->Size = System::Drawing::Size(11, 16);
			this->customerBirthSlash2->TabIndex = 35;
			this->customerBirthSlash2->Text = L"/";
			// 
			// customerBirthSlash1
			// 
			this->customerBirthSlash1->AutoSize = true;
			this->customerBirthSlash1->Location = System::Drawing::Point(139, 85);
			this->customerBirthSlash1->Name = L"customerBirthSlash1";
			this->customerBirthSlash1->Size = System::Drawing::Size(11, 16);
			this->customerBirthSlash1->TabIndex = 34;
			this->customerBirthSlash1->Text = L"/";
			// 
			// ordersDeliveryYearInput
			// 
			this->ordersDeliveryYearInput->Location = System::Drawing::Point(314, 335);
			this->ordersDeliveryYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->ordersDeliveryYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->ordersDeliveryYearInput->Name = L"ordersDeliveryYearInput";
			this->ordersDeliveryYearInput->Size = System::Drawing::Size(70, 22);
			this->ordersDeliveryYearInput->TabIndex = 43;
			this->ordersDeliveryYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// ordersDeliveryMonthInput
			// 
			this->ordersDeliveryMonthInput->Location = System::Drawing::Point(241, 335);
			this->ordersDeliveryMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ordersDeliveryMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersDeliveryMonthInput->Name = L"ordersDeliveryMonthInput";
			this->ordersDeliveryMonthInput->Size = System::Drawing::Size(50, 22);
			this->ordersDeliveryMonthInput->TabIndex = 42;
			this->ordersDeliveryMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersDeliveryDayInput
			// 
			this->ordersDeliveryDayInput->Location = System::Drawing::Point(168, 335);
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
			this->ordersDdeliverySlash2->Location = System::Drawing::Point(297, 338);
			this->ordersDdeliverySlash2->Name = L"ordersDdeliverySlash2";
			this->ordersDdeliverySlash2->Size = System::Drawing::Size(11, 16);
			this->ordersDdeliverySlash2->TabIndex = 40;
			this->ordersDdeliverySlash2->Text = L"/";
			// 
			// ordersDeliverySlash1
			// 
			this->ordersDeliverySlash1->AutoSize = true;
			this->ordersDeliverySlash1->Location = System::Drawing::Point(224, 338);
			this->ordersDeliverySlash1->Name = L"ordersDeliverySlash1";
			this->ordersDeliverySlash1->Size = System::Drawing::Size(11, 16);
			this->ordersDeliverySlash1->TabIndex = 39;
			this->ordersDeliverySlash1->Text = L"/";
			// 
			// ordersEmitYearInput
			// 
			this->ordersEmitYearInput->Location = System::Drawing::Point(281, 387);
			this->ordersEmitYearInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2100, 0, 0, 0 });
			this->ordersEmitYearInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1900, 0, 0, 0 });
			this->ordersEmitYearInput->Name = L"ordersEmitYearInput";
			this->ordersEmitYearInput->Size = System::Drawing::Size(70, 22);
			this->ordersEmitYearInput->TabIndex = 48;
			this->ordersEmitYearInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			// 
			// ordersEmitMonthInput
			// 
			this->ordersEmitMonthInput->Location = System::Drawing::Point(208, 387);
			this->ordersEmitMonthInput->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 12, 0, 0, 0 });
			this->ordersEmitMonthInput->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->ordersEmitMonthInput->Name = L"ordersEmitMonthInput";
			this->ordersEmitMonthInput->Size = System::Drawing::Size(50, 22);
			this->ordersEmitMonthInput->TabIndex = 47;
			this->ordersEmitMonthInput->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// ordersEmitDayInput
			// 
			this->ordersEmitDayInput->Location = System::Drawing::Point(135, 387);
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
			this->ordersEmitSlash2->Location = System::Drawing::Point(264, 390);
			this->ordersEmitSlash2->Name = L"ordersEmitSlash2";
			this->ordersEmitSlash2->Size = System::Drawing::Size(11, 16);
			this->ordersEmitSlash2->TabIndex = 45;
			this->ordersEmitSlash2->Text = L"/";
			// 
			// ordersEmitSlash1
			// 
			this->ordersEmitSlash1->AutoSize = true;
			this->ordersEmitSlash1->Location = System::Drawing::Point(191, 390);
			this->ordersEmitSlash1->Name = L"ordersEmitSlash1";
			this->ordersEmitSlash1->Size = System::Drawing::Size(11, 16);
			this->ordersEmitSlash1->TabIndex = 44;
			this->ordersEmitSlash1->Text = L"/";
			// 
			// stockGroup
			// 
			this->stockGroup->Controls->Add(this->numericUpDown20);
			this->stockGroup->Controls->Add(this->label37);
			this->stockGroup->Controls->Add(this->groupBox18);
			this->stockGroup->Controls->Add(this->label41);
			this->stockGroup->Controls->Add(this->numericUpDown23);
			this->stockGroup->Controls->Add(this->label42);
			this->stockGroup->Controls->Add(this->label43);
			this->stockGroup->Controls->Add(this->numericUpDown24);
			this->stockGroup->Controls->Add(this->numericUpDown25);
			this->stockGroup->Controls->Add(this->numericUpDown26);
			this->stockGroup->Controls->Add(this->comboBox5);
			this->stockGroup->Controls->Add(this->label44);
			this->stockGroup->Controls->Add(this->comboBox6);
			this->stockGroup->Controls->Add(this->label45);
			this->stockGroup->Controls->Add(this->textBox2);
			this->stockGroup->Controls->Add(this->label46);
			this->stockGroup->Controls->Add(this->groupBox19);
			this->stockGroup->Location = System::Drawing::Point(1393, 443);
			this->stockGroup->Name = L"stockGroup";
			this->stockGroup->Size = System::Drawing::Size(390, 425);
			this->stockGroup->TabIndex = 7;
			this->stockGroup->TabStop = false;
			this->stockGroup->Text = L"Edition d\'articles";
			// 
			// numericUpDown20
			// 
			this->numericUpDown20->Location = System::Drawing::Point(237, 240);
			this->numericUpDown20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown20->Name = L"numericUpDown20";
			this->numericUpDown20->Size = System::Drawing::Size(84, 22);
			this->numericUpDown20->TabIndex = 21;
			this->numericUpDown20->ThousandsSeparator = true;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(23, 242);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(189, 16);
			this->label37->TabIndex = 20;
			this->label37->Text = L"Seuil de réapprovisionnement:";
			// 
			// groupBox18
			// 
			this->groupBox18->Controls->Add(this->label38);
			this->groupBox18->Controls->Add(this->numericUpDown21);
			this->groupBox18->Controls->Add(this->numericUpDown22);
			this->groupBox18->Controls->Add(this->label39);
			this->groupBox18->Controls->Add(this->label40);
			this->groupBox18->Location = System::Drawing::Point(20, 332);
			this->groupBox18->Name = L"groupBox18";
			this->groupBox18->Size = System::Drawing::Size(349, 72);
			this->groupBox18->TabIndex = 19;
			this->groupBox18->TabStop = false;
			this->groupBox18->Text = L"Remise";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(183, 18);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(19, 16);
			this->label38->TabIndex = 20;
			this->label38->Text = L"%";
			// 
			// numericUpDown21
			// 
			this->numericUpDown21->DecimalPlaces = 2;
			this->numericUpDown21->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numericUpDown21->Location = System::Drawing::Point(263, 42);
			this->numericUpDown21->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown21->Name = L"numericUpDown21";
			this->numericUpDown21->Size = System::Drawing::Size(59, 22);
			this->numericUpDown21->TabIndex = 19;
			// 
			// numericUpDown22
			// 
			this->numericUpDown22->Location = System::Drawing::Point(121, 16);
			this->numericUpDown22->Name = L"numericUpDown22";
			this->numericUpDown22->Size = System::Drawing::Size(56, 22);
			this->numericUpDown22->TabIndex = 18;
			this->numericUpDown22->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(16, 44);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(220, 16);
			this->label39->TabIndex = 1;
			this->label39->Text = L"Poids du nombre d\'articles achetés:";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(16, 18);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(93, 16);
			this->label40->TabIndex = 0;
			this->label40->Text = L"Taux de base:";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(181, 294);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(19, 16);
			this->label41->TabIndex = 18;
			this->label41->Text = L"%";
			// 
			// numericUpDown23
			// 
			this->numericUpDown23->Location = System::Drawing::Point(122, 290);
			this->numericUpDown23->Name = L"numericUpDown23";
			this->numericUpDown23->Size = System::Drawing::Size(53, 22);
			this->numericUpDown23->TabIndex = 17;
			this->numericUpDown23->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(20, 294);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(89, 16);
			this->label42->TabIndex = 16;
			this->label42->Text = L"Taux de TVA:";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(20, 190);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(112, 16);
			this->label43->TabIndex = 15;
			this->label43->Text = L"Quantité en stock:";
			// 
			// numericUpDown24
			// 
			this->numericUpDown24->Location = System::Drawing::Point(152, 188);
			this->numericUpDown24->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown24->Name = L"numericUpDown24";
			this->numericUpDown24->Size = System::Drawing::Size(84, 22);
			this->numericUpDown24->TabIndex = 14;
			this->numericUpDown24->ThousandsSeparator = true;
			// 
			// numericUpDown25
			// 
			this->numericUpDown25->DecimalPlaces = 3;
			this->numericUpDown25->Location = System::Drawing::Point(184, 135);
			this->numericUpDown25->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown25->Name = L"numericUpDown25";
			this->numericUpDown25->Size = System::Drawing::Size(120, 22);
			this->numericUpDown25->TabIndex = 13;
			this->numericUpDown25->ThousandsSeparator = true;
			// 
			// numericUpDown26
			// 
			this->numericUpDown26->DecimalPlaces = 3;
			this->numericUpDown26->Location = System::Drawing::Point(201, 82);
			this->numericUpDown26->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown26->Name = L"numericUpDown26";
			this->numericUpDown26->Size = System::Drawing::Size(120, 22);
			this->numericUpDown26->TabIndex = 12;
			this->numericUpDown26->ThousandsSeparator = true;
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"€", L"$" });
			this->comboBox5->Location = System::Drawing::Point(312, 134);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(55, 24);
			this->comboBox5->TabIndex = 11;
			this->comboBox5->Text = L"€";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(20, 136);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(125, 16);
			this->label44->TabIndex = 9;
			this->label44->Text = L"Prix unitaire d\'achat:";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"€", L"$" });
			this->comboBox6->Location = System::Drawing::Point(329, 81);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(55, 24);
			this->comboBox6->TabIndex = 8;
			this->comboBox6->Text = L"€";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(20, 83);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(142, 16);
			this->label45->TabIndex = 6;
			this->label45->Text = L"Prix unitaire hors taxes:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(103, 34);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(145, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(20, 37);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(39, 16);
			this->label46->TabIndex = 4;
			this->label46->Text = L"Nom:";
			// 
			// groupBox19
			// 
			this->groupBox19->Location = System::Drawing::Point(0, 431);
			this->groupBox19->Name = L"groupBox19";
			this->groupBox19->Size = System::Drawing::Size(390, 49);
			this->groupBox19->TabIndex = 3;
			this->groupBox19->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Location = System::Drawing::Point(0, 431);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(390, 49);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			// 
			// statsGroup
			// 
			this->statsGroup->Controls->Add(this->groupBox4);
			this->statsGroup->Location = System::Drawing::Point(158, 12);
			this->statsGroup->Name = L"statsGroup";
			this->statsGroup->Size = System::Drawing::Size(390, 425);
			this->statsGroup->TabIndex = 0;
			this->statsGroup->TabStop = false;
			this->statsGroup->Text = L"Statistiques";
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
			// Root
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 993);
			this->Controls->Add(this->stockGroup);
			this->Controls->Add(this->staffGroup);
			this->Controls->Add(this->ordersGroup);
			this->Controls->Add(this->clientGroup);
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
			this->clientGroup->ResumeLayout(false);
			this->clientGroup->PerformLayout();
			this->ordersGroup->ResumeLayout(false);
			this->ordersGroup->PerformLayout();
			this->ordersPaymentGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersPaymentDisplay))->EndInit();
			this->customerDeliveryGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerDeliveryDisplay))->EndInit();
			this->customerInvoiceGroup->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerInvoiceDisplay))->EndInit();
			this->staffGroup->ResumeLayout(false);
			this->staffGroup->PerformLayout();
			this->staffAddressGroup->ResumeLayout(false);
			this->staffAddressGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->staffHiredDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->customerBirthDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersDeliveryDayInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitYearInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitMonthInput))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ordersEmitDayInput))->EndInit();
			this->stockGroup->ResumeLayout(false);
			this->stockGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown20))->EndInit();
			this->groupBox18->ResumeLayout(false);
			this->groupBox18->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown26))->EndInit();
			this->statsGroup->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Root_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label24_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
