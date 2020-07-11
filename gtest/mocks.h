/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../protocol.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{

class CControlbusMock : public siguni::interface::IControlbus
{
   public: 
      CControlbusMock() = default;
      ~CControlbusMock() = default;
      
      int WriteData( const std::string & attMessage ) override final
      {
         writtenData = attMessage;
         return writeDataReturnValue;

      };

      int ReadData( std::string & attMessage ) override final
      {
         attMessage = readData;
         return readDataReturnValue;
      };

      void SetReadData( const std::string & attReadData ) 
      { 
         readData = attReadData; 
      };

      void SetReadDataReturnValue( int attReadDataReturnValue ) 
      { 
         readDataReturnValue = attReadDataReturnValue;  
      }; 

      std::string GetWrittenData() 
      { 
         return writtenData; 
      };

      void SetWriteDataReturnValue( int attWriteDataReturnValue ) 
      { 
         writeDataReturnValue = attWriteDataReturnValue;  
      }; 

   private:
      std::string writtenData = "";
      int readDataReturnValue = 0;
      std::string readData = "";
      int writeDataReturnValue = 0;
};
   


}
