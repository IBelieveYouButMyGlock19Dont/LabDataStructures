#include <iostream>
#include <string>
#include "logger.h"
#include "tracked_string.h"

int main() {
    auto& logger = Logger::getInstance(std::string(LOG_DIR) + "/task05.log"
    );

    {
        TrackedString a("hello");
        TrackedString b("world");
        std::cout << a << " " << b << std::endl;
        std::cout << (a == b) << " " << (a != b) << " " << (a < b) << std::endl;
        auto c=a+b;
        std::cout << c << std::endl;
    }
}
