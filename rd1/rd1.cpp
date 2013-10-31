// rd1.cpp : main project file.

#include "stdafx.h"
#include "ControlPanel.h"

using namespace rd1;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew ControlPanel());

	return 0;
}
