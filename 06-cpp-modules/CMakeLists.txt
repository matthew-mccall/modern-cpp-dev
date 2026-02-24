add_executable(06CppModules)

target_sources(06CppModules
    PRIVATE
        main.cpp
        workshop.cpp
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            workshop.ixx
            workshop.types.ixx
            workshop.relations.ixx)

target_compile_features(06CppModules PRIVATE cxx_std_23)
