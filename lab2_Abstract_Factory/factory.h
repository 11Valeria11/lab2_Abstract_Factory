#ifndef ICODEFACTORY_H
#define ICODEFACTORY_H

#include <memory>
#include <string>
#include "unit.h"


class ICodeFactory {
public:
    virtual ~ICodeFactory() = default;
    virtual std::shared_ptr<Unit> createClass(const std::string& name,Unit::Flags flags,Unit::Flags accessModifier) const = 0;
    virtual std::shared_ptr<Unit> createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const= 0;
    virtual std::shared_ptr<Unit> createPrintOperator(const std::string& text) const= 0;
};

#endif // ICODEFACTORY_H
