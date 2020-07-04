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

         void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue, interface::CSystemSettings & attSystemSettings ) override final;

      private:
         interface::IUnitOutput & unitOutput;
   };

   class CUnitInput
      : public interface::ISignalGetSignals
      , public interface::ISignalSetReset
      , public interface::ISignalGetVersion
      , public interface::ISignalGetVoltage
   {
      public:
	     CUnitInput( interface::IUnitInput & attUnitInput) ;
         ~CUnitInput() = default;

         void UpdateUnitSignalGetSignals( std::string & attKey, std::string & attValue, interface::CSystemSettings & attSystemSettings ) override final;

         void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue, interface::CSystemSettings & attSystemSettings ) override final;
         void UpdateUnitSignalGetVersion( std::string & attKey, std::string & attValue, interface::CSystemSettings & attSystemSettings  ) override final;
         void UpdateUnitSignalGetVoltage( std::string & attKey, std::string & attValue, interface::CSystemSettings & attSystemSettings  ) override final;

      private:
         interface::IUnitInput & unitInput;
   };


}
