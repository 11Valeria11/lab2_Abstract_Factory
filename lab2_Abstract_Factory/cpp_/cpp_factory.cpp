#include "cpp\cpp_factory.h"
#include "cpp\cpp_class_unit.h"
#include "cpp\cpp_method_unit.h"
#include "cpp\cpp_print_operator_unit.h"

std::shared_ptr<Unit> CppFactory::createClass(const std::string& name, Unit::Flags flags, Unit::Flags accessModifier) const {
    return std::make_shared<CppClassUnit>(name, flags, accessModifier);
}

std::shared_ptr<Unit> CppFactory::createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<Unit> CppFactory::createPrintOperator(const std::string& text) const {
    return std::make_shared<CppPrintOperatorUnit>(text);
}
