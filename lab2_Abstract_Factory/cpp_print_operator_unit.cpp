#include "cpp_print_operator_unit.h"

CppPrintOperatorUnit::CppPrintOperatorUnit(const std::string& text) : m_text(text) {}

std::string CppPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "printf(\"" + m_text + "\\n\");\n";
}
