/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "managerbase.h"

#include <iostream>

namespace siguni
{

   CManagerBase::CManagerBase( interface::IControlbus & attControlbus ) 
      : controlbus( attControlbus )
      , protocol( controlbus )
      , halUnitInputGetSignals( signalVector )
      , halUnitInputGetSimulationStatus( signalVector )
      , halUnitOutputSetResetSimulationModus( signalVector )
      , halUnitInputGetLogging( signalVector )
   {
     
      additionals.SimulationMode = false; 

      //additionals.Settings.insert( std::pair<std::string_view, std::string>( "KEY", "VALUE" ) );

      signalVector["GetSignals"] = &GetSignals;
      GetSignals.AddUnit( &unitInputGetSignals );

      signalVector["GetSimulationStatus"] = &GetSimulationStatus;
      GetSimulationStatus.AddUnit( &unitInputGetSimulationStatus );
      
      signalVector["SetResetSimulationModus"] = &SetResetSimulationModus;
      SetResetSimulationModus.AddUnit( &unitOutputSetResetSimulationModus );

      signalVector["GetLogging"] = &GetLogging;
      GetLogging.AddUnit( &unitInputGetLogging );

   }

   void CManagerBase::ProcessSignal()
   {
      std::string key;
      std::string value;      
      std::string valueCopy;      

      if( true == protocol.GetKeyValue( key, value ) ) {
         if ( true == signalVector.count(key) ) {
            
            valueCopy = value;
            signalVector.at( key )->UpdateUnit( key, value, additionals );

            if( 0 == valueCopy.compare( "GET" ) ) {
               protocol.SendKeyValue( key, value );
            }
         }
      }
   }

   void CManagerBase::DoWork()
   {

      while( 1 )
      {
         ProcessSignal();        
      } 
   }
}
