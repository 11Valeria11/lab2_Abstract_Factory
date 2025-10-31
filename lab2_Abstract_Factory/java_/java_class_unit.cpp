#include "java\java_class_unit.h"

const std::vector<std::string> JavaClassUnit::ACCESS_MODIFIERS = {
    "public", "protected", "private"
};

JavaClassUnit::JavaClassUnit(const std::string& name, Flags flags, Flags accessModifier)
    : m_name(name), m_flags(flags), m_accessModifier(accessModifier) {}

void JavaClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    m_fields.push_back({unit, flags});
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    //std::string result;
    if (m_accessModifier < ACCESS_MODIFIERS.size()) {
        result += ACCESS_MODIFIERS[m_accessModifier] + " ";
    }
    if (m_flags & Unit::ABSTRACT) result += "abstract ";
    else if (m_flags & Unit::FINAL) result += "final ";

    result += "class " + m_name + " {\n";

    for (const auto& f : m_fields){
        std::string modifier = "private"; // Default
        if (f.second < ACCESS_MODIFIERS.size()) {
            modifier = ACCESS_MODIFIERS[f.second];
        }
        result += generateShift(level + 1) + modifier + " " + f.first->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
