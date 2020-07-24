SET(LIB_NAME "sigunit-test")
project (${LIB_NAME})

add_executable( ${LIB_NAME} 
   helper_test.cpp
	unit_test.cpp
	signal_test.cpp
   hal_test.cpp
	siguni_test.cpp
   protocol_test.cpp
   managerbase_test.cpp
	test.cpp
)

target_link_libraries( ${LIB_NAME} 
	gtest
	pthread
	siguni 
)
