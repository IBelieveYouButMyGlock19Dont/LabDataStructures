#include "wrapper.h"

WrapperA::WrapperA(const std::string& s) {
    str=TrackedString(s);
}

WrapperB::WrapperB(const std::string& s): str(s) {
}

