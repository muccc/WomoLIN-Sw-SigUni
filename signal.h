/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2019 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#pragma once

#include "interface/isignal.h"
#include <vector>

namespace siguni
{

   template<class T>
   class CSignalAddUnit
   {
      public:
	   	CSignalAddUnit() = default;
	      ~CSignalAddUnit() = default;

	      void AddUnit(T* unit);

      protected:
	      std::vector<T*> units;
   };

   template class CSignalAddUnit<interface::ISignalGetString>;

   class CSignalGetString final
      : public CSignalAddUnit<interface::ISignalGetString>
      , public interface::ISignal
   {
      public:
         CSignalGetString() = default;
         ~CSignalGetString() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };


   template class CSignalAddUnit<interface::ISignalSetReset>;

   class CSignalSetReset final
      : public CSignalAddUnit<interface::ISignalSetReset>
      , public interface::ISignal
   {
      public:
	   	CSignalSetReset() = default;
         ~CSignalSetReset() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };


   template class CSignalAddUnit<interface::ISignalGetVoltage>;

   class CSignalGetVoltage final
      : public CSignalAddUnit<interface::ISignalGetVoltage>
      , public interface::ISignal
   {
      public:
         CSignalGetVoltage() = default;
         ~CSignalGetVoltage() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };


   template class CSignalAddUnit<interface::ISignalGetVersion>;

   class CSignalGetVersion final
      : public CSignalAddUnit<interface::ISignalGetVersion>
      , public interface::ISignal
   {
      public:
         CSignalGetVersion() = default;
         ~CSignalGetVersion() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetPressure>;

   class CSignalGetPressure final
      : public CSignalAddUnit<interface::ISignalGetPressure>
      , public interface::ISignal
   {
      public:
         CSignalGetPressure() = default;
         ~CSignalGetPressure() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetTemperature>;

   class CSignalGetTemperature final
      : public CSignalAddUnit<interface::ISignalGetTemperature>
      , public interface::ISignal
   {
      public:
         CSignalGetTemperature() = default;
         ~CSignalGetTemperature() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetHumidity>;

   class CSignalGetHumidity final
      : public CSignalAddUnit<interface::ISignalGetHumidity>
      , public interface::ISignal
   {
      public:
         CSignalGetHumidity() = default;
         ~CSignalGetHumidity() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetMagnetic>;

   class CSignalGetMagnetic final
      : public CSignalAddUnit<interface::ISignalGetMagnetic>
      , public interface::ISignal
   {
      public:
         CSignalGetMagnetic() = default;
         ~CSignalGetMagnetic() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetAcceleration>;

   class CSignalGetAcceleration final
      : public CSignalAddUnit<interface::ISignalGetAcceleration>
      , public interface::ISignal
   {
      public:
         CSignalGetAcceleration() = default;
         ~CSignalGetAcceleration() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetCurrent>;

   class CSignalGetCurrent final
      : public CSignalAddUnit<interface::ISignalGetCurrent>
      , public interface::ISignal
   {
      public:
         CSignalGetCurrent() = default;
         ~CSignalGetCurrent() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetBatteryCapacity>;

   class CSignalGetBatteryCapacity final
      : public CSignalAddUnit<interface::ISignalGetBatteryCapacity>
      , public interface::ISignal
   {
      public:
         CSignalGetBatteryCapacity() = default;
         ~CSignalGetBatteryCapacity() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetBatteryCharge>;

   class CSignalGetBatteryCharge final
      : public CSignalAddUnit<interface::ISignalGetBatteryCharge>
      , public interface::ISignal
   {
      public:
         CSignalGetBatteryCharge() = default;
         ~CSignalGetBatteryCharge() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetBatteryHealth>;

   class CSignalGetBatteryHealth final
      : public CSignalAddUnit<interface::ISignalGetBatteryHealth>
      , public interface::ISignal
   {
      public:
         CSignalGetBatteryHealth() = default;
         ~CSignalGetBatteryHealth() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
   };

   template class CSignalAddUnit<interface::ISignalGetVictronInfo>;

	class CSignalGetVictronInfo final
	 : public CSignalAddUnit<interface::ISignalGetVictronInfo>
	 , public interface::ISignal
	{
	 public:
		CSignalGetVictronInfo() = default;
		~CSignalGetVictronInfo() = default;
		void UpdateUnit( std::string & attKey, std::string & attValue, interface::CAdditionals & attAdditionals ) override final;
	};

}
