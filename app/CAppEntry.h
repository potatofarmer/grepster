/**
 * @file    CAppEntry.h
 * @author  Allen Vanderlinde
 * @date    November 2, 2014
 * @brief   wxWidgets application execution class definition.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    grepster and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPENTRY_H_
#define _CAPPENTRY_H_

#include <wx/wx.h>

#include "CAppFrame.h"

/** Option to display the splash screen. */
#define DISPLAY_SPLASH                  false
/** Splash screen duration in milliseconds. */
#define SPLASH_DURATION                 1700

/**
 * This object registers the application with the OS and executes the application's primary frame.
 * @class   CAppEntry
 * @brief   Class definition for grepster's application execution.
 */
class CAppEntry : public wxApp {
public:
    /** Initializes the wxWidgets application back-end. */
    virtual bool OnInit();
    /** Display grepster's splash screen. */
    bool ShowSplash(int resource_id);

private:
    /** grepster's primary frame. */
    CAppFrame* m_pGrepsterFrame;

    /**
     * @brief       Load grepster's configuration from file.
     * @retval      bool Returns true if configuration was loaded successfully.
     */
    bool LoadConfiguration();
};

#endif  // _CAPPENTRY_H_
