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

      void Get( std::string & attGetInput ) override final; 

      private:
         const std::map<std::string_view, interface::ISignal*> & signalMap;
   };

}
