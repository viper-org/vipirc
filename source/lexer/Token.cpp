// Copyright 2025 solar-mist

#include "lexer/Token.h"

namespace lexer
{
    Token::Token(std::string text, TokenType tokenType, SourceLocation start, SourceLocation end)
        : mText(std::move(text))
        , mTokenType(tokenType)
        , mStartLoc(start)
        , mEndLoc(end)
    {
    }

    std::string_view Token::getText() const
    {
        return mText;
    }

    std::string_view Token::getName() const
    {
        switch (mTokenType)
        {
            case TokenType::FunctionKeyword:
                return "function";
            case TokenType::RetKeyword:
                return "ret";
            case TokenType::TypeKeyword:
                return "a type";
            case TokenType::RightArrow:
                return "->";
            case TokenType::LeftParen:
                return "(";
            case TokenType::RightParen:
                return ")";
            case TokenType::LeftBrace:
                return "{";
            case TokenType::RightBrace:
                return "}";
            case TokenType::Colon:
                return ":";
            case TokenType::Asperand:
                return "@";
            case TokenType::IntegerLiteral:
                return "integer literal";
            case TokenType::Identifier:
                return "an identifier";
            case TokenType::Error:
                return "Error";
            case TokenType::EndOfFile:
                return "eof";
        }
        return "forgot to add new token to Token::getName()";
    }

    TokenType Token::getTokenType() const
    {
        return mTokenType;
    }


    SourceLocation Token::getStartLocation() const
    {
        return mStartLoc;
    }

    SourceLocation Token::getEndLocation() const
    {
        return mEndLoc;
    }
}