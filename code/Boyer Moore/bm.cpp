#include "bm.h"
#include <map>

BoyerMoore::BoyerMoore(std::string filename, std::string pattern)
    :text(filename),key(pattern) {
    makeBadTable(key);
    makeGoodArray(key);
    goodSuffixShift(key.length());
    borderArray(key.length());
}

void BoyerMoore::makeBadTable(const std::string& key){
    //given a mismatched character from the text, the shift distance that would align the rightmost
    //instance of that character in the pattern with the mismatched character in the text.

    //push values into the bad char table
    for(int i = 0; i < key.length(); i++){
        badCharacterTable[key[i]] = key.length() - 1- i;
    }

}

int gsPreproccess1(const std::string& key){
    //The matching suffix is a border of a suffix of the pattern. We have to determine our borders.
    //We do this by checking if an already existing border can be made longer. Case one handles when a shorter suffix has same border
    //a border is a substring whihc has the same prefex and suffix
    //////////TODO//////////

    int i = key.length();
    int j = key.length() + 1;

    //the last letter has no border since we are at the end of the pattern so we set the border array for the last letter
    //gets set to the length of the pattern plus one
    borderArray[i] = j;

    //loop through while i is bigger than 0 and decrement i. This reads the pattern right to left and
    //looks for a border
    while(i > 0){
        //check if the adjacent letters are equal. If they are nor equal the shift value becomes
        
    }


}

int gsPreproccess2(const std::string& key){
    //a part of the matching suffix of the pattern occurs at the beginning of the pattern
    //////////TODO//////////
}

void BoyerMoore::makeGoodArray(const std::string& key){
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
    //get shift from good suffix array
    ///////TODO////////



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