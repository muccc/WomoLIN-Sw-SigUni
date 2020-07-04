/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "isignal.h"

namespace siguni::interface
{

   class IUnitOutput
   {
      public:
         virtual ~IUnitOutput() = default;

         virtual void Set( std::string & attSetOutput, CSystemSettings & attSystemSettings ) = 0;
   };

   class IUnitInput
   {
      public:
         virtual ~IUnitInput() = default;

         virtual void Get( std::string & attGetOuput , CSystemSettings & attSystemSettings ) = 0;
   };
}
