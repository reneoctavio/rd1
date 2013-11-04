#include "ConnManager.h"
#include "Parameters.h"
#include "Database.h"
#pragma once

namespace rd1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ControlPanel
	/// </summary>
	public ref class ControlPanel : public System::Windows::Forms::Form
	{

#pragma region Controller Variables
	private: ConnManager ^ cm;
	private: Parameters ^ pm;
	private: Database ^ db;
#pragma endregion

#pragma region View Variables
	private: System::Windows::Forms::GroupBox^  groupBoxR11;
	private: System::Windows::Forms::RadioButton^  radioButtonR11Off;
	private: System::Windows::Forms::RadioButton^  radioButtonR11On;

	private: System::Windows::Forms::GroupBox^  groupBoxR20;
	private: System::Windows::Forms::RadioButton^  radioButtonR20Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR20On;

	private: System::Windows::Forms::GroupBox^  groupBoxR19;
	private: System::Windows::Forms::RadioButton^  radioButtonR19Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR19On;

	private: System::Windows::Forms::GroupBox^  groupBoxR18;
	private: System::Windows::Forms::RadioButton^  radioButtonR18Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR18On;

	private: System::Windows::Forms::GroupBox^  groupBoxR16;
	private: System::Windows::Forms::RadioButton^  radioButtonR16Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR16On;

	private: System::Windows::Forms::GroupBox^  groupBoxR17;
	private: System::Windows::Forms::RadioButton^  radioButtonR17Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR17On;

	private: System::Windows::Forms::GroupBox^  groupBoxR15;
	private: System::Windows::Forms::RadioButton^  radioButtonR15Off;
	private: System::Windows::Forms::RadioButton^  radioButtonR15On;



	private: System::Windows::Forms::GroupBox^  groupBoxR14;
	private: System::Windows::Forms::RadioButton^  radioButtonR14Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR14On;

	private: System::Windows::Forms::GroupBox^  groupBoxR13;
	private: System::Windows::Forms::RadioButton^  radioButtonR13Off;

	private: System::Windows::Forms::RadioButton^  radioButtonR13On;

	private: System::Windows::Forms::GroupBox^  groupBoxR12;
	private: System::Windows::Forms::RadioButton^  radioButtonR12Off;
	private: System::Windows::Forms::RadioButton^  radioButtonR12On;

	private: System::Windows::Forms::GroupBox^  groupBoxM6;
	private: System::Windows::Forms::TrackBar^  trackBarM6;
	private: System::Windows::Forms::Label^  labelM6;
	
	private: System::Windows::Forms::GroupBox^  groupBoxM7;
	private: System::Windows::Forms::Label^  labelM7;
	private: System::Windows::Forms::TrackBar^  trackBarM7;

	private: System::Windows::Forms::GroupBox^  groupBoxM8;
	private: System::Windows::Forms::Label^  labelM8;
	private: System::Windows::Forms::TrackBar^  trackBarM8;

	private: System::Windows::Forms::GroupBox^  groupBoxM9;
	private: System::Windows::Forms::Label^  labelM9;
	private: System::Windows::Forms::TrackBar^  trackBarM9;

	private: System::Windows::Forms::GroupBox^  groupBoxM10;
	private: System::Windows::Forms::Label^  labelM10;
	private: System::Windows::Forms::TrackBar^  trackBarM10;

	private: System::Windows::Forms::GroupBox^  groupBoxD4;
	private: System::Windows::Forms::Label^  labelD4;
	private: System::Windows::Forms::TrackBar^  trackBarD4;

	private: System::Windows::Forms::GroupBox^  groupBoxD5;
	private: System::Windows::Forms::Label^  labelD5;
	private: System::Windows::Forms::TrackBar^  trackBarD5;

	private: System::Windows::Forms::GroupBox^  groupBoxD6;
	private: System::Windows::Forms::Label^  labelD6;
	private: System::Windows::Forms::TrackBar^  trackBarD6;

	private: System::Windows::Forms::GroupBox^  groupBoxD7;
	private: System::Windows::Forms::Label^  labelD7;
	private: System::Windows::Forms::TrackBar^  trackBarD7;

	private: System::Windows::Forms::GroupBox^  groupBoxD8;
	private: System::Windows::Forms::Label^  labelD8;
	private: System::Windows::Forms::TrackBar^  trackBarD8;

	private: System::Windows::Forms::GroupBox^  groupBoxTime;
	private: System::Windows::Forms::TextBox^  textBoxTime;
	private: System::Windows::Forms::Label^  labelSeconds;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButtonSimplified;
	private: System::Windows::Forms::RadioButton^  radioButtonComplete;
#pragma endregion

	public:
		ControlPanel(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ControlPanel()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// Initialize Mutexes
		static System::Threading::Mutex^ clpMutex = gcnew System::Threading::Mutex;
		static System::Threading::Mutex^ dbMutex = gcnew System::Threading::Mutex;
		static System::Threading::Mutex^ bufferMutex = gcnew System::Threading::Mutex;
		
		// Timer
		static System::Timers::Timer^ aTimer = gcnew System::Timers::Timer(1000); // 1seg

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBoxR11 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR11Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR11On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR20 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR20Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR20On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR19 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR19Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR19On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR18 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR18Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR18On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR16 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR16Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR16On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR17 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR17Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR17On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR15 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR15Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR15On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR14 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR14Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR14On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR13 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR13Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR13On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR12 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR12Off = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR12On = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxM6 = (gcnew System::Windows::Forms::GroupBox());
			this->labelM6 = (gcnew System::Windows::Forms::Label());
			this->trackBarM6 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxM7 = (gcnew System::Windows::Forms::GroupBox());
			this->labelM7 = (gcnew System::Windows::Forms::Label());
			this->trackBarM7 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxM8 = (gcnew System::Windows::Forms::GroupBox());
			this->labelM8 = (gcnew System::Windows::Forms::Label());
			this->trackBarM8 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxM9 = (gcnew System::Windows::Forms::GroupBox());
			this->labelM9 = (gcnew System::Windows::Forms::Label());
			this->trackBarM9 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxM10 = (gcnew System::Windows::Forms::GroupBox());
			this->labelM10 = (gcnew System::Windows::Forms::Label());
			this->trackBarM10 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxD4 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBarD4 = (gcnew System::Windows::Forms::TrackBar());
			this->labelD4 = (gcnew System::Windows::Forms::Label());
			this->groupBoxD5 = (gcnew System::Windows::Forms::GroupBox());
			this->labelD5 = (gcnew System::Windows::Forms::Label());
			this->trackBarD5 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxD6 = (gcnew System::Windows::Forms::GroupBox());
			this->labelD6 = (gcnew System::Windows::Forms::Label());
			this->trackBarD6 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxD7 = (gcnew System::Windows::Forms::GroupBox());
			this->labelD7 = (gcnew System::Windows::Forms::Label());
			this->trackBarD7 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxD8 = (gcnew System::Windows::Forms::GroupBox());
			this->trackBarD8 = (gcnew System::Windows::Forms::TrackBar());
			this->labelD8 = (gcnew System::Windows::Forms::Label());
			this->groupBoxTime = (gcnew System::Windows::Forms::GroupBox());
			this->labelSeconds = (gcnew System::Windows::Forms::Label());
			this->textBoxTime = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonSimplified = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonComplete = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR11->SuspendLayout();
			this->groupBoxR20->SuspendLayout();
			this->groupBoxR19->SuspendLayout();
			this->groupBoxR18->SuspendLayout();
			this->groupBoxR16->SuspendLayout();
			this->groupBoxR17->SuspendLayout();
			this->groupBoxR15->SuspendLayout();
			this->groupBoxR14->SuspendLayout();
			this->groupBoxR13->SuspendLayout();
			this->groupBoxR12->SuspendLayout();
			this->groupBoxM6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM6))->BeginInit();
			this->groupBoxM7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM7))->BeginInit();
			this->groupBoxM8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM8))->BeginInit();
			this->groupBoxM9->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM9))->BeginInit();
			this->groupBoxM10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM10))->BeginInit();
			this->groupBoxD4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD4))->BeginInit();
			this->groupBoxD5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD5))->BeginInit();
			this->groupBoxD6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD6))->BeginInit();
			this->groupBoxD7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD7))->BeginInit();
			this->groupBoxD8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD8))->BeginInit();
			this->groupBoxTime->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxR11
			// 
			this->groupBoxR11->Controls->Add(this->radioButtonR11Off);
			this->groupBoxR11->Controls->Add(this->radioButtonR11On);
			this->groupBoxR11->Location = System::Drawing::Point(12, 12);
			this->groupBoxR11->Name = L"groupBoxR11";
			this->groupBoxR11->Size = System::Drawing::Size(81, 71);
			this->groupBoxR11->TabIndex = 0;
			this->groupBoxR11->TabStop = false;
			this->groupBoxR11->Text = L"R11";
			// 
			// radioButtonR11Off
			// 
			this->radioButtonR11Off->AutoSize = true;
			this->radioButtonR11Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR11Off->Name = L"radioButtonR11Off";
			this->radioButtonR11Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR11Off->TabIndex = 1;
			this->radioButtonR11Off->TabStop = true;
			this->radioButtonR11Off->Text = L"Desligado";
			this->radioButtonR11Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR11On
			// 
			this->radioButtonR11On->AutoSize = true;
			this->radioButtonR11On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR11On->Name = L"radioButtonR11On";
			this->radioButtonR11On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR11On->TabIndex = 0;
			this->radioButtonR11On->TabStop = true;
			this->radioButtonR11On->Text = L"Ligado";
			this->radioButtonR11On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR20
			// 
			this->groupBoxR20->Controls->Add(this->radioButtonR20Off);
			this->groupBoxR20->Controls->Add(this->radioButtonR20On);
			this->groupBoxR20->Location = System::Drawing::Point(795, 12);
			this->groupBoxR20->Name = L"groupBoxR20";
			this->groupBoxR20->Size = System::Drawing::Size(81, 71);
			this->groupBoxR20->TabIndex = 1;
			this->groupBoxR20->TabStop = false;
			this->groupBoxR20->Text = L"R20";
			// 
			// radioButtonR20Off
			// 
			this->radioButtonR20Off->AutoSize = true;
			this->radioButtonR20Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR20Off->Name = L"radioButtonR20Off";
			this->radioButtonR20Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR20Off->TabIndex = 1;
			this->radioButtonR20Off->TabStop = true;
			this->radioButtonR20Off->Text = L"Desligado";
			this->radioButtonR20Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR20On
			// 
			this->radioButtonR20On->AutoSize = true;
			this->radioButtonR20On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR20On->Name = L"radioButtonR20On";
			this->radioButtonR20On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR20On->TabIndex = 0;
			this->radioButtonR20On->TabStop = true;
			this->radioButtonR20On->Text = L"Ligado";
			this->radioButtonR20On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR19
			// 
			this->groupBoxR19->Controls->Add(this->radioButtonR19Off);
			this->groupBoxR19->Controls->Add(this->radioButtonR19On);
			this->groupBoxR19->Location = System::Drawing::Point(708, 12);
			this->groupBoxR19->Name = L"groupBoxR19";
			this->groupBoxR19->Size = System::Drawing::Size(81, 71);
			this->groupBoxR19->TabIndex = 2;
			this->groupBoxR19->TabStop = false;
			this->groupBoxR19->Text = L"R19";
			// 
			// radioButtonR19Off
			// 
			this->radioButtonR19Off->AutoSize = true;
			this->radioButtonR19Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR19Off->Name = L"radioButtonR19Off";
			this->radioButtonR19Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR19Off->TabIndex = 1;
			this->radioButtonR19Off->TabStop = true;
			this->radioButtonR19Off->Text = L"Desligado";
			this->radioButtonR19Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR19On
			// 
			this->radioButtonR19On->AutoSize = true;
			this->radioButtonR19On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR19On->Name = L"radioButtonR19On";
			this->radioButtonR19On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR19On->TabIndex = 0;
			this->radioButtonR19On->TabStop = true;
			this->radioButtonR19On->Text = L"Ligado";
			this->radioButtonR19On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR18
			// 
			this->groupBoxR18->Controls->Add(this->radioButtonR18Off);
			this->groupBoxR18->Controls->Add(this->radioButtonR18On);
			this->groupBoxR18->Location = System::Drawing::Point(621, 12);
			this->groupBoxR18->Name = L"groupBoxR18";
			this->groupBoxR18->Size = System::Drawing::Size(81, 71);
			this->groupBoxR18->TabIndex = 2;
			this->groupBoxR18->TabStop = false;
			this->groupBoxR18->Text = L"R18";
			// 
			// radioButtonR18Off
			// 
			this->radioButtonR18Off->AutoSize = true;
			this->radioButtonR18Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR18Off->Name = L"radioButtonR18Off";
			this->radioButtonR18Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR18Off->TabIndex = 1;
			this->radioButtonR18Off->TabStop = true;
			this->radioButtonR18Off->Text = L"Desligado";
			this->radioButtonR18Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR18On
			// 
			this->radioButtonR18On->AutoSize = true;
			this->radioButtonR18On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR18On->Name = L"radioButtonR18On";
			this->radioButtonR18On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR18On->TabIndex = 0;
			this->radioButtonR18On->TabStop = true;
			this->radioButtonR18On->Text = L"Ligado";
			this->radioButtonR18On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR16
			// 
			this->groupBoxR16->Controls->Add(this->radioButtonR16Off);
			this->groupBoxR16->Controls->Add(this->radioButtonR16On);
			this->groupBoxR16->Location = System::Drawing::Point(447, 12);
			this->groupBoxR16->Name = L"groupBoxR16";
			this->groupBoxR16->Size = System::Drawing::Size(81, 71);
			this->groupBoxR16->TabIndex = 2;
			this->groupBoxR16->TabStop = false;
			this->groupBoxR16->Text = L"R16";
			// 
			// radioButtonR16Off
			// 
			this->radioButtonR16Off->AutoSize = true;
			this->radioButtonR16Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR16Off->Name = L"radioButtonR16Off";
			this->radioButtonR16Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR16Off->TabIndex = 1;
			this->radioButtonR16Off->TabStop = true;
			this->radioButtonR16Off->Text = L"Desligado";
			this->radioButtonR16Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR16On
			// 
			this->radioButtonR16On->AutoSize = true;
			this->radioButtonR16On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR16On->Name = L"radioButtonR16On";
			this->radioButtonR16On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR16On->TabIndex = 0;
			this->radioButtonR16On->TabStop = true;
			this->radioButtonR16On->Text = L"Ligado";
			this->radioButtonR16On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR17
			// 
			this->groupBoxR17->Controls->Add(this->radioButtonR17Off);
			this->groupBoxR17->Controls->Add(this->radioButtonR17On);
			this->groupBoxR17->Location = System::Drawing::Point(534, 12);
			this->groupBoxR17->Name = L"groupBoxR17";
			this->groupBoxR17->Size = System::Drawing::Size(81, 71);
			this->groupBoxR17->TabIndex = 2;
			this->groupBoxR17->TabStop = false;
			this->groupBoxR17->Text = L"R17";
			// 
			// radioButtonR17Off
			// 
			this->radioButtonR17Off->AutoSize = true;
			this->radioButtonR17Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR17Off->Name = L"radioButtonR17Off";
			this->radioButtonR17Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR17Off->TabIndex = 1;
			this->radioButtonR17Off->TabStop = true;
			this->radioButtonR17Off->Text = L"Desligado";
			this->radioButtonR17Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR17On
			// 
			this->radioButtonR17On->AutoSize = true;
			this->radioButtonR17On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR17On->Name = L"radioButtonR17On";
			this->radioButtonR17On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR17On->TabIndex = 0;
			this->radioButtonR17On->TabStop = true;
			this->radioButtonR17On->Text = L"Ligado";
			this->radioButtonR17On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR15
			// 
			this->groupBoxR15->Controls->Add(this->radioButtonR15Off);
			this->groupBoxR15->Controls->Add(this->radioButtonR15On);
			this->groupBoxR15->Location = System::Drawing::Point(360, 12);
			this->groupBoxR15->Name = L"groupBoxR15";
			this->groupBoxR15->Size = System::Drawing::Size(81, 71);
			this->groupBoxR15->TabIndex = 2;
			this->groupBoxR15->TabStop = false;
			this->groupBoxR15->Text = L"R15";
			// 
			// radioButtonR15Off
			// 
			this->radioButtonR15Off->AutoSize = true;
			this->radioButtonR15Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR15Off->Name = L"radioButtonR15Off";
			this->radioButtonR15Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR15Off->TabIndex = 1;
			this->radioButtonR15Off->TabStop = true;
			this->radioButtonR15Off->Text = L"Desligado";
			this->radioButtonR15Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR15On
			// 
			this->radioButtonR15On->AutoSize = true;
			this->radioButtonR15On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR15On->Name = L"radioButtonR15On";
			this->radioButtonR15On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR15On->TabIndex = 0;
			this->radioButtonR15On->TabStop = true;
			this->radioButtonR15On->Text = L"Ligado";
			this->radioButtonR15On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR14
			// 
			this->groupBoxR14->Controls->Add(this->radioButtonR14Off);
			this->groupBoxR14->Controls->Add(this->radioButtonR14On);
			this->groupBoxR14->Location = System::Drawing::Point(273, 12);
			this->groupBoxR14->Name = L"groupBoxR14";
			this->groupBoxR14->Size = System::Drawing::Size(81, 71);
			this->groupBoxR14->TabIndex = 2;
			this->groupBoxR14->TabStop = false;
			this->groupBoxR14->Text = L"R14";
			// 
			// radioButtonR14Off
			// 
			this->radioButtonR14Off->AutoSize = true;
			this->radioButtonR14Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR14Off->Name = L"radioButtonR14Off";
			this->radioButtonR14Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR14Off->TabIndex = 1;
			this->radioButtonR14Off->TabStop = true;
			this->radioButtonR14Off->Text = L"Desligado";
			this->radioButtonR14Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR14On
			// 
			this->radioButtonR14On->AutoSize = true;
			this->radioButtonR14On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR14On->Name = L"radioButtonR14On";
			this->radioButtonR14On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR14On->TabIndex = 0;
			this->radioButtonR14On->TabStop = true;
			this->radioButtonR14On->Text = L"Ligado";
			this->radioButtonR14On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR13
			// 
			this->groupBoxR13->Controls->Add(this->radioButtonR13Off);
			this->groupBoxR13->Controls->Add(this->radioButtonR13On);
			this->groupBoxR13->Location = System::Drawing::Point(186, 12);
			this->groupBoxR13->Name = L"groupBoxR13";
			this->groupBoxR13->Size = System::Drawing::Size(81, 71);
			this->groupBoxR13->TabIndex = 2;
			this->groupBoxR13->TabStop = false;
			this->groupBoxR13->Text = L"R13";
			// 
			// radioButtonR13Off
			// 
			this->radioButtonR13Off->AutoSize = true;
			this->radioButtonR13Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR13Off->Name = L"radioButtonR13Off";
			this->radioButtonR13Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR13Off->TabIndex = 1;
			this->radioButtonR13Off->TabStop = true;
			this->radioButtonR13Off->Text = L"Desligado";
			this->radioButtonR13Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR13On
			// 
			this->radioButtonR13On->AutoSize = true;
			this->radioButtonR13On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR13On->Name = L"radioButtonR13On";
			this->radioButtonR13On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR13On->TabIndex = 0;
			this->radioButtonR13On->TabStop = true;
			this->radioButtonR13On->Text = L"Ligado";
			this->radioButtonR13On->UseVisualStyleBackColor = true;
			// 
			// groupBoxR12
			// 
			this->groupBoxR12->Controls->Add(this->radioButtonR12Off);
			this->groupBoxR12->Controls->Add(this->radioButtonR12On);
			this->groupBoxR12->Location = System::Drawing::Point(99, 12);
			this->groupBoxR12->Name = L"groupBoxR12";
			this->groupBoxR12->Size = System::Drawing::Size(81, 71);
			this->groupBoxR12->TabIndex = 2;
			this->groupBoxR12->TabStop = false;
			this->groupBoxR12->Text = L"R12";
			// 
			// radioButtonR12Off
			// 
			this->radioButtonR12Off->AutoSize = true;
			this->radioButtonR12Off->Location = System::Drawing::Point(7, 44);
			this->radioButtonR12Off->Name = L"radioButtonR12Off";
			this->radioButtonR12Off->Size = System::Drawing::Size(72, 17);
			this->radioButtonR12Off->TabIndex = 1;
			this->radioButtonR12Off->TabStop = true;
			this->radioButtonR12Off->Text = L"Desligado";
			this->radioButtonR12Off->UseVisualStyleBackColor = true;
			// 
			// radioButtonR12On
			// 
			this->radioButtonR12On->AutoSize = true;
			this->radioButtonR12On->Location = System::Drawing::Point(7, 20);
			this->radioButtonR12On->Name = L"radioButtonR12On";
			this->radioButtonR12On->Size = System::Drawing::Size(57, 17);
			this->radioButtonR12On->TabIndex = 0;
			this->radioButtonR12On->TabStop = true;
			this->radioButtonR12On->Text = L"Ligado";
			this->radioButtonR12On->UseVisualStyleBackColor = true;
			// 
			// groupBoxM6
			// 
			this->groupBoxM6->Controls->Add(this->labelM6);
			this->groupBoxM6->Controls->Add(this->trackBarM6);
			this->groupBoxM6->Location = System::Drawing::Point(12, 90);
			this->groupBoxM6->Name = L"groupBoxM6";
			this->groupBoxM6->Size = System::Drawing::Size(168, 87);
			this->groupBoxM6->TabIndex = 3;
			this->groupBoxM6->TabStop = false;
			this->groupBoxM6->Text = L"M6";
			// 
			// labelM6
			// 
			this->labelM6->AutoSize = true;
			this->labelM6->Location = System::Drawing::Point(6, 16);
			this->labelM6->Name = L"labelM6";
			this->labelM6->Size = System::Drawing::Size(13, 13);
			this->labelM6->TabIndex = 1;
			this->labelM6->Text = L"0";
			// 
			// trackBarM6
			// 
			this->trackBarM6->Location = System::Drawing::Point(6, 32);
			this->trackBarM6->Maximum = 32767;
			this->trackBarM6->Minimum = -32768;
			this->trackBarM6->Name = L"trackBarM6";
			this->trackBarM6->Size = System::Drawing::Size(155, 45);
			this->trackBarM6->TabIndex = 0;
			this->trackBarM6->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarM6_Scroll);
			// 
			// groupBoxM7
			// 
			this->groupBoxM7->Controls->Add(this->labelM7);
			this->groupBoxM7->Controls->Add(this->trackBarM7);
			this->groupBoxM7->Location = System::Drawing::Point(186, 90);
			this->groupBoxM7->Name = L"groupBoxM7";
			this->groupBoxM7->Size = System::Drawing::Size(168, 87);
			this->groupBoxM7->TabIndex = 4;
			this->groupBoxM7->TabStop = false;
			this->groupBoxM7->Text = L"M7";
			// 
			// labelM7
			// 
			this->labelM7->AutoSize = true;
			this->labelM7->Location = System::Drawing::Point(6, 16);
			this->labelM7->Name = L"labelM7";
			this->labelM7->Size = System::Drawing::Size(13, 13);
			this->labelM7->TabIndex = 1;
			this->labelM7->Text = L"0";
			// 
			// trackBarM7
			// 
			this->trackBarM7->Location = System::Drawing::Point(6, 32);
			this->trackBarM7->Maximum = 32767;
			this->trackBarM7->Minimum = -32768;
			this->trackBarM7->Name = L"trackBarM7";
			this->trackBarM7->Size = System::Drawing::Size(155, 45);
			this->trackBarM7->TabIndex = 0;
			this->trackBarM7->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarM7_Scroll);
			// 
			// groupBoxM8
			// 
			this->groupBoxM8->Controls->Add(this->labelM8);
			this->groupBoxM8->Controls->Add(this->trackBarM8);
			this->groupBoxM8->Location = System::Drawing::Point(360, 90);
			this->groupBoxM8->Name = L"groupBoxM8";
			this->groupBoxM8->Size = System::Drawing::Size(168, 87);
			this->groupBoxM8->TabIndex = 5;
			this->groupBoxM8->TabStop = false;
			this->groupBoxM8->Text = L"M8";
			// 
			// labelM8
			// 
			this->labelM8->AutoSize = true;
			this->labelM8->Location = System::Drawing::Point(6, 16);
			this->labelM8->Name = L"labelM8";
			this->labelM8->Size = System::Drawing::Size(13, 13);
			this->labelM8->TabIndex = 1;
			this->labelM8->Text = L"0";
			// 
			// trackBarM8
			// 
			this->trackBarM8->Location = System::Drawing::Point(6, 32);
			this->trackBarM8->Maximum = 32767;
			this->trackBarM8->Minimum = -32768;
			this->trackBarM8->Name = L"trackBarM8";
			this->trackBarM8->Size = System::Drawing::Size(155, 45);
			this->trackBarM8->TabIndex = 0;
			this->trackBarM8->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarM8_Scroll);
			// 
			// groupBoxM9
			// 
			this->groupBoxM9->Controls->Add(this->labelM9);
			this->groupBoxM9->Controls->Add(this->trackBarM9);
			this->groupBoxM9->Location = System::Drawing::Point(534, 89);
			this->groupBoxM9->Name = L"groupBoxM9";
			this->groupBoxM9->Size = System::Drawing::Size(168, 87);
			this->groupBoxM9->TabIndex = 6;
			this->groupBoxM9->TabStop = false;
			this->groupBoxM9->Text = L"M9";
			// 
			// labelM9
			// 
			this->labelM9->AutoSize = true;
			this->labelM9->Location = System::Drawing::Point(6, 16);
			this->labelM9->Name = L"labelM9";
			this->labelM9->Size = System::Drawing::Size(13, 13);
			this->labelM9->TabIndex = 1;
			this->labelM9->Text = L"0";
			// 
			// trackBarM9
			// 
			this->trackBarM9->Location = System::Drawing::Point(6, 32);
			this->trackBarM9->Maximum = 32767;
			this->trackBarM9->Minimum = -32768;
			this->trackBarM9->Name = L"trackBarM9";
			this->trackBarM9->Size = System::Drawing::Size(155, 45);
			this->trackBarM9->TabIndex = 0;
			this->trackBarM9->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarM9_Scroll);
			// 
			// groupBoxM10
			// 
			this->groupBoxM10->Controls->Add(this->labelM10);
			this->groupBoxM10->Controls->Add(this->trackBarM10);
			this->groupBoxM10->Location = System::Drawing::Point(708, 90);
			this->groupBoxM10->Name = L"groupBoxM10";
			this->groupBoxM10->Size = System::Drawing::Size(168, 87);
			this->groupBoxM10->TabIndex = 7;
			this->groupBoxM10->TabStop = false;
			this->groupBoxM10->Text = L"M10";
			// 
			// labelM10
			// 
			this->labelM10->AutoSize = true;
			this->labelM10->Location = System::Drawing::Point(6, 16);
			this->labelM10->Name = L"labelM10";
			this->labelM10->Size = System::Drawing::Size(13, 13);
			this->labelM10->TabIndex = 1;
			this->labelM10->Text = L"0";
			// 
			// trackBarM10
			// 
			this->trackBarM10->Location = System::Drawing::Point(6, 32);
			this->trackBarM10->Maximum = 32767;
			this->trackBarM10->Minimum = -32768;
			this->trackBarM10->Name = L"trackBarM10";
			this->trackBarM10->Size = System::Drawing::Size(155, 45);
			this->trackBarM10->TabIndex = 0;
			this->trackBarM10->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarM10_Scroll);
			// 
			// groupBoxD4
			// 
			this->groupBoxD4->Controls->Add(this->trackBarD4);
			this->groupBoxD4->Controls->Add(this->labelD4);
			this->groupBoxD4->Location = System::Drawing::Point(12, 183);
			this->groupBoxD4->Name = L"groupBoxD4";
			this->groupBoxD4->Size = System::Drawing::Size(168, 87);
			this->groupBoxD4->TabIndex = 8;
			this->groupBoxD4->TabStop = false;
			this->groupBoxD4->Text = L"D4";
			// 
			// trackBarD4
			// 
			this->trackBarD4->Location = System::Drawing::Point(7, 32);
			this->trackBarD4->Maximum = 1000;
			this->trackBarD4->Minimum = -1000;
			this->trackBarD4->Name = L"trackBarD4";
			this->trackBarD4->Size = System::Drawing::Size(155, 45);
			this->trackBarD4->TabIndex = 2;
			this->trackBarD4->TickFrequency = 50;
			this->trackBarD4->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarD4_Scroll);
			// 
			// labelD4
			// 
			this->labelD4->AutoSize = true;
			this->labelD4->Location = System::Drawing::Point(6, 16);
			this->labelD4->Name = L"labelD4";
			this->labelD4->Size = System::Drawing::Size(13, 13);
			this->labelD4->TabIndex = 1;
			this->labelD4->Text = L"0";
			// 
			// groupBoxD5
			// 
			this->groupBoxD5->Controls->Add(this->labelD5);
			this->groupBoxD5->Controls->Add(this->trackBarD5);
			this->groupBoxD5->Location = System::Drawing::Point(186, 183);
			this->groupBoxD5->Name = L"groupBoxD5";
			this->groupBoxD5->Size = System::Drawing::Size(168, 87);
			this->groupBoxD5->TabIndex = 9;
			this->groupBoxD5->TabStop = false;
			this->groupBoxD5->Text = L"D5";
			// 
			// labelD5
			// 
			this->labelD5->AutoSize = true;
			this->labelD5->Location = System::Drawing::Point(6, 16);
			this->labelD5->Name = L"labelD5";
			this->labelD5->Size = System::Drawing::Size(13, 13);
			this->labelD5->TabIndex = 1;
			this->labelD5->Text = L"0";
			// 
			// trackBarD5
			// 
			this->trackBarD5->Location = System::Drawing::Point(6, 32);
			this->trackBarD5->Maximum = 1000;
			this->trackBarD5->Minimum = -1000;
			this->trackBarD5->Name = L"trackBarD5";
			this->trackBarD5->Size = System::Drawing::Size(155, 45);
			this->trackBarD5->TabIndex = 0;
			this->trackBarD5->TickFrequency = 50;
			this->trackBarD5->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarD5_Scroll);
			// 
			// groupBoxD6
			// 
			this->groupBoxD6->Controls->Add(this->labelD6);
			this->groupBoxD6->Controls->Add(this->trackBarD6);
			this->groupBoxD6->Location = System::Drawing::Point(360, 183);
			this->groupBoxD6->Name = L"groupBoxD6";
			this->groupBoxD6->Size = System::Drawing::Size(168, 87);
			this->groupBoxD6->TabIndex = 10;
			this->groupBoxD6->TabStop = false;
			this->groupBoxD6->Text = L"D6";
			// 
			// labelD6
			// 
			this->labelD6->AutoSize = true;
			this->labelD6->Location = System::Drawing::Point(6, 16);
			this->labelD6->Name = L"labelD6";
			this->labelD6->Size = System::Drawing::Size(13, 13);
			this->labelD6->TabIndex = 1;
			this->labelD6->Text = L"0";
			// 
			// trackBarD6
			// 
			this->trackBarD6->Location = System::Drawing::Point(6, 32);
			this->trackBarD6->Maximum = 1000;
			this->trackBarD6->Minimum = -1000;
			this->trackBarD6->Name = L"trackBarD6";
			this->trackBarD6->Size = System::Drawing::Size(155, 45);
			this->trackBarD6->TabIndex = 0;
			this->trackBarD6->TickFrequency = 50;
			this->trackBarD6->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarD6_Scroll);
			// 
			// groupBoxD7
			// 
			this->groupBoxD7->Controls->Add(this->labelD7);
			this->groupBoxD7->Controls->Add(this->trackBarD7);
			this->groupBoxD7->Location = System::Drawing::Point(534, 183);
			this->groupBoxD7->Name = L"groupBoxD7";
			this->groupBoxD7->Size = System::Drawing::Size(168, 87);
			this->groupBoxD7->TabIndex = 11;
			this->groupBoxD7->TabStop = false;
			this->groupBoxD7->Text = L"D7";
			// 
			// labelD7
			// 
			this->labelD7->AutoSize = true;
			this->labelD7->Location = System::Drawing::Point(6, 16);
			this->labelD7->Name = L"labelD7";
			this->labelD7->Size = System::Drawing::Size(13, 13);
			this->labelD7->TabIndex = 1;
			this->labelD7->Text = L"0";
			// 
			// trackBarD7
			// 
			this->trackBarD7->Location = System::Drawing::Point(6, 32);
			this->trackBarD7->Maximum = 1000;
			this->trackBarD7->Minimum = -1000;
			this->trackBarD7->Name = L"trackBarD7";
			this->trackBarD7->Size = System::Drawing::Size(155, 45);
			this->trackBarD7->TabIndex = 0;
			this->trackBarD7->TickFrequency = 50;
			this->trackBarD7->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarD7_Scroll);
			// 
			// groupBoxD8
			// 
			this->groupBoxD8->Controls->Add(this->trackBarD8);
			this->groupBoxD8->Controls->Add(this->labelD8);
			this->groupBoxD8->Location = System::Drawing::Point(708, 183);
			this->groupBoxD8->Name = L"groupBoxD8";
			this->groupBoxD8->Size = System::Drawing::Size(168, 87);
			this->groupBoxD8->TabIndex = 12;
			this->groupBoxD8->TabStop = false;
			this->groupBoxD8->Text = L"D8";
			// 
			// trackBarD8
			// 
			this->trackBarD8->Location = System::Drawing::Point(6, 32);
			this->trackBarD8->Maximum = 1000;
			this->trackBarD8->Minimum = -1000;
			this->trackBarD8->Name = L"trackBarD8";
			this->trackBarD8->Size = System::Drawing::Size(155, 45);
			this->trackBarD8->TabIndex = 13;
			this->trackBarD8->TickFrequency = 50;
			this->trackBarD8->Scroll += gcnew System::EventHandler(this, &ControlPanel::trackBarD8_Scroll);
			// 
			// labelD8
			// 
			this->labelD8->AutoSize = true;
			this->labelD8->Location = System::Drawing::Point(6, 16);
			this->labelD8->Name = L"labelD8";
			this->labelD8->Size = System::Drawing::Size(13, 13);
			this->labelD8->TabIndex = 1;
			this->labelD8->Text = L"0";
			// 
			// groupBoxTime
			// 
			this->groupBoxTime->Controls->Add(this->labelSeconds);
			this->groupBoxTime->Controls->Add(this->textBoxTime);
			this->groupBoxTime->Location = System::Drawing::Point(12, 277);
			this->groupBoxTime->Name = L"groupBoxTime";
			this->groupBoxTime->Size = System::Drawing::Size(168, 50);
			this->groupBoxTime->TabIndex = 13;
			this->groupBoxTime->TabStop = false;
			this->groupBoxTime->Text = L"Tempo de Leitura";
			// 
			// labelSeconds
			// 
			this->labelSeconds->AutoSize = true;
			this->labelSeconds->Location = System::Drawing::Point(114, 20);
			this->labelSeconds->Name = L"labelSeconds";
			this->labelSeconds->Size = System::Drawing::Size(53, 13);
			this->labelSeconds->TabIndex = 1;
			this->labelSeconds->Text = L"segundos";
			// 
			// textBoxTime
			// 
			this->textBoxTime->Location = System::Drawing::Point(7, 20);
			this->textBoxTime->Name = L"textBoxTime";
			this->textBoxTime->Size = System::Drawing::Size(100, 20);
			this->textBoxTime->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButtonSimplified);
			this->groupBox1->Controls->Add(this->radioButtonComplete);
			this->groupBox1->Location = System::Drawing::Point(186, 277);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(168, 50);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Gravação de Dados";
			// 
			// radioButtonSimplified
			// 
			this->radioButtonSimplified->AutoSize = true;
			this->radioButtonSimplified->Location = System::Drawing::Point(83, 20);
			this->radioButtonSimplified->Name = L"radioButtonSimplified";
			this->radioButtonSimplified->Size = System::Drawing::Size(81, 17);
			this->radioButtonSimplified->TabIndex = 1;
			this->radioButtonSimplified->TabStop = true;
			this->radioButtonSimplified->Text = L"Simplificada";
			this->radioButtonSimplified->UseVisualStyleBackColor = true;
			// 
			// radioButtonComplete
			// 
			this->radioButtonComplete->AutoSize = true;
			this->radioButtonComplete->Location = System::Drawing::Point(7, 20);
			this->radioButtonComplete->Name = L"radioButtonComplete";
			this->radioButtonComplete->Size = System::Drawing::Size(69, 17);
			this->radioButtonComplete->TabIndex = 0;
			this->radioButtonComplete->TabStop = true;
			this->radioButtonComplete->Text = L"Completa";
			this->radioButtonComplete->UseVisualStyleBackColor = true;
			// 
			// ControlPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(889, 343);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBoxTime);
			this->Controls->Add(this->groupBoxD8);
			this->Controls->Add(this->groupBoxD7);
			this->Controls->Add(this->groupBoxD6);
			this->Controls->Add(this->groupBoxD5);
			this->Controls->Add(this->groupBoxD4);
			this->Controls->Add(this->groupBoxM10);
			this->Controls->Add(this->groupBoxM9);
			this->Controls->Add(this->groupBoxM8);
			this->Controls->Add(this->groupBoxM7);
			this->Controls->Add(this->groupBoxM6);
			this->Controls->Add(this->groupBoxR19);
			this->Controls->Add(this->groupBoxR17);
			this->Controls->Add(this->groupBoxR18);
			this->Controls->Add(this->groupBoxR16);
			this->Controls->Add(this->groupBoxR15);
			this->Controls->Add(this->groupBoxR14);
			this->Controls->Add(this->groupBoxR13);
			this->Controls->Add(this->groupBoxR12);
			this->Controls->Add(this->groupBoxR20);
			this->Controls->Add(this->groupBoxR11);
			this->Name = L"ControlPanel";
			this->Text = L"Painel de Controle do CLP";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ControlPanel::ControlPanel_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ControlPanel::ControlPanel_Load);
			this->groupBoxR11->ResumeLayout(false);
			this->groupBoxR11->PerformLayout();
			this->groupBoxR20->ResumeLayout(false);
			this->groupBoxR20->PerformLayout();
			this->groupBoxR19->ResumeLayout(false);
			this->groupBoxR19->PerformLayout();
			this->groupBoxR18->ResumeLayout(false);
			this->groupBoxR18->PerformLayout();
			this->groupBoxR16->ResumeLayout(false);
			this->groupBoxR16->PerformLayout();
			this->groupBoxR17->ResumeLayout(false);
			this->groupBoxR17->PerformLayout();
			this->groupBoxR15->ResumeLayout(false);
			this->groupBoxR15->PerformLayout();
			this->groupBoxR14->ResumeLayout(false);
			this->groupBoxR14->PerformLayout();
			this->groupBoxR13->ResumeLayout(false);
			this->groupBoxR13->PerformLayout();
			this->groupBoxR12->ResumeLayout(false);
			this->groupBoxR12->PerformLayout();
			this->groupBoxM6->ResumeLayout(false);
			this->groupBoxM6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM6))->EndInit();
			this->groupBoxM7->ResumeLayout(false);
			this->groupBoxM7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM7))->EndInit();
			this->groupBoxM8->ResumeLayout(false);
			this->groupBoxM8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM8))->EndInit();
			this->groupBoxM9->ResumeLayout(false);
			this->groupBoxM9->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM9))->EndInit();
			this->groupBoxM10->ResumeLayout(false);
			this->groupBoxM10->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarM10))->EndInit();
			this->groupBoxD4->ResumeLayout(false);
			this->groupBoxD4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD4))->EndInit();
			this->groupBoxD5->ResumeLayout(false);
			this->groupBoxD5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD5))->EndInit();
			this->groupBoxD6->ResumeLayout(false);
			this->groupBoxD6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD6))->EndInit();
			this->groupBoxD7->ResumeLayout(false);
			this->groupBoxD7->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD7))->EndInit();
			this->groupBoxD8->ResumeLayout(false);
			this->groupBoxD8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarD8))->EndInit();
			this->groupBoxTime->ResumeLayout(false);
			this->groupBoxTime->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ControlPanel_Load(System::Object^  sender, System::EventArgs^  e) {
				 // Open Connection to CLP
				 cm = gcnew ConnManager();
				 cm->OpenPort();

				 // Allocate Buffers
				 pm = gcnew Parameters();
				 // Zero buffers
				 pm->ResetBuffers();

				 // Connection to the database
				 db = gcnew Database();
				 //Testing of Database
				 //db->InsertEntry(pm->GetBufferR(), pm->GetBufferM(), pm->GetBufferD());
				 
				 // Hook up the Elapsed event for the timer.
				 aTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(OnTimedEvent);
				 aTimer->Enabled = true;
	}

