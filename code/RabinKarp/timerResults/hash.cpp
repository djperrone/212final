#include <iostream>
#define b 256
# define q 293
#include <cmath>

// Function to calculate initial hash
int hash(const std::string& text, int keyLen) {
    //PROFILE_FUNCTION();
    int h = 0;
    h = (int)text[0];
    for (int i = 1; i < keyLen; i++) {

        h = (h * b + (text[i])) % q;

    }
    h = h % q;
    return h;
}



int main(int argc, char** argv){

    std::string m_string = argv[1];
    std::string m_text = "ABCABAC";
    int kh = hash(m_string,m_string.length());
    std::cout<<kh<<std::endl;
    int subHash = hash(m_text.substr(0,3),m_string.length());
    int keyLen = 3;
    int power_val = std::pow(b,m_string.length()-1);

    //int th = hash(m_string,m_string.length());
    std::cout<<"ASD"<<subHash<<std::endl;
    
    for (int i = 0; i < m_text.length() - m_string.length() + 1; i++){
        // check for match
        
        //roll the hash
        subHash = ((subHash + q - ((int)m_string[i] * power_val) % q) * b + (int)m_string[i + keyLen]) % q;
        std::cout<<subHash<<std::endl;
    }    
}