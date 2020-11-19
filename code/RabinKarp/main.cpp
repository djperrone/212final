#include "rk.h"
#include "../tools/timer.h"
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

//function to get names from a directory
std::vector<std::string> GetNames (const std::string& directory){
    std::ifstream container;
	container.open(directory);
    std::vector<std::string> names;
    std::string line;
    while(std::getline(container,line)){
        line.insert(0,"../books/");
        names.push_back(line);
    }
    return names;
}

int main(int argc, char** argv){
    std::string directory = (argv[1]);
    std::string pattern = (argv[2]);

    std::vector<std::string> names = {};
    names = GetNames(directory);

    Timer timer("rk_timer_english1");
    for(auto i: names){

        std::cout<<i<<std::endl;
        std::string fname = i;
        //std::string pattern = "English";
        RabinKarp rkSearch(fname, pattern);
        for(int j =0;j<5;j++){
            rkSearch.rk(fname,pattern,timer);

        }
    }

}