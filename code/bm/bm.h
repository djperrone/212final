#include <iostream>
#include <string>
#include <fstream>
#include <map>

Class BoyerMoore
{
    private:
        std::string fname, key;
        std::map<char, int> badCharacterTable
        //may have to make this an array
        std::map<char, int> goodSuffixTable
        int lineNum = 1;

        int getShift(const std::string& letter);
        int getBadCharShift(const std::string& letter);
        int getGoodSuffixShift(const std::string& letter);

        void makeBadTable(const std::string& key);
        void makeGoodTable(const std::string& key);

    public:
        BoyerMoore(std::string filename, std::string pattern);
        void bm(const std::string& text, const std::string& key);

};
