#include "rk.h"
#include "timer.h"
#include <iostream>
#include <fstream>
#include <vector>



//do we need to erase symbols and does case matter, do spaces

// void RunBenchmarks()
// {
// 	PROFILE_SCOPE("RunBenchmarks");
// 	std::cout << "Running Benchmarks...\n";
//     std::string fname = "landbeyond.txt";
//     std::string pattern = "English";
//     RabinKarp rkSearch(fname,pattern);
//     rkSearch.ReadFile();
//     // std::cout<<"///////////////"<<std::endl;
//     // std::cout<<"String Class Find Function results"<<std::endl;
//     // stringFind(text, pattern);
// }

int main(int argc, char** argv)
{

    // std::string fname = "landbeyond.txt";
    // std::string pattern = "English";
    // RabinKarp rkSearch(fname, pattern);
	//  Instrumentor::Get().BeginSession("Profile");
	// //RunBenchmarks();
    // rkSearch.ReadFile();
	//  Instrumentor::Get().EndSession();


    std::ifstream container;
	container.open("books/names.txt");
    std::vector<std::string> names;
    std::string line;
    while(std::getline(container,line))
    {
        line.insert(0,"books/");
        names.push_back(line);
    }
    Timer timer;
     timer.WriteHeader();

    for(auto i: names){

        std::cout<<i<<std::endl;
        std::string fname = i;
        std::string pattern = "English";
        RabinKarp rkSearch(fname, pattern);
        timer.SetName(fname);

        timer.Start();

        rkSearch.ReadFile(fname);
        timer.Stop();
         timer.WriteCSV();
         timer.Reset();

    }




}