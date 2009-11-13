#ifdef ENABLE_DTRACE
#include <sys/sdt.h>
#include "dtrace.h"
#define PROBE_STRING_BEGIN(PROBE,str,len) do {\
  if (RUBY_STRING_##PROBE##_BEGIN_ENABLED())\
   RUBY_STRING_##PROBE##_BEGIN((char*)str, (int)len);\
} while (0)
#define PROBE_EVALSTR_BEGIN() do {\
  if (RUBY_EVAL_BEGIN_ENABLED())\
   RUBY_EVAL_BEGIN();\
} while (0)
#define PROBE_EVALSTR_END() do {\
  if (RUBY_EVAL_END_ENABLED())\
   RUBY_EVAL_END();\
} while (0)
#define PROBE_SEND_BEGIN() do {\
  if (RUBY_SEND_BEGIN_ENABLED())\
   RUBY_SEND_BEGIN();\
} while (0)
#define PROBE_SEND_END() do {\
  if (RUBY_SEND_END_ENABLED())\
   RUBY_SEND_END();\
} while (0)
#define PROBE_STRING_END(PROBE,ptr,len) do {\
  if (RUBY_STRING_##PROBE##_END_ENABLED())\
   RUBY_STRING_##PROBE##_END((char*)ptr, (int)len);\
} while (0)
#define PROBE_EVAL_BEGIN(PROBE) do {\
  if (RUBY_##PROBE##_EVAL_BEGIN_ENABLED())\
   RUBY_##PROBE##_EVAL_BEGIN();\
} while (0)
#define PROBE_EVAL_END(PROBE) do {\
  if (RUBY_##PROBE##_EVAL_END_ENABLED())\
   RUBY_##PROBE##_EVAL_END();\
} while (0)
#define PROBE_EXEC_BEGIN(PROBE) do {\
  if (RUBY_##PROBE##_EXEC_BEGIN_ENABLED())\
   RUBY_##PROBE##_EXEC_BEGIN();\
} while (0)
#define PROBE_EXEC_END(PROBE) do {\
  if (RUBY_##PROBE##_EXEC_END_ENABLED())\
   RUBY_##PROBE##_EXEC_END();\
} while (0)
#else
#define PROBE_STRING_BEGIN(PROBE,str,len)
#define PROBE_STRING_END(PROBE,str,len)
#define PROBE_EVAL_BEGIN(PROBE)
#define PROBE_EVAL_END(PROBE)
#define PROBE_EXEC_BEGIN(PROBE)
#define PROBE_EXEC_END(PROBE)
#define PROBE_SEND()
#define PROBE_EVAL()
#endif