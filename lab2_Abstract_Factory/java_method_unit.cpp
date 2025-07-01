#include "java_method_unit.h"

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : m_name(name), m_returnType(returnType), m_flags(flags) {}

void JavaMethodUnit::add(const std::shared_ptr<Unit>& unit, Flags) {
    m_body.push_back(unit);
}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "public ";
    if (m_flags & STATIC) {
        result += "static ";
    }
    if (m_flags & FINAL) {
        result += "final ";
    }
    else if (m_flags & ABSTRACT) {
        result += "abstract ";
    }
    result += m_returnType + " " + m_name + "() {\n";
    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
