#pragma once

#include "unit.h"

class CppPrintOperatorUnit : public Unit {
public:
    explicit CppPrintOperatorUnit(const std::string& text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const override {
        // Экранируем кавычки и обратные слэши для printf
        std::string escaped_text;
        for (char c : m_text) {
            if (c == '\"' || c == '\\') {
                escaped_text += '\\';
            }
            escaped_text += c;
        }
        return generateShift(level) + "printf(\"" + escaped_text + "\\n\");\n";
    }

private:
    std::string m_text;
};
