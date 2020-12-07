#include "bm-h.h"

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
    std::string pattern = (argv[2]);
    std::string code = (argv[3]);

    // std::string directory = "../../books/names.txt";
    // std::string pattern = "English";
    // std::string code = ("testing");

    //std::cout << directory << ' ' << pattern <<' '<< code << std::endl;

    std::vector<std::string> names = {};
    names = GetNames(directory);

    std::string title = "bmh_comp_" + code;
    CompTool compTool(title,code);
    for (auto fname : names) {

        //std::cout << fname << std::endl;

        BoyerMoore bmSearch(fname, pattern);

        for (int j = 0; j < 5; j++){
            bmSearch.concatStr();

            bmSearch.bm(compTool);
            bmSearch.clearStr();
        }
    }
}