// Brute Force Algorithm implementation with timer

#include <iostream>
#include <vector>
#include <fstream>
#include "../../tools/timer.h"
#include "../../tools/parser.h"

// Declare Functions
std::vector<std::string> GetNames (const std::string& directory);
void concatString(const std::string& text, std::string& longStr);
void bf(const std::string& text, const std::string& longStr, const std::string& key, Timer& timer);
void Strip(std::string& line);
void concatString(std::string& fname, std::string& m_string);

/* Main Function
* Command line args - 1. File containing list of files to search 2. Pattern file name 3. Output File tag
* pre-processing - concats pattern and prepares text file for search
*/
int main(int argc, char** argv){
    std::string directory = (argv[1]);
    std::string pattern_name= (argv[2]);
    std::string code = (argv[3]);
   
    std::string longStr = "";
    Parser pattern(pattern_name);
    pattern.concatStr();
    std::cout<<pattern.m_string.length()<<std::endl;    

    std::vector<std::string> names = {};
    names = GetNames(directory);
    std::string title = "brute_timer_" + code;
    // Instantiate timer
    Timer timer(title,pattern.m_string,code);
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

// Remove leading and trailing white space from each line of the file
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
    // Get each line from the file, skip empty lines, strip line, add space, append to text
    while (std::getline(inFile, line)) {       
        if (line == "") continue;
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


// Brute force algorithm implementation
void bf(const std::string& text,const std::string& longStr, const std::string& key, Timer& timer){
    // Set text length for timer outfile
    timer.SetTextLen(std::to_string(longStr.length()));
    int keyLen = key.length();
    int foundTimes = 0;
    int fp =0;

    // Start timer
    timer.Start();  
    // If string is shorter than pattern, end function
    if(longStr.length() < keyLen){
        timer.Stop();    
        timer.Calc();
        timer.WriteCSV();
        timer.Reset();
        std::cout << foundTimes << " patterns found " << std::endl;
        return;
    }
    //  Loop through string
    for(int i = 0; i <= longStr.length() - keyLen+1; i++){
        int j;
        // Inner loop, breaks if mismatch
        for(j = 0; j < keyLen; j++){
            if(longStr[i+j] != key[j]){
                fp++;
                break;
            }
        }
        // Pattern found
        if (j == keyLen){
            foundTimes++;
        }
    }    
    // Stop timer, calc duration, write to file, and reset for next file
    timer.Stop();	
    timer.Calc();
    timer.WriteCSV();
    timer.Reset();  
    
    std::cout<<foundTimes <<" patterns found"<<std::endl;
   // std::cout<<fp <<" false positives"<<std::endl;
}
