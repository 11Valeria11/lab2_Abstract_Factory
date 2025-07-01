#include "cpp_class_unit.h"

CppClassUnit::CppClassUnit(const std::string& name) : m_name(name) {
    m_fields.resize(3);
}

void CppClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = PRIVATE;
    if (flags < 3) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string CppClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";
    static const std::vector<std::string> access_modifiers = { "public", "protected", "private" };

    for (size_t i = 0; i < 3; ++i) {
        if (m_fields[i].empty()) {
            continue;
        }
        result += access_modifiers[i] + ":\n";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 1);
        }
    }
    result += generateShift(level) + "};\n";
    return result;
}
