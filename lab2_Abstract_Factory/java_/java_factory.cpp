#include "java\java_factory.h"
#include "java\java_class_unit.h"
#include "java\java_method_unit.h"
#include "java\java_print_operator_unit.h"

std::shared_ptr<Unit> JavaFactory::createClass(const std::string& name, Unit::Flags flags, Unit::Flags accessModifier) const {
    return std::make_shared<JavaClassUnit>(name, flags, accessModifier);
}
std::shared_ptr<Unit> JavaFactory::createMethod(const std::string& name, const std::string& returnType, unsigned int flags) const {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}
std::shared_ptr<Unit> JavaFactory::createPrintOperator(const std::string& text) const {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
