#include <iostream>
#include <string>
#include <fstream>
#include <map>

Class BoyerMoore
{
    private:
        std::string text, key;
        std::map<char, int> badCharacterTable;
        std::vector<int> goodSuffixShift;
        std::vector<int> borderArray;
        int lineNum = 1;

        int getShift(const std::string& letter);
        int getBadCharShift(const std::string& letter);
        int gsPreproccess1(const std::string& key);
        int gsPreproccess2(const std::string& key);
        int getGoodSuffixShift(const std::string& letter);

        void makeBadTable(const std::string& key);
        void makeGoodArray(const std::string& key);

    public:
        BoyerMoore(std::string filename, std::string pattern);
        void bm(const std::string& text, const std::string& key);

};