cmake_minimum_required(VERSION 3.28)
project(PackratParsing)

set(CMAKE_CXX_STANDARD 23)

add_executable(PackratParsing
        src/main.cpp
        src/parser/Parser.h
        src/parser/Parser.cpp
        src/parser/LiteralParser.h
        src/parser/SequenceParser.h
        src/parser/SequenceParser.cpp
        src/parser/LiteralParser.cpp
)
