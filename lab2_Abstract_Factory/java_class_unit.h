#ifndef JAVA_CLASS_UNIT_H
#define JAVA_CLASS_UNIT_H

#include "unit.h"

class JavaClassUnit : public Unit {

public:
    explicit JavaClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override;
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_name;
    using Field = std::pair<std::shared_ptr<Unit>, Flags>;
    std::vector<Field> m_fields;
};

#endif // JAVA_CLASS_UNIT_H
