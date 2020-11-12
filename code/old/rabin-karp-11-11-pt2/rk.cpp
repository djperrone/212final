#include "rk.h"

RabinKarp::RabinKarp(std::string filename, std::string pattern)
    :fname(filename),key(pattern) {}

int RabinKarp::power(int base, int exponent){
	int poww = 1;

	if (exponent == 0){
		return 1;
	}
	else{
		for(int i = 0; i < exponent; i++){
			poww *= base;
			poww = poww%101;
		}
	}

//	poww = poww%101;

	return poww;
}

int RabinKarp::hash(const std::string& text, int len)
{
    int h = 0;
    for (int i = 0; i < len; i++)
    {
        h += (int)text[i] * (power(256, len - 1 - i));

    }
    return h;
}

void RabinKarp::rk(const std::string& text, const std::string& key)
{
    

    int len = key.length();
    // calculate hash value of key
    int keyHash = hash(key, len);

    // calculate hash value of first substring to search
    int strHash = hash(text.substr(0, len),len);
    //std::cout<<"length "<<text.length()<<std::endl;
   // std::cout<<text<<std::endl;

    //if the line is less than the length of the pattern we are looking for skip it
    if(text.length() < key.length()){
        return;
    }

    for (int i = 0; i <= text.length()-len; i++)
    {

        std::string sub = text.substr(i, len);
        //strHash = hash(sub, len);
        //std::cout<<text[i]<<": "<<(int)text[i]<<std::endl;

        //std::cout<<sub<<std::endl;

        if (keyHash == strHash)
        {
            std::cout << "our Pattern found at index " << i <<" on line "<<lineNum<< std::endl;
            //std::cout<<"str hash "<<strHash<<std::endl;
        }

        strHash -= int(sub[0]) * power(256, len - 2);
        strHash *= 256;


    }
}

void RabinKarp::stringFind(const std::string& text, const std::string& key){
    //find first occurence
    std::size_t found = text.find(key);
     while(found != std::string::npos){
        // print out tthat the pattern occurs
        std::cout << "Standard pattern found at index " << found <<" on line "<<lineNum<< std::endl;
        // Get the next occurrence from the current position
        found =text.find(key, found + key.size());
    }
}

void RabinKarp::ReadFile()
{
	std::ifstream inFile;
	inFile.open(fname);
	std::string line;

	for (;std::getline(inFile, line);)
	{
	   // std::cout<<line<<std::endl;
	   rk(line,key);
	   stringFind(line,key);
	   lineNum ++;
	}
	inFile.close();
}