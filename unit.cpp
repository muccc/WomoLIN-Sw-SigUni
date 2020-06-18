/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "unit.h"

namespace siguni
{

   CUnitOutput::CUnitOutput( interface::IUnitOutput & attUnitOutput ) : unitOutput( attUnitOutput ) {}

   void CUnitInput::UpdateUnitSignalGetSignals( std::string & /*attKey*/, std::string & attValue )
   {
      unitInput.Get( attValue ); 
   }

   void CUnitOutput::UpdateUnitSignalSetReset( std::string & /*attKey*/, std::string & attValue )
   {
      unitOutput.Set( attValue ); 
   }

   CUnitInput::CUnitInput( interface::IUnitInput & attUnitInput ) : unitInput( attUnitInput ) {}

   void CUnitInput::UpdateUnitSignalSetReset( std::string & /*attKey*/, std::string & attValue )
   {
      unitInput.Get( attValue );
   }

   void CUnitInput::UpdateUnitSignalGetVersion( std::string & /*attKey*/, std::string & attValue )
   {
      unitInput.Get( attValue );
   }

   void CUnitInput::UpdateUnitSignalGetVoltage( std::string & /*attKey*/, std::string & attValue )
   {
      unitInput.Get( attValue );
   }
}
