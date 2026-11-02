#include "tracked_string.h"
#include "logger.h"
#include <format>

int TrackedString::totalCreated = 0;
int TrackedString::aliveCount = 0;

TrackedString::TrackedString() : TrackedString(std::string("")) {
    Logger::getInstance().log(std::format("[default ctor] id={} this={}",id, static_cast<const void*>(this)),Logger::Level::INFO
    );
}

TrackedString::TrackedString(const std::string& s) {
    value = s;
    id = ++totalCreated;
    aliveCount++;

    Logger::getInstance().log(std::format("[string ctor] id={} this={} value=\"{}\" alive={}",id, static_cast<const void*>(this), value, aliveCount),Logger::Level::INFO
    );
}

TrackedString::TrackedString(const char* s): TrackedString(std::string(s)) {
    Logger::getInstance().log(std::format("[cstr ctor] id={} this={}",id, static_cast<const void*>(this)),Logger::Level::INFO
    );
}

TrackedString::TrackedString(const TrackedString& other) {
    value = other.value;
    id = ++totalCreated;
    aliveCount++;

    Logger::getInstance().log(std::format("[copy ctor] id={} this={} from id={} alive={}",id, static_cast<const void*>(this), other.id, aliveCount),Logger::Level::INFO
    );
}

TrackedString& TrackedString::operator=(const TrackedString& other) {
    value = other.value;

    Logger::getInstance().log(std::format("[copy assign] id={} this={} from id={}",id, static_cast<const void*>(this), other.id),Logger::Level::INFO
    );
    return *this;
}

int TrackedString::getTotalCreated() {
    return totalCreated;
}

int TrackedString::getAliveCount() {
    return aliveCount;
}

TrackedString::~TrackedString() {
    aliveCount--;

    Logger::getInstance().log(std::format("[dtor] id={} this={} alive={}",id, static_cast<const void*>(this), aliveCount),Logger::Level::INFO
    );
}

std::ostream& operator<<(std::ostream& os, const TrackedString& a) {
    Logger::getInstance().log("[operator <<]", Logger::Level::INFO);
    os << a.value;
    return os;
}

bool operator==(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator ==]", Logger::Level::INFO);
    return a.value==b.value;
}

bool operator!=(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator !=]", Logger::Level::INFO);
    return a.value!=b.value;
}

bool operator<(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator <]", Logger::Level::INFO);
    return a.value<b.value;
}

TrackedString operator+(const TrackedString& a, const TrackedString& b) {
    Logger::getInstance().log("[operator +]", Logger::Level::INFO);
    return TrackedString(a.value+b.value);
}
