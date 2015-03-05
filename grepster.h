/**
 * @file    grepster.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   grepster's global definitions, main classes, and variables.
 */
/*
    Copyright (C) 2014-2015 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _GREPSTER_H_
#define _GREPSTER_H_

#include <wx/wx.h>

#include "app/CConsole.h"
#include "app/CServerStacks.h"
#include "app/CGrepNotebook.h"
#include "app/CAppInit.h"

#include "version.h"


/** grepster's frame globals. */
extern wxString         g_szFrameTitle;

/**
 * This control reports grepster's activity and remote commands to the user.
 * @brief       grepster's console.
 */
extern CConsole*        Console;
/**
 * This control is the graphical list of servers configured for grepping.
 * @brief       grepster's Server Stack.
 */
extern CServerStacks*     ServerStacks;
/**
 * This control holds the user's notebook of grep scripts and jobs.
 * @brief       grepster's grep Session Notebook.
 */
extern CGrepNotebook*   GrepNotebook;

/**
 * This object contains each of grepster's configuration settings which are saved automatically to file upon change.
 *
 * @brief       grepster's configuration object.
 */
extern CAppInit*        Configuration;

/**
 * @brief       Structure which represents a dialog's basic control variables.
 * Note: This is defined in each CDialog type class.
 */
struct dialogVars_t {
    wxString title;
    unsigned short width;
    unsigned short height;
};

/* Utility functions. */
/**
 * @brief       Translate a resource integer ID into a wxWidgets readable string for calling resources.
 * @param[in]   id The resource's integer ID as found in grepster_rc.h.
 */
wxString RESOURCE_ID_TO_STRING(int id);

/**
 * @brief       Creates a child process and sends it an argument list for remote commands. SpawnAndRun also records the child's stdout to grepster's console.
 * @param[in]   path Local directory path to external application.
 * @param[in]   args Argument list passed to child process.
 * @retval      std::string Returns the process's stdout buffer as a string.
 *
 * grepster can launch external applications and send them arguments as if it were a terminal.
 *
 * For example:
 * @code
 * C:\Users\Admin>psftp admin@127.0.0.1 -pw passwd
 * @endcode
 * can be launched with grepster code as:
 * @code
 * *Console << SpawnAndRun("C:\Program Files (x86)\PuTTY\", "psftp.exe admin@127.0.0.1 -pw passwd");
 * @endcode
 */
std::string SpawnAndRun(wxString path, wxString args);

/**
 * @brief       Casts a variable's identifier as a wxString for debugging/console reporting.
 */
#define _cast(v) wxString(#v)

/** grepster's configuration file path. */
#define CONFIGURATION_FILE_PATH             "grepster.xml"

/** grepster's buffer length for sending remote commands. Measured in bytes. */
#define CHAR_BUFFER_LENGTH                  4096

/* These are globals which identify the various PuTTY programs grepster uses. */
/** The default path to PuTTY. */
#define DEFAULT_PATH_TO_PUTTY               L"C:\\Program Files (x86)\\PuTTY\\"
/** Name of grepster's SFTP program. */
#define SFTP_COMMAND_STRING                 L"psftp "
/** Name of grepster's SSH link program. */
#define SSH_COMMAND_STRING                  L"plink "

/* Console control settings. */
/** grepster's console control ID. */
#define CONSOLE_ID                          1000
/** grepster's console's local name for wxWidgets. */
#define CONSOLE_NAME                        "the_con"
/** grepster's console's control title. */
#define CONSOLE_CTRL_TITLE                  L"Console"
/** Default height (pixels) of grepster's console control used when floating. */
#define CONSOLE_DEFAULT_HEIGHT              140

/* Server Stacks tree control settings. */
/** grepster's server stack's control ID. */
#define SERVER_STACKS_ID                    1001
/** grepster's server stack's local name for wxWidgets. */
#define SERVER_STACKS_NAME                  "server_stacks"
/** grepster's server stack's control title. */
#define SERVER_STACKS_CTRL_TITLE            L"Server Stacks"
/** Default width (pixels) of grepster's tree list control used when floating. */
#define SERVER_STACKS_DEFAULT_WIDTH         200

/* Grep Notebook control settings. */
/** grepster's AUI notebook control ID. */
#define GREP_NOTEBOOK_ID                    1002
/** grepster's notebook's local name for wxWidgets. */
#define GREP_NOTEBOOK_NAME                  "grep_notebook"
/** grepster's notebook control title. */
#define GREP_NOTEBOOK_CTRL_TITLE            L"Notebook"

/* Browser/web viewer control settings. */
/** grepster's browser control ID. */
#define BROWSER_ID                          1003
/** grepster's browser's local name for wxWidgets. */
#define BROWSER_NAME                        "browser"

#endif
