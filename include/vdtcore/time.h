/// Copyright (c) Vito Domenico Tagliente

#pragma once

#include <chrono>

namespace core
{
	class Time
	{
	public:

		using clock_t = std::chrono::high_resolution_clock::time_point;

		Time();

		// retrieve the time data
		inline double getTime() const { return m_time; }
		inline double getDeltaTime() const { return m_deltaTime; }
		
		// tick the time
		void tick();

		// reset the time
		void reset();

	private:

		// high resolution clocks
		clock_t m_clock1;
		clock_t m_clock2;

		// cache time and delta time
		double m_time;
		double m_deltaTime;
	};
}