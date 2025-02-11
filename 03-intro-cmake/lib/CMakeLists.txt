add_library(MyLib lib.cpp include/lib/lib.hpp)
target_include_directories(MyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(MyLib PRIVATE cxx_std_23)