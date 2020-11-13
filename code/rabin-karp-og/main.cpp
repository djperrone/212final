 #include "rk.h"

//do we need to erase symbols and does case matter, do spaces

int main(int argc, char** argv)
{
    // std::string fname = (argv[1]);
    // std::string key = (argv[2]);
    std::string fname = "landbeyond.txt";
    std::string pattern = "English";
   // std::cout<<"Our Rabin Karp Algorithm Results"<<std::endl;
   
   RabinKarp rkSearch(fname,pattern);
    {
        Timer timer;
        rkSearch.ReadFile();
    }
    
    // std::cout<<"///////////////"<<std::endl;
    // std::cout<<"String Class Find Function results"<<std::endl;
    // stringFind(text, pattern);

}