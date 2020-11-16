#include "rk.h"
#include "timer.h"

RabinKarp::RabinKarp(std::string filename, std::string pattern)
    :fname(filename),key(pattern) {}

int RabinKarp::power(int base, int exponent) {
    int poww = 1;
    for (int i = 0; i < exponent; i++)
    {
        poww *= base;
        poww %= 101;
    }
    return poww % 101;
}

int RabinKarp::hash(const std::string& text, int len)
{
    //PROFILE_FUNCTION();
    int h = 0;
    for (int i = 0; i < key.length(); i++)
    {
        h += ((int)text[i] * power(256, key.length() - i - 1)) % 101;

    }
    h %= 101;
    return h;
}

void RabinKarp::rk(const std::string& text, const std::string& key, Timer& timer){
    //if the line is less than the length of the pattern we are looking for skip it

    //Timer timer(__func__,text,key);
    timer.SetBookName(text);
    std::ifstream inFile;
	inFile.open(text);
	std::string line;

    timer.Start();
	for (;std::getline(inFile, line);)
	{

	   if (line.length() < key.length())
	   {
	       lineNum++;
            continue;
        }

        //key length
        int len = key.length();

        // calculate hash value of key
        int keyHash = hash(key, len);

        //make a int to store substring hash
        int subHash = 0;
        //make a string to store substring
        std::string sub;

        //get substring hash
        sub = line.substr(0, len);
        subHash = hash(sub, len);

        for(int i = 0; i < line.length() -len + 1; i++){
            //check for match
            sub = line.substr(i,len);
            bool match = true;
            if(subHash == keyHash){
                //check for false positive
                for(int j = 0; j < key.length(); j++){
                    if(sub[j] != key[j]){
                        match = false;
                        break;
                    }
                }
                if (match){
                    ////std::cout<<subHash<<std::endl;
                    std::cout << "Our Pattern found at index " << i <<" on line "<<lineNum<< std::endl;
                }
            }
            //roll the hash
            subHash = ((subHash + 101 - ((int)line[i] * power(256, len-1))%101)*256 + (int)line[i+len])%101;
    }
    lineNum++;

	}
	inFile.close();
    timer.Stop();
    timer.Calc();
    timer.WriteCSV();
    timer.Reset();

}

void RabinKarp::stringFind(const std::string& text, const std::string& key){
    //PROFILE_FUNCTION();
    //find first occurence
    std::size_t found = text.find(key);
     while(found != std::string::npos){
        // print out tthat the pattern occurs
        std::cout << "Standard pattern found at index " << found <<" on line "<<lineNum<< std::endl;
        // Get the next occurrence from the current position
        found = text.find(key, found + key.size());
    }
}