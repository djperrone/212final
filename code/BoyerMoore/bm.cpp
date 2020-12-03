#include "bm.h"
#include <map>

BoyerMoore::BoyerMoore(std::string filename, std::string pattern)
    :text(filename),key(pattern) {
    makeBadTable(key);
    makeGoodArrayL(key);
    makeGoodArrayH(key);
}

void BoyerMoore::makeBadTable(const std::string& key){
    //given a mismatched character from the text, the shift distance that would align the rightmost
    //instance of that character in the pattern with the mismatched character in the text.

    //push values into the bad char table
    for(int i = 0; i < key.length(); i++){
        badCharacterTable[key[i]] = key.length() - 1- i;
    }

    ///print map//////
    // std::map<char, int>::iterator it;

    // std::cout << "\n-----------bad--------------------\n";
    // for (it = badCharacterTable.begin(); it != badCharacterTable.end(); it++){
    //     std::cout<<it->first<<' '<<it->second<<std::endl;
    // }
    // std::cout << "-------------------------------\n";

}

void BoyerMoore::makeGoodArrayH(const std::string& key){
    //initialize array to store shift values
    goodArrayH.reserve(key.length());

    std::string suffix;
    std::string prefix;

    int shift;

    //for every substring starting at back of key
    for(int i = 1; i < key.length(); i++){
        //find the last occurence of substring before its matching suffix
        //make suffix and prefix substrings
        suffix = key.substr(key.length() - i, key.length());
        prefix = key.substr(0, i);

        //store value as shift
        //length of longest suffix that is prefix if one exists otherwise H[i] = 0
        if(suffix == prefix){
            shift = suffix.length();
        }
        //no match found use previous longest suffix
        else{
            //for suffix length one longest found is 0
            if(i == 1){
                shift = 0;
            }
            //else longest suffix is to the right
            else{
                shift = goodArrayH[key.length() - i + 1];
            }
        }
        //push into array for corresponding i
        goodArrayH[key.length() - i] = shift;
    }

    //for the 0 case ie a match
    goodArrayH[0] = goodArrayH[1];

    /////print table///////
    // std::cout << "\n-----------goodh--------------------\n";
    // for (int i = 0; i < key.length(); i++) {
    //     std::cout <<goodArrayH[i] << std::endl;

    // }
    // std::cout << "-------------------------------\n";
}

void BoyerMoore::makeGoodArrayL(const std::string& key){
    //initialize array to store shift values
    goodArrayL.reserve(key.length());

    std::string suffix;
    std::string prefix;

    int shift;

    // for every substring starting at back of key
    for(int i = 1; i < key.length(); i++){
        //find the last occurence of substring before its matching suffix
        //make suffix and prefix substrings
        suffix = key.substr(key.length() - i, key.length());
        prefix = key.substr(0, key.length() - 1);

        //store value as shift
        shift = prefix.rfind(suffix);

        //while suffix found and out of bounds and suffix bad keep looking
        while(shift != std::string::npos && (shift - 1 < 0 || key[shift - 1] == key[key.length() - i - 1])){
            prefix = key.substr(0, shift + suffix.length() - 1);
            shift = prefix.rfind(suffix);
        }

        //if we didnt find one
        if(shift == std::string::npos){
            shift = 0;
        }
        //if we found one
        else {
            shift = shift + suffix.length() - 1;
        }
        //push into array for corresponding i (go where the mismatch is)
        goodArrayL[key.length() - i] = shift;
    }

    goodArrayL[0] = 0;

    /////print table///////
    // std::cout << "\n-----------goodL--------------------\n";
    // for (int i = 0; i < key.length(); i++) {
    //     std::cout <<goodArrayL[i] << std::endl;

    // }
    // std::cout << "-------------------------------\n";
}

int BoyerMoore::getShift(int mismatchIndex, char character){
    //return max of the good/bad table shifts
    int badShift = getBadCharShift(character);
    int goodShift = getGoodSuffixShift(mismatchIndex);

    // std::cout<<"good shift: "<<goodShift<<" bad shift:"<<badShift<<std::endl;

    if (badShift > goodShift){
        return badShift;
    }
    else{
        return goodShift;
    }
}

int BoyerMoore::getBadCharShift(char letter){
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

int BoyerMoore::getGoodSuffixShift(int mismatchIndex){
    //get shift from good suffix array according to slide 20

    if(mismatchIndex == key.length() - 1){
        return 1;
    }

    int l = goodArrayL[mismatchIndex + 1];
    int h = goodArrayH[mismatchIndex];

    if(l > 0){
        return key.length() - l - 1;
    }
    else{
        return key.length() - h;
    }

}

void BoyerMoore::bm(const std::string& text, const std::string& key){
    //int value for alignment this is the index of the character in text matched up with the last charcter of the key
    int align = key.length() - 1;

    //loop through while the pattern is longer than the text
    while(align < text.length()){
        //iterator
        int i = key.length() - 1;

        //compare key to aligned text
        while(key[i] == text[align - key.length() + i + 1]){
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
            align = align + key.length() - goodArrayH[1] - 1;
        }
        //if there isnt a match get a shift
        else{
            align = align + getShift(i, text[align - key.length() + i + 1]);
        }
    }
}