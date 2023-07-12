#include "SOSH_Token.h"

void SOSH_Token::EditValue(std::string v) {
    lexeme = v;
};

Token_t SOSH_Token::GetType() const {
    return type;
};
