#include <iostream>
#include <vector>
#include <fstream>
#include "../../tools/comptool.h"
#include "../../tools/parser.h"

// Function Declarations
std::vector<std::string> GetNames (const std::string& directory);
void concatString(const std::string& text, std::string& longStr);
void bf(const std::string& text, const std::string& longStr, const std::string& key, CompTool& tool);
void Strip(std::string& line);
void concatString(std::string& fname, std::string& m_string);


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

    std::string longStr = "";
    
    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "brute_comp_" + code;
    CompTool tool(title,pattern.m_string,code);
    for(auto i: names){
        std::cout<<i<<std::endl;
        std::string fname = i;

        concatString(fname, longStr);
        bf(fname,longStr,pattern.m_string,tool);
        longStr.clear();       
        
    }
}

// Remove leading and trailing whitespace from line in textfile
void Strip(std::string& line){

    if(line[0]==' ' || line[line.length()-1]==' '){
            if(line[0]==' '){              
                for(int i = 0;i<line.length();i++)
                {
                    if(line[i] != ' '){
                        line.erase(0,i);
                        break;
                    }
                }           
            }

            if(line[line.length()-1]==' '){
                for(int i =line.length()-1;i>=0;i--){
                    if(line[i] != ' '){
                        line.erase(i+1,line.length());
                        break;
                    }
                }
            }            
    }        
}

// Concatenate entire file into one string
void concatString(std::string& fname, std::string& m_string) {

    std::ifstream inFile;
    inFile.open(fname);
    std::string line;
    while (std::getline(inFile, line)) {        
        if (line == "")
            continue;
    Strip(line);             
    
        line.append(" ");
        m_string.append(line);
    }   
    inFile.close();
}


// Create a vector of text file names to be searched
std::vector<std::string> GetNames (const std::string& directory){
    std::ifstream container;
	container.open(directory);
    std::vector<std::string> names;
    std::string line;
    std::string path = "";
    // Grab folder path of filename
    for(int i =directory.length()-1; i >=0;i--){
        if(directory[i] == '/'){
            path = directory.substr(0,i+1);
            break;
        }
    }
    //std::cout<<"p "<<prefix<<std::endl;
    // Loop through file, inert filepath, push onto vector
    while (std::getline(container, line)) {
        line.insert(0, path);
       // std::cout<<line<<std::endl;
        names.push_back(line);
    }
    return names;
}

// Brute Force algorithm implementation
void bf(const std::string& text,const std::string& longStr, const std::string& key, CompTool& tool){
   
    tool.SetTextLen(std::to_string(longStr.length()));
    int keyLen = key.length();
    int lineLen = longStr.length();
    int foundTimes = 0;    

    // if pattern is longer than text string
    if(longStr.length() < keyLen){
        tool.totalComps = tool.innerComps + tool.outterComps;
        tool.WriteCSV();
        tool.Reset();  
  
        std::cout<<foundTimes <<" patterns found"<<std::endl;
        return;
    }

    // outter loop compares one character
    for(int i = 0; i <= lineLen - keyLen+1; i++){
        int j;
        tool.outterComps +=1;
        // inner loop to compare substrings
        for(j = 0; j < keyLen; j++){
            tool.innerComps+=1;
            if(longStr[i+j] != key[j]){
                tool.fPositives+=1;
                break;
            }
        }
        if (j == keyLen){
            tool.patterns_found+=1;
            foundTimes++;
        }
    }
    // calc total comps, write to file, reset tool
    tool.totalComps = tool.innerComps + tool.outterComps;
    tool.WriteCSV();
    std::cout<<tool.patterns_found <<" patterns found"<<std::endl;
    tool.Reset();    
    return;
}

