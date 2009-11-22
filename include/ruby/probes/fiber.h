#define PROBE_FIBER_BEGIN(probe,fib) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(fib->prev),(int)fib->status);\
} while (0)
#define PROBE_FIBER_END(probe,fib) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(fib->prev),(int)fib->status);\
} while (0)

#define PROBE_FIBER_MARK_BEGIN(fiber) PROBE_FIBER_BEGIN(FIBER_MARK,fiber)
#define PROBE_FIBER_MARK_END(fiber) PROBE_FIBER_END(FIBER_MARK,fiber)
#define PROBE_FIBER_FREE_BEGIN(fiber) PROBE_FIBER_BEGIN(FIBER_FREE,fiber)
#define PROBE_FIBER_FREE_END(fiber) PROBE_FIBER_END(FIBER_FREE,fiber)
#define PROBE_FIBER_SWITCH_BEGIN(fiber) PROBE_FIBER_BEGIN(FIBER_SWITCH,fiber)
#define PROBE_FIBER_SWITCH_END(fiber) PROBE_FIBER_END(FIBER_SWITCH,fiber)
#define PROBE_FIBER_START_BEGIN(fiber) PROBE_FIBER_BEGIN(FIBER_START,fiber)
#define PROBE_FIBER_START_END(fiber) PROBE_FIBER_END(FIBER_START,fiber)
#define PROBE_FIBER_TERMINATE_BEGIN(fiber) PROBE_FIBER_BEGIN(FIBER_TERMINATE,fiber)
#define PROBE_FIBER_TERMINATE_END(fiber) PROBE_FIBER_END(FIBER_TERMINATE,fiber)