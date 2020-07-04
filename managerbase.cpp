/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "managerbase.h"

#include <iostream>

namespace siguni
{

   CManagerBase::CManagerBase( interface::IControlbus & attControlbus ) 
      : systemSettings( interface::CSystemSettings() ) 
      , controlbus( attControlbus )
      , protocol( controlbus )
      , halUnitInputGetSignals( signalVector )
      , halUnitInputGetSimulationStatus( signalVector )
      , halUnitOutputSetResetSimulationModus( signalVector )
   {

      signalVector["GetSignals"] = &GetSignals;
      GetSignals.AddUnit( &unitInputGetSignals );

      signalVector["GetSimulationStatus"] = &GetSimulationStatus;
      GetSimulationStatus.AddUnit( &unitInputGetSimulationStatus );
      
      signalVector["SetResetSimulationModus"] = &SetResetSimulationModus;
      SetResetSimulationModus.AddUnit( &unitOutputSetResetSimulationModus );

   }

   void CManagerBase::DoWork()
   {

      std::string key;
      std::string value;      
      std::string valueCopy;      

      while( 1 )
      {
         if( true == protocol.GetKeyValue( key, value ) ) {
            if ( true == signalVector.count(key) ) {

               valueCopy = value;
               signalVector.at(key)->UpdateUnit( key, value, systemSettings );

               if( 0 == valueCopy.compare( "GET" ) ) {
                  protocol.SendKeyValue( key, value );
               }
            }
         }
      } 
   }
}
