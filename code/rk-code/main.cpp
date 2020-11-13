#include "rk.h"
#include "timer.h"

//do we need to erase symbols and does case matter, do spaces

void RunBenchmarks()
{    
	PROFILE_SCOPE("RunBenchmarks");
	std::cout << "Running Benchmarks...\n";
    std::string fname = "landbeyond.txt";
    std::string pattern = "English";
    RabinKarp rkSearch(fname,pattern);
    rkSearch.ReadFile();
    // std::cout<<"///////////////"<<std::endl;
    // std::cout<<"String Class Find Function results"<<std::endl;
    // stringFind(text, pattern);
}

int main(int argc, char** argv)
{
	 Instrumentor::Get().BeginSession("Profile");
	 RunBenchmarks();
	 Instrumentor::Get().EndSession();
	

   
       
    {
        Timer timer;
         std::string fname = "landbeyond.txt";
        std::string pattern = "English";
        RabinKarp rkSearch(fname, pattern);
        rkSearch.ReadFile();
    }
}