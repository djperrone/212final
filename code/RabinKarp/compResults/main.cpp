#include "rk.h"
#include "../../tools/comptool.h"
#include "../../tools/parser.h"
#include <iostream>
#include <fstream>
#include <vector>

//function to get names from a directory
std::vector<std::string> GetNames(const std::string& directory) {

    std::ifstream container;
    container.open(directory);
    std::cout<<"dir "<<directory<<std::endl;
    std::vector<std::string> names;
    std::string line;

    std::cout << directory << std::endl;
    // Get filepath
    std::string path = "";
    for(int i =directory.length()-1; i >=0;i--){
        if(directory[i] == '/'){
            path = directory.substr(0,i+1);
            break;
        }
    }
    //std::cout<<"p "<<path<<std::endl;
    
    while (std::getline(container, line)) {
        line.insert(0, path);
       // std::cout<<line<<std::endl;
        names.push_back(line);
    }
    return names;
}

/* Main Function
* Command line args - 1. File containing list of files to search 2. Pattern file name 3. Output File tag
* pre-processing - concats pattern and prepares text file for search
*/
int main(int argc, char** argv){
   std::string directory = (argv[1]);
   std::string pattern_name = (argv[2]);
   std::string code = (argv[3]);

    Parser pattern(pattern_name);
    pattern.concatStr();
    std::cout<<pattern.m_string.length()<<std::endl;
    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "rk_comp_"+code+"-"+std::to_string(q);
    CompTool compTool(title,pattern.m_string,code,q);   
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