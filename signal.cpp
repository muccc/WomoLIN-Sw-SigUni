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

   void CSignalGetString::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetString( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalSetReset::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalSetReset( attKey, attValue, attAdditionals );
	   }

   }

   void CSignalGetVersion::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetVersion( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetVoltage::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetVoltage( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetPressure::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetPressure( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetTemperature::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetTemperature( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetHumidity::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetHumidity( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetMagnetic::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetMagnetic( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetAcceleration::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetAcceleration( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetCurrent::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetCurrent( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetBatteryCapacity::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetBatteryCapacity( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetBatteryCharge::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetBatteryCharge( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetBatteryHealth::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ){
		   unit->UpdateUnitSignalGetBatteryHealth( attKey, attValue, attAdditionals );
	   }
   }

   void CSignalGetVictronInfo::UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
	   for( const auto & unit : units ) {
		   unit->UpdateUnitSignalGetVictronInfo( attKey, attValue, attAdditionals );
	   }
	}
}
