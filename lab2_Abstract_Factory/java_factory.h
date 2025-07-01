#ifndef JAVA_FACTORY_H
#define JAVA_FACTORY_H

#include "factory.h"

class JavaFactory : public ICodeFactory {

public:
    std::shared_ptr<Unit> createClass(const std::string& name) override;
    std::shared_ptr<Unit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) override;
    std::shared_ptr<Unit> createPrintOperator(const std::string& text) override;
};

#endif // JAVA_FACTORY_H
