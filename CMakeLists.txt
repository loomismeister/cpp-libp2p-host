CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(p2p CXX)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test/host_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/crypto)
add_executable(tests ${TEST_SOURCES})
set_property(TARGET tests PROPERTY CXX_STANDARD 17)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(tests Catch)