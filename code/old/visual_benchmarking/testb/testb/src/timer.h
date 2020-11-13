#include "rk.h"
class Timer
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

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
		
		auto duration = end - start;
		//double ms = duration * 0.001;
		double ms = duration / 100.0f;
		

		//std::cout << duration << std::endl;
		std::cout << ms << " ms)\n";
	}

private:
	std::chrono::time_point< std::chrono::high_resolution_clock > m_StartTimePoint;
};