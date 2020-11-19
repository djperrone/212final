#include "rk.h"

RabinKarp::RabinKarp(std::string filename, std::string pattern)
    :fname(filename),key(pattern) {}

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

void RabinKarp::rk(const std::string& text, const std::string& key, Timer& timer){
    //if the line is less than the length of the pattern we are looking for skip it

    //Timer timer(__func__,text,key);
    timer.SetBookName(text);
    std::ifstream inFile;
	inFile.open(text);
	std::string line;

	//make a int to store substring hash
    int subHash = 0;
    //key length
    int keyLen = key.length();

    int power_val = power(b, keyLen-1);

    timer.Start();
    // calculate hash value of key
    int keyHash = hash(key, keyLen);

	for (;std::getline(inFile, line);){
	   int lineLen = line.length();

        if (lineLen < keyLen){
            continue;
        }

        subHash = hash(line.substr(0, keyLen), keyLen);

        for(int i = 0; i < lineLen -keyLen + 1; i++){
            //check for match

            bool match = true;
            if(subHash == keyHash){
                //check for false positive
                for(int j = 0; j < keyLen; j++){
                    if(line.substr(i,keyLen)[j] != key[j]){
                        match = false;
                        break;
                    }
                }
                if (match){
                    //increment number of patters founf
                    foundTimes++;
                }
            }
            //roll the hash
            subHash = ((subHash + q - ((int)line[i] * power_val)%q)*b + (int)line[i+keyLen])%q;
        }
	}

	timer.Stop();
	inFile.close();
    timer.Calc();
    timer.WriteCSV();
    timer.Reset();

    std::cout << foundTimes <<" patterns found "<<std::endl;

}