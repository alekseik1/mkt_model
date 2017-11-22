 cmake_minimum_required(VERSION 2.8)
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

 # Unit tests
 add_library(Catch INTERFACE)

 project(MKT-model)
 add_executable(main main.cpp)

 #project(Tests)
 #add_executable(test-Atom Tests/Atom_test.cpp)
 #target_link_libraries(test-Atom Catch)