#include "bm.h"
#include "../../tools/parser.h"

//function to get names from a directory
std::vector<std::string> GetNames(const std::string& directory) {

    std::ifstream container;
    container.open(directory);
    std::vector<std::string> names;
    std::string line;

    std::cout << directory << std::endl;
    while (std::getline(container, line)) {
        line.insert(0, "../../books/");
       // std::cout<<line<<std::endl;
        names.push_back(line);
    }
    return names;
}

int main(int argc, char** argv){
    std::string directory = (argv[1]);
    std::string pattern_name = (argv[2]);
    std::string code = (argv[3]);

    Parser pattern(pattern_name);
    pattern.concatStr();
    std::cout<<pattern.m_string.length()<<std::endl;
    // std::string directory = "../../books/names.txt";
    // std::string pattern = "English";
    // std::string code = ("testing");

    //std::cout << directory << ' ' << pattern <<' '<< code << std::endl;

    std::vector<std::string> names = {};
    names = GetNames(directory);

    std::string title = "bm_comp_" + code;
    CompTool compTool(title,code);
    for (auto fname : names) {

        //std::cout << fname << std::endl;

        BoyerMoore bmSearch(fname, pattern.m_string);

        for (int j = 0; j < 5; j++){
            bmSearch.concatStr();

            bmSearch.bm(compTool);
            bmSearch.clearStr();
        }
    }
}