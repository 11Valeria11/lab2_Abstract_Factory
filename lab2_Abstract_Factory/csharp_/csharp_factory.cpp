#include "csharp\csharp_factory.h"
#include "csharp\csharp_class_unit.h"
#include "csharp\csharp_method_unit.h"
#include "csharp\csharp_print_operator_unit.h"

std::shared_ptr<Unit> CSharpFactory::createClass(const std::string& name, Unit::Flags flags, Unit::Flags accessModifier) const {
    return std::make_shared<CSharpClassUnit>(name, flags, accessModifier);
}
std::shared_ptr<Unit> CSharpFactory::createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}
std::shared_ptr<Unit> CSharpFactory::createPrintOperator(const std::string& text) const {
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}
