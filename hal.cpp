/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "hal.h"

namespace siguni
{

   // Get Signals
   CHalUnitInputGetSignals::CHalUnitInputGetSignals ( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetSignals::Get( std::string & attGetInput, 
                                      interface::CAdditionals & /*attAdditionals*/ )
   {
      attGetInput.clear();
      for(const auto & [key, ignored]  : signalMap ){
         attGetInput.append( key ); 
         attGetInput.append( "," ); 
      }
      attGetInput.pop_back(); // delete last character ","
   }
   
   // Get Simulation Status 
   CHalUnitInputGetSimulationStatus::CHalUnitInputGetSimulationStatus( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetSimulationStatus::Get( std::string & attGetInput, interface::CAdditionals & attAdditionals ) 
   {
      if( attAdditionals.SimulationMode ) {
         attGetInput = "SET"; 
      }
      else {
         attGetInput = "RESET"; 
      }
   } 

   // Set Simulation Modus
   CHalUnitOutputSetResetSimulationModus::CHalUnitOutputSetResetSimulationModus( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 


   void CHalUnitOutputSetResetSimulationModus::Set( std::string & attSetOutput, interface::CAdditionals & attAdditionals  ) 
   {
      if ( attSetOutput.compare("SET") == 0 ) {
         attAdditionals.SimulationMode = true;
      }
      else if ( attSetOutput.compare("RESET") == 0 ) {
         attAdditionals.SimulationMode = false;
      }
      else {
         attAdditionals.WriteErrorLog( 
            "CHalUnitOutputSetResetSimulationModus::Set",  
            "unknown attSetOutput: " + attSetOutput );
      }
   } 

   // Get Logging 
   CHalUnitInputGetLogging::CHalUnitInputGetLogging( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetLogging::Get( std::string & attGetInput, interface::CAdditionals & attAdditionals )
   {
      attGetInput = attAdditionals.ReadErrorLog();
   }
 

}
