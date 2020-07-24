/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../hal.h"
#include "../signal.h"

#include <gtest/gtest.h>

#include <sstream>

namespace siguni::gtest
{

class CHalTest  : public ::testing::Test 
{ 
protected:

   CHalTest() 
      : additionals( interface::CAdditionals() ) 
      , signal( CSignalGetString() )
   {
   }

   void SetUp()
   {
      std::map<std::string_view, interface::ISignal*> signalmap;
   }

   std::map<std::string_view, interface::ISignal*> signalmap;
   interface::CAdditionals                         additionals;
   CSignalGetString                                signal;

   std::string inputResult {};
};


TEST_F( CHalTest, CHalUnitInputGetSignals ) {
   
   // empty list
   auto test = CHalUnitInputGetSignals( signalmap );
   test.Get( inputResult, additionals ); // readout signal list
	ASSERT_STREQ( inputResult.c_str() , "" ) << "no signals added, result list must be empty" ;

   // one signal
   signalmap["TEST"] = &signal; // add a signal called TEST, reference to signal
   test.Get( inputResult, additionals ); // readout signal list
	ASSERT_STREQ( inputResult.c_str() , "TEST" ) << "result list must contains one signal called TEST" ;

   // two signals
   signalmap["TEST1"] = &signal; // add a signal called TEST, reference to signal
   test.Get( inputResult, additionals ); // readout signal list
	ASSERT_STREQ( inputResult.c_str() , "TEST,TEST1" ) << "result list must contains two signals called TEST and TEST1" ;
}

TEST_F( CHalTest, CHalUnitInputGetSimulationsStatus ) {
   
   auto test = CHalUnitInputGetSimulationStatus( signalmap );

   // default setting for simulation 
   test.Get( inputResult, additionals ); // readout simulation status 
	ASSERT_STREQ( inputResult.c_str() , "RESET" ) << "initialized value must be RESET" ;

   // change to 
   additionals.SimulationMode = true;
   test.Get( inputResult, additionals ); // readout simulation status 
	ASSERT_STREQ( inputResult.c_str() , "SET" ) << "simulationActiv is true, result must be SET" ;

}

TEST_F( CHalTest, CHalUnitOutputSetResetSimulationModus ) {
   
   std::string setResetCommand;
   
   auto test = CHalUnitOutputSetResetSimulationModus( signalmap );

   // begin test
   // set
   setResetCommand = "SET";
   test.Set( setResetCommand, additionals );
   ASSERT_EQ( additionals.SimulationMode, true ) << "SET must set additionals.SimulationMode to true";   

   // invalid command, state must be previous value 
   // error logging must executed 
   setResetCommand = "NOT_SET_OR_RESET";
   test.Set( setResetCommand, additionals );
   ASSERT_EQ( additionals.SimulationMode, true ) << "invalid command => previous command was SET";   
	ASSERT_STREQ( additionals.ReadErrorLog().c_str() , 
                 "CHalUnitOutputSetResetSimulationModus::Set ==> unknown attSetOutput: NOT_SET_OR_RESET" );

   // reset
   setResetCommand = "RESET";
   test.Set( setResetCommand, additionals );
   ASSERT_EQ( additionals.SimulationMode, false ) << "RESET must set additionals.SimulationMode to false";   

   // invalid command, state must be previous value 
   // error logging must executed 
   setResetCommand = "INVALID_SET_RESET";
   test.Set( setResetCommand, additionals );
   ASSERT_EQ( additionals.SimulationMode, false ) << "invalid command ==> previous command was RESET";   
	ASSERT_STREQ( additionals.ReadErrorLog().c_str() , 
                 "CHalUnitOutputSetResetSimulationModus::Set ==> unknown attSetOutput: INVALID_SET_RESET" );
}

TEST_F( CHalTest, CHalUnitInputGetLogging ) {
   
   auto test = CHalUnitInputGetLogging( signalmap );
   
   // we haven't make a log 
   test.Get( inputResult, additionals ); // readout logging 
	ASSERT_STREQ( inputResult.c_str() , "" ) << "no logging executed, log string must be empty";

   // now, we make a log
   std::string functionName = __FUNCTION__ ;
   std::stringstream ss;
   ss << __LINE__ ;
   std::string functionLine = ss.str() ;

   std::string logMessageIdentifier = functionName + ":" + functionLine ;
   std::string logMessage = "NO_ERROR";
   std::string logEntry = logMessageIdentifier + " ==> " + logMessage ;

   additionals.WriteErrorLog( logMessageIdentifier, logMessage );
   test.Get( inputResult, additionals ); // readout logging 

	ASSERT_STREQ( inputResult.c_str() , logEntry.c_str() ) << "expected my log entry";
}


}
