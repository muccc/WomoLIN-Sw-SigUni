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
   }

   std::string key;
   std::string value;

};

// start tests

TEST_F( CManagerbaseTest, GetSignals ) {

   auto test = CManager();

   // simulate received message for the manager
   std::string receivedMessage = "^GetSignals;GET$";
   test.ControlbusMock.SetReadData( receivedMessage );
   
   // call a single process step from manager
   // the manager has to process the received message
   // and send the response via the contolbus
   test.ProcessSignal();

   // readout the send message from the controlbus mock
   auto returnMessage = test.ControlbusMock.GetWrittenData();

   // delete start and endbytes from the response message 
   returnMessage = returnMessage.substr( 1, returnMessage.size() - 3 );

   std::string key;
   std::string value;

	ASSERT_EQ( true, helper::CSignalStrings::ExtractKeyValue( returnMessage, ';', key, value ) );
 
  
   // the reponse key must be equal to the request key 
	ASSERT_STREQ( key.c_str() , "GetSignals" );

   std::vector<std::string> expectedValueItems = 
   { "GetLogging", "GetSignals", "GetSimulationStatus", "SetResetSimulationModus" };

   auto valueItems = helper::CSignalStrings::GetValueItems( value, ',' );

	ASSERT_EQ( true, helper::CSignalStrings::CompareTwoStringVectors( expectedValueItems, valueItems ) ) << \
      value << "\n" << \
      helper::CSignalStrings::CreateStringFromVector( expectedValueItems, ',' ); 

}



}
