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

   void CHalUnitInputGetSignals::Get( std::string & attGetInput, std::map<std::string_view, std::string> & /*attAdditionalSettings*/ )
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

   void CHalUnitInputGetSimulationStatus::Get( std::string & attGetInput, std::map<std::string_view, std::string> & attAdditionalSettings ) 
   {
      attGetInput = attAdditionalSettings["SIMULATION_STATUS"];
   } 

   // Set Simulation Modus
   CHalUnitOutputSetResetSimulationModus::CHalUnitOutputSetResetSimulationModus( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 


   void CHalUnitOutputSetResetSimulationModus::Set( std::string & attSetOutput, std::map<std::string_view, std::string> & attAdditionalSettings  ) 
   {
      attAdditionalSettings["SIMULATION_STATUS"] = attSetOutput;
   } 

}
