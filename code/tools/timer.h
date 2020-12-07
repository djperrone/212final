#pragma once
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

#define algorithm __FUNCTION__

class Timer
{

private:
	std::chrono::time_point<std::chrono::steady_clock> m_startTimePoint;
	std::chrono::time_point<std::chrono::steady_clock> m_endTimepoint;
	std::string m_inFile, m_outFile, m_functionName, m_Pattern, m_code;
	int m_mod;
	long double start, end, duration;


public:
	// Default Constructor
	Timer()
		:m_outFile("timer.csv"), m_inFile("na"), start(0), end(0), duration(0) {
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
		start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_startTimePoint).time_since_epoch().count();
		end = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_endTimepoint).time_since_epoch().count();
		duration = (end - start) * 0.000001;
	}

	void Reset() {
		start = end = duration = 0;
	}

	void WriteHeader() {
		std::ofstream oStream;
		oStream.open(m_outFile);
		oStream << "str_len,duration," << m_code << "," << m_mod << std::endl;
		oStream.close();
	}


	void WriteCSV() {
		std::ofstream oStream;
		oStream.open(m_outFile, std::ios::app);
		oStream << m_inFile << "," << duration<< std::endl;
		oStream.close();
	}

	
	void SetName(const std::string& bookName) {
		m_inFile = bookName;
	}

	inline void Start() { m_startTimePoint = std::chrono::steady_clock::now(); }
	inline void Stop() { m_endTimepoint = std::chrono::steady_clock::now(); }
	inline void SetBookName(const std::string& name) { m_inFile = name; }
};