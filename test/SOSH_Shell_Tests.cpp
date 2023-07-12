#include "gtest/gtest.h"
#include "SOSH/SOSH_Shell.h"
#include "SOSH/SOSH_Function.h"

void test(){};

// Тестирование функции AddFunction
TEST(SOSH_ShellTest, AddFunction) {
    SOSH_Shell shell("TestShell");
    SOSH_Function function("TestFunction", test);
    SOSH_Function_Base& function_base = function;
    bool result = shell.AddFunction(function_base);

    EXPECT_TRUE(result);
}

// Тестирование функции FindFunction
TEST(SOSH_ShellTest, FindFunction) {
    SOSH_Shell shell("TestShell");
    SOSH_Function function("TestFunction", test);
    SOSH_Function_Base& function_base = function;
    shell.AddFunction(function_base);

    SOSH_Function_Base* result = shell.FindFunction("TestFunction");

    EXPECT_EQ(result, &function);
}

// Тестирование функции ListFunction
TEST(SOSH_ShellTest, ListFunction) {
    SOSH_Shell shell("TestShell");
    SOSH_Function function1("TestFunction1", test);
    SOSH_Function_Base& function_base1 = function1;
    SOSH_Function function2("TestFunction2", test);
    SOSH_Function_Base& function_base2 = function2;
    shell.AddFunction(function_base1);
    shell.AddFunction(function_base2);

    std::vector<std::reference_wrapper<SOSH_Function_Base>> result = shell.ListFunction();

    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].get().GetName(), "TestFunction1");
    EXPECT_EQ(result[1].get().GetName(), "TestFunction2");
}

// Тестирование функции GetName
TEST(SOSH_ShellTest, GetName) {
    SOSH_Shell shell("TestShell");
    std::string result = shell.GetName();
    EXPECT_EQ(result, "TestShell");
}
