#include "gtest/gtest.h"
#include "SOSH/SOSH_Function.h"

// Define sample functions for testing

int Add(int a, int b) {
    return a + b;
}

void PrintMessage(std::string message) {
    std::cout << message << std::endl;
}

TEST(SOSHFunctionTest, Apply_ReturnsCorrectResult) {
    SOSH_Function<int, int, int> add_func("Add", Add);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base* add_func_base = &add_func;

    std::vector<SOSH_Token> arguments = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "Add"),
        SOSH_Token(Token_t::SOSH_INT, "2"),
        SOSH_Token(Token_t::SOSH_INT, "3")
    };

    // Test apply method with valid arguments
    auto result = add_func_base->call<10>(arguments);
    EXPECT_EQ(result.GetValue<int>(), 5);
}

TEST(SOSHFunctionTest, Apply_WrongArgumentType_ReturnsUndefinedToken) {
    SOSH_Function<int, int, int> add_func("Add", Add);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base* add_func_base = &add_func;

    std::vector<SOSH_Token> arguments = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "Add"),
        SOSH_Token(Token_t::SOSH_INT, "2"),
        SOSH_Token(Token_t::SOSH_STRING, "3")  // Passing string instead of int
    };

    // Test apply method with wrong argument type
    auto result = add_func_base->call<20>(arguments);
    EXPECT_EQ(result.GetType(), Token_t::SOSH_UNDEFINED);
}

TEST(SOSHFunctionTest, Apply_WrongNumberOfArguments_ReturnsUndefinedToken) {
    SOSH_Function<int, int, int> add_func("Add", Add);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base* add_func_base = &add_func;

    std::vector<SOSH_Token> arguments = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "Add"),
        SOSH_Token(Token_t::SOSH_INT, "2")
    };

    // Test apply method with wrong number of arguments
    auto result = add_func_base->call<10>(arguments); // Passing only one argument instead of two
    EXPECT_EQ(result.GetType(), Token_t::SOSH_UNDEFINED);
}

TEST(SOSHFunctionTest, ApplyString_ReturnsCorrectResult) {
    SOSH_Function print_func("PrintMessage", PrintMessage);
    print_func.AddArgs(Token_t::SOSH_STRING);
    SOSH_Function_Base* print_func_base = &print_func;

    std::vector<SOSH_Token> arguments = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "PrintMessage"),
        SOSH_Token(Token_t::SOSH_STRING, "Hello, World!")
    };

    // Test Apply method with valid arguments
    auto result = print_func_base->call(arguments);
    EXPECT_EQ(result.GetType(), Token_t::SOSH_VOID);
}

TEST(SOSHFunctionTest, Apply_MismatchedArgumentType_ReturnsUndefinedToken) {
    SOSH_Function print_func("PrintMessage", PrintMessage);
    print_func.AddArgs(Token_t::SOSH_STRING);
    SOSH_Function_Base* print_func_base = &print_func;

    std::vector<SOSH_Token> arguments = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "PrintMessage"),
        SOSH_Token(Token_t::SOSH_INT, "123") // Passing int token instead of string token
    };

    // Test apply method with mismatched argument type 
    auto result = print_func_base->call(arguments);
    EXPECT_EQ(result.GetType(), Token_t::SOSH_UNDEFINED);
}

TEST(SOSHFunctionTest, Call_ReturnsCorrectResult) {
    SOSH_Function<int, int, int> add_func("Add", Add);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base& add_func_base = add_func;

    std::vector<SOSH_Token> tokens = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "Add"),
        SOSH_Token(Token_t::SOSH_INT, "2"),
        SOSH_Token(Token_t::SOSH_INT, "3")
    };

    // Test call method
    auto result = add_func_base.call<3>(tokens);
    EXPECT_EQ(result.GetValue<int>(), 5);
}

TEST(SOSHFunctionTest, Call_InvalidNumberOfArguments_ReturnsUndefinedToken) {
    SOSH_Function<int, int, int> add_func("Add", Add);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddArgs(Token_t::SOSH_INT);
    add_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base& add_func_base = add_func;

    std::vector<SOSH_Token> tokens = {
        SOSH_Token(Token_t::SOSH_FUNCTION_NAME, "Add"),
        SOSH_Token(Token_t::SOSH_INT, "2")
    };

    // Test call method with invalid number of arguments
    auto result = add_func_base.call<3>(tokens); // Expected 3 arguments, but only 2 provided
    EXPECT_EQ(result.GetType(), Token_t::SOSH_UNDEFINED);
}
