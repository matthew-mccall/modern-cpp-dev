add_executable(02ModernStd)

target_sources(02ModernStd PRIVATE
    main.cpp)


target_compile_features(02ModernStd PRIVATE cxx_std_23)