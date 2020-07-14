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

   std::vector<std::string> 
   CSignalStrings::GetValueItems( std::string attString, 
                                  const char attSplitCharacter )
   {
      std::vector<std::string> items;

      size_t pos = 0;
      std::string token;

      while ( ( pos = attString.find( attSplitCharacter ) ) != std::string::npos) {
         items.push_back( attString.substr( 0, pos ) );
         attString.erase( 0, pos + 1 );
      }
      items.push_back( attString );

      return items;
   }    

   bool CSignalStrings::CompareTwoStringVectors( std::vector<std::string> attStr1, 
                                                 std::vector<std::string> attStr2 )    
   {
      sort( attStr1.begin(), attStr1.end() ); 
      sort( attStr2.begin(), attStr2.end() ); 
      
      if( attStr1.size() != attStr2.size() ){
         return false;
      }

      for ( unsigned int i=0; i<attStr1.size(); i++ ) 
      {
         if( 0 != attStr1[i].compare( attStr2[i] ) )
         {
            return false;
         }
      }
      
      return true;
   }


   std::string CSignalStrings::CreateStringFromVector( std::vector<std::string> attStrVector, 
                                                       const char attSplitCharacter )
   {
      std::string vectorString;
      vectorString += attStrVector[0];
      for ( unsigned int i=1; i<attStrVector.size(); i++ ) 
      {
         vectorString += attSplitCharacter;  
         vectorString += attStrVector[i];
      }
      
      return vectorString; 
   }

}

