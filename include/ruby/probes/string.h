#define PROBE_STRING_BEGIN(PROBE,str) do {\
  if (RUBY_STR_##PROBE##_BEGIN_ENABLED())\
   RUBY_STR_##PROBE##_BEGIN((char*)RSTRING_PTR(str));\
} while (0)
#define PROBE_STRING_INT_BEGIN(PROBE,str,len) do {\
  if (RUBY_STR_##PROBE##_BEGIN_ENABLED())\
   RUBY_STR_##PROBE##_BEGIN((char*)RSTRING_PTR(str),len);\
} while (0)
#define PROBE_STRING1_BEGIN(PROBE,str,str2) do {\
  if (RUBY_STR_##PROBE##_BEGIN_ENABLED())\
   RUBY_STR_##PROBE##_BEGIN((char*)RSTRING_PTR(str),(char*)RSTRING_PTR(str2));\
} while (0)
#define PROBE_STRING_END(PROBE,str) do {\
  if (RUBY_STR_##PROBE##_END_ENABLED())\
   RUBY_STR_##PROBE##_END((char*)RSTRING_PTR(str));\
} while (0)
#define PROBE_STRING_INT_END(PROBE,str,len) do {\
  if (RUBY_STR_##PROBE##_END_ENABLED())\
   RUBY_STR_##PROBE##_END((char*)RSTRING_PTR(str),len);\
} while (0)
#define PROBE_STRING1_END(PROBE,str,str2) do {\
  if (RUBY_STR_##PROBE##_END_ENABLED())\
   RUBY_STR_##PROBE##_END((char*)RSTRING_PTR(str),(char*)RSTRING_PTR(str2));\
} while (0)

#define PROBE_STR_NEW_BEGIN(ptr,len) PROBE_STR_INT_BEGIN(STR_NEW,ptr,len)
#define PROBE_STR_NEW_END(ptr,len) PROBE_STR_INT_END(STR_NEW,ptr,len)
#define PROBE_STR_NEW_SHARED_BEGIN(str) PROBE_STRING_BEGIN(NEW_SHARED,str)
#define PROBE_STR_NEW_SHARED_END(str) PROBE_STRING_END(NEW_SHARED,str)
#define PROBE_STR_FREE_BEGIN(str) PROBE_STRING_BEGIN(FREE,str)
#define PROBE_STR_FREE_END(str) PROBE_STRING_END(FREE,str)
#define PROBE_STR_DUP_BEGIN(str) PROBE_STRING_BEGIN(DUP,str)
#define PROBE_STR_DUP_END(str) PROBE_STRING_END(DUP,str)
#define PROBE_STR_REPLACE_BEGIN(str,str2) PROBE_STRING1_BEGIN(REPLACE,str,str2)
#define PROBE_STR_REPLACE_END(str,str2) PROBE_STRING1_END(REPLACE,str,str2)
#define PROBE_STR_SHARED_REPLACE_BEGIN(str,str2) PROBE_STRING1_BEGIN(SHARED_REPLACE,str,str2)
#define PROBE_STR_SHARED_REPLACE_END(str,str2) PROBE_STRING1_END(SHARED_REPLACE,str,str2)
#define PROBE_STR_BUF_NEW_BEGIN(size) PROBE_INT_BEGIN(STR_BUF_NEW,size)
#define PROBE_STR_BUF_NEW_END(size) PROBE_INT_END(STR_BUF_NEW,size)
#define PROBE_STR_BUF_CSTR_NEW_BEGIN(ptr) PROBE_STR_BEGIN(STR_BUF_CSTR_NEW,ptr)
#define PROBE_STR_BUF_CSTR_NEW_END(ptr) PROBE_STR_END(STR_BUF_CSTR_NEW,ptr)
#define PROBE_STR_RESIZE_CAPACITY_BEGIN(str,cap) PROBE_STRING_INT_BEGIN(RESIZE_CAPACITY,str,cap)
#define PROBE_STR_RESIZE_CAPACITY_END(str,cap) PROBE_STRING_INT_END(RESIZE_CAPACITY,str,cap)
#define PROBE_STR_DEC_LENGTH_BEGIN(str) PROBE_STRING_BEGIN(DEC_LENGTH,str)
#define PROBE_STR_DEC_LENGTH_END(str) PROBE_STRING_END(DEC_LENGTH,str)
#define PROBE_STR_SET_LENGTH_BEGIN(str,len) PROBE_STRING_INT_BEGIN(SET_LENGTH,str,len)
#define PROBE_STR_SET_LENGTH_END(str,len) PROBE_STRING_INT_END(SET_LENGTH,str,len)