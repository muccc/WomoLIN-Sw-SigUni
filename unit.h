/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface/isignal.h"
#include "interface/iunit.h"

namespace siguni
{

   class CUnitOutput
   	   : public interface::ISignalSetReset
   {
      public:
	     CUnitOutput( interface::IUnitOutput & attUnitOutput) ;
         ~CUnitOutput() = default;

         void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;

      private:
         interface::IUnitOutput & unitOutput;
   };

   class CUnitInput
      : public interface::ISignalGetString
      , public interface::ISignalSetReset
      , public interface::ISignalGetVersion
      , public interface::ISignalGetVoltage
      , public interface::ISignalGetPressure
      , public interface::ISignalGetTemperature
      , public interface::ISignalGetHumidity
      , public interface::ISignalGetMagnetic
      , public interface::ISignalGetAcceleration
      , public interface::ISignalGetCurrent
      , public interface::ISignalGetBatteryCapacity
      , public interface::ISignalGetBatteryCharge
      , public interface::ISignalGetBatteryHealth
   {
      public:
	     CUnitInput( interface::IUnitInput & attUnitInput) ;
         ~CUnitInput() = default;

         void UpdateUnitSignalGetString( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;

         void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
         void UpdateUnitSignalGetVersion( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetVoltage( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;

         void UpdateUnitSignalGetPressure( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetTemperature( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetHumidity( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;

         void UpdateUnitSignalGetMagnetic( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetAcceleration( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;

         void UpdateUnitSignalGetCurrent( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetBatteryCapacity( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetBatteryCharge( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;
         void UpdateUnitSignalGetBatteryHealth( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals  ) override final;

      private:
         interface::IUnitInput & unitInput;
   };


}
