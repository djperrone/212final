#include "rk.h"
#include "../../tools/comptool.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "../../tools/parser.h"

//function to get names from a directory
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

int main(int argc, char** argv){
   std::string directory = (argv[1]);
   std::string pattern_name = (argv[2]);
   std::string code = (argv[3]);

//     std::string code = "phrase3";
//    std::string directory = "../../books2/names.txt";
//    std::string pattern = "She said quietly to him, as if she were preparing him for a great disappointment, “I have deliberately, very deliberately, removed remorse from the forbidden fruit,” and he was abject suddenly and trembling.";
    Parser pattern(pattern_name);
    pattern.concatStr();
    std::cout<<pattern.m_string.length()<<std::endl;
    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "rk_comp_"+code+"-"+std::to_string(q);
    CompTool compTool(title,code,q);   
    for(auto i: names){

        std::cout<<i<<std::endl;
        std::string fname = i;
        //std::string pattern = "English";
        RabinKarp rkSearch(fname, pattern.m_string);
        //for(int j =0;j<5;j++){
        rkSearch.concatStr();
        rkSearch.rk(compTool);
            
            
       // }
    }

}