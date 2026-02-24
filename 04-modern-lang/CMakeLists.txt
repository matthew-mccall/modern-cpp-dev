add_executable(04ModernLang)

target_sources(04ModernLang PRIVATE
    main.cpp)

target_compile_features(04ModernLang PRIVATE cxx_std_23)
