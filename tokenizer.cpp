// tokenizer.cpp

#include "search_engine.h"
#include <sstream>
#include <algorithm>

std::vector<std::string> Tokenizer::tokenize(const std::string &text) {
    std::vector<std::string> tokens;
    std::istringstream stream(text);
    std::string token;
    while (stream >> token) {
        // Procesamiento de tokens, eliminando caracteres especiales
        token.erase(remove_if(token.begin(), token.end(), ispunct), token.end());
        std::transform(token.begin(), token.end(), token.begin(), ::tolower);
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}
