#include "Thread.h"

/*
 * @param method
 *        action that is launched by timer
 * @param interval
 *        time between actions
 * @param pause
 *        pause a thread or not
 */

void Thread::configure(void (*method)(void), const uint32_t interval, const bool pause) {
  _method = method;
  _interval = interval;
  _pause = pause;
  _time = millis();
}

/*
 * The method runs in the main loop()
 * Launches an action by timer
 */
 
void Thread::run() {
  if (!_pause && millis() - _time >= _interval) {
    _time = millis();
    _method();
  }
}

/*
 * Interrupts a thead
 * @return true if the operation is successful
 */
 
bool Thread::pause() {
  if (!_pause) {
    _pause = true;
	return true;
  }
  return false;
}

/*
 * Runs a thread
 * @return true if the operation is successful
 */
 
bool Thread::resume() {
  if (_pause) {
    _pause = false;
    _time = millis();
	return true;
  }
  return false;
}

/*
 * @return thread state
 */
 
bool Thread::isPause() {
  return _pause;
}