/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "interface/helper.h"

#include <iostream>

namespace siguni::helper
{

   int CSignalStrings::FindFirstCharacter( const std::string & attSignalMessage, 
                                           const char attCharacter,
                                           const size_t attPos )
   {
      auto pos = attSignalMessage.find( attCharacter, attPos );
      if ( std::string::npos == pos )
      {
         return -1;
      }
      else
      {
         return pos;
      }
   }

   int CSignalStrings::FindLastCharacter( const std::string & attSignalMessage, 
                                          const char attCharacter )
   {
      int pos = -1;
      int lastPos { -1 };

      do
      {
         pos = FindFirstCharacter( attSignalMessage, attCharacter, pos+1 );
         if( pos >= 0 )
         {
            lastPos = pos;
         }
      }while( pos >= 0 );

      return lastPos;
   }

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
   CSignalStrings::GetValueItems( const std::string & /*attString*/, 
                                  const char /*attSplitCharacter*/ )
   {
      std::vector<std::string_view> items;
      return items;
   }    

}

