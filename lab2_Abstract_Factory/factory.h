#ifndef ICODEFACTORY_H
#define ICODEFACTORY_H

#include <memory>
#include <string>

class Unit; //предварительное объявление

class ICodeFactory {
public:
    virtual ~ICodeFactory() = default;
    virtual std::shared_ptr<Unit> createClass(const std::string& name) = 0;
    virtual std::shared_ptr<Unit> createMethod(const std::string& name, const std::string& returnType, unsigned int flags) = 0;
    virtual std::shared_ptr<Unit> createPrintOperator(const std::string& text) = 0;
};

#endif // ICODEFACTORY_H
