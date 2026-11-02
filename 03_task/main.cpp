#include <string>
#include "logger.h"
#include "wrapper.h"

int main() {
    Logger& logger = Logger::getInstance(
        std::string(LOG_DIR) + "/task03_a.log"
    );

    {
        WrapperA w("hello");
    }

    logger.setFile(std::string(LOG_DIR) + "/task03_b.log");

    {
        WrapperB w("hello");
    }
}
