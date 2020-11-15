<<<<<<< HEAD
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
	std::string m_inFile,m_outFile, m_functionName;
	long double start, end, duration;

public:
	Timer()
		:m_outFile("timer.csv"), m_inFile("nan"),start(0),end(0),duration(0) {}
	Timer(std::string out, std::string book)
		: m_outFile(out.append(".csv")),m_inFile(book),start(0),end(0),duration(0){}
	~Timer() {}

	void Start()
	{
		m_startTimePoint = std::chrono::steady_clock::now();
	}

	void Stop()
	{
		m_endTimepoint = std::chrono::steady_clock::now();

		start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
		end = std::chrono::time_point_cast<std::chrono::microseconds>(m_endTimepoint).time_since_epoch().count();

		duration = (end - start) * 0.001;
	}

	void Reset()
	{
		start = end = duration = 0;
	}

	void Header()
	{
		std::ofstream oStream;
		oStream.open(m_outFile);
		oStream << "file_name,duration" << std::endl;
		oStream.close();
	}

	void WriteCSV()
	{
		std::ofstream oStream;
		oStream.open(m_outFile,std::ios::app);

		oStream << m_inFile  << "," << duration << std::endl;
		oStream.close();
	}

		void SetName(const std::string& name)
	{
		m_inFile = name;
	}
};




// #include <iostream>
// #include <chrono>
// #include <fstream>
// #include <string>

// class Timer1
// {
// public:
// 	Timer1()
// 	{
// 		m_StartTimePoint = std::chrono::steady_clock::now();
// 	}

// 	~Timer1()
// 	{
// 		Stop();
// 	}

// 	void Stop()
// 	{
// 		auto endTimepoint = std::chrono::steady_clock::now();

// 		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
// 		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

// 		auto duration = end - start;
// 		double ms = duration * 0.001;
// 		//double ms = duration / 100.0f;


// 		//std::cout << duration << std::endl;
// 		std::cout << ms << " ms\n";
// 	}


// private:
// 	std::chrono::time_point< std::chrono::steady_clock > m_StartTimePoint;
// };
=======
#include "rk.h"
class Timer
{
public:
	Timer()
	{
		m_StartTimePoint = std::chrono::steady_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::steady_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
		
		auto duration = end - start;
		double ms = duration * 0.001;
		//double ms = duration / 100.0f;
		

		//std::cout << duration << std::endl;
	std::cout << ms << " ms\n";
	}

private:
	std::chrono::time_point< std::chrono::steady_clock > m_StartTimePoint;
};
>>>>>>> cb218b3a77751bcaae0797331dae5c072ec3abaa
