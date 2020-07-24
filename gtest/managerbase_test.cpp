/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../managerbase.h"
#include "../interface/helper.h"
#include "mocks.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{

class CManager : public CManagerBase
{
   public:
      CManager() : CManagerBase( ControlbusMock ) 
                 , ControlbusMock( CControlbusMock() ) {}

      ~CManager() = default;

   public:
       CControlbusMock   ControlbusMock; 
};


class CManagerbaseTest  : public ::testing::Test 
{ 
protected:
   CManagerbaseTest()
   {
   };
   virtual ~CManagerbaseTest() = default; 

   void SetUp()
   {
     CManager test = CManager();
   }

   CManager test;

   std::string key;
   std::string value;

};

// *********************************************
// Common helper functions
// *********************************************

std::string SendMessageAndReceiveResponse( CManager & manager, std::string message)
{

   // simulate received message for the manager
   manager.ControlbusMock.SetReadData( message );
   
   // call a single process step from manager
   // the manager has to process the received message
   // and send the response via the contolbus
   manager.ProcessSignal();

   // readout the send message from the controlbus mock
   auto returnMessage = manager.ControlbusMock.GetWrittenData();

   // delete start and endbytes from the response message 
   return returnMessage.substr( 1, returnMessage.size() - 3 );

}

// *********************************************
// Get Signals 
// *********************************************

TEST_F( CManagerbaseTest, GetSignals ) {

   auto returnMessage = SendMessageAndReceiveResponse( test, "^GetSignals;GET$" );

	ASSERT_EQ( true, helper::CSignalStrings::SplitKeyValue( returnMessage, ';', key, value ) );
 
	ASSERT_STREQ( key.c_str() , "GetSignals" );

   std::vector<std::string> expectedValueItems = 
   { "GetLogging", "GetSignals", "GetSimulationStatus", "SetResetSimulationModus" };

   auto valueItems = helper::CSignalStrings::GetValueItems( value, ',' );

	ASSERT_EQ( true, helper::CSignalStrings::CompareTwoStringVectors( expectedValueItems, valueItems ) ) << \
      value << "\n" << \
      helper::CSignalStrings::CreateStringFromVector( expectedValueItems, ',' ); 

}

// ******************************************************************************************
// Simulation Modus
//
// *1 set/reset output command does not send a response, the serial mock have the old values
// ******************************************************************************************

void AssertResult( std::string returnMessage, 
                   std::string key, std::string key_expected, 
                   std::string value, std::string value_expected )
{

	ASSERT_EQ( true, helper::CSignalStrings::SplitKeyValue( returnMessage, ';', key, value ) );

	ASSERT_STREQ( key.c_str() , key_expected.c_str() );
	ASSERT_STREQ( value.c_str() , value_expected.c_str() );

}

TEST_F( CManagerbaseTest, SimulationModus ) {

   // *********************************************
   // get the current state of the simulation modus
   // *********************************************
   auto returnMessage = SendMessageAndReceiveResponse( test, "^GetSimulationStatus;GET$" );

   AssertResult( returnMessage, key, "GetSimulationStatus", value, "RESET" );

   // *********************************************
   // change from RESET to RESET 
   // *********************************************
   returnMessage = SendMessageAndReceiveResponse( test, "^SetResetSimulationModus;RESET$" );

   // see *1 
   AssertResult( returnMessage, key, "GetSimulationStatus", value, "RESET" );

   returnMessage = SendMessageAndReceiveResponse( test, "^GetSimulationStatus;GET$" );

   AssertResult( returnMessage, key, "GetSimulationStatus", value, "RESET" );

   // *********************************************
   // change from RESET to SET 
   // *********************************************
 
   returnMessage = SendMessageAndReceiveResponse( test, "^SetResetSimulationModus;SET$" );

   // see *1 
   AssertResult( returnMessage, key, "GetSimulationStatus", value, "RESET" );

   returnMessage = SendMessageAndReceiveResponse( test, "^GetSimulationStatus;GET$" );

   AssertResult( returnMessage, key, "GetSimulationStatus", value, "SET" );

   // *********************************************
   // change from SET to SET 
   // *********************************************
 
   returnMessage = SendMessageAndReceiveResponse( test, "^SetResetSimulationModus;SET$" );

   // see *1 
   AssertResult( returnMessage, key, "GetSimulationStatus", value, "SET" );

   returnMessage = SendMessageAndReceiveResponse( test, "^GetSimulationStatus;GET$" );

   AssertResult( returnMessage, key, "GetSimulationStatus", value, "SET" );

   // *********************************************
   // change from SET to RESET 
   // *********************************************
 
   returnMessage = SendMessageAndReceiveResponse( test, "^SetResetSimulationModus;RESET$" );

   // see *1 
   AssertResult( returnMessage, key, "GetSimulationStatus", value, "SET" );

   returnMessage = SendMessageAndReceiveResponse( test, "^GetSimulationStatus;GET$" );

   AssertResult( returnMessage, key, "GetSimulationStatus", value, "RESET" );

}

TEST_F( CManagerbaseTest, Logging ) {
   // TODO

}



}
