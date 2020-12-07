#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>

#include "../../tools/timer.h"
#include "../../tools/parser.h"

//function to get names from a directory
std::vector<std::string> GetNames(const std::string& directory) {
    std::ifstream container;
    container.open(directory);
    std::vector<std::string> names;
    std::string line;
    while (std::getline(container, line)) {       
        line.insert(0, "../../books/");

        names.push_back(line);
    }
    return names;
}

int main(int argc, char** argv) 
{

    //std::string pattern_file_name = "src/../../../patterns/English.txt";


    //Parser pattern(pattern_file_name);
   // pattern.concatStr();

   // std::cout << pattern.m_string << std::endl;
   

    //std::string directory = "src/../../../books/names.txt";

    //std::string pattern = "English";
    //std::string code = "rkvstest";

    std::string directory = (argv[1]);
    std::string pattern = (argv[2]);
    std::string code = (argv[3]);

   // Parser pattern(pattern_name);
    //pattern.concatStr();
   // std::cout<<pattern.m_string.length()<<std::endl;

    std::string title = "std-vm_" + code;

    std::vector<std::string> names = {};
    names = GetNames(directory);
    Timer timer(title, code);
    timer.WriteHeader();
    for (auto fname : names) {

        std::cout << "fname " << fname << std::endl;

        //std::cout << "test\n";
        for (int i = 0; i < 5; i++) {           

            //for (int j = 0; j < 5; j++) {
            Parser text(fname);
            text.concatStr();         
            std::string in = text.m_string;
            std::string needle = pattern;
            timer.SetBookName(std::to_string(text.m_string.length()));

            timer.Start();
            auto it = std::search(in.begin(), in.end(),
                std::boyer_moore_searcher(
                    needle.begin(), needle.end()));
            if (it != in.end())
                std::cout << "The string " << needle.length() << " found at offset "
                << it - in.begin() << '\n';
            else
                std::cout << "The string " << needle.length() << " not found\n";

            timer.Stop();
            timer.Calc();
            timer.WriteCSV();
            timer.Reset();
            text.clearStr();
        }

    }
	
}