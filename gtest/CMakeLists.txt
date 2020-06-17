SET(LIB_NAME "sigunit-test")
project (${LIB_NAME})

add_executable( ${LIB_NAME} 
	test.cpp
	signal_test.cpp
	unit_test.cpp
	siguni_test.cpp
)

target_link_libraries( ${LIB_NAME} 
	gtest
	pthread
	siguni 
)
