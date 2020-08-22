/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "additionals.h" 

namespace siguni::interface
{

	class ISignal
	{
	  public:
		 virtual ~ISignal() = default;
		 virtual void UpdateUnit( std::string & attKey, std::string & attValue, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalGetString
	{
	  public:
		 virtual ~ISignalGetString() = default;
		 virtual void UpdateUnitSignalGetString( std::string & attKey, std::string & attVersion, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalSetReset
	{
	  public:
		 virtual ~ISignalSetReset() = default;
		 virtual void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalGetVoltage
	{
	  public:
		 virtual ~ISignalGetVoltage() = default;
		 virtual void UpdateUnitSignalGetVoltage( std::string & attKey, std::string & attGetVoltage, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalGetVersion
	{
	  public:
		 virtual ~ISignalGetVersion() = default;
		 virtual void UpdateUnitSignalGetVersion( std::string & attKey, std::string & attVersion, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalGetPressure
	{
	  public:
		 virtual ~ISignalGetPressure() = default;
		 virtual void UpdateUnitSignalGetPressure( std::string & attKey, std::string & attVersion, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalGetTemperature
	{
	  public:
		 virtual ~ISignalGetTemperature() = default;
		 virtual void UpdateUnitSignalGetTemperature( std::string & attKey, std::string & attVersion, CAdditionals & attAdditionals ) = 0;
	};

	class ISignalGetHumidity
	{
	  public:
		 virtual ~ISignalGetHumidity() = default;
		 virtual void UpdateUnitSignalGetHumidity( std::string & attKey, std::string & attVersion, CAdditionals & attAdditionals ) = 0;
	};


}

