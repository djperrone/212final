#include <iostream>
#include <vector>
#include <fstream>
#include "../../tools/timer.h"
#include "../../tools/parser.h"

std::vector<std::string> GetNames (const std::string& directory);
void concatString(const std::string& text, std::string& longStr);
void bf(const std::string& text, const std::string& longStr, const std::string& key, Timer& timer);
void Strip(std::string& line);
void concatString(std::string& fname, std::string& m_string);


int main(int argc, char** argv){
    std::string directory = (argv[1]);
    std::string pattern_name= (argv[2]);
    std::string code = (argv[3]);
   
    std::string longStr = "";
    Parser pattern(pattern_name);
    pattern.concatStr();
    std::cout<<pattern.m_string.length()<<std::endl;

        // std::ofstream oStream;
		// oStream.open("testing123.txt");
		// oStream << pattern;
		// oStream.close();

    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "brute_timer_" + code;
    Timer timer(title,code);
    for(auto i: names){
        std::cout<<i<<std::endl;
        std::string fname = i;
        for(int j =0;j<5;j++){
            concatString(fname, longStr);
            bf(fname,longStr,pattern.m_string,timer);
            longStr.clear();
            
        }
        
    }
}



void Strip(std::string& line){

    if(line[0]==' ' || line[line.length()-1]==' '){
            if(line[0]==' '){
              //  std::cout<<"before: "<<line<<"*"<<std::endl;
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
            //std::cout<<"after: "<<line<<"*"<<std::endl;
    }        
}

// Concatenate entire file into one string
void concatString(std::string& fname, std::string& m_string) {

    std::ifstream inFile;
    inFile.open(fname);
    std::string line;
    while (std::getline(inFile, line)) {
        //std::cout<<line<<std::endl;
        if (line == "")
            continue;
    Strip(line);             
    
        line.append(" ");
        m_string.append(line);
    }   

    inFile.close();
}
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



void bf(const std::string& text,const std::string& longStr, const std::string& key, Timer& timer){
    
    timer.SetBookName(std::to_string(longStr.length()));
    int keyLen = key.length();
    int foundTimes = 0;
    int fp =0;
    timer.Start();  

    if(longStr.length() < keyLen){
        timer.Stop();    
        timer.Calc();
        timer.WriteCSV();
        timer.Reset();
        std::cout << foundTimes << " patterns found " << std::endl;
        return;
    }
    for(int i = 0; i <= longStr.length() - keyLen+1; i++){
        int j;
        for(j = 0; j < keyLen; j++){
            if(longStr[i+j] != key[j]){
                fp++;
                break;
            }
        }
        if (j == keyLen){
            foundTimes++;
        }
    }    
    timer.Stop();	
    timer.Calc();
    timer.WriteCSV();
    timer.Reset();  

    std::cout<<foundTimes <<" patterns found"<<std::endl;
   // std::cout<<fp <<" false positives"<<std::endl;
}
