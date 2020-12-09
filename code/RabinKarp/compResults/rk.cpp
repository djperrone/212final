#include "rk.h"

RabinKarp::RabinKarp(std::string filename, std::string pattern)
    :fname(filename),key(pattern) {}

// Remove leading and trailing whitespace from line
void RabinKarp::Strip(std::string& line) {

    if (line[0] == ' ' || line[line.length() - 1] == ' ') {
        if (line[0] == ' ') {
            // std::cout<<"before: "<<line<<"*"<<std::endl;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] != ' ') {
                    line.erase(0, i);
                    break;
                }
            }
        }

        if (line[line.length() - 1] == ' ') {
            for (int i = line.length() - 1; i >= 0; i--) {
                if (line[i] != ' ') {
                    line.erase(i + 1, line.length());
                    break;
                }
            }
        }
        //std::cout<<"after: "<<line<<"*"<<std::endl;
    }
}

// Concatenate entire file into one string
void RabinKarp::concatStr() {

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


int RabinKarp::power(int base, int exponent){
    //PROFILE_FUNCTION();
	int poww = 1;

		for(int i = 0; i < exponent; i++){
			poww *= base;
			poww = poww%q;
		}
	//}

	return poww%q;
}

int RabinKarp::hash(const std::string& text, int keyLen){
    //PROFILE_FUNCTION();
    int h = 0;
    h = (int)text[0];
    for (int i = 1; i < keyLen; i++){

       h = (h*b + (text[i]))%q;

    }
    h = h%q;
    return h;
}

void RabinKarp::rk(CompTool& tool){
    //if the line is less than the length of the pattern we are looking for skip it

    //Timer timer(__func__,text,key);
    tool.SetTextLen(std::to_string(m_string.length()));    

	//make a int to store substring hash
    int subHash = 0;
    //key length
    int keyLen = key.length();

    int power_val = power(b, keyLen-1);

    
    // calculate hash value of key
    int keyHash = hash(key, keyLen);

	
	int lineLen = m_string.length();
    
    //tool.lineLength+=line.length();

    if (m_string.length() < keyLen){
        tool.totalComps = tool.innerComps + tool.outterComps;        
        tool.WriteCSV();
        tool.Reset();
        return;
    }

    subHash = hash(m_string.substr(0, keyLen), keyLen);       

    for(int i = 0; i < lineLen - keyLen + 1; i++){
        //check for match
        // std::cout<<"outter subhash "<<subHash<<" key "<<keyHash<<std::endl;
        bool match = true;
        tool.outterComps+=1;
        if(subHash == keyHash){
            //  std::cout<<"inner subhash "<<subHash<<" key "<<keyHash<<std::endl;
            //check for false positive
            for(int j = 0; j < keyLen; j++){
                tool.innerComps+=1;
                if(m_string.substr(i,keyLen)[j] != key[j]){
                    match = false;
                    tool.fPositives+=1;
                    break;
                }
            }
            if (match){
                //increment number of patters founf
                tool.patterns_found+=1;
                foundTimes++;
            }
        }
        //roll the hash
        subHash = ((subHash + q - ((int)m_string[i] * power_val)%q)*b + (int)m_string[i+keyLen])%q;
        
                
	}
	tool.totalComps = tool.innerComps + tool.outterComps;	 
    tool.WriteCSV();
    tool.Reset();

    std::cout << foundTimes <<" patterns found "<<std::endl;

}