#ifndef JAVA_PRINT_OPERATOR_UNIT_H
#define JAVA_PRINT_OPERATOR_UNIT_H

#include "unit.h"

class JavaPrintOperatorUnit : public Unit {

public:
    explicit JavaPrintOperatorUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif // JAVA_PRINT_OPERATOR_UNIT_H
