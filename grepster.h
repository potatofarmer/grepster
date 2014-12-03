/**
 * @file    grepster.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   grepster's global definitions, main classes, and variables.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _GREPSTER_H_
#define _GREPSTER_H_

#include <wx/wx.h>

#include "app/CConsole.h"
#include "app/CServerStack.h"
#include "app/CGrepNotebook.h"
#include "app/CAppInit.h"

#include "version.h"

/** grepster's frame globals. */
extern wxString         g_szFrameTitle;

/**
 * This object reports grepster's activity to a central text control for the user.
 * @brief       grepster's console.
 */
extern CConsole*        Console;
/**
 * This object holds the list of server's configured for grepping.
 * @brief       grepster's Server Stack.
 */
extern CServerStack*     ServerStack;
/**
 * This object holds the user's book of grep session pages.
 * @brief       grepster's grep Session Notebook.
 */
extern CGrepNotebook*   GrepNotebook;

/**
 * This structure contains each of grepster's configuration settings which are saved automatically file upon change.
 *
 * @brief       grepster's configuration object.
 */
extern CAppInit*        Configuration;

/* Utility functions. */
/**
 * @brief       Translate a resource integer ID into a wxWidgets readable string for calling resources.
 *
 * @param[in]   id The resource's integer ID as found in grepster_rc.h.
 */
wxString RESOURCE_ID_TO_STRING(int id);

/**
 * @brief       Casts a variable's identifier as a wxString for debugging/console reporting.
 */
#define _cast(v) wxString(#v)

/** grepster's configuration file path. */
#define CONFIGURATION_FILE_PATH     "grepster.xml"

/* Console control settings. */
/** grepster's console control ID. */
#define CONSOLE_ID                  1000
/** grepster's console's local name for wxWidgets. */
#define CONSOLE_NAME                "the_con"
/** grepster's console's control title. */
#define CONSOLE_CTRL_TITLE          "Console"
/** Default height (pixels) of grepster's console control used when floating. */
#define CONSOLE_DEFAULT_HEIGHT      140

/* Server stack control settings. */
/** grepster's server stack's control ID. */
#define SERVER_STACK_ID              1001
/** grepster's server stack's local name for wxWidgets. */
#define SERVER_STACK_NAME            "server_stack"
/** grepster's server stack's control title. */
#define SERVER_STACK_CTRL_TITLE      "Server Stacks"
/** Default width (pixels) of grepster's tree list control used when floating. */
#define SERVER_STACK_DEFAULT_WIDTH   200

/* Grep Notebook control settings. */
/** grepster's AUI notebook control ID. */
#define GREP_NOTEBOOK_ID            1002
/** grepster's notebook's local name for wxWidgets. */
#define GREP_NOTEBOOK_NAME          "grep_notebook"
/** grepster's notebook control title. */
#define GREP_NOTEBOOK_CTRL_TITLE    "Grep Notebook"

/* Browser/web viewer control settings. */
/** grepster's browser control ID. */
#define BROWSER_ID             1003
/** grepster's browser's local name for wxWidgets. */
#define BROWSER_NAME           "browser"

#endif
