#include <iostream>
#include "cpp\cpp_factory.h"//конкретная фабрика для main
#include "cpp\cpp_factory.h"
#include "csharp\csharp_factory.h"
#include "unit.h"
#include "java\java_factory.h"


std::string generateProgram(std::shared_ptr<ICodeFactory> factory) {

    auto myClass = factory->createClass("MyTestClass", Unit::ABSTRACT, Unit::PUBLIC);



    myClass->add(
        factory->createMethod("testFunc1", "void", Unit::FINAL | Unit::STATIC),
        Unit::PUBLIC
        );


    myClass->add(
        factory->createMethod("testFunc2", "void", Unit::VIRTUAL | Unit::CONST),
        Unit::PROTECTED
        );


    myClass->add(
        factory->createMethod("testFunc3", "void", Unit::ABSTRACT),
        Unit::PRIVATE
        );


    auto methodWithBody = factory->createMethod("testFunc4", "void", 0);
    methodWithBody->add(
        factory->createPrintOperator("Hello from testFunc4!")
        );
    myClass->add(methodWithBody, Unit::PUBLIC);
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
