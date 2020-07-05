/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "unit.h"
#include "hal.h"
#include "signal.h"
#include "protocol.h"

#include <map>

namespace siguni
{

   class CManagerBase
   {
      public:
         CManagerBase( interface::IControlbus & attControlbus );
         ~CManagerBase() = default;

         void DoWork();

      protected:
         interface::CAdditionals                              additionals; 
         std::string                                         message;
         std::map<std::string_view, interface::ISignal*>     signalVector;
         
      private:
         interface::IControlbus &                  controlbus;
         CProtocol                                 protocol;

         // units
         CHalUnitInputGetSignals                   halUnitInputGetSignals;   
         CUnitInput                                unitInputGetSignals{ halUnitInputGetSignals } ; 

         CHalUnitInputGetSimulationStatus          halUnitInputGetSimulationStatus;   
         CUnitInput                                unitInputGetSimulationStatus{ halUnitInputGetSimulationStatus } ; 

         CHalUnitOutputSetResetSimulationModus     halUnitOutputSetResetSimulationModus;   
         CUnitOutput                               unitOutputSetResetSimulationModus{ halUnitOutputSetResetSimulationModus } ; 


         // signals 
         CSignalGetSignals                         GetSignals { CSignalGetSignals() };
         CSignalSetReset                           GetSimulationStatus { CSignalSetReset() };

         CSignalSetReset                           SetResetSimulationModus{ CSignalSetReset() };

   };
}
