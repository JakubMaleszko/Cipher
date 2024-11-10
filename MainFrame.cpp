#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/font.h>


MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "Cipher");
    wxFont font(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    staticText->SetFont(font);

    textCtrl1 = new wxTextCtrl(this, wxID_ANY, "Normal text", wxDefaultPosition, wxSize(300, 100), wxTE_MULTILINE);
    wxButton* codeButton = new wxButton(this, wxID_ANY, "Encrypt");
    wxButton* decodeButton = new wxButton(this, wxID_ANY, "Decrypt");
    textCtrl2 = new wxTextCtrl(this, wxID_ANY, "Encrypted text", wxDefaultPosition, wxSize(300, 100), wxTE_MULTILINE);

    codeButton->Bind(wxEVT_BUTTON, &MainFrame::OnCodeButtonClick, this);
	decodeButton->Bind(wxEVT_BUTTON, &MainFrame::OnDecodeButtonClick, this);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonSizer->Add(codeButton, 1);
    buttonSizer->AddSpacer(10);
    buttonSizer->Add(decodeButton, 1);

    mainSizer->Add(staticText, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);
    mainSizer->Add(textCtrl1, 1, wxEXPAND | wxALL, 10);
    mainSizer->Add(buttonSizer, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP | wxBOTTOM, 10);
    mainSizer->Add(textCtrl2, 1, wxEXPAND | wxALL, 10);

    // Set the sizer and fit
    SetSizerAndFit(mainSizer);
}

void MainFrame::OnCodeButtonClick(wxCommandEvent& event) {

    std::string process = textCtrl1->GetValue().ToStdString();
    int len = process.length();
    std::vector<int> ascii(len);
    std::vector<int> cascii(len);
    for (int i = 0; i <= len - 1; i++)
    {
        ascii[i] = process[i];
        // start ciphering
        cascii[i] = ascii[i] + len;
        while (cascii[i] > 126)
        {
            cascii[i] -= 94;
        }
        process[i] = cascii[i];
    }
    textCtrl2->SetValue(process);
}

void MainFrame::OnDecodeButtonClick(wxCommandEvent& event) {
        std::string process = textCtrl2->GetValue().ToStdString();
        int len = process.length();
        std::vector<int> ascii(len);
        std::vector<int> cascii(len);
        for (int i = 0; i <= len - 1; i++)
        {
            ascii[i] = process[i];
            // start deciphering
            cascii[i] = ascii[i] - len;
            while (cascii[i] < 32)
            {
                cascii[i] += 94;
            }
            process[i] = cascii[i];
        }
        textCtrl1->SetValue(process);
    
}