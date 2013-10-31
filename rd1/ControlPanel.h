#include "ConnManager.h"
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
	public:
		ControlPanel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}
	private: System::Windows::Forms::GroupBox^  groupBoxR11;
	public:
	private: System::Windows::Forms::RadioButton^  radioButtonR11Off;
	private: System::Windows::Forms::RadioButton^  radioButtonR11On;
			 ConnManager ^ cm;

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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBoxR11 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonR11On = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR11Off = (gcnew System::Windows::Forms::RadioButton());
			this->groupBoxR11->SuspendLayout();
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
			// ControlPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(573, 485);
			this->Controls->Add(this->groupBoxR11);
			this->Name = L"ControlPanel";
			this->Text = L"ControlPanel";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ControlPanel::ControlPanel_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ControlPanel::ControlPanel_Load);
			this->groupBoxR11->ResumeLayout(false);
			this->groupBoxR11->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ControlPanel_Load(System::Object^  sender, System::EventArgs^  e) {
				 cm = gcnew ConnManager();
				 cm->OpenPort();
	}
	private: System::Void ControlPanel_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 cm->ClosePort();
				 cm->FreeLib();
	}
	};
}
