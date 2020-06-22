/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface/ihw.h"

namespace siguni
{

   class CProtocol final
   {
      public:
         CProtocol( interface::IControlbus & attControlbus );
         ~CProtocol() = default;

         bool GetKeyValue( std::string & attKey, std::string & attValue);
         void SendKeyValue( std::string & attKey, std::string & attValue);

      private:
         interface::IControlbus &   controlbus;
         std::string                messageBuffer;


      private:

         static constexpr char STARTBYTE { '^' };
         static constexpr char SEPARATOR { ';' };
         static constexpr char ENDBYTE   { '$' };
         static constexpr char LINEBREAK { '\n' };
   };
}

