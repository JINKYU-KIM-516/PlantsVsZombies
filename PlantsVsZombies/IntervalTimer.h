#pragma once
#include <chrono>

class IntervalTimer {
private:
    std::chrono::steady_clock::time_point m_last;
    int m_interval;

public:
    IntervalTimer(int p_sec);
    bool HasElapsed() const;  // 상태 확인
    void Tick();              // 상태 갱신
};