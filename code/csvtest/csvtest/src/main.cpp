#include "rk.h"
#include "timer.h"

//do we need to erase symbols and does case matter, do spaces

void RunBenchmarks(char** argv)
{    
	PROFILE_SCOPE("RunBenchmarks");
	std::cout << "Running Benchmarks...\n";
   /* std::string fname = "landbeyond.txt";
    std::string pattern = "English";*/
    std::string fname = argv[1];
    std::string pattern = argv[2];
    RabinKarp rkSearch(fname,pattern);
    rkSearch.ReadFile();
    // std::cout<<"///////////////"<<std::endl;
    // std::cout<<"String Class Find Function results"<<std::endl;
    // stringFind(text, pattern);
}

int main(int argc, char** argv)
{ 

     std::string fname = "landbeyond.txt";
     std::string pattern = "English";

    //std::string fname = argv[1];
   // std::string pattern = argv[2];      
   
        
    RabinKarp rkSearch(fname, pattern);
    rkSearch.ReadFile();    
}