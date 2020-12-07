#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "../../tools/timer.h"

class BoyerMoore
{
    private:
        //std::string text, key;
        std::map<char, int> badCharacterTable;
        std::vector<int> goodArrayL;
        std::vector<int> goodArrayH;
        int lineNum = 1;
        int patterns = 0;


        int getShift(int mismatchIndex, char character);
        int getBadCharShift(char letter);
        int getGoodSuffixShift(int mismatchIndex);

        void makeBadTable(const std::string& key);
        void makeGoodArrayL(const std::string& key);
        void makeGoodArrayH(const std::string& key);

    public:
        BoyerMoore(std::string filename, std::string pattern);
        void bm(Timer& timer);

        void concatStr();
        void Strip(std::string& line);

        inline void clearStr(){m_string.clear();}

        std::string fname,m_string,key;
};