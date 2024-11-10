// dictionary.cpp

#include "search_engine.h"

void Dictionary::addToken(const std::string &token, int docId) {
    tokenDict[token].frequency++;
    tokenDict[token].postingList.push_back(docId);
}

void Dictionary::removeLowFrequencyTokens(int threshold) {
    for (auto it = tokenDict.begin(); it != tokenDict.end(); ) {
        if (it->second.frequency < threshold) {
            it = tokenDict.erase(it);
        } else {
            ++it;
        }
    }
}

void Dictionary::saveToHashTable(const std::string &filename) {
    std::ofstream outFile(filename);
    for (const auto &entry : tokenDict) {
        outFile << entry.first << " " << entry.second.frequency << "\n";
        for (int docId : entry.second.postingList) {
            outFile << docId << " ";
        }
        outFile << "\n";
    }
    outFile.close();
}
