/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "hal.h"

namespace siguni
{

   CHalUnitInputGetSignals::CHalUnitInputGetSignals( const std::map<std::string_view, interface::ISignal*> & attSignalMap )
      : signalMap( attSignalMap )
   {

   } 

   void CHalUnitInputGetSignals::Get( std::string & attGetInput )
   {
      attGetInput.clear();
      for(const auto & [key, ignored]  : signalMap ){
         attGetInput.append( key ); 
         attGetInput.append( "," ); 
      }
   }

}
