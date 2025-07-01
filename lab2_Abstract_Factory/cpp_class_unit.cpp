#include "cpp_class_unit.h"
#include <map>

CppClassUnit::CppClassUnit(const std::string& name) : m_name(name) {}

void CppClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    m_fields.push_back({unit, flags});
}

std::string CppClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    std::map<Flags, std::vector<std::shared_ptr<Unit>>> groupedFields;
    for (const auto& f : m_fields) {
        groupedFields[f.second].push_back(f.first);
    }

    const std::vector<Flags> accessOrder = {PUBLIC, PROTECTED, PRIVATE};
    const std::map<Flags, std::string> accessNames = {
        {PUBLIC, "public"}, {PROTECTED, "protected"}, {PRIVATE, "private"}
    };

    for (Flags access : accessOrder) {
        if (groupedFields.find(access) == groupedFields.end()) {
            continue;
        }
        result += generateShift(level) + accessNames.at(access) + ":\n";
        for (const auto& field : groupedFields[access]) {
            result += field->compile(level + 1);
        }
    }

    result += generateShift(level) + "};\n";
    return result;
}
