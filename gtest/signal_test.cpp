/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../signal.h"

#include <gtest/gtest.h>


namespace siguni::gtest
{

class CSerialTest  : public ::testing::Test { };


class CSignalSetResetTest : public interface::ISignalSetReset
{
public:
	CSignalSetResetTest() = default ;
	~CSignalSetResetTest() = default;
	void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue ) override final
	{
		key = attKey;
		value = attValue;
	};
	std::string key;
	std::string value { "UNKNOWN" };

};


TEST_F( CSerialTest, ISignalSetReset ) {

	std::string key { "KEY" };
	std::string val { "GET" };

	auto test = CSignalSetResetTest();

	test.UpdateUnitSignalSetReset( key, val );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.value.c_str(), "GET" );

}

class CSignalGetVoltageTest : public interface::ISignalGetVoltage
{
public:
	CSignalGetVoltageTest() = default ;
	~CSignalGetVoltageTest() = default;
	void UpdateUnitSignalGetVoltage( std::string & attKey, std::string & attGetVoltage ) override final
	{
		key = attKey;
		voltage = attGetVoltage;
	};
	std::string key;
	std::string voltage;
};


TEST_F( CSerialTest, ISignalGetVoltage ) {

	std::string key {"KEY"};
	std::string voltage {"VOLTAGE"};

	auto test = CSignalGetVoltageTest();

	test.UpdateUnitSignalGetVoltage( key, voltage );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.voltage.c_str() , "VOLTAGE");

}


class CSignalGetVersionTest : public interface::ISignalGetVersion
{
public:
	CSignalGetVersionTest() = default ;
	~CSignalGetVersionTest() = default;
	void UpdateUnitSignalGetVersion( std::string & attKey, std::string & attVersion ) override final
	{
		key = attKey;
		fw = attVersion;
	};
	std::string key;
	std::string fw;
};


TEST_F( CSerialTest, ISignalGetVersion ) {

	std::string key {"KEY"};
	std::string fw {"FW"};

	auto test = CSignalGetVersionTest();

	test.UpdateUnitSignalGetVersion( key, fw );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.fw.c_str() , "FW");

}




class CSignalAddUnitIntTest : public CSignalAddUnit<int>
{
public:
	CSignalAddUnitIntTest() { unitsPointer = &units ; } ;
	~CSignalAddUnitIntTest() = default;
	const std::vector<int*>* unitsPointer; // pointer to access unit array
};

TEST_F( CSerialTest, CSignalAddUnitInt ) {

	int val1 {1};
	int val2 {2};

	auto test = CSignalAddUnitIntTest();

	ASSERT_TRUE( (*test.unitsPointer).empty() ) << "no values added, array must be empty";
	test.AddUnit( &val1 );
	ASSERT_EQ( 1,  (*test.unitsPointer).size() ) << "added one value, array must be have one value";

	test.AddUnit( &val2 ); // add second value to array

	val1 = 10; // change initialize value from value 1
	val2 = 20; // change initialize value from value 2

	ASSERT_EQ( 10, *(*test.unitsPointer).at(0) ) << "value 1 must be 10, changed variable var1 changed";
	ASSERT_EQ( 20, *(*test.unitsPointer).at(1) ) << "value 1 must be 20, changed variable var2 changed";

}

}

