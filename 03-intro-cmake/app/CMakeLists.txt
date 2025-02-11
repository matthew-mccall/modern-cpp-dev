add_executable(MyExec main.cpp)
target_link_libraries(MyExec PRIVATE MyLib)
target_compile_features(MyExec PRIVATE cxx_std_23)