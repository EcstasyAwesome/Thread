#include <Thread.h>

Thread thread;

void serialPrint() {
  Serial.println("Thread test");
}

void setup() {
  Serial.begin(9600);
  thread.configure(serialPrint, 1000, false);
}

void loop() {
  thread.run();
  if (!thread.isPause() && millis() > 5000) thread.pause();
  else if (thread.isPause() && millis() > 8000) thread.resume();
}