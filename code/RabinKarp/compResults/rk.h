#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "../../tools/comptool.h"

#define b 256
#define q 293

class RabinKarp {

private:
    std::string fname, key, m_string;
    int foundTimes = 0;

public:

    RabinKarp(std::string filename, std::string pattern);

    int power(int base, int exponent);
    int hash(const std::string& text, int len);
    void rk(CompTool& tool);
    void concatStr();
    void Strip(std::string& line);
    inline void clearStr() { m_string.clear(); }
};