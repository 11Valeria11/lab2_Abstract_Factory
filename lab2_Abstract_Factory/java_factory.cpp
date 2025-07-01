#include "java_factory.h"
#include "java_class_unit.h"
#include "java_method_unit.h"
#include "java_print_operator_unit.h"

std::shared_ptr<Unit> JavaFactory::createClass(const std::string& name) {
    return std::make_shared<JavaClassUnit>(name);
}
std::shared_ptr<Unit> JavaFactory::createMethod(const std::string& name, const std::string& returnType, unsigned int flags) {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}
std::shared_ptr<Unit> JavaFactory::createPrintOperator(const std::string& text) {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
