/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "unit.h"

namespace siguni
{

   CUnitOutput::CUnitOutput( interface::IUnitOutput & attUnitOutput ) : unitOutput( attUnitOutput ) {}

   void CUnitInput::UpdateUnitSignalGetString( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals ); 
   }

   void CUnitOutput::UpdateUnitSignalSetReset( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitOutput.Set( attValue, attAdditionals ); 
   }

   CUnitInput::CUnitInput( interface::IUnitInput & attUnitInput ) : unitInput( attUnitInput ) {}

   void CUnitInput::UpdateUnitSignalSetReset( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetVersion( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetVoltage( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetPressure( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetTemperature( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetHumidity( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }

   void CUnitInput::UpdateUnitSignalGetMagnetic( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }


   void CUnitInput::UpdateUnitSignalGetAcceleration( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }


   void CUnitInput::UpdateUnitSignalGetCurrent( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }


   void CUnitInput::UpdateUnitSignalGetBatteryCapacity( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }


   void CUnitInput::UpdateUnitSignalGetBatteryCharge( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }


   void CUnitInput::UpdateUnitSignalGetBatteryHealth( [[maybe_unused]] std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals )
   {
      unitInput.Get( attValue, attAdditionals );
   }


}
