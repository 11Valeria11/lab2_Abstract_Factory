#ifndef JAVA_CLASS_UNIT_H
#define JAVA_CLASS_UNIT_H

#include "unit.h"

class JavaClassUnit : public Unit {

public:
    static const std::vector<std::string> ACCESS_MODIFIERS;
    JavaClassUnit(const std::string& name, Flags flags, Flags accessModifier);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    Flags m_flags;
    Flags m_accessModifier;
    using Field = std::pair<std::shared_ptr<Unit>, Flags>;
    std::vector<Field> m_fields;
};

#endif // JAVA_CLASS_UNIT_H
