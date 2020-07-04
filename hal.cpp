/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "hal.h"

namespace siguni
{

   // Get Signals
   CHalUnitInputGetSignals::CHalUnitInputGetSignals( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetSignals::Get( std::string & attGetInput, interface::CSystemSettings & attSystemSettings )
   {
      attGetInput.clear();
      for(const auto & [key, ignored]  : signalMap ){
         attGetInput.append( key ); 
         attGetInput.append( "," ); 
      }
   }
   
   // Get Simulation Status 
   CHalUnitInputGetSimulationStatus::CHalUnitInputGetSimulationStatus( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetSimulationStatus::Get( std::string & attGetInput, interface::CSystemSettings & attSystemSettings ) 
   {
      attGetInput = "UNKNOWN";
   } 

   // Set Simulation Modus
   CHalUnitOutputSetResetSimulationModus::CHalUnitOutputSetResetSimulationModus( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 


   void CHalUnitOutputSetResetSimulationModus::Set( std::string & /*attSetOutput*/, interface::CSystemSettings & /*attSystemSettings*/  ) 
   {

   } 

}
