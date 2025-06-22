#pragma once

#include "unit.h"

class ClassUnit : public Unit {
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

public:
    explicit ClassUnit(const std::string& name) : m_name(name) {
        m_fields.resize(3); // 3 - количество модификаторов доступа
    }

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override {
        int accessModifier = PRIVATE;
        if (flags < 3) {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + "class " + m_name + " {\n";

        for (size_t i = 0; i < 3; ++i) {
            if (m_fields[i].empty()) {
                continue;
            }
            result += ACCESS_MODIFIERS[i] + ":\n";
            for (const auto& f : m_fields[i]) {
                result += f->compile(level + 1);
            }
        }

        result += generateShift(level) + "};\n";
        return result;
    }

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    // Статический член из исходного кода
    static const std::vector<std::string> ACCESS_MODIFIERS;
};

// Инициализация статического члена
const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};
