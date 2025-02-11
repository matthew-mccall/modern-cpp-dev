cmake_minimum_required(VERSION 3.10)
project(MoreCMake)

find_package(spdlog REQUIRED)

add_executable(MyExec main.cpp)
target_compile_features(MyExec PRIVATE cxx_std_23)
target_link_libraries(MyExec PRIVATE spdlog::spdlog)