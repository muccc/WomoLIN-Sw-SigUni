/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../interface/helper.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{

class CHelperSignalStringsFindFirstCharacter  : public ::testing::Test {}; 

TEST_F( CHelperSignalStringsFindFirstCharacter, PositionTests ) {

   std::string testString = "^OneCaptureByteAtPostion0";
   auto pos = helper::CSignalStrings::FindFirstCharacter( testString, '^'); 
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

   // with offset 1, we expect the position of the second pos
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^', 1); 
	ASSERT_EQ( 4, pos );

   testString = "AtEndPosition^"; 
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^' ); 
	ASSERT_EQ( 13, pos );

   testString = "NoCaptureByte"; 
   pos = helper::CSignalStrings::FindFirstCharacter( testString, '^' ); 
	ASSERT_EQ( -1, pos );
}

class CHelperSignalStringsFindLastCharacter  : public ::testing::Test {}; 

TEST_F( CHelperSignalStringsFindLastCharacter, PositionTests ) {

   // TODO
}

class CHelperSignalStringsExtractKeyValue  : public ::testing::Test {}; 

TEST_F( CHelperSignalStringsExtractKeyValue, PositionTests ) {

   // TODO
}




}
