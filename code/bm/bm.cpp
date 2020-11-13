#include "bm.h"
#include <map>

BoyerMoore::BoyerMoore(std::string filename, std::string pattern)
    :fname(filename),key(pattern) {
    makeBadTable(key);
    makeGoodTable(key);
}

void BoyerMoore::makeBadTable(const std::string& key){
    //given a mismatched character from the text, the shift distance that would align the rightmost
    //instance of that character in the pattern with the mismatched character in the text.

    //push values into the bad char table
    for(int i = 0; i < key.length(); i++){
        badCharacterTable[key[i]] = key.length() - 1- i;
    }

}

void BoyerMoore::makeGoodTable(const std::string& key){
    //given an index in the pattern, the smallest shift distance that would align a prefix of the pattern
    //with the largest suffix of the pattern that has been matched so far in the text.

    //////////TODO//////////

}

int BoyerMoore::getShift(const std::string& letter){
    //return max of the good/bad table shifts
    int badShift = getBadCharShift(letter);
    int goodShift = getGoodSuffixShift(letter);

    if (badShift > goodShift){
        return badShift;
    }
    else{
        return goodShift;
    }
}

int BoyerMoore::getBadCharShift(const std::string& letter){
    //get shift from bad tabe
    std::map<char, int>::iterator shift = badCharacterTable.find(letter);

    //if the element isnt in the table ie other
    if(shift == badCharacterTable.end()){
        return key.length();
    }
    else{
        return shift->second;
    }

}

int BoyerMoore::getGoodSuffixShift(const std::string& letter){
    //get shift from good tabe
    std::map<char, int>::iterator shift = goodSuffixTable.find(letter);

    //if the element isnt in the table ie other
    if(shift == goodSuffixTable.end()){
        return //////////TODO//////////
    }
    else{
        return shift->second;
    }

}

void BoyerMoore::bm(const std::string& text, const std::string& key){
    //int value for alignment
    int align = key.length() - 1;

    //loop through while the pattern is longer than the text
    while(align < text.length()){
        //iterator
        int i = key.length() - 1;

        //compare key to aligned text
        while(key[i] == text[align]){
            //if we got through whole pattern we found a match
            if(i == 0){
                //print where we found a pattern
                std::cout<<"Pattern found at index "<<align-(key.length()-1)<<std::endl;
                break;
            }
            //decrement i
            i--;
        }

        //if i is 0 make a shift since we want more than just the first occurence
        if (i == 0){
            align = align + key.length();
        }
        //if there isnt a match get a shift
        else{
            align = align + getShift(key[i]);
        }
    }
}
