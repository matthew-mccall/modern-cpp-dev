cmake_minimum_required(VERSION 3.28) # Note: CMake 3.28 Minimum
project(CppModule)

add_executable(MyExec)
target_sources(MyExec PRIVATE main.cpp)
target_sources(MyExec PRIVATE FILE_SET my_exec_modules TYPE CXX_MODULES FILES other.cppm)
target_compile_features(MyExec PRIVATE cxx_std_23)