#include <iostream>
#include <string>
#include <fstream>

#define b 256
#define q 101

class RabinKarp
{

private:
    std::string fname, key;
    int lineNum = 1;

public:

    RabinKarp(std::string filename, std::string pattern);

    int power(int base, int exponent);
    int hash(const std::string& text, int len);
    void rk(const std::string& text, const std::string& key);
    void stringFind(const std::string& text, const std::string& key);
    void ReadFile();


};