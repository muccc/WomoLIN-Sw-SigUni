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

   void CSignalGetSignals::UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attAdditionalSettings )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetSignals( attKey, attValue, attAdditionalSettings );
	   }
   }

   void CSignalSetReset::UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attAdditionalSettings )
   {

	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalSetReset( attKey, attValue, attAdditionalSettings );
	   }

  }

   void CSignalGetVersion::UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attAdditionalSettings )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetVersion( attKey, attValue, attAdditionalSettings );
	   }
  }

   void CSignalGetVoltage::UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attAdditionalSettings )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetVoltage( attKey, attValue, attAdditionalSettings );
	   }
  }



}
