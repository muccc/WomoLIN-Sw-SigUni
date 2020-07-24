/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../interface/helper.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{

// FindFirstCharacter  
class CHelperSignalStringsFindFirstCharacter  : public ::testing::Test {}; 

TEST_F( CHelperSignalStringsFindFirstCharacter, PositionTests ) {

   std::string testString = "NoCaptureByte"; 
   auto pos = helper::CSignalStrings::FindFirstCharacter( testString, '^' ); 
	ASSERT_EQ( -1, pos );

   testString = "^OneCaptureByteAtPostion0";
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^'); 
	ASSERT_EQ( 0, pos );

   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^', 0); 
	ASSERT_EQ( 0, pos );

   testString = ">^OneCaptureByteAtPosition1";
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^'); 
	ASSERT_EQ( 1, pos );

   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^', 1); 
	ASSERT_EQ( 1, pos );

   testString = "^Two^CaptureBytes";
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^'); 
	ASSERT_EQ( 0, pos );

   // offset 1, we expect the position of the second pos
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^', 1); 
	ASSERT_EQ( 4, pos );

   testString = "AtEndPosition^"; 
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^' ); 
	ASSERT_EQ( 13, pos );

}

// FindLastCharacter  
class CHelperSignalStringsFindLastCharacter  : public ::testing::Test {}; 

TEST_F( CHelperSignalStringsFindLastCharacter, PositionTests ) {

   std::string testString = "NoCaptureByte"; 
   auto pos = helper::CSignalStrings::FindLastCharacter( testString, '^' ); 
	ASSERT_EQ( -1, pos );

   testString = "^OneCaptureByteAtPostion0";
   pos = helper::CSignalStrings::FindLastCharacter( testString, '^'); 
	ASSERT_EQ( 0, pos );

   testString = "OneCaptureByteAtEndPostion^";
   pos = helper::CSignalStrings::FindLastCharacter( testString, '^'); 
	ASSERT_EQ( testString.size() - 1, pos );

   testString = "^Capture^ByteAtPostion8";
   pos = helper::CSignalStrings::FindLastCharacter( testString, '^'); 
	ASSERT_EQ( 8, pos );

   testString = "^Capture^ByteAtEndPostion^";
   pos = helper::CSignalStrings::FindLastCharacter( testString, '^'); 
	ASSERT_EQ( testString.size() - 1, pos );
}


// ExtractKeyValue  
class CHelperSignalStringsSplitKeyValue  : public ::testing::Test 
{

protected:
   std::string signalMessage;
   std::string key;
   std::string value;
   bool testresult;
}; 

TEST_F( CHelperSignalStringsSplitKeyValue, PositiveTest ) {

   signalMessage = "GetSignals;GET";

   testresult = helper::CSignalStrings::SplitKeyValue( signalMessage, ';', key, value ); 

   ASSERT_EQ( true, testresult ); 

	ASSERT_STREQ( key.c_str(), "GetSignals" );
	ASSERT_STREQ( value.c_str(), "GET" );
}


TEST_F( CHelperSignalStringsSplitKeyValue, NegativeTests ) {

   signalMessage = "GetSignals,GET";

   testresult = helper::CSignalStrings::SplitKeyValue( signalMessage, ';', key, value ); 
   ASSERT_EQ( false, testresult ); 

   signalMessage = ";GetSignals;GET";

   testresult = helper::CSignalStrings::SplitKeyValue( signalMessage, ';', key, value ); 
   ASSERT_EQ( false, testresult ); 

   signalMessage = "GetSignals;GET;";

   testresult = helper::CSignalStrings::SplitKeyValue( signalMessage, ';', key, value ); 
   ASSERT_EQ( false, testresult ); 

}



// GetValueItems 
class CHelperSignalStringsGetValueItems : public ::testing::Test {}; 

TEST_F( CHelperSignalStringsGetValueItems, SplitWithReturnCheck ) {

   std::vector<std::string> expectedItems = 
   { "GetLogging", "GetSignals", "GetSimulationStatus", "SetResetSimulationModus" };

   // generate teststring from vector
   auto separator = ',';
   auto testString = helper::CSignalStrings::CreateStringFromVector( expectedItems, separator );
    
   // call test function 
   auto items = helper::CSignalStrings::GetValueItems( testString, separator ); 


	ASSERT_EQ( true, helper::CSignalStrings::CompareTwoStringVectors( expectedItems, items ) ) << \
      testString << "\n" << helper::CSignalStrings::CreateStringFromVector( items, separator );
  
}




}
