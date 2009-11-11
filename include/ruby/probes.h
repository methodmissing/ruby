#ifdef ENABLE_DTRACE
#include "dtrace.h"
#define LINE_PROBE(PROBE) do {\
  if (RUBY_##PROBE##_ENABLED()) \
    RUBY_##PROBE(rb_sourcefile(), rb_sourceline()); \
} while (0)
#else
#define LINE_PROBE(x)
#endif