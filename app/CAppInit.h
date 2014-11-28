/**
 * @file    CAppInit.h
 * @author  Allen Vanderlinde
 * @date    November 27, 2014
 * @brief   This object loads and populates grepster's configuration settings.
 */
/*
    Copyright (C) 2014 by Allen Vanderlinde.
    Songbird and its source code is licensed under the GNU General Public License (GPL)
    and is subject to the terms and conditions provided in LICENSE.txt.
*/

#ifndef _CAPPINIT_H_
#define _CAPPINIT_H_

#include "../pugixml-1.4/pugixml.hpp"

/**
 * This object opens grepster's XML configuration and populates the configuration structure with its settings.
 * Variables which control grepster's current usage are public within this class so that they can be easily modified by other grepster objects.
 *
 * @class   CAppInit
 * @brief   Class definition for grepster's configuration.
 */
class CAppInit {
public:
    /**
     * @brief       Default constructor loads grepster's configuration from file and populates the configuration structure with its settings.
     */
    CAppInit();

    /**
     * Note: The order in which configuration settings are written to file must not be changed. This processing order is hard-coded.
     * @brief       Writes XML data to file from any configuration changes.
     */
    void WriteXMLData();

    /**
     * @brief       Query successful loading of configuration.
     */
    bool Success() { return m_bConfigurationLoadedSuccessfully; }

    /* Configuration session flags/settings. */
    /** Toggle floating controls. */
    bool bToggleFloating;

private:
    /**
     * Note: The order in which elements are parsed and settings applied must not be changed. This processing order is hard-coded.
     * @brief       Reads XML data from file and applies its values to this class's members.
     */
    void ApplyXMLData();

    /** XML file handle. */
    pugi::xml_document m_XMLFile;
    /** pugixml's parsing node used to read XML data. */
    pugi::xml_node m_XMLSettings;

    /** Flag for successful loading of configuration. */
    bool m_bConfigurationLoadedSuccessfully;
};

#endif // _CAPPINIT_H_