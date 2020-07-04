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

   template class CSignalAddUnit<interface::ISignalGetSignals>;

   class CSignalGetSignals final
      : public CSignalAddUnit<interface::ISignalGetSignals>
      , public interface::ISignal
   {
      public:
         CSignalGetSignals() = default;
         ~CSignalGetSignals() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attSystemSettings ) override final;
   };


   template class CSignalAddUnit<interface::ISignalSetReset>;

   class CSignalSetReset final
      : public CSignalAddUnit<interface::ISignalSetReset>
      , public interface::ISignal
   {
      public:
	   	CSignalSetReset() = default;
         ~CSignalSetReset() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attSystemSettings ) override final;
   };


   template class CSignalAddUnit<interface::ISignalGetVoltage>;

   class CSignalGetVoltage final
      : public CSignalAddUnit<interface::ISignalGetVoltage>
      , public interface::ISignal
   {
      public:
         CSignalGetVoltage() = default;
         ~CSignalGetVoltage() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attSystemSettings ) override final;
   };


   template class CSignalAddUnit<interface::ISignalGetVersion>;

   class CSignalGetVersion final
      : public CSignalAddUnit<interface::ISignalGetVersion>
      , public interface::ISignal
   {
      public:
         CSignalGetVersion() = default;
         ~CSignalGetVersion() = default;
         void UpdateUnit( std::string & attKey, std::string & attValue, std::map<std::string_view, std::string> & attSystemSettings ) override final;
   };


}
