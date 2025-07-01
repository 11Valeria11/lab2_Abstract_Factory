#include <iostream>
#include "cpp_class_unit.h"//конкретная фабрика для main
#include "cpp_factory.h"
#include "csharp_factory.h"
#include "unit.h"
#include "java_factory.h"

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

    auto method = factory->createMethod("testFunc4", "void", Unit::STATIC| Unit::FINAL);
    method->add(
        factory->createPrintOperator("Hello, world!")
        );
    myClass->add(method, CppClassUnit::PROTECTED);

    return myClass->compile();
}

int main() {
    std::cout << "---------- C++ ----------" << std::endl;
    std::cout << generateProgram(std::make_shared<CppFactory>()) << std::endl;
    std::cout << "---------- C# ----------" << std::endl;
    std::cout << generateProgram(std::make_shared<CSharpFactory>()) << std::endl;
    std::cout << "---------- JAVA ----------" << std::endl;
    std::cout << generateProgram(std::make_shared<JavaFactory>()) << std::endl;
    return 0;
}
