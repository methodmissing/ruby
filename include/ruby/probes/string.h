#define PROBE_STRING_BEGIN(PROBE,str,len) do {\
  if (RUBY_STRING_##PROBE##_BEGIN_ENABLED())\
   RUBY_STRING_##PROBE##_BEGIN((char*)str, (int)len);\
} while (0)
#define PROBE_STRING_END(PROBE,ptr,len) do {\
  if (RUBY_STRING_##PROBE##_END_ENABLED())\
   RUBY_STRING_##PROBE##_END((char*)ptr, (int)len);\
} while (0)
