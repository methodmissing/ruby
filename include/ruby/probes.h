#ifdef ENABLE_DTRACE
#include "dtrace.h"
#define PROBE_LOCATION(PROBE) do {\
  if (RUBY_##PROBE##_LOCATION_ENABLED()) \
    RUBY_##PROBE##_LOCATION(rb_sourcefile(), rb_sourceline()); \
} while (0)
#else
#define PROBE_LOCATION(x)
#endif