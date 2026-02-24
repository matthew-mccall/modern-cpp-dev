cmake_minimum_required(VERSION 3.28)
project(ModernCPPWorkshop)

add_compile_options(
        "$<$<CXX_COMPILER_ID:MSVC>:/W4;/WX>"
        "$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall;-Wextra;-Wpedantic;-Werror>"
)

add_subdirectory(01-smart-ptrs)
add_subdirectory(02-modern-std)
add_subdirectory(03-concepts)
add_subdirectory(04-modern-lang)
add_subdirectory(05-ranges-views)
add_subdirectory(06-cpp-modules)