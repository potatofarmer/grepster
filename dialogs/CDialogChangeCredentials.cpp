/**
 * @file    CDialogChangeCredentials.cpp
 * @author  Allen Vanderlinde
 * @date    February 28, 2015
 * @brief   Dialog box's methods.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "../resources/grepster_rc.h"

#include "CDialogChangeCredentials.h"
#include "../app/CAppFrame.h"


/* The dialog's event handler calls. */
wxBEGIN_EVENT_TABLE(CDialogChangeCredentials, wxDialog)
    EVT_BUTTON(CDialogChangeCredentials::BUTTON_OK, CDialogChangeCredentials::OnOK)
wxEND_EVENT_TABLE()

/*
    CDialogChangeCredentials::CDialogChangeCredentials
*/
CDialogChangeCredentials::CDialogChangeCredentials(wxWindow* parentFrame, dialogVars_t dialogVars)
    : wxDialog(parentFrame, wxID_ANY, dialogVars.title, wxDefaultPosition, wxSize(dialogVars.width, dialogVars.height)) {
    SetIcon(wxICON(aaaaappicon));
    CenterOnParent();
    /* Dialog controls. */
    wxStaticText* pTextUsername, *pTextPassword;
    pTextUsername = new wxStaticText(this, wxID_ANY, L"Username:");
    m_pInputUsername = new wxTextCtrl(this, INPUT_USERNAME, Configuration->Username(), wxDefaultPosition, wxSize(210, -1));
    pTextPassword = new wxStaticText(this, wxID_ANY, L"Password:");
    m_pInputPassword = new wxTextCtrl(this, INPUT_PASSWORD, Configuration->Password(), wxDefaultPosition, wxSize(210, -1), wxTE_PASSWORD);

    m_pButtonOK = new wxButton(this, BUTTON_OK, L"OK", wxDefaultPosition, wxDefaultSize);
    wxButton* pButtonCancel = new wxButton(this, wxID_CANCEL, L"Cancel", wxPoint(0, 0), wxDefaultSize); // Cancel button for convenience; catches ESC key
    m_pButtonOK->SetDefault();

    // Create dialog's banner
    wxStaticBitmap* pPNGBanner = new wxStaticBitmap(this, wxID_ANY, wxBitmap(RESOURCE_ID_TO_STRING(RESID_PNG_CREDENTIALS), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize);

    /* Set dialog's main sizers. */
    m_pSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* pSizerButtons = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* pStaticSizer = new wxStaticBoxSizer(wxVERTICAL, this, L"Credentials");
    wxFlexGridSizer* pSizerInput = new wxFlexGridSizer(2, 2, 5, 5);

    pSizerInput->Add(pTextUsername, wxSizerFlags().Center());
    pSizerInput->Add(m_pInputUsername, 1, wxEXPAND);
    pSizerInput->Add(pTextPassword, wxSizerFlags().Center());
    pSizerInput->Add(m_pInputPassword, 1, wxEXPAND);

    pStaticSizer->Add(pSizerInput, wxSizerFlags().Border(wxALL, 5));

    pSizerButtons->Add(m_pButtonOK, wxSizerFlags().Center());
    pSizerButtons->Add(pButtonCancel, wxSizerFlags().Center());

    m_pSizer->Add(pPNGBanner);
    m_pSizer->Add(pStaticSizer, wxSizerFlags().Center().Expand().Border(wxALL, 5));
    m_pSizer->Add(pSizerButtons, wxSizerFlags().Center());

    SetSizer(m_pSizer);
    Show(true); // Display the dialog box
}

/*
    CDialogChangeCredentials::OnOK
*/
void CDialogChangeCredentials::OnOK(wxCommandEvent& event) {
    wxString szPrevUsername = Configuration->Username();
    wxString szPrevPassword = Configuration->Password();
    /* Change the administrator's credentials and update configuration. Note: The user's password is never saved to file. */
    Configuration->ChangeCredentials(m_pInputUsername->GetLineText(0), m_pInputPassword->GetLineText(0));
    if(!szPrevUsername.IsSameAs(Configuration->Username())) {
        *Console << L"\n\nChanging username from " + szPrevUsername + " to " + Configuration->Username() + ".";
        Configuration->WriteXMLData();
        ServerStacks->UpdateStacks();
    }
    if(!szPrevPassword.IsSameAs(Configuration->Password())) {
        Console->BlueText();
        *Console << L"\n\nChanging password.";
        Console->BlackText();
    }

    EndModal(BUTTON_OK);    // End the dialog box with a specified successful return code
}
