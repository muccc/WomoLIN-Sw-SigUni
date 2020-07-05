/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "unit.h"

namespace siguni
{

   CUnitOutput::CUnitOutput( interface::IUnitOutput & attUnitOutput ) : unitOutput( attUnitOutput ) {}

   void CUnitInput::UpdateUnitSignalGetString( std::string & /*attKey*/, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals ); 
   }

   void CUnitOutput::UpdateUnitSignalSetReset( std::string & /*attKey*/, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitOutput.Set( attValue, attAdditionals ); 
   }

   CUnitInput::CUnitInput( interface::IUnitInput & attUnitInput ) : unitInput( attUnitInput ) {}

   void CUnitInput::UpdateUnitSignalSetReset( std::string & /*attKey*/, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetVersion( std::string & /*attKey*/, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetVoltage( std::string & /*attKey*/, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }
}
