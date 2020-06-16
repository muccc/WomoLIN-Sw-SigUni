/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include <cinttypes>
#include <string>
#include <map>


namespace siguni::interface
{

	class ISignal
	{
	  public:
		 virtual ~ISignal() = default;
		 virtual void UpdateUnit( std::string & attKey, std::string & attValue ) = 0;
	};

	class ISignalSetReset
	{
	  public:
		 virtual ~ISignalSetReset() = default;
		 virtual void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue ) = 0;
	};

	class ISignalGetVoltage
	{
	  public:
		 virtual ~ISignalGetVoltage() = default;
		 virtual void UpdateUnitSignalGetVoltage( std::string & attKey, std::string & attGetVoltage ) = 0;
	};

	class ISignalGetVersion
	{
	  public:
		 virtual ~ISignalGetVersion() = default;
		 virtual void UpdateUnitSignalGetVersion( std::string & attKey, std::string & attVersion ) = 0;
	};


}

