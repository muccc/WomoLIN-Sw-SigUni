/* SPDX-License-Identifier: GPLv3-or-later */
/* Copyright (c) 2020 Project WomoLIN */
/* Author Myron Franze <myronfranze@web.de> */

#include "../unit.h"
#include "../signal.h"

#include <gtest/gtest.h>

namespace siguni::gtest
{


class CSiguniTest  : public ::testing::Test { };



class CUnitSignalSetReset : public interface::ISignalSetReset
{
	void UpdateUnitSignalSetReset( std::string & /*attKey*/, std::string & /*attValue*/, interface::CSystemSettings & /*attSystemSettings*/ ) override {};
};


class CRelayOutput : public interface::IUnitOutput
{
public:
	CRelayOutput() = default ;
	~CRelayOutput() = default;

    void Set( std::string & attSetOutput, interface::CSystemSettings & /*attSystemSettings*/ ) override final { set = attSetOutput; };

    std::string set;
};


TEST_F( CSiguniTest, CUnitOutput ) {

	auto signal_setReset_1 = CSignalSetReset();

	auto unit_setReset_1 = CUnitSignalSetReset();

	signal_setReset_1.AddUnit( &unit_setReset_1 );

	std::string key {};
	std::string val {};

   auto systemSettings = interface::CSystemSettings();
	signal_setReset_1.UpdateUnit( key, val, systemSettings );

	// TODO
	//std::cout << key << std::endl;
	//std::cout << val << std::endl;

}

}
