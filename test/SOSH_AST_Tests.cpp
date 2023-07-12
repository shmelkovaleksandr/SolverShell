#include "gtest/gtest.h"
#include "SOSH/SOSH_AST.h"

TEST(NumberNodeTest, Evaluate) {
    NumberNode node(5.0);
    SOSH_Token result = node.evaluate();

    ASSERT_EQ(result.GetType(), Token_t::SOSH_DOUBLE);
    ASSERT_DOUBLE_EQ(result.GetValue<double>(), 5.0);
}

TEST(BinaryOperatorNodeTest, Evaluate) {
    NumberNode* leftNode = new NumberNode(3.0);
    NumberNode* rightNode = new NumberNode(2.0);
    BinaryOperatorNode node('+', leftNode, rightNode);
    SOSH_Token result = node.evaluate();
    
    ASSERT_EQ(result.GetType(), Token_t::SOSH_DOUBLE);
    ASSERT_DOUBLE_EQ(result.GetValue<double>(), 5.0);
}
