/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../unit.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{

class CUnitTest  : public ::testing::Test { };


// unit output
class CUnitOutputTest : public interface::IUnitOutput
{
public:
	CUnitOutputTest() = default ;
	~CUnitOutputTest() = default;

    void Set( std::string & attSetOutput, 
              interface::CAdditionals & /*attAdditionals*/ ) override final 
            { 
               setCommand = attSetOutput; 
            };

    std::string setCommand;
};

TEST_F( CUnitTest, IUnitOutput ) {

	auto test = CUnitOutputTest();
   auto additionals = interface::CAdditionals();

   std::string setCommand { "SET" };

	test.Set( setCommand, additionals );
	ASSERT_STREQ( test.setCommand.c_str() , "SET" );

   setCommand = "RESET";

	test.Set( setCommand, additionals );
	ASSERT_STREQ( test.setCommand.c_str() , "RESET" );
}

// unit intput
class CUnitInputTest : public interface::IUnitInput
{
public:
	CUnitInputTest() = default ;
	~CUnitInputTest() = default;

    void Get( std::string & attStatus, 
              interface::CAdditionals & /*attAdditionals*/ ) override final 
            {	
               attStatus = "SET"; 
            };
};

TEST_F( CUnitTest, IUnitInput ) {

	auto test = CUnitInputTest();
   auto additionals = interface::CAdditionals();

	std::string status_string {"UNKNOWN"};

	test.Get( status_string, additionals );
	ASSERT_STREQ( status_string.c_str() , "SET" );
}

}
