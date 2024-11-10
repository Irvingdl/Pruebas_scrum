// search_engine.h

#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>

struct TokenData {
    int frequency;
    std::vector<int> postingList;
};

class Tokenizer {
public:
    static std::vector<std::string> tokenize(const std::string &text);
};

class Dictionary {
    std::unordered_map<std::string, TokenData> tokenDict;
public:
    void addToken(const std::string &token, int docId);
    void removeLowFrequencyTokens(int threshold);
    void saveToHashTable(const std::string &filename);
};

class Logger {
public:
    static void logExecutionTime(const std::string &action, double duration);
};

#endif // SEARCH_ENGINE_H
