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
	std::string m_inFile,m_outFile, m_functionName, m_Pattern;
	long double start, end, duration;

public:
	Timer()
		:m_outFile("timer.csv"), m_inFile("na"), start(0), end(0), duration(0) { WriteHeader(); }
		
	Timer(std::string outFile, const std::string& book,const  std::string& pattern)
		: m_outFile(outFile.append(".csv")), m_inFile(book), start(0), end(0), duration(0){ WriteHeader(); }
		
	Timer(std::string outFile)
		: m_outFile(outFile.append(".csv")), m_inFile("na"), start(0), end(0), duration(0){	WriteHeader(); }

	void Calc(){
		start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
		end = std::chrono::time_point_cast<std::chrono::microseconds>(m_endTimepoint).time_since_epoch().count();
		duration = (end - start) * 0.001;
	}

	void Reset(){
		start = end = duration = 0;
	}

	void WriteCSV(){
		std::ofstream oStream;
		oStream.open(m_outFile, std::ios::app);
		oStream << m_inFile << "," << duration << std::endl;
		oStream.close();
	}

	void WriteHeader(){
		std::ofstream oStream;
		oStream.open(m_outFile);
		//oStream << "key: "<< pattern << std::endl;
		oStream << "file_name,duration" << std::endl;
		oStream.close();
	}

	void SetName(const std::string& bookName){
		m_inFile = bookName;
	}

	inline void Start() { m_startTimePoint = std::chrono::steady_clock::now(); }
	inline void Stop() { m_endTimepoint = std::chrono::steady_clock::now(); }
	inline void SetBookName(const std::string& name) { m_inFile = name; };

};