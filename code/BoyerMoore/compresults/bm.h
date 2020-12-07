#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "../../tools/timer.h"
#include "../../tools/comptool.h"

class BoyerMoore
{
    private:
        //std::string text, key;
        std::map<char, int> badCharacterTable;
        std::vector<int> goodArrayL;
        std::vector<int> goodArrayH;
        int lineNum = 1;
        int patterns = 0;

        std::string fname,m_string,key;

        int getShift(int mismatchIndex, char character);
        int getBadCharShift(char letter);
        int getGoodSuffixShift(int mismatchIndex);

        void makeBadTable(const std::string& key);
        void makeGoodArrayL(const std::string& key);
        void makeGoodArrayH(const std::string& key);

    public:
        BoyerMoore(std::string filename, std::string pattern);
        void bm(CompTool& tool);

        void concatStr();
        void Strip(std::string& line);

        inline void clearStr(){m_string.clear();}

};