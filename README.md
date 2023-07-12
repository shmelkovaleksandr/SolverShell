# Библиотека SolverShell

![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

Библиотека SolverShell - это средство для описания предметно-ориентированных языков (Domain-Specific Languages, DSL) и построения их интерпретаторов. Она разработана на языке C++ с использованием инструмента сборки CMake.

## Возможности

- Построение языка: Библиотека позволяет описывать и определять синтаксис, грамматику и семантику предметно-ориентированных языков.
- Интерпретация языка: SolverShell обеспечивает возможность создания интерпретаторов для различных предметно-ориентированных языков.
- Поддержка пользовательских расширений: Библиотека предоставляет механизмы для добавления пользовательских функций и операций в язык.

## Требования

- Компилятор C++17 или выше
- CMake версии 3.23 и выше

## Установка

```shell
git clone https://github.com/your-username/SolverShell.git
cd SolverShell
mkdir build && cd build
cmake ..
make
```

## Пример использования

```cpp
#include "SOSH/API.h"

int Sub(int a, int b) {
    return a - b;
};

int main() {
    // Регистрация пользовательской фунции
    SOSH_Function sub_func("sub", Sub);
    sub_func.AddArgs(Token_t::SOSH_INT);
    sub_func.AddArgs(Token_t::SOSH_INT);
    sub_func.AddReturn(Token_t::SOSH_INT);
    SOSH_Function_Base& sub_func_base = sub_func;

    // Группировка пользовательской фунции
    SOSH_Shell shell("Shell");
    shell.AddFunction(sub_func_base);

    SOSH_Token result(Token_t::SOSH_UNDEFINED, "Empty.");
    // Получение команды
    std::string input = "sub 6 -3";
    // Интерпретация кода на предметно-ориентированном языке
    result = SOSH_Interpreter::evaluate(input, shell);

    std::cout << "Result: " << result.GetValue() << std::endl;

    return 0;
};

```

## Лицензия

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.