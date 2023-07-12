#ifndef SOSH_INTERPRETER_H
#define SOSH_INTERPRETER_H

#include "SOSH_Parser.h"

/**
 * @file SOSH_Interpreter.h
 * @brief Объявление класса SOSH_Interpreter
 */

/**
 * @class SOSH_Interpreter
 * @brief Класс, представляющий интерпретатор для вычисления выражений
 */
class SOSH_Interpreter {
public:
    /**
     * @brief Выполняет вычисление выражения
     * @param expression Выражение для вычисления
     * @param shell Объект SOSH_Shell, представляющий оболочку
     * @return Результат вычисления в виде объекта SOSH_Token
     */
    static SOSH_Token SOSH_Interpreter::evaluate(const std::string& expression, SOSH_Shell shell = SOSH_Shell(""));

};

#endif // SOSH_INTERPRETER_H
