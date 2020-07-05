/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface/isignal.h"
#include "interface/iunit.h"

namespace siguni
{

   class CHalUnitInputGetSignals : public interface::IUnitInput
   {
      public:
         CHalUnitInputGetSignals( const std::map<std::string_view, interface::ISignal*> & attSignalMap );
         ~CHalUnitInputGetSignals() = default;

      void Get( std::string & attGetInput, interface::CAdditionals & attAdditionals ) override final; 

      private:
         const std::map<std::string_view, interface::ISignal*> & signalMap;
   };

   class CHalUnitInputGetSimulationStatus: public interface::IUnitInput
   {
      public:
         CHalUnitInputGetSimulationStatus( const std::map<std::string_view, interface::ISignal*> & attSignalMap );
         ~CHalUnitInputGetSimulationStatus() = default;

      void Get( std::string & attGetInput, interface::CAdditionals & attAdditionals ) override final; 

      private:
         const std::map<std::string_view, interface::ISignal*> & signalMap;
   };

   class CHalUnitOutputSetResetSimulationModus : public interface::IUnitOutput
   {
      public:
         CHalUnitOutputSetResetSimulationModus( const std::map<std::string_view, interface::ISignal*> & attSignalMap );
         ~CHalUnitOutputSetResetSimulationModus() = default;

         void Set( std::string & attSetOutput, interface::CAdditionals & attAdditionals ) override final;

      private:
         const std::map<std::string_view, interface::ISignal*> & signalMap;
   };


}
