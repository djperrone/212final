#include "rk.h"
class TimerClass
{
public:
	Timer()
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
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

		std::cout << duration << "us (" << ms << "ms)\n";
	}

private:
	std::chrono::time_point< std::chrono::high_resolution_clock > m_StartTimePoint;
};

struct TimerStruct
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