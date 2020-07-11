/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../managerbase.h"
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
   std::string message = "^GetSignals;GET$";

   test.ControlbusMock.SetReadData( message );

   test.ProcessSignal();

   auto returnMessage = test.ControlbusMock.GetWrittenData();
   // delete start and endbytes 
   returnMessage = returnMessage.substr( 1, returnMessage.size() - 3 );
   // split into key and value 
   auto splitPos = returnMessage.find( ";" );
   auto key = returnMessage.substr( 0, splitPos );
   auto val = returnMessage.substr( splitPos + 1 );
   
	ASSERT_STREQ( key.c_str() , "GetSignals" );

   std::vector<std::string> valueItems;

/*
   do 
   {
      splitPos = val.find(",")
      if()

   } while()
*/
}



}
