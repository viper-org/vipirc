// Copyright 2025 solar-mist

#ifndef VIPIRC_LEXER_TOKEN_H
#define VIPIRC_LEXER_TOKEN_H 1

#include "lexer/SourceLocation.h"

#include <string>

namespace lexer
{
    enum class TokenType
    {
        FunctionKeyword,
        TypeKeyword,
        RetKeyword,

        Identifier,
        IntegerLiteral,

        Asperand,
        LeftParen,
        RightParen,
        LeftBrace,
        RightBrace,
        RightArrow,
        Colon,

        EndOfFile,
        Error,
    };

    class Token
    {
    public:
        Token(std::string text, TokenType tokenType, SourceLocation startLocation, SourceLocation endLocation);

        std::string_view getText() const;
        std::string_view getName() const; // For diagnostics
        TokenType getTokenType() const;

        SourceLocation getStartLocation() const;
        SourceLocation getEndLocation() const;

    private:
        std::string mText;
        TokenType mTokenType;

        SourceLocation mStartLoc;
        SourceLocation mEndLoc;
    };
}

#endif // VIPIRC_LEXER_TOKEN_H