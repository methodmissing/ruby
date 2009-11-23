#define PROBE_FIBER_ENTRY(probe,fib) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_obj_classname(fib->prev),(int)fib->status);\
} while (0)
#define PROBE_FIBER_RETURN(probe,fib) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(fib->prev),(int)fib->status);\
} while (0)

#define PROBE_FIBER_MARK_ENTRY(fiber) PROBE_FIBER_ENTRY(FIBER_MARK,fiber)
#define PROBE_FIBER_MARK_RETURN(fiber) PROBE_FIBER_RETURN(FIBER_MARK,fiber)
#define PROBE_FIBER_FREE_ENTRY(fiber) PROBE_FIBER_ENTRY(FIBER_FREE,fiber)
#define PROBE_FIBER_FREE_RETURN(fiber) PROBE_FIBER_RETURN(FIBER_FREE,fiber)
#define PROBE_FIBER_SWITCH_ENTRY(fiber) PROBE_FIBER_ENTRY(FIBER_SWITCH,fiber)
#define PROBE_FIBER_SWITCH_RETURN(fiber) PROBE_FIBER_RETURN(FIBER_SWITCH,fiber)
#define PROBE_FIBER_START_ENTRY(fiber) PROBE_FIBER_ENTRY(FIBER_START,fiber)
#define PROBE_FIBER_START_RETURN(fiber) PROBE_FIBER_RETURN(FIBER_START,fiber)
#define PROBE_FIBER_TERMINATE_ENTRY(fiber) PROBE_FIBER_ENTRY(FIBER_TERMINATE,fiber)
#define PROBE_FIBER_TERMINATE_RETURN(fiber) PROBE_FIBER_RETURN(FIBER_TERMINATE,fiber)