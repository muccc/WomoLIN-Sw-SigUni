/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface/isignal.h"
#include "protocol.h"

#include <map>

namespace siguni
{

   class CManagerBase
   {
      public:
         CManagerBase( interface::IControlbus & attControlbus );
         ~CManagerBase() = default;

         void DoWork();

      protected:
         std::string                                         message;
         std::map<std::string_view, interface::ISignal*>     signalVector;

      private:
         interface::IControlbus &            controlbus;
         CProtocol                           protocol;

   };
}
