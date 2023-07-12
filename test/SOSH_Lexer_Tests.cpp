#include <gtest/gtest.h>
#include "SOSH/SOSH_Lexer.h"

TEST(LexerTest, TokenizeWhitespace) {
    std::string code = "   \t\n";
    SOSH_Lexer lexer(code);
    std::vector<SOSH_Token> tokens = lexer.tokenize();
    EXPECT_EQ(tokens.size(), 0);
}

TEST(LexerTest, TokenizeIdentifier) {
    std::string code = "variable_name";
    SOSH_Lexer lexer(code);
    std::vector<SOSH_Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].GetType(), Token_t::SOSH_IDENTIFIER);
    EXPECT_EQ(tokens[0].GetValue(), code);
}

TEST(LexerTest, TokenizeNumber) {
    std::string code = "123.45";
    SOSH_Lexer lexer(code);
    std::vector<SOSH_Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].GetType(), Token_t::SOSH_FLOAT);
    EXPECT_EQ(tokens[0].GetValue(), code);
}

TEST(LexerTest, TokenizeString) {
    std::string code = "\"Hello, world!\"";
    SOSH_Lexer lexer(code);
    std::vector<SOSH_Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].GetType(), Token_t::SOSH_STRING);
    EXPECT_EQ(tokens[0].GetValue(), "Hello, world!");
}

TEST(LexerTest, TokenizeCharacter) {
    std::string code = "'A'";
    SOSH_Lexer lexer(code);
    std::vector<SOSH_Token> tokens = lexer.tokenize();
    ASSERT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0].GetType(), Token_t::SOSH_CHAR);
    EXPECT_EQ(tokens[0].GetValue(), code);
}
