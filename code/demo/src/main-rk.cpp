#include "rk.h"
#include "../../tools/parser.h"

//function to get names from a directory
std::vector<std::string> GetNames(const std::string& directory) {
    std::ifstream container;
    container.open(directory);
    std::vector<std::string> names;
    std::string line;

    // Get filepath
    std::string path = "";
    for(int i =directory.length()-1; i >=0;i--){
        if(directory[i] == '/'){
            path = directory.substr(0,i+1);
            break;
        }
    }
    std::cout<<"p "<<path<<std::endl;
    while (std::getline(container, line)) {
        line.insert(0, path);
        names.push_back(line);
    }
    return names;
}

/* Main Function
* Command line args - 1. File containing list of files to search 2. Pattern file name 3. Output File tag
* pre-processing - concats pattern and prepares text file for search
*/
int main(int argc, char** argv) {
    std::string directory = (argv[1]);
    std::string pattern_name = (argv[2]);
    std::string code = (argv[3]);
    
    Parser pattern(pattern_name);
    pattern.concatStr();
    std::cout<<pattern.m_string<<std::endl;    

    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "rk_timer_" + code + "-" + std::to_string(q);
    Timer timer(title,pattern_name, code, q);
    
    for (auto fname : names) {

        std::cout << fname << std::endl;          
        
        RabinKarp rkSearch(fname, pattern.m_string);
       
        for (int j = 0; j < 5; j++) {
        rkSearch.concatStr();         
        rkSearch.rk(timer);
        rkSearch.clearStr();
        }
    }
}