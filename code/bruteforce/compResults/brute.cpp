#include <iostream>
#include <vector>
#include <fstream>
#include "../../tools/comptool.h"

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

void bf(const std::string& text, const std::string& key, CompTool& tool){
    std::ifstream inFile;
	inFile.open(text);
	std::string line;
    tool.SetBookName(text);
    int keyLen = key.length();
    int foundTimes = 0;
    
    for (;std::getline(inFile, line);){
        int lineLen = line.length();
        tool.numLines+=1;
        tool.lineLength += line.length();

        if (lineLen < keyLen){
            continue;
        }

        for(int i = 0; i <= lineLen - keyLen+1; i++){
            int j;
            for(j = 0; j < keyLen; j++){
                tool.totalComps+=1;
                if(line[i+j] != key[j]){
                    tool.fPositives+=1;
                    break;
                }
            }
            if (j == keyLen){
                tool.patterns_found+=1;
                foundTimes++;
            }
        }
       
    }   
	
    tool.WriteCSV();
    tool.Reset();
    inFile.close();
    std::cout<<foundTimes <<" patterns found"<<std::endl;
}

int main(int argc, char** argv){
    std::string directory = (argv[1]);
    std::string pattern = (argv[2]);
    std::string code = (argv[3]);
    
    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "brute_comp_" + code;
    CompTool tool(title,code);
    for(auto i: names){
        std::cout<<i<<std::endl;
        std::string fname = i;
        //for(int j =0;j<5;j++){
        bf(fname,pattern,tool);
        
       // }
        
    }
}
