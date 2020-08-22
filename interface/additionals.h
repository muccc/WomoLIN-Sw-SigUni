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

       void WriteErrorLog( std::string attIdentifier, std::string attErrorLog );
       [[nodiscard]] std::string ReadErrorLog(); 

       // TODO use functions
       bool SimulationMode { false };      
		 std::map<std::string_view, std::string> Settings;

    private:
      std::map<std::string, std::string> errorLog;
	};

}

