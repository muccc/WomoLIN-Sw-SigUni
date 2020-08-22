/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "hal.h"
#include "interface/helper.h"

namespace siguni
{

   // Get Signals
   CHalUnitInputGetSignals::CHalUnitInputGetSignals ( 
      const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetSignals::Get( std::string & attGetInput, 
                                      interface::CAdditionals & /*attAdditionals*/ )
   {

      if( 0 == attGetInput.compare("GET") )
      {
         attGetInput =  std::to_string( signalMap.size() );
         return; 
      }

      // we expect the format "GET,indexvalue", indexvalue > 0
      auto valueItems = helper::CSignalStrings::GetValueItems( attGetInput, ',');

      if( 2 != valueItems.size() ) 
      {
         attGetInput = "invalid value";
         return;
      }

      if( 0 != valueItems.at(0).compare("GET") )    
      {
         attGetInput = "invalid value";
         return;
      }
 
      auto index = std::atoi( valueItems.at(1).c_str()); 

      if( index == 0)
      {
         attGetInput = "can't convert index";
         return; 
      }

      if( index > static_cast<int>(signalMap.size()) )
      {
         attGetInput = "index out of range";
         return; 
      }
      
      auto count = 1;
      for(const auto & [key, ignored]  : signalMap ){
         if( count == index )
         {
            attGetInput =  key; 
            break;
         } 
         count++;
      }

   }
   
   // Get Simulation Status 
   CHalUnitInputGetSimulationStatus::CHalUnitInputGetSimulationStatus( 
      const std::map<std::string_view, interface::ISignal*> & attSignalMap )
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
   CHalUnitInputGetLogging::CHalUnitInputGetLogging( 
      const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetLogging::Get( 
      std::string & attGetInput, interface::CAdditionals & attAdditionals )
   {
      attGetInput = attAdditionals.ReadErrorLog();
   }
 

}
