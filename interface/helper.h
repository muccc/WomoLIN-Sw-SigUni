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

      static bool ExtractKeyValue( const std::string & attSignalMessage, 
                            const char attSplitCharacter,
                            std::string & attKey,
                            std::string & attValue );

      static std::vector<std::string_view> 
      GetValueItems( const std::string & attString, const char attSplitCharacter );    

   };
}

