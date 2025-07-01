#include "csharp_class_unit.h"

CSharpClassUnit::CSharpClassUnit(const std::string& name) : m_name(name) {}
void CSharpClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    m_fields.push_back({unit, flags});
}

std::string CSharpClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "public class " + m_name + "\n" + generateShift(level) + "{\n";
    for (const auto& f : m_fields){
        result += f.first->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
