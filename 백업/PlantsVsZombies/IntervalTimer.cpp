#include "IntervalTimer.h"

IntervalTimer::IntervalTimer(int sec)
    : m_interval(sec), m_last(std::chrono::steady_clock::now())
{

}

bool IntervalTimer::HasElapsed() const
{
    return std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::steady_clock::now() - m_last
    ).count() >= m_interval;
}

void IntervalTimer::Tick()
{
    m_last = std::chrono::steady_clock::now();
}