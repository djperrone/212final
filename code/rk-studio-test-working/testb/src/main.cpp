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
	 Instrumentor::Get().BeginSession("Profile");
	 RunBenchmarks(argv);
	 Instrumentor::Get().EndSession(); 

     //std::string fname = "landbeyond.txt";
     //std::string pattern = "English";

    std::string fname = argv[1];
    std::string pattern = argv[2];
    
       
     
       
    {
        Timer timer;
        
        RabinKarp rkSearch(fname, pattern);
        rkSearch.ReadFile();
    }

    std::chrono::time_point< std::chrono::steady_clock > m_StartTimePoint;
    std::chrono::time_point< std::chrono::steady_clock > endTimePoint;
    {
        
        RabinKarp rkSearch(fname, pattern);
        m_StartTimePoint = std::chrono::steady_clock::now();        
        rkSearch.ReadFile();
        endTimePoint = std::chrono::steady_clock::now();
        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
        double duration = end - start;
        std::cout << duration << std::endl;
    }    

   


    {
       
        RabinKarp rkSearch(fname, pattern);
        TimerStruct timer;
        rkSearch.ReadFile();        
    }

    {
        
        RabinKarp rkSearch(fname, pattern);
        auto start = std::chrono::steady_clock::now();
        rkSearch.ReadFile();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
}