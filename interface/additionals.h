/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include <cinttypes>
#include <string>
#include <map>
#include <iostream>

// TODO Log Macro and gtest for Log Macro, see hal_test.cpp CHalUnitInputGetLogging 

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

         if( errorLog.size() ){
            return errorLog.begin()->first + " ==> " + errorLog.begin()->second ; 
         }
         else {
            return "" ; 
         }

       };

		 std::map<std::string_view, std::string> Settings;

    private:
      std::map<std::string, std::string> errorLog;
	};

}

