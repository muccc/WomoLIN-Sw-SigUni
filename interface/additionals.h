/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include <cinttypes>
#include <string>
#include <map>


namespace siguni::interface
{

	class CAdditionals 
	{
	  public:
       CAdditionals() = default;
		 ~CAdditionals() = default;

       bool SimulationMode { false };      

       void WriteErrorLog( std::string attIdentifier, std::string attErrorLog ) 
       { 
         errorLog.clear();
         errorLog[attIdentifier] = attErrorLog; 
       };

       std::string ReadErrorLog() 
       {
         return errorLog.begin()->first + " ==> " + errorLog.begin()->second ; 
       };

		 std::map<std::string_view, std::string> Settings;

    private:
      std::map<std::string, std::string> errorLog;
	};

}

