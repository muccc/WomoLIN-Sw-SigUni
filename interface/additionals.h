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

       bool SimulationActive { false };      
       void writeLog( std::string attLogMsg ) { lastLog = attLogMsg; } ;
       std::string readLog() { return lastLog; } ;

		 std::map<std::string_view, std::string> Settings;

    private:
      std::string lastLog;
	};

}

