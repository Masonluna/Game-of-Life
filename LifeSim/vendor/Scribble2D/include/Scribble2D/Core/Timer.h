#pragma once
#include <chrono>



namespace Scribble {

	class Timer
	{
	public:
		Timer()
		{
			Reset();
		}
		~Timer() = default;

		void Reset()
		{
			m_Start = std::chrono::high_resolution_clock::now();
		}

		float TimePassed()
		{
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.000000001f;
		}
		float TimePassedMillis()
		{
			return TimePassed() * 1000.f;
		}
	private:
		// SomeDataType m_Start;
		std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
	};

}