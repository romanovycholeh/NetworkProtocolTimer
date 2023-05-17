#include "windowstimer.h"

#include <QDebug>

WindowsTimer::WindowsTimer() {}

bool WindowsTimer::SetInterval(UINT_PTR& outTimerHandle,
                               std::chrono::milliseconds delayIntervalMs, TIMERPROC handler) {
  const UINT delayInMilliseconds = static_cast<UINT>(delayIntervalMs.count());
  outTimerHandle = SetTimer(nullptr, 0, delayInMilliseconds, handler);
  if (outTimerHandle == 0) {
      DWORD errorCode = GetLastError();
      qDebug() << "Failed to set timer interval" << Qt::endl
      << "Error code: " << errorCode;
    return false;
  }

  qDebug() << "Timer interval set successfully";
  return true;
}

bool WindowsTimer::Cancel(UINT_PTR timerHandle) {
  if (KillTimer(nullptr, timerHandle) == FALSE) {
      DWORD errorCode = GetLastError();
      qDebug() << "Failed to cancel the timer" << Qt::endl
      << "Error code: " << errorCode;
    return false;
  }

  qDebug() << "Timer canceled successfully";
  return true;
}
