#ifndef Thread_h
#define Thread_h
#include <Arduino.h>

class Thread {
  private:
    bool _pause;
    uint32_t _time;
    uint32_t _interval;
    void (*_method)(void);
  public:
    void configure(void (*method)(void), const uint32_t interval, const bool pause = false);
    void run();
	bool pause();
    bool resume();
	bool isPause();
};

#endif