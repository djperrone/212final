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
		std::chrono::time_point< std::chrono::steady_clock > endTimepoint = std::chrono::steady_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
		
		auto duration = end - start;
		//double ms = duration * 0.001;
		double ms = duration / 100.0f;
		

		//std::cout << duration << std::endl;
		std::cout << ms << " ms)\n";
	}

private:
	std::chrono::time_point< std::chrono::steady_clock > m_StartTimePoint;
};

struct TimerStruct
{

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	TimerStruct()
	{
		start = std::chrono::steady_clock::now();

	}
	~TimerStruct()
	{
		end = std::chrono::steady_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;

		std::cout << "Timer took " << ms << "ms" << std::endl;

	}

};