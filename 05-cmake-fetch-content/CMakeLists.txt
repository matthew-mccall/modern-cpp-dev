cmake_minimum_required(VERSION 3.10)
project(MoreCMake)

include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.1
)
FetchContent_MakeAvailable(spdlog)

add_executable(MyExec main.cpp)
target_compile_features(MyExec PRIVATE cxx_std_23)
target_link_libraries(MyExec PRIVATE spdlog::spdlog)