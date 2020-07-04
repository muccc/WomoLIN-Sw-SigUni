/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "iunit.h"

namespace siguni::interface
{

   class IControlbus
   {
      public:
         virtual ~IControlbus() = default;

         virtual int WriteData( const std::string & attMessage ) = 0;
         virtual int ReadData( std::string & attMessage ) = 0;
   };

	class IUnitInputGetHwBoardVersion : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetHwBoardVersion() = default;

		 void Get( std::string & attGetInput, std::map<std::string_view, std::string> & attAdditionalSettings ) override = 0;
	};

	class IUnitInputGetDriverVersion : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IUnitInputGetDriverVersion() = default;

		 void Get( std::string & attGetInput, std::map<std::string_view, std::string> & attAdditionalSettings ) override = 0;
	};

}

