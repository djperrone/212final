#include "bm.h"


int main(int argc, char** argv)
{
    std::string text = "This is a simple example.";
    std::string pattern = "example";

    BoyerMoore bmSearch(text, pattern);
    bmSearch.bm(text, pattern);

    // bmSearch.ReadFile();

}
