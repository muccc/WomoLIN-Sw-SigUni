/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "signal.h"

namespace siguni
{


   template<class T>
   void CSignalAddUnit<T>::AddUnit( T* unit )
   {
	   units.push_back(unit);
   }


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

   void CSignalGetSignals::UpdateUnit( std::string & attKey, std::string & attValue )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetSignals( attKey, attValue );
	   }
  }



}
