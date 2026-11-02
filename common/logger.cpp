#include "logger.h"
#include <filesystem>
#include <chrono>
#include <format>

Logger& Logger::getInstance(const std::string& filename) {
    static Logger instance(filename);
    return instance;
}

Logger::Logger(const std::string& filename) {
    currentLevel = Level::DEBUG;

    auto folder = std::filesystem::path(filename).parent_path();
    if (!folder.empty()) {
        std::filesystem::create_directories(folder);
    }
    file.open(filename);
}

void Logger::log(const std::string& message, int level) {
    if (level > currentLevel) {
        return;
    }
    std::string name;

    if (level == Level::ERROR) {
        name = "ERROR";
    }
    else if (level == Level::WARNING) {
        name = "WARNING";
    }
    else if (level == Level::INFO) {
        name = "INFO";
    }
    else if (level == Level::DEBUG) {
        name = "DEBUG";
    }

    auto now = std::chrono::floor<std::chrono::seconds>(
        std::chrono::system_clock::now()
    );
    std::string time = std::format("{:%Y-%m-%d %H:%M:%S}", now);

    file << "[" << time << "] [" << name << "] "
         << message << '\n';
}

void Logger::setLevel(int level) {
    currentLevel = level;
}

void Logger::setFile(const std::string& filename) {
    file.close();
    auto folder = std::filesystem::path(filename).parent_path();
    if (!folder.empty()) {
        std::filesystem::create_directories(folder);
    }
    file.open(filename);
}

Logger::~Logger() {
    file.close();
}



