#include "csharp\csharp_method_unit.h"

CSharpMethodUnit::CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void CSharpMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags) { m_body.push_back(unit); }

std::string CSharpMethodUnit::compile(unsigned int level) const {
//    std::string result = generateShift(level);
    std::string result;
    if (m_flags & STATIC) {
        result += "static ";}
    else if (m_flags & VIRTUAL) {
        result += "virtual ";
    }
    else if (m_flags & ABSTRACT) {
        result += "abstract ";
    }
    result += m_returnType + " " + m_name + "()\n" + generateShift(level) + "{\n";
    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
