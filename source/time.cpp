#include <vdtcore/time.h>
#include <vdtcore/timer.h>

namespace core
{
	Time::Time()
		: m_clock1(std::chrono::high_resolution_clock::now())
		, m_clock2(std::chrono::high_resolution_clock::now())
		, m_time()
		, m_deltaTime()
	{
	}
	
	void Time::tick()
	{
		m_clock1 = m_clock2;
		m_clock2 = std::chrono::high_resolution_clock::now();

		// m_time to be calculated
		m_deltaTime = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(
			m_clock2 - m_clock1
			).count());

		// update all the timers
		// Timer::update(m_deltaTime);
	}
}