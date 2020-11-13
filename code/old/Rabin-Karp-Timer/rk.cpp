#include "rk.h"

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::duration<double> Seconds;
typedef std::chrono::nanoseconds NS;

// #include <type_traits>
//http://www.cplusplus.com/forum/general/187899/
/*using clock_type = typename std::conditional< std::chrono::high_resolution_clock::is_steady,
                                              std::chrono::high_resolution_clock,
                                              std::chrono::steady_clock >::type ;*/


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
			poww = poww%293;
		}
	}

	poww = poww%293;

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
        strHash = hash(sub, len);

        bool match = true;

        if (keyHash == strHash)
        {

            for(int j = 0; j < key.length(); j++){
                if(sub[j] != key[j]){
                    match = false;
                    break;
                }
            }
            if (match){
                std::cout << "Our Pattern found at index " << i <<" on line "<<lineNum<< std::endl;
            }
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

struct Timer
{
	
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer()
	{
        //msvc
		//start = std::chrono::high_resolution_clock::now();

        //gcc
	    start = std::chrono::steady_clock::now();
        //start = std::chrono::time_point<std::chrono::steady_clock>


	}
	~Timer()
	{
        //msvc
		end = std::chrono::steady_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;

		std::cout << "Cherno timing Timer took "<<ms  << "ms" << std::endl;

	}

};

void RabinKarp::ReadFile()
{
    
	std::ifstream inFile;
	inFile.open(fname);
	std::string line;
    double c_start,c_end;
    // lab start
    c_start = std::clock();
    //euler
    Clock::time_point tic, toc;
    //std::chrono::duration<double> Seconds;
    std::chrono::duration<float> duration;
    TimerStruct timerStruct;
    TimerClass timerClass;
    tic = Clock::now();
	for (;std::getline(inFile, line);)
	{
	   // std::cout<<line<<std::endl;
	   rk(line,key);
	   //stringFind(line,key);
	   lineNum ++;
      
	}
    // lab end
    c_end = std::clock();
     float output =  (c_end - c_start) / (double)CLOCKS_PER_SEC;
     //float output =  (c_end - c_start);

    std::cout << std::fixed << std::setprecision(4) << "Time from lab file: "<<output<< std::endl;
    // euler
    toc = Clock::now();
     std::cout<< std::fixed << std::setprecision(4) <<"euler demo time: "<< (double)NS(toc-tic).count()/1000000 << "ms"<< std::endl;

     //cherno timing
     //timer.~Timer();

	inFile.close();
}