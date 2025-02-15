cmake_minimum_required(VERSION 3.26)

project(vipirc)

include(FetchContent)
FetchContent_Declare(vipir
    GIT_REPOSITORY https://github.com/viper-org/vipir.git
    GIT_TAG master
)
FetchContent_MakeAvailable(vipir)

set(SOURCES
    "source/main.cpp"

    "source/lexer/SourceLocation.cpp"
    "source/lexer/Token.cpp"
    "source/lexer/Lexer.cpp"
)

set(HEADERS
    "include/lexer/SourceLocation.h"
    "include/lexer/Token.h"
    "include/lexer/Lexer.h"
)

add_executable(vipirc ${SOURCES} ${HEADERS})
target_include_directories(vipirc PRIVATE include)
target_compile_features(vipirc PRIVATE cxx_std_20)
target_link_libraries(vipirc PRIVATE vipir)