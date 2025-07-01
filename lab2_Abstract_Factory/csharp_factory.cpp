#include "csharp_factory.h"
#include "csharp_class_unit.h"
#include "csharp_method_unit.h"
#include "csharp_print_operator_unit.h"

std::shared_ptr<Unit> CSharpFactory::createClass(const std::string& name) {
    return std::make_shared<CSharpClassUnit>(name);
}
std::shared_ptr<Unit> CSharpFactory::createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}
std::shared_ptr<Unit> CSharpFactory::createPrintOperator(const std::string& text) {
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}
