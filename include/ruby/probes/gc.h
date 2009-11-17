#define PROBE_OBJSPACE_BEGIN(probe,os) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count);\
} while (0)
#define PROBE_OBJSPACE_END(probe,os) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count);\
} while (0)
#define PROBE_OBJSPACE_PTR_BEGIN(probe,os,pointer) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count, (void *)pointer);\
} while (0)
#define PROBE_OBJSPACE_PTR_END(probe,os,pointer) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count, (void *)pointer);\
} while (0)
#define PROBE_OBJSPACE_PTR_INT_BEGIN(probe,os,pointer,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count, (void *)pointer, (int)val);\
} while (0)
#define PROBE_OBJSPACE_PTR_INT_END(probe,os,pointer,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count, (void *)pointer, (int)val);\
} while (0)
#define PROBE_OBJSPACE_OBJ_BEGIN(probe,os,obj) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count, (char *)rb_obj_classname(obj));\
} while (0)
#define PROBE_OBJSPACE_OBJ_END(probe,os,obj) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count, (char *)rb_obj_classname(obj));\
} while (0)
#define PROBE_GC_OBJSPACE_ALLOC_BEGIN() PROBE_BEGIN(GC_OBJSPACE_ALLOC)
#define PROBE_GC_OBJSPACE_ALLOC_END(objspace) PROBE_OBJSPACE_END(GC_OBJSPACE_ALLOC,objspace)
#define PROBE_GC_OBJSPACE_FREE_BEGIN(objspace) PROBE_OBJSPACE_BEGIN(GC_OBJSPACE_FREE,objspace)
#define PROBE_GC_OBJSPACE_FREE_END() PROBE_END(GC_OBJSPACE_FREE)
#define PROBE_GC_IS_POINTER_TO_HEAP_BEGIN(objspace,pointer) PROBE_OBJSPACE_PTR_BEGIN(GC_IS_POINTER_TO_HEAP,objspace,pointer)
#define PROBE_GC_IS_POINTER_TO_HEAP_END(objspace,pointer) PROBE_OBJSPACE_PTR_END(GC_IS_POINTER_TO_HEAP,objspace,pointer)
#define PROBE_GC_OBJ_FREE_BEGIN(objspace,obj) PROBE_OBJSPACE_OBJ_BEGIN(GC_OBJ_FREE,objspace,obj)
#define PROBE_GC_OBJ_FREE_END(objspace,obj) PROBE_OBJSPACE_OBJ_END(GC_OBJ_FREE,objspace,obj)
#define PROBE_GC_GARBAGE_COLLECT_BEGIN(objspace) PROBE_OBJSPACE_BEGIN(GC_GARBAGE_COLLECT,objspace)
#define PROBE_GC_GARBAGE_COLLECT_END(objspace) PROBE_OBJSPACE_END(GC_GARBAGE_COLLECT,objspace)
#define PROBE_GC_SWEEP_BEGIN(objspace) PROBE_OBJSPACE_BEGIN(GC_SWEEP,objspace)
#define PROBE_GC_SWEEP_END(objspace) PROBE_OBJSPACE_END(GC_SWEEP,objspace)
#define PROBE_GC_FREE_UNUSED_HEAPS_BEGIN(objspace) PROBE_OBJSPACE_BEGIN(GC_FREE_UNUSED_HEAPS,objspace)
#define PROBE_GC_FREE_UNUSED_HEAPS_END(objspace) PROBE_OBJSPACE_END(GC_FREE_UNUSED_HEAPS,objspace)
#define PROBE_GC_ADD_FREELIST_BEGIN(objspace,pointer) PROBE_OBJSPACE_PTR_BEGIN(GC_ADD_FREELIST,objspace,pointer)
#define PROBE_GC_ADD_FREELIST_END(objspace,pointer) PROBE_OBJSPACE_PTR_END(GC_ADD_FREELIST,objspace,pointer)
#define PROBE_GC_MARK_BEGIN(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_BEGIN(GC_MARK,objspace,pointer,level)
#define PROBE_GC_MARK_END(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_END(GC_MARK,objspace,pointer,level)
#define PROBE_GC_MARK_CHILDREN_BEGIN(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_BEGIN(GC_MARK_CHILDREN,objspace,pointer,level)
#define PROBE_GC_MARK_CHILDREN_END(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_END(GC_MARK_CHILDREN,objspace,pointer,level)