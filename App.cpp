#include "App.h"
#include <wx/wx.h>
#include "MainFrame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainFrame = new MainFrame("Ciphher");
	mainFrame->SetClientSize(600, 500);
	mainFrame->Center();
	mainFrame->Show();
	return true;
}
