#ifdef ENABLE_DTRACE
#include <sys/sdt.h>
#include "dtrace.h"
#define PROBE_STRING_BEGIN(PROBE,str,len) do {\
  if (RUBY_STRING_##PROBE##_BEGIN_ENABLED())\
   RUBY_STRING_##PROBE##_BEGIN((char*)str, (int)len);\
} while (0)
#define PROBE_STRING_END(PROBE,ptr,len) do {\
  if (RUBY_STRING_##PROBE##_END_ENABLED())\
   RUBY_STRING_##PROBE##_END((char*)ptr, (int)len);\
} while (0)
#define PROBE_EVALSTR_BEGIN() do {\
  if (RUBY_EVAL_BEGIN_ENABLED())\
   RUBY_EVAL_BEGIN();\
} while (0)
#define PROBE_EVALSTR_END() do {\
  if (RUBY_EVAL_END_ENABLED())\
   RUBY_EVAL_END();\
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
#define PROBE_BEGIN(probe) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN();\
} while (0)
#define PROBE_END(probe) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END();\
} while (0)
#define PROBE_SEND_BEGIN() PROBE_BEGIN(SEND)
#define PROBE_SEND_END() PROBE_END(SEND)
#define PROBE_BLOCK_GIVEN_BEGIN() PROBE_BEGIN(BLOCK_GIVEN)
#define PROBE_BLOCK_GIVEN_END() PROBE_END(BLOCK_GIVEN)
#define PROBE_CATCH_BEGIN() PROBE_BEGIN(CATCH)
#define PROBE_CATCH_END() PROBE_END(CATCH)
#define PROBE_THROW_BEGIN() PROBE_BEGIN(THROW)
#define PROBE_THROW_END() PROBE_END(THROW)
#define PROBE_CALLER_BEGIN() PROBE_BEGIN(CALLER)
#define PROBE_CALLER_END() PROBE_END(CALLER)
#define PROBE_CALL_BEGIN() PROBE_BEGIN(CALL)
#define PROBE_CALL_END() PROBE_END(CALL)
#define PROBE_SUPER_BEGIN() PROBE_BEGIN(SUPER)
#define PROBE_SUPER_END() PROBE_END(SUPER)
#define PROBE_METHOD_MISSING_BEGIN() PROBE_BEGIN(METHOD_MISSING)
#define PROBE_METHOD_MISSING_END() PROBE_END(METHOD_MISSING)
#else
#define PROBE_STRING_BEGIN(PROBE,str,len)
#define PROBE_STRING_END(PROBE,str,len)
#define PROBE_EVALSTR_BEGIN
#define PROBE_EVALSTR_END
#define PROBE_EVAL_BEGIN(PROBE)
#define PROBE_EVAL_END(PROBE)
#define PROBE_EXEC_BEGIN(PROBE)
#define PROBE_EXEC_END(PROBE)
#define PROBE_SEND_BEGIN
#define PROBE_SEND_END
#define PROBE_BLOCK_GIVEN_BEGIN
#define PROBE_BLOCK_GIVEN_END
#define PROBE_CATCH_BEGIN
#define PROBE_CATCH_END
#define PROBE_THROW_BEGIN
#define PROBE_THROW_END
#define PROBE_CALLER_BEGIN
#define PROBE_CALLER_END
#define PROBE_CALL_BEGIN
#define PROBE_CALL_END
#define PROBE_SUPER_BEGIN
#define PROBE_SUPER_END
#define PROBE_METHOD_MISSING_BEGIN
#define PROBE_METHOD_MISSING_END
#endif