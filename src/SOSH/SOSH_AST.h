#ifndef SOSH_AST_H
#define SOSH_AST_H

#include "SOSH_Function.h"

/**
 * @file SOSH_ASTNode.h
 * @brief Заголовочный файл для класса SOSH_ASTNode
 */

/**
 * @class SOSH_ASTNode
 * @brief Базовый абстрактный класс для узла абстрактного синтаксического дерева (Abstract Syntax Tree - AST)
 */
class SOSH_ASTNode {
public:
    /**
     * @brief Виртуальный деструктор
     */
    virtual ~SOSH_ASTNode() {}

    /**
     * @brief Выполняет вычисление значения узла
     * @return Значение узла в виде SOSH_Token
     */
    virtual SOSH_Token evaluate() const = 0;
};

/**
 * @class NumberNode
 * @brief Класс узла, представляющего числовое значение
 */
class NumberNode : public SOSH_ASTNode {
public:
    /**
     * @brief Конструктор класса NumberNode
     * @param value Значение числа
     */
    explicit NumberNode(double value) : value(value) {}

    /**
     * @brief Выполняет вычисление значения числового узла
     * @return Значение числа в виде SOSH_Token
     */
    SOSH_Token evaluate() const override;

private:
    double value; /**< Значение числа */
};

/**
 * @class BinaryOperatorNode
 * @brief Класс узла, представляющего бинарный оператор
 */
class BinaryOperatorNode : public SOSH_ASTNode {
public:
    /**
     * @brief Конструктор класса BinaryOperatorNode
     * @param op Оператор
     * @param left Левый операнд
     * @param right Правый операнд
     */
    BinaryOperatorNode(char op, SOSH_ASTNode* left, SOSH_ASTNode* right) : op(op), left(left), right(right) {}

    /**
     * @brief Деструктор класса BinaryOperatorNode
     */
    ~BinaryOperatorNode() {
        delete left;
        delete right;
    }

    /**
     * @brief Выполняет вычисление значения бинарного оператора
     * @return Значение оператора в виде SOSH_Token
     */
    SOSH_Token evaluate() const override;

private:
    char op; /**< Оператор */
    SOSH_ASTNode* left; /**< Левый операнд */
    SOSH_ASTNode* right; /**< Правый операнд */
};

/**
 * @class ASTShellFunctionNode
 * @brief Класс узла, представляющего функцию в оболочке AST
 */
class ASTShellFunctionNode : public SOSH_ASTNode {
public:
    /**
     * @brief Конструктор класса ASTShellFunctionNode
     * @param name Название функции
     * @param args Аргументы функции
     * @param func Указатель на объект функции
     */
    ASTShellFunctionNode(const std::string& name, std::vector<SOSH_Token> args, SOSH_Function_Base* func)
        : function_name(name), arguments(args), function(func) {}

    /**
     * @brief Выполняет вычисление значения функции
     * @return Значение функции в виде SOSH_Token
     */
    SOSH_Token evaluate() const override;

private:
    std::string function_name; /**< Название функции */
    std::vector<SOSH_Token> arguments; /**< Аргументы функции */
    SOSH_Function_Base* function; /**< Указатель на объект функции */
};

#endif // SOSH_AST_H
