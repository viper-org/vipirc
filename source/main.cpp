// Copyright 2025 solar-mist

#include "lexer/Token.h"
#include "lexer/Lexer.h"

#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "vasm: no input files\n";
        return 1;
    }

    std::string inputPath = argv[1];
    std::ifstream inputFile = std::ifstream(inputPath);
    std::stringstream buf;
    buf << inputFile.rdbuf();
    std::string text = std::move(buf).str();
    
    lexer::Lexer lexer(text, inputPath);
    auto tokens = lexer.lex();
    for (auto& token : tokens)
    {
        std::cout << token.getText() << "\n";
    }

    return 0;
}