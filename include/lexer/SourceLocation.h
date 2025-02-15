// Copyright 2025 solar-mist

#ifndef VIPIRC_LEXER_SOURCE_LOCATION_H
#define VIPIRC_LEXER_SOURCE_LOCATION_H 1

#include <string_view>

namespace lexer
{
    struct SourceLocation
    {
        SourceLocation() = default;
        SourceLocation(std::string_view file, unsigned int line, unsigned int col, unsigned int position);

        std::string_view file;

        unsigned int line;
        unsigned int col;
        unsigned int position;
    };
}

#endif // VIPIRC_LEXER_SOURCE_LOCATION_H