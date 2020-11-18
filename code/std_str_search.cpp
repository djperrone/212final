#include "rk_optimize.h"

RabinKarp::RabinKarp(std::string filename, std::string pattern)
    :fname(filename),key(pattern) {}

void RabinKarp::stringFind(const std::string& text, const std::string& key){
    //PROFILE_FUNCTION();
    //find first occurence
    std::size_t found = text.find(key);
     while(found != std::string::npos){
        // Get the next occurrence from the current position
        found = text.find(key, found + key.size());
    }

    std::cout << foundTimes <<" patterns found "<<std::endl;

}