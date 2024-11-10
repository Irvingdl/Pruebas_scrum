// logger.cpp

#include "search_engine.h"

void Logger::logExecutionTime(const std::string &action, double duration) {
    std::ofstream logFile("a2_matricula.txt", std::ios::app);
    logFile << action << ": " << duration << " ms\n";
    logFile.close();
}
