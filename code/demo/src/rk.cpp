#include "rk.h"

RabinKarp::RabinKarp(std::string filename, std::string pattern)
    :fname(filename), key(pattern),m_string("") {}


// Remove leading and trailing whitespace from line
void RabinKarp::Strip(std::string& line){

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
void RabinKarp::concatStr() {

    std::ifstream inFile;
    inFile.open(fname);
    std::string line;
    // loop through each line of file
    while (std::getline(inFile, line)) {
        // skip empty lines
        if (line == "")
            continue;
        Strip(line);             
        //concat string
        line.append(" ");
        m_string.append(line);
    }   
    inFile.close();
}

// Function to calculate initial power
int RabinKarp::power(int base, int exponent) {
    
    int poww = 1;
    for (int i = 0; i < exponent; i++) {
        poww *= base;
        poww = poww % q;
    }   
    return poww % q;
}

// Function to calculate initial hash
int RabinKarp::hash(const std::string& text, int keyLen) {
    //PROFILE_FUNCTION();
    int h = 0;
    h = (int)text[0];
    for (int i = 1; i < keyLen; i++) {
        h = (h * b + (text[i])) % q;
    }
    h = h % q;
    return h;
}

// Rabin Karp String search implementation
void RabinKarp::rk(Timer& timer) {    
    
    timer.SetTextLen(std::to_string(m_string.length()));    
    //key length
    int keyLen = key.length();
    int power_val = power(b, keyLen - 1);

    // Start timer
    timer.Start();
    // If string to search is shorter than pattern
    if(m_string.length() < keyLen){
        timer.Stop();    
        timer.Calc();
        timer.WriteCSV();
        timer.Reset();
        clearStr();
       // std::cout << foundTimes << " patterns found " << std::endl;
        return;
    }
    // calculate hash value of key and initial substring
    int keyHash = hash(key, keyLen);   
    int subHash = hash(m_string.substr(0, keyLen), keyLen);

    // Loop through string
    for (int i = 0; i < m_string.length() - keyLen + 1; i++){
        // check for match
        bool match = true;
        if (subHash == keyHash) {
            //check for false positive
            for (int j = 0; j < keyLen; j++) {
                if (m_string.substr(i, keyLen)[j] != key[j]){
                    match = false;
                    break;
                }
            }
            if (match) {
                //increment number of patters found
               // std::cout<<"pattern found at index "<<i<<std::endl;
               // std::cout<<m_string.substr(i-10,keyLen+10)<<std::endl;
                foundTimes++;
            }
        }
        //roll the hash
        subHash = ((subHash + q - ((int)m_string[i] * power_val) % q) * b + (int)m_string[i + keyLen]) % q;
    }    

    // Stop timer, write results to file, reset for next file search
    timer.Stop();    
    timer.Calc();
    timer.WriteCSV();
    timer.Reset();
    clearStr();
    std::cout << foundTimes << " patterns found " << std::endl;
    foundTimes=0;
}