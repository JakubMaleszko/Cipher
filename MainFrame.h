#pragma once
#include <wx/wx.h>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
private:
	wxTextCtrl* textCtrl1;
	wxTextCtrl* textCtrl2;
	void OnCodeButtonClick(wxCommandEvent& event);
	void OnDecodeButtonClick(wxCommandEvent& event);
};

