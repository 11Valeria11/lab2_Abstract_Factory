#ifndef CPP_FACTORY_H
#define CPP_FACTORY_H

#include "factory.h"

class CppFactory : public ICodeFactory {

public:
    std::shared_ptr<Unit> createClass(const std::string& name, Unit::Flags flags, Unit::Flags accessModifier) const override;
    std::shared_ptr<Unit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;
    std::shared_ptr<Unit> createPrintOperator(const std::string& text) const override;
};

#endif // CPP_FACTORY_H
