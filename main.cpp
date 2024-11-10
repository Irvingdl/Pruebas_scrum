// main.cpp

#include "search_engine.h"
#include <filesystem>
#include <chrono>

void processDocuments(const std::string &inputDir, Dictionary &dictionary) {
    int docId = 0;
    for (const auto &file : std::filesystem::directory_iterator(inputDir)) {
        std::ifstream inFile(file.path());
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        auto tokens = Tokenizer::tokenize(content);
        
        for (const auto &token : tokens) {
            dictionary.addToken(token, docId);
        }
        docId++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: tokenize input-dir output-dir\n";
        return 1;
    }

    std::string inputDir = argv[1];
    std::string outputDir = argv[2];
    
    Dictionary dictionary;
    auto start = std::chrono::high_resolution_clock::now();

    processDocuments(inputDir, dictionary);
    dictionary.removeLowFrequencyTokens(2); // Threshold de ejemplo para eliminar tokens de baja frecuencia
    dictionary.saveToHashTable(outputDir + "/dictionary.txt");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    Logger::logExecutionTime("Tokenization and Indexing", duration.count());
    
    std::cout << "Tokenization and indexing completed in " << duration.count() << " ms\n";

    return 0;
}
