#ifndef CPP_CLASS_UNIT_H
#define CPP_CLASS_UNIT_H

#include "unit.h"

class CppClassUnit : public Unit {
public:

    CppClassUnit(const std::string& name, Flags flags, Flags accessModifier);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    Flags m_flags;
    using Fields = std::pair<std::shared_ptr<Unit>, Flags>;
    std::vector<Fields> m_fields;
};
#endif // CPP_CLASS_UNIT_H
