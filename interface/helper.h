/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include <string>
#include <vector>


namespace siguni::helper
{
   class CSignalStrings
   {
   public:
      CSignalStrings() = default; 
      ~CSignalStrings() = default; 

   public: 

      static int FindFirstCharacter( const std::string & attSignalMessage, 
                                     const char attCharacter,
                                     const size_t attPos = 0 );

      static int FindLastCharacter( const std::string & attSignalMessage, 
                                    const char attCharacter );

      static bool ExtractKeyValue( const std::string & attSignalMessage, 
                                   const char attSplitCharacter,
                                   std::string & attKey,
                                   std::string & attValue );

      static std::vector<std::string> 
      GetValueItems( std::string attString, const char attSplitCharacter );    

      static bool CompareTwoStringVectors( std::vector<std::string> attStr1, std::vector<std::string> attStr2 );    

      static std::string
      CreateStringFromVector( std::vector<std::string> attStrVector, const char attSplitCharacter );

   };
}

