/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../unit.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{

class CUnitTest  : public ::testing::Test { };


class CUnitOutputTest : public interface::IUnitOutput
{
public:
	CUnitOutputTest() = default ;
	~CUnitOutputTest() = default;

    void Set( std::string & attSetOutput, interface::CSystemSettings & /*attSystemSettings*/ ) override final { setCommand = attSetOutput; };

    std::string setCommand;
};

TEST_F( CUnitTest, IUnitOutput ) {

	auto test = CUnitOutputTest();
   auto systemSettings = interface::CSystemSettings();

   std::string setCommand { "SET" };

	test.Set( setCommand, systemSettings );
	ASSERT_STREQ( test.setCommand.c_str() , "SET" );

   setCommand = "RESET";

	test.Set( setCommand, systemSettings );
	ASSERT_STREQ( test.setCommand.c_str() , "RESET" );
}

class CUnitInputTest : public interface::IUnitInput
{
public:
	CUnitInputTest() = default ;
	~CUnitInputTest() = default;

    void Get( std::string & attStatus, interface::CSystemSettings & /*attSystemSettings*/ ) override final {	attStatus = "SET"; };
};

TEST_F( CUnitTest, IUnitInput ) {

	auto test = CUnitInputTest();
   auto systemSettings = interface::CSystemSettings();

	std::string status_string {"UNKNOWN"};

	test.Get( status_string, systemSettings );
	ASSERT_STREQ( status_string.c_str() , "SET" );
}

}
