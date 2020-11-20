#include <iostream>
#include <vector>
#include <fstream>
#include "../tools/timer.h"

std::vector<std::string> GetNames (const std::string& directory){
    std::ifstream container;
	container.open(directory);
    std::vector<std::string> names;
    std::string line;
    while(std::getline(container,line)){
        line.insert(0,"../../books/");
        names.push_back(line);
    }
    return names;
}

void bf(const std::string& text, const std::string& key, Timer& timer){
    std::ifstream inFile;
	inFile.open(text);
	std::string line;
     timer.SetBookName(text);
    int keyLen = key.length();
    int foundTimes = 0;
    timer.Start();
    for (;std::getline(inFile, line);){
        int lineLen = line.length();

        if (lineLen < keyLen){
            continue;
        }

        for(int i = 0; i <= lineLen - keyLen+1; i++){
            int j;
            for(j = 0; j < keyLen; j++){
                if(line[i+j] != key[j]){
                    break;
                }
            }
            if (j == keyLen){
                foundTimes++;
            }
        }

    }
    timer.Stop();
	inFile.close();
    timer.Calc();
    timer.WriteCSV();
    timer.Reset();
    inFile.close();
    std::cout<<foundTimes <<" patterns found"<<std::endl;
}

int main(int argc, char** argv){
    std::string directory = (argv[1]);
    std::string pattern = (argv[2]);

    std::vector<std::string> names = {};
    names = GetNames(directory);

    Timer timer("brute_timer_english");
    for(auto i: names){
        std::cout<<i<<std::endl;
        std::string fname = i;
        for(int j =0;j<5;j++){
            bf(fname,pattern,timer);
        }
        
    }
}
