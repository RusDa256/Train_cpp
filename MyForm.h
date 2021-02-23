#pragma once
#include <iostream>
#include "Header.h"
#include <vector>
#include<math.h>

namespace Train {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			Vagon = new vector<vagon>();
			Parovoz = new vector<parovoz>();
			graphics = panel->CreateGraphics(); // получение холста
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		bool drawn = false; // проверка на нарисованный поезд
		int count = 1; // количество вагонов
		int speed = 1; // скорость
		int h = 3; // масштаб

	private: System::Diagnostics::EventLog^ eventLog1;
	private: System::Windows::Forms::PictureBox^ panel;

		   vector <vagon>* Vagon;
		   vector <parovoz>* Parovoz;

	private: System::Windows::Forms::Button^ button1;
	protected:
		Pen^ pen;
		Graphics^ graphics;
		Brush^ colorVag;
		Brush^ colorPar;
		int indexcolor; // индекс номера цвета
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TrackBar^ label;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ trackBar1;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->eventLog1 = (gcnew System::Diagnostics::EventLog());
			this->panel = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label = (gcnew System::Windows::Forms::TrackBar());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panel))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// eventLog1
			// 
			this->eventLog1->SynchronizingObject = this;
			// 
			// panel
			// 
			this->panel->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel->Location = System::Drawing::Point(96, -3);
			this->panel->Name = L"panel";
			this->panel->Size = System::Drawing::Size(781, 414);
			this->panel->TabIndex = 0;
			this->panel->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(6, 359);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Новый поезд";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 70;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LawnGreen;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(6, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 42);
			this->button2->TabIndex = 2;
			this->button2->Text = L"PLay";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(6, 49);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 42);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label
			// 
			this->label->BackColor = System::Drawing::SystemColors::Control;
			this->label->Location = System::Drawing::Point(6, 315);
			this->label->Maximum = 6;
			this->label->Name = L"label";
			this->label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label->Size = System::Drawing::Size(84, 45);
			this->label->TabIndex = 4;
			this->label->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 296);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 22);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Скорость";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(6, 122);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(84, 20);
			this->numericUpDown1->TabIndex = 8;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 19);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Вагоны";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 166);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 23);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Масштаб";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(6, 186);
			this->trackBar1->Maximum = 8;
			this->trackBar1->Minimum = 3;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(84, 45);
			this->trackBar1->TabIndex = 8;
			this->trackBar1->Value = 3;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll_1);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"Оранжевый", L"Коричневый", L"Синий",
			L"Зелёный", L"Фиолетовый", L"Жёлтый"});
			this->comboBox1->Location = System::Drawing::Point(6, 253);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(84, 21);
			this->comboBox1->TabIndex = 12;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->SelectedItem = "Оранжевый";
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;

			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(6, 233);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 19);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Цвет";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 411);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->panel))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->label))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		panel->Refresh();
		Parovoz->clear();
		Vagon->clear();
		Parovoz->push_back(parovoz(50 + 46 * h, 250, h));
		for (int i = 0; i < count; i++)
		{
			Vagon->push_back(vagon(50 - i * 46 * h, 250, h));
		}
		if (h < 6)
		{
			pen = gcnew Pen(System::Drawing::Color::Black, 2);
		}
		else
		{
			pen = gcnew Pen(System::Drawing::Color::Black, 3);
		}
		for (parovoz& elem : *this->Parovoz)
		{
			elem.DrawParovoz(pen, graphics, colorPar, h);
		}
		for (vagon& elem : *this->Vagon)
		{
			elem.DrawVagon(graphics, pen, colorVag, h);
		}
		drawn = true;
	}
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (drawn)
		{
			timer1->Enabled = true;
		}
    }
    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (speed > 0)
		{
			timer1->Enabled = true;
			panel->Refresh();
			for (parovoz& elem : *this->Parovoz)
			{
				elem.Play(speed);
				elem.Playparovoz(speed, graphics,h);
				elem.DrawParovoz(pen, graphics, colorPar, h);
			}
			for (vagon& elem : *this->Vagon)
			{
				elem.PlayVag(speed);
				elem.Play(speed);
				elem.DrawVagon(graphics, pen, colorVag,h);
			}
		}

	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
	}
    private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {

		speed = label->Value;
    }
    private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		count = (int)numericUpDown1->Value;
    }
    
    private: System::Void trackBar1_Scroll_1(System::Object^ sender, System::EventArgs^ e) {
		if (!drawn)
		{
			h = trackBar1->Value;	
		}
    }
    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		indexcolor = comboBox1->SelectedIndex;
		switch (indexcolor)
		{
		case 0:
		{
			colorVag = gcnew SolidBrush(Color::Orange);
			colorPar = gcnew SolidBrush(Color::OrangeRed);
			break;
		}
		case 1:
		{
			colorVag = gcnew SolidBrush(Color::Chocolate);
			colorPar = gcnew SolidBrush(Color::Brown);
			break;
		}
		case 2:
		{
			colorVag = gcnew SolidBrush(Color::DeepSkyBlue);
			colorPar = gcnew SolidBrush(Color::Blue);
			break;
		}
		case 3:
		{
			colorVag = gcnew SolidBrush(Color::Lime);
			colorPar = gcnew SolidBrush(Color::DarkGreen);
			break;
		}
		case 4:
		{
			colorVag = gcnew SolidBrush(Color::Violet);
			colorPar = gcnew SolidBrush(Color::BlueViolet);
			break;
		}
		case 5:
		{
			colorVag = gcnew SolidBrush(Color::Yellow);
			colorPar = gcnew SolidBrush(Color::BurlyWood);
			break;
		}
		}
    }
};
}
