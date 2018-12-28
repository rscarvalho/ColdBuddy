#include "utils.h"

void p(const __FlashStringHelper *fmt, ...) {
  char buf[128];
  va_list args;
  va_start(args, fmt);
#ifdef __AVR__
  vsnprintf_P(buf, sizeof(buf), (const char *)fmt, args);
#else
  vsnprintf(buf, sizeof(buf), (const char *)fmt, args);
#endif
  va_end(args);

  Serial.print(buf);
}
