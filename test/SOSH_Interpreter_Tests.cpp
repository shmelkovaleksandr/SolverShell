#include <gtest/gtest.h>
#include "SOSH/SOSH_Interpreter.h"

int Sub(int a, int b) {
    return a - b;
}

TEST(SOSHInterpreterTest, evaluate_ReturnsCorrectResult) {
    SOSH_Function<int, int, int> sub_func("sub", Sub);
    sub_func.AddArgs(Token_t::SOSH_INT);
    sub_func.AddArgs(Token_t::SOSH_INT);
    sub_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base& sub_func_base = sub_func;

    SOSH_Shell shell("Shell");
    shell.AddFunction(sub_func_base);

    SOSH_Token result(Token_t::SOSH_UNDEFINED, "Empty.");
    std::string input = "sub 6 3";
    result = SOSH_Interpreter::evaluate(input, shell);

    EXPECT_EQ(result.GetValue<int>(), 3);
}
