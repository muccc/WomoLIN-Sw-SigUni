/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "iunit.h"

namespace siguni::interface
{

	class IInputHwBoardVersion : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IInputHwBoardVersion() = default;

		 void Get( std::string & attGetInput ) override = 0;
	};

	class IInputDriverVersion : public siguni::interface::IUnitInput
	{
	  public:
		 virtual ~IInputDriverVersion() = default;

		 void Get( std::string & attGetInput ) override = 0;
	};

}

