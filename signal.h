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


   template<class T>
   void CSignalAddUnit<T>::AddUnit( T* unit )
   {
	   units.push_back(unit);
   }


   class CSignalSetReset final
      : public CSignalAddUnit<interface::ISignalSetReset>
      , public interface::ISignal
   {
      public:
	   	CSignalSetReset() = default;
         ~CSignalSetReset() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue ) override final;
   };

   class CSignalGetVoltage final
      : public CSignalAddUnit<interface::ISignalGetVoltage>
      , public interface::ISignal
   {
      public:
         CSignalGetVoltage() = default;
         ~CSignalGetVoltage() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue ) override final;
   };


   class CSignalGetVersion final
      : public CSignalAddUnit<interface::ISignalGetVersion>
      , public interface::ISignal
   {
      public:
         CSignalGetVersion() = default;
         ~CSignalGetVersion() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue ) override final;
   };


}
