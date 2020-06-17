/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include <string>

namespace siguni::interface
{
   class IControlbus
   {
      public:
         virtual ~IControlbus() = default;

         virtual int WriteData( const std::string & attMessage ) = 0;
         virtual int ReadData( std::string & attMessage ) = 0;
   };
}
