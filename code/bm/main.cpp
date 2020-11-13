#include "bm.h"


int main(int argc, char** argv)
{
    std::string text = "landbeyond.txt";
    std::string pattern = "English";

    BoyerMoore bmSearch(text, pattern);
   // bmSearch.ReadFile();
   bmSearch.bm(text, pattern);

}