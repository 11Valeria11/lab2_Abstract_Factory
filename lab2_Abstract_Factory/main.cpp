#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

// Функция, жестко привязанная к C++
std::string generateProgram() {
    ClassUnit myClass("MyClass");

    myClass.add(
        std::make_shared<MethodUnit>("testFunc1", "void", 0),
        ClassUnit::PUBLIC
        );

    myClass.add(
        std::make_shared<MethodUnit>("testFunc2", "void", MethodUnit::STATIC),
        ClassUnit::PRIVATE
        );

    myClass.add(
        std::make_shared<MethodUnit>("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST),
        ClassUnit::PUBLIC
        );

    auto method = std::make_shared<MethodUnit>("testFunc4", "void", MethodUnit::STATIC);
    method->add(
        std::make_shared<PrintOperatorUnit>("Hello, world!")
        );
    myClass.add(method, ClassUnit::PROTECTED);

    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    std::cout << "\nPress Enter to exit..."; // Сообщение для пользователя
    std::cin.get(); // Ожидание нажатия клавиши Enter
    return 0;
}
