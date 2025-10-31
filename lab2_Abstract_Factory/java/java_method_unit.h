#ifndef JAVA_METHOD_UNIT_H
#define JAVA_METHOD_UNIT_H

#include "unit.h"

class JavaMethodUnit : public Unit {

public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add(const std::shared_ptr<Unit>& unit, Flags = 0) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // JAVA_METHOD_UNIT_H
