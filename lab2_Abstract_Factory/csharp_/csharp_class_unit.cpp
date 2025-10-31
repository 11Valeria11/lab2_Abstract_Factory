#include "csharp\csharp_class_unit.h"

const std::vector<std::string> CSharpClassUnit::ACCESS_MODIFIERS = {
    "public", "protected", "private", "internal", "protected internal", "private protected"
};

CSharpClassUnit::CSharpClassUnit(const std::string& name, Flags flags, Flags accessModifier)
    : m_name(name), m_flags(flags), m_accessModifier(accessModifier) {}

void CSharpClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    m_fields.push_back({unit, flags});
}

std::string CSharpClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    if (m_accessModifier < ACCESS_MODIFIERS.size()) {
        result += ACCESS_MODIFIERS[m_accessModifier] + " ";
    }
    if (m_flags & Unit::ABSTRACT) {
        result += "abstract ";
    }
    result += "class " + m_name + " {\n";

    for (const auto& f : m_fields){
        std::string modifier = "private";
        if (f.second < ACCESS_MODIFIERS.size()) {
            modifier = ACCESS_MODIFIERS[f.second];
        }
        result += generateShift(level + 1) + modifier + " " + f.first->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