#pragma region Controller Functions
	private: void ReadDataFromCLP(void)
	{
				 // Read Data from CLP and save in the buffer
				 bufferMutex->WaitOne();
				 clpMutex->WaitOne();

				 cm->ReadDataParamR(pm->GetBufferR());
				 cm->ReadDataParamM(pm->GetBufferM());
				 cm->ReadDataParamD(pm->GetBufferD());

				 // Release mutexes
				 clpMutex->ReleaseMutex();
				 bufferMutex->ReleaseMutex();
	}

	private: void SaveDataToCLP(void)
	{
				 // Read Data from Buffer and save in the CLP
				 bufferMutex->WaitOne();
				 clpMutex->WaitOne();

				 cm->WriteDataParamR(pm->GetBufferR());
				 cm->WriteDataParamM(pm->GetBufferM());
				 cm->WriteDataParamD(pm->GetBufferD());

				 // Release mutexes
				 clpMutex->ReleaseMutex();
				 bufferMutex->ReleaseMutex();
	}

	private: void UpdateView(void)
	{
				 bufferMutex->WaitOne();

				 // Update the View
				 // Update R
				 if (pm->GetBufferR()[0] == 0) radioButtonR11Off->Select();
				 else radioButtonR11On->Select();

				 if (pm->GetBufferR()[1] == 0) radioButtonR12Off->Select();
				 else radioButtonR12On->Select();

				 if (pm->GetBufferR()[2] == 0) radioButtonR13Off->Select();
				 else radioButtonR13On->Select();

				 if (pm->GetBufferR()[3] == 0) radioButtonR14Off->Select();
				 else radioButtonR14On->Select();

				 if (pm->GetBufferR()[4] == 0) radioButtonR15Off->Select();
				 else radioButtonR15On->Select();

				 if (pm->GetBufferR()[5] == 0) radioButtonR16Off->Select();
				 else radioButtonR16On->Select();

				 if (pm->GetBufferR()[6] == 0) radioButtonR17Off->Select();
				 else radioButtonR17On->Select();

				 if (pm->GetBufferR()[7] == 0) radioButtonR18Off->Select();
				 else radioButtonR18On->Select();

				 if (pm->GetBufferR()[8] == 0) radioButtonR19Off->Select();
				 else radioButtonR19On->Select();

				 if (pm->GetBufferR()[9] == 0) radioButtonR20Off->Select();
				 else radioButtonR20On->Select();

				 // Update M
				 trackBarM6->Value = pm->GetBufferM()[0];
				 labelM6->Text = pm->GetBufferM()[0].ToString();

				 trackBarM7->Value = pm->GetBufferM()[1];
				 labelM7->Text = pm->GetBufferM()[1].ToString();

				 trackBarM8->Value = pm->GetBufferM()[2];
				 labelM8->Text = pm->GetBufferM()[2].ToString();

				 trackBarM9->Value = pm->GetBufferM()[3];
				 labelM9->Text = pm->GetBufferM()[3].ToString();

				 trackBarM10->Value = pm->GetBufferM()[4];
				 labelM10->Text = pm->GetBufferM()[4].ToString();

				 // Update D
				 trackBarD4->Value = pm->GetBufferD()[0];
				 labelD4->Text = pm->GetBufferD()[0].ToString();

				 trackBarD5->Value = pm->GetBufferD()[1];
				 labelD5->Text = pm->GetBufferD()[1].ToString();

				 trackBarD6->Value = pm->GetBufferD()[2];
				 labelD6->Text = pm->GetBufferD()[2].ToString();

				 trackBarD7->Value = pm->GetBufferD()[3];
				 labelD7->Text = pm->GetBufferD()[3].ToString();

				 trackBarD8->Value = pm->GetBufferD()[4];
				 labelD8->Text = pm->GetBufferD()[4].ToString();

				 bufferMutex->ReleaseMutex();
	}

	private: void SaveParametersToDatabase(void)
	{
				 // Save data in the database
				 dbMutex->WaitOne();
				 bufferMutex->WaitOne();

				 db->InsertEntry(pm->GetBufferR(), pm->GetBufferM(), pm->GetBufferD());

				 bufferMutex->ReleaseMutex();
				 dbMutex->ReleaseMutex();
	}

	private: static void OnTimedEvent(Object^ source, System::Timers::ElapsedEventArgs^ e)
	{
				 ((ControlPanel^)source)->ReadDataFromCLP();
				 ((ControlPanel^)source)->SaveParametersToDatabase();
	}

