 cmake_minimum_required(VERSION 2.8)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

 # Unit tests
 add_library(Catch INTERFACE)
 add_library(tester-main Tests/tester-main.cpp)

 add_library(MaterialDot MaterialDot.cpp)

 project(MKT-model)
 add_executable(main main.cpp)
 target_link_libraries(main MaterialDot)

 project(Tests)
 add_executable(test-MaterialDot Tests/MaterialDot-test.cpp)
 target_link_libraries(test-MaterialDot Catch tester-main MaterialDot)