#ifndef WINDOWSTIMER_H
#define WINDOWSTIMER_H

#include <Windows.h>
#include <chrono>

class WindowsTimer
{
public:
    WindowsTimer();

    bool SetInterval(UINT_PTR& outTimerHandle, std::chrono::milliseconds delayIntervalMs, TIMERPROC handler);
    bool Cancel(UINT_PTR timerHandle);

    ~WindowsTimer() = default;
};

#endif // WINDOWSTIMER_H
