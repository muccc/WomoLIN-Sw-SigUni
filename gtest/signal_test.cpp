/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

// for testing purposes, we add the cpp file instead of the header file
#include "../signal.cpp"

#include <gtest/gtest.h>


namespace siguni::gtest
{

class CSignalTest  : public ::testing::Test { };


// Test add unit
class CSignalAddUnitIntTest : public CSignalAddUnit<int>
{
public:
	CSignalAddUnitIntTest() { unitsPointer = &units ; } ;
	~CSignalAddUnitIntTest() = default;
	const std::vector<int*>* unitsPointer; // pointer to access unit array
};

TEST_F( CSignalTest, CSignalAddUnitInt ) {

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
	ASSERT_EQ( 20, *(*test.unitsPointer).at(1) ) << "value 2 must be 20, changed variable var2 changed";

}

// Test Signal GetString
class CSignalGetSignalsTest : public interface::ISignalGetString
{
public:
	CSignalGetSignalsTest() = default ;
	~CSignalGetSignalsTest() = default;
	void UpdateUnitSignalGetString( std::string & attKey, std::string & attValue, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		value = attValue;
	};

	std::string key { "" };
	std::string value { "UNKNOWN" };

};


TEST_F( CSignalTest, ISignalGetString) {

	std::string key { "KEY" };
	std::string val { "GET" };

	auto test = CSignalGetSignalsTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalGetString( key, val, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.value.c_str(), "GET" );

}


// Test Signal SetReset
class CSignalSetResetTest : public interface::ISignalSetReset
{
public:
	CSignalSetResetTest() = default ;
	~CSignalSetResetTest() = default;
	void UpdateUnitSignalSetReset( std::string & attKey, std::string & attValue, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		value = attValue;
	};
	std::string key;
	std::string value { "UNKNOWN" };

};


TEST_F( CSignalTest, ISignalSetReset ) {

	std::string key { "KEY" };
	std::string val { "GET" };

	auto test = CSignalSetResetTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalSetReset( key, val, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.value.c_str(), "GET" );

}

// Test Signal GetVoltage
class CSignalGetVoltageTest : public interface::ISignalGetVoltage
{
public:
	CSignalGetVoltageTest() = default ;
	~CSignalGetVoltageTest() = default;
	void UpdateUnitSignalGetVoltage( std::string & attKey, std::string & attGetVoltage, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		voltage = attGetVoltage;
	};
	std::string key;
	std::string voltage;
};


TEST_F( CSignalTest, ISignalGetVoltage ) {

	std::string key {"KEY"};
	std::string voltage {"VOLTAGE"};

	auto test = CSignalGetVoltageTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalGetVoltage( key, voltage, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.voltage.c_str() , "VOLTAGE");

}


// Test Signal GetVersion
class CSignalGetVersionTest : public interface::ISignalGetVersion
{
public:
	CSignalGetVersionTest() = default ;
	~CSignalGetVersionTest() = default;
	void UpdateUnitSignalGetVersion( std::string & attKey, std::string & attVersion, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		fw = attVersion;
	};
	std::string key;
	std::string fw;
};


TEST_F( CSignalTest, ISignalGetVersion ) {

	std::string key {"KEY"};
	std::string fw {"FW"};

	auto test = CSignalGetVersionTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalGetVersion( key, fw, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.fw.c_str() , "FW");

}

// Test Signal GetPressure
class CSignalGetPressureTest : public interface::ISignalGetPressure
{
public:
	CSignalGetPressureTest() = default ;
	~CSignalGetPressureTest() = default;
	void UpdateUnitSignalGetPressure( std::string & attKey, std::string & attPressure, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		fw = attPressure;
	};
	std::string key;
	std::string fw;
};


TEST_F( CSignalTest, ISignalGetPressure ) {

	std::string key {"KEY"};
	std::string fw {"FW"};

	auto test = CSignalGetPressureTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalGetPressure( key, fw, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.fw.c_str() , "FW");

}

// Test Signal GetTemperature
class CSignalGetTemperatureTest : public interface::ISignalGetTemperature
{
public:
	CSignalGetTemperatureTest() = default ;
	~CSignalGetTemperatureTest() = default;
	void UpdateUnitSignalGetTemperature( std::string & attKey, std::string & attTemperature, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		fw = attTemperature;
	};
	std::string key;
	std::string fw;
};


TEST_F( CSignalTest, ISignalGetTemperature ) {

	std::string key {"KEY"};
	std::string fw {"FW"};

	auto test = CSignalGetTemperatureTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalGetTemperature( key, fw, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.fw.c_str() , "FW");

}

// Test Signal GetHumidity
class CSignalGetHumidityTest : public interface::ISignalGetHumidity
{
public:
	CSignalGetHumidityTest() = default ;
	~CSignalGetHumidityTest() = default;
	void UpdateUnitSignalGetHumidity( std::string & attKey, std::string & attHumidity, interface::CAdditionals & /*attAdditionals*/ ) override final
	{
		key = attKey;
		fw = attHumidity;
	};
	std::string key;
	std::string fw;
};


TEST_F( CSignalTest, ISignalGetHumidity ) {

	std::string key {"KEY"};
	std::string fw {"FW"};

	auto test = CSignalGetHumidityTest();
   auto additionals = interface::CAdditionals();

	test.UpdateUnitSignalGetHumidity( key, fw, additionals );

	ASSERT_STREQ( test.key.c_str() , "KEY" );
	ASSERT_STREQ( test.fw.c_str() , "FW");

}




}

