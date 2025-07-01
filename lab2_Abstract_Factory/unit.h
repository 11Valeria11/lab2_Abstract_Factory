#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Unit {
public:
    using Flags = unsigned int;
    //куда они отсюда делись????
    enum Modifier {
        STATIC = 1 << 0,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
    };

    virtual ~Unit() = default;

    virtual void add(const std::shared_ptr<Unit>&, Flags = 0);// ТОЛЬКО ОБЪЯВЛЕНИЕ

    virtual std::string compile(unsigned int level = 0) const = 0;

protected:
    // ТОЛЬКО ОБЪЯВЛЕНИЕ
    virtual std::string generateShift(unsigned int level) const;
};
#endif //UNIT_H
