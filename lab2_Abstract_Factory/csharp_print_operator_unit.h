#ifndef CSHARP_PRINT_OPERATOR_UNIT_H
#define CSHARP_PRINT_OPERATOR_UNIT_H

#include "unit.h"

class CSharpPrintOperatorUnit : public Unit {

public:
    explicit CSharpPrintOperatorUnit(const std::string& text);
    std::string compile(unsigned int level = 0) const override;

private:
    std::string m_text;
};

#endif // CSHARP_PRINT_OPERATOR_UNIT_H
