/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "signal.h"

namespace siguni
{

   void CSignalSetReset::UpdateUnit( std::string & attKey, std::string & attValue )
   {

	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalSetReset( attKey, attValue );
	   }

  }

   void CSignalGetVersion::UpdateUnit( std::string & attKey, std::string & attValue )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetVersion( attKey, attValue );
	   }
  }

   void CSignalGetVoltage::UpdateUnit( std::string & attKey, std::string & attValue )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetVoltage( attKey, attValue );
	   }
  }



}
