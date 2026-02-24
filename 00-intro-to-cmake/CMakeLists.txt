cmake_minimum_required(VERSION 3.28)
project(IntroToCMake)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.17.0
    FIND_PACKAGE_ARGS
)

FetchContent_MakeAvailable(spdlog)

add_executable(00IntroToCMake)

target_sources(00IntroToCMake PRIVATE
    main.cpp)

target_link_libraries(00IntroToCMake PRIVATE spdlog::spdlog)