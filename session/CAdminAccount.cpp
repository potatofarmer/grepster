/*
    File:       CAdminAccount.cpp
    Version:    Alpha
    Author:     Allen Vanderlinde

    Desc:       grepster's administrator account class initialization and methods.

    Created:    12/3/14

    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#include "../precomp.h"

#include "CAdminAccount.h"


/*
    CAdminAccount::CAdminAccount
*/
CAdminAccount::CAdminAccount(wxString username) {
    /* Set basic administrator authentication information. */
    m_szUsername = username;
    m_szPassword = wxEmptyString;
}