#pragma endregion

	private: System::Void ControlPanel_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 cm->ClosePort();
				 cm->FreeLib();
	}

	private: System::Void trackBarM6_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 labelM6->Text = trackBarM6->Value.ToString();
	}
	private: System::Void trackBarM7_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 labelM7->Text = trackBarM7->Value.ToString();
	}
	private: System::Void trackBarM8_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 labelM8->Text = trackBarM8->Value.ToString();
	}
	private: System::Void trackBarM9_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 labelM9->Text = trackBarM9->Value.ToString();
	}
	private: System::Void trackBarM10_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 labelM10->Text = trackBarM10->Value.ToString();
	}
	private: System::Void trackBarD4_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 float f = ((float)trackBarD4->Value) * 1E35;
				 labelD4->Text = f.ToString();
	}
	private: System::Void trackBarD5_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 float f = ((float)trackBarD5->Value) * 1E35;
				 labelD5->Text = f.ToString();
	}
	private: System::Void trackBarD6_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 float f = ((float)trackBarD6->Value) * 1E35;
				 labelD6->Text = f.ToString();
	}
	private: System::Void trackBarD7_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 float f = ((float)trackBarD7->Value) * 1E35;
				 labelD7->Text = f.ToString();
	}
	private: System::Void trackBarD8_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 float f = ((float)trackBarD8->Value) * 1E35;
				 labelD8->Text = f.ToString();
	}
};
}
