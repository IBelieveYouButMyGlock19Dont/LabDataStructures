#ifndef LAB03_WRAPPER_H
#define LAB03_WRAPPER_H

#include <string>
#include "tracked_string.h"

class WrapperA {
private:
    TrackedString str;
public:
    WrapperA(const std::string& s);
};

class WrapperB {
private:
    TrackedString str;
public:
    WrapperB(const std::string& s);
};

#endif //LAB03_WRAPPER_H
