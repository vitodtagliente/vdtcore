#include <vdtcore/time.h>
#include <vdtcore/timer.h>

namespace core
{
	Time::Time()
		: m_begin_clock()
		, m_clock1()
		, m_clock2()
		, m_time()
		, m_deltaTime()
	{
		m_begin_clock = m_clock1 = m_clock2 = std::chrono::high_resolution_clock::now();
	}										  
	
	void Time::tick()
	{
		m_clock1 = m_clock2;
		m_clock2 = std::chrono::high_resolution_clock::now();

		m_time = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(
			m_clock2 - m_begin_clock
			).count());

		m_deltaTime = static_cast<double>(std::chrono::duration_cast<std::chrono::milliseconds>(
			m_clock2 - m_clock1
			).count());

		// update all the timers
		// Timer::update(m_deltaTime);
	}

	void Time::reset()
	{
		m_begin_clock = m_clock1 = m_clock2 = std::chrono::high_resolution_clock::now();
		m_time = 0;
		m_deltaTime = 0;
	}
}