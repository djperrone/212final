#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
#include <memory>
#include <array>
#include "Instrumentator.h"


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




class TimerClass
{
public:
	TimerClass()
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~TimerClass()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << duration << "us (" << ms << "ms) - cherno class timer\n";
	}

private:
	std::chrono::time_point< std::chrono::high_resolution_clock > m_StartTimePoint;
};

struct TimerStruct
{
	
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	TimerStruct()
	{
        //msvc
		//start = std::chrono::high_resolution_clock::now();

        //gcc
	    start = std::chrono::steady_clock::now();
        //start = std::chrono::time_point<std::chrono::steady_clock>


	}
	~TimerStruct()
	{
        //msvc
		end = std::chrono::steady_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;

		std::cout << "Cherno struct Timer took "<<ms  << "ms" << std::endl;

	}

};