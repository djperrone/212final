#include "bm.h"


int main(int argc, char** argv)
{
    //this test case works//
    // std::string text =    "leading TEXT cXXXcXXXbXXXcXXX rest of the TEXT";
    // std::string pattern = "cXXXcXXXbXXXcXXX";

    //this test case works//
    // std::string text =    "This is a simple example";
    // std::string pattern = "example";

    //this test case works//
    // std::string text =    "Does it find two find patterns";
    // std::string pattern = "find";

    //this test case fails//
    // std::string text =    "GTTATAGCTGATCGCGGCGTAGCGGCGAA";
    // std::string pattern = "GTAGCGGCG";

    //this test case works//
    // std::string text =    "LEADING TEXT ABCXXXABC TRAILING TEXT";
    // std::string pattern = "ABCXXXABC";

    std::string text =    "ABBCBCADBAAABBBDC";
    std::string pattern = "CADB";


    BoyerMoore bmSearch(text, pattern);
    bmSearch.bm(text, pattern);

}