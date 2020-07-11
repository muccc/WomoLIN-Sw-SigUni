/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "interface/additionals.h"

namespace siguni::interface
{

   void CAdditionals::WriteErrorLog( std::string attIdentifier, std::string attErrorLog ) 
   { 
      errorLog.clear();
      errorLog[attIdentifier] = attErrorLog; 
   }

   std::string CAdditionals::ReadErrorLog() 
   {

      if( errorLog.size() )
      {
         return errorLog.begin()->first + " ==> " + errorLog.begin()->second ; 
      }
      else 
      {
         return "" ; 
      }
   }

}

