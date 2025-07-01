#include "cpp_factory.h"
#include "cpp_class_unit.h"
#include "cpp_method_unit.h"
#include "cpp_print_operator_unit.h"

std::shared_ptr<Unit> CppFactory::createClass(const std::string& name) {
    return std::make_shared<CppClassUnit>(name);
}

std::shared_ptr<Unit> CppFactory::createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> CppFactory::createPrintOperator(const std::string& text) {
    return std::make_shared<CppPrintOperatorUnit>(text);
}
