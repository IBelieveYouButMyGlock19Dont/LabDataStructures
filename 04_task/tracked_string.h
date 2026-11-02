#ifndef LAB03_TRACKED_STRING_H
#define LAB03_TRACKED_STRING_H

#include <string>

class TrackedString {
private:
    std::string value;
    int id;
    static int totalCreated;
    static int aliveCount;
public:
    TrackedString();
    TrackedString(const std::string& s);
    TrackedString(const char* s);
    TrackedString(const TrackedString& other);
    TrackedString& operator=(const TrackedString& other);
    ~TrackedString();

    static int getTotalCreated();
    static int getAliveCount();
};

#endif
