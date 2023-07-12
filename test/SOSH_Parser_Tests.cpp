#include <gtest/gtest.h>
#include "SOSH/SOSH_Parser.h"

TEST(SOSH_ParserTest, TestBasicArithmetic) {
    SOSH_Parser parser("2 + 3 * 4");
    SOSH_ASTNode* result = parser.parse();
    EXPECT_EQ(result->evaluate().GetValue<int>(), 14.0);

    delete result;
}

TEST(SOSH_ParserTest, TestNegativeNumbers) {
    SOSH_Parser parser("-5 + 8 - -3");
    SOSH_ASTNode* result = parser.parse();
    EXPECT_EQ(result->evaluate().GetValue<int>(), 6.0);

    delete result;
}

TEST(SOSH_ParserTest, TestParentheses) {
    SOSH_Parser parser("(2 + 3) * 4");
    SOSH_ASTNode* result = parser.parse();
    EXPECT_EQ(result->evaluate().GetValue<int>(), 20.0);

    delete result;
}

/*TEST(SOSH_ParserTest, TestFunctions) {
    SOSH_Shell shell;
    shell.AddFunction("add", [](std::vector<double> args) { return args[0] + args[1]; });
    shell.AddFunction("subtract", [](std::vector<double> args) { return args[0] - args[1]; });

    SOSH_Parser parser("add(2, 3) - subtract(5, 2)");
    SOSH_ASTNode* result = parser.parse();
    EXPECT_EQ(result->evaluate(), 4.0);

    delete result;
}*/

/*TEST(SOSH_ParserTest, TestInvalidExpression) {
    SOSH_Parser parser("2 + * 3");
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

TEST(SOSH_ParserTest, TestMismatchedParentheses) {
    SOSH_Parser parser("(2 + 3 * 4");
    EXPECT_THROW(parser.parse(), std::runtime_error);
}*/
