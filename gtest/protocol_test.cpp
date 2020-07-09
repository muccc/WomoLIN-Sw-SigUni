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
      
      int WriteData( const std::string & attMessage ) override final;
      int ReadData( std::string & attMessage ) override final;

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
   

int CControlbusMock::WriteData( const std::string & attMessage )
{
   writtenData = attMessage;
   return writeDataReturnValue;
} 
 
int CControlbusMock::ReadData( std::string & attMessage )
{
   attMessage = readData;
   return readDataReturnValue;
} 



class CProtocolTest  : public ::testing::Test 
{ 
protected:
   CProtocolTest() 
      : controlbus( CControlbusMock() )
      , test( controlbus )
   {
   };
   virtual ~CProtocolTest() = default; 

   void SetUp()
   {
      CControlbusMock controlbus = CControlbusMock(); 
      CProtocol test = CProtocol( controlbus );
   }

   CControlbusMock controlbus;
   CProtocol test;

   std::string key;
   std::string value;

};

// start tests

TEST_F( CProtocolTest, NoDataReadErrorFromControlbus ) {

   controlbus.SetReadDataReturnValue( -1 );
	ASSERT_EQ( false , test.GetKeyValue( key, value ) );
}

TEST_F( CProtocolTest, NoDataReadZeroBytes ) {

   controlbus.SetReadDataReturnValue( 0 );
	ASSERT_EQ( false, test.GetKeyValue( key, value ) );
}

TEST_F( CProtocolTest, ReadOneValidKeyValuePair ) {

   std::string keyValuePair = "^GetSignals;GET$"; 
   controlbus.SetReadData( keyValuePair );
   controlbus.SetReadDataReturnValue( keyValuePair.size() ); 

	ASSERT_EQ( true, test.GetKeyValue( key, value ) );
	ASSERT_STREQ( key.c_str() , "GetSignals" );
	ASSERT_STREQ( value.c_str() , "GET" );
   
}

TEST_F( CProtocolTest, ReadTwoValidKeyValuePair ) {

   // data for first read process
   std::string keyValuePair = "^SetSimulationModus;RESET$^GetSignals;GET$"; 

   controlbus.SetReadData( keyValuePair );
   controlbus.SetReadDataReturnValue( keyValuePair.size() ); 

	ASSERT_EQ( true, test.GetKeyValue( key, value ) );
	ASSERT_STREQ( key.c_str() , "SetSimulationModus" );
	ASSERT_STREQ( value.c_str() , "RESET" );

   // no data for second read process
   keyValuePair = "";
   controlbus.SetReadData( keyValuePair );
   controlbus.SetReadDataReturnValue( keyValuePair.size() ); 

   // first read process must have read two key values
   // now we expect the second pair
	ASSERT_EQ( true, test.GetKeyValue( key, value ) );
	ASSERT_STREQ( key.c_str() , "GetSignals" );
	ASSERT_STREQ( value.c_str() , "GET" );
}

TEST_F( CProtocolTest, ReadValidKeyValuePairFragments ) {

   std::string fragment1 = "Garbage^";
   std::string fragment2 = "SetSimulationModus";
   std::string fragment3 = ";RESET";
   std::string fragment4 = "$Garbage^";
   std::string fragment5 = "GetSignals;GET$"; 

   controlbus.SetReadData( fragment1 );
   controlbus.SetReadDataReturnValue( fragment1.size() ); 

	ASSERT_EQ( false, test.GetKeyValue( key, value ) );

   controlbus.SetReadData( fragment2 );
   controlbus.SetReadDataReturnValue( fragment2.size() ); 

	ASSERT_EQ( false, test.GetKeyValue( key, value ) );

   controlbus.SetReadData( fragment3 );
   controlbus.SetReadDataReturnValue( fragment3.size() ); 

	ASSERT_EQ( false, test.GetKeyValue( key, value ) );

   controlbus.SetReadData( fragment4 );
   controlbus.SetReadDataReturnValue( fragment4.size() ); 

	ASSERT_EQ( true, test.GetKeyValue( key, value ) );
	ASSERT_STREQ( key.c_str() , "SetSimulationModus" );
	ASSERT_STREQ( value.c_str() , "RESET" );

   controlbus.SetReadData( fragment5 );
   controlbus.SetReadDataReturnValue( fragment5.size() ); 

	ASSERT_EQ( true, test.GetKeyValue( key, value ) );
	ASSERT_STREQ( key.c_str() , "GetSignals" );
	ASSERT_STREQ( value.c_str() , "GET" );
}


TEST_F( CProtocolTest, SendKeyValue ) {

   key = "GetSimulationStatus";
   value = "RESET";

   test.SendKeyValue( key, value );
   auto sendMessage = controlbus.GetWrittenData();
	ASSERT_STREQ( sendMessage.c_str(), "^GetSimulationStatus;RESET$\n" );
}


}
