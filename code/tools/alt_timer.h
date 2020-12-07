#pragma once
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

#define algorithm __FUNCTION__

class Timer
{

private:
	// std::chrono::time_point<std::chrono::steady_clock> m_startTimePoint;
	// std::chrono::time_point<std::chrono::steady_clock> m_endTimepoint;
	 std::string m_inFile, m_outFile, m_functionName, m_Pattern, m_code;
	std::chrono::steady_clock::time_point m_startTimePoint;
	std::chrono::steady_clock::time_point m_endTimepoint;
	std::chrono::duration<double> duration;


	int m_mod;
	long double start, end;// duration;


public:
	// Default Constructor
	Timer()
		:m_outFile("timer.csv"), m_inFile("na"), start(0), end(0), duration(0) {
		WriteHeader();
	}

	// constructor to test operators
	Timer(std::string outFile)
		: m_outFile(outFile.append(".csv")), m_inFile("na"), m_code("na"), start(0), end(0), duration(0), m_mod(-1) {
		WriteHeader();
	}

	// Standard Constructor for testing - takes in outfile, code, and mod
	Timer(std::string outFile, std::string code, int mod)
		: m_outFile(outFile.append(".csv")), m_inFile("na"), m_code(code), start(0), end(0), duration(0), m_mod(mod) {
		WriteHeader();
	}

	// Bruteforce Consutrctor sets mod to -1
	Timer(std::string outFile, std::string code)
		: m_outFile(outFile.append(".csv")), m_inFile("na"), m_code(code), start(0), end(0), duration(0), m_mod(-1) {
		WriteHeader();
	}

	void Calc() {
		//start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
		//end = std::chrono::time_point_cast<std::chrono::microseconds>(m_endTimepoint).time_since_epoch().count();
		
		//std::cout<<"start "<<start<<" end "<<end<<std::endl;
		//duration = (end-start) * 0.001;
		duration = std::chrono::duration_cast<duration<double>>(m_endTimepoint-m_startTimePoint);

	}

	void Reset() {
		start = end = 0;
		//duration = 0;
	}

	void WriteHeader() {
		std::ofstream oStream;
		oStream.open(m_outFile);
		oStream << "file_name,duration," << m_code << "," << m_mod << std::endl;
		oStream.close();
	}


	void WriteCSV() {
		std::ofstream oStream;
		oStream.open(m_outFile, std::ios::app);
		//oStream << m_inFile << "," << (duration.count() * 1000)<< std::endl;
		oStream << m_inFile << "," << (duration.count()) << std::endl;

		oStream.close();
	}	

	inline void Start() { m_startTimePoint = std::chrono::steady_clock::now(); }
	inline void Stop() { m_endTimepoint = std::chrono::steady_clock::now(); }
	inline void SetBookName(const std::string& name) { m_inFile = name; }
};