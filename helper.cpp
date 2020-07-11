/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "interface/helper.h"

namespace siguni::helper
{

   bool CSignalStrings::ExtractKeyValue( const std::string & attSignalMessage, 
                                         const char attSplitCharacter,
                                         std::string & attKey,
                                         std::string & attValue )
   {

      auto pos = attSignalMessage.find( attSplitCharacter );
      if ( std::string::npos == pos ) {
         return false;
      }

      // extract key and value 
      attKey = attSignalMessage.substr( 0, pos );
      attValue = attSignalMessage.substr( pos + 1 );

      return true;
   }

   std::vector<std::string_view> 
   CSignalStrings::GetValueItems( const std::string & attString, 
                                  const char attSplitCharacter )
   {
      std::vector<std::string_view> items;
      return items;
   }    

}

