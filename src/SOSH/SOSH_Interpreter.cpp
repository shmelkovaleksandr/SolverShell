#include "SOSH_Interpreter.h"

SOSH_Token SOSH_Interpreter::evaluate(const std::string& expression, SOSH_Shell shell) { 
    SOSH_Parser parser(expression, shell);
    SOSH_ASTNode* rootNode = parser.parse();
    SOSH_Token result = rootNode->evaluate();
    delete rootNode;
    return result;
}
