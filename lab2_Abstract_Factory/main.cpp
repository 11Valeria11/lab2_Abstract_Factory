#include <iostream>
#include "cpp_class_unit.h"//конкретная фабрика для main
#include "cpp_factory.h"
#include "unit.h"

// принимает абстрактную фабрику
std::string generateProgram(std::shared_ptr<ICodeFactory> factory) {
    auto myClass=factory->createClass("MyClass");

    myClass->add(
        factory->createMethod("testFunc1", "void", 0),
        CppClassUnit::PUBLIC
        );

    myClass->add(
        factory->createMethod("testFunc2", "void", Unit::STATIC),
        CppClassUnit::PRIVATE
        );

    myClass->add(
        factory->createMethod("testFunc3", "void", Unit::VIRTUAL | Unit::CONST),
        CppClassUnit::PUBLIC
        );

    auto method = factory->createMethod("testFunc4", "void", Unit::STATIC);
    method->add(
        factory->createPrintOperator("Hello, world!")
        );
    myClass->add(method, CppClassUnit::PROTECTED);

    return myClass->compile();
}

int main() {//решаем, какую конкретную фабрику использовать и передаем её в нашу универсальную функцию
    std::cout << "---------- C++ ----------" << std::endl;
    std::cout << generateProgram(std::make_shared<CppFactory>()) << std::endl;
    std::cout << "\nPress Enter to exit..."; // Сообщение для пользователя
    std::cin.get(); // Ожидание нажатия клавиши Enter
    return 0;
}
