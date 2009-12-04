#define OBJECT_SPACE_ARGS(os) (long)os->malloc_params.limit, (long)os->malloc_params.increase, (long)os->heap.increment, (long)os->heap.length, (long)os->heap.used, (unsigned int)os->count 

#define PROBE_OBJSPACE_ENTRY(probe,os) PROBE_ENTRY(probe,OBJECT_SPACE_ARGS(os))
#define PROBE_OBJSPACE_RETURN(probe,os) PROBE_RETURN(probe,OBJECT_SPACE_ARGS(os))
#define PROBE_OBJSPACE_PTR_ENTRY(probe,os,ptr) PROBE_ENTRY(probe,OBJECT_SPACE_ARGS(os),(void*)ptr)
#define PROBE_OBJSPACE_PTR_RETURN(probe,os,ptr) PROBE_RETURN(probe,OBJECT_SPACE_ARGS(os),(void*)ptr)
#define PROBE_OBJSPACE_PTR_INT_ENTRY(probe,os,ptr,val) PROBE_ENTRY(probe,OBJECT_SPACE_ARGS(os),(void*)ptr,(int)val)
#define PROBE_OBJSPACE_PTR_INT_RETURN(probe,os,ptr,val) PROBE_RETURN(probe,OBJECT_SPACE_ARGS(os),(void*)ptr,(int)val)
#define PROBE_OBJSPACE_OBJ_ENTRY(probe,os,obj) PROBE_ENTRY(probe,OBJECT_SPACE_ARGS(os),(unsigned long)rb_obj_id(obj))
#define PROBE_OBJSPACE_OBJ_RETURN(probe,os,obj) PROBE_RETURN(probe,OBJECT_SPACE_ARGS(os),(unsigned long)rb_obj_id(obj))

#define PROBE_GC_OBJSPACE_ALLOC_ENTRY() PROBE_ENTRY(GC_OBJSPACE_ALLOC)
#define PROBE_GC_OBJSPACE_ALLOC_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_OBJSPACE_ALLOC,objspace)
#define PROBE_GC_OBJSPACE_FREE_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_OBJSPACE_FREE,objspace)
#define PROBE_GC_OBJSPACE_FREE_RETURN() PROBE_RETURN(GC_OBJSPACE_FREE)
#define PROBE_GC_IS_POINTER_TO_HEAP_ENTRY(objspace,pointer) PROBE_OBJSPACE_PTR_ENTRY(GC_IS_POINTER_TO_HEAP,objspace,pointer)
#define PROBE_GC_IS_POINTER_TO_HEAP_RETURN(objspace,pointer) PROBE_OBJSPACE_PTR_RETURN(GC_IS_POINTER_TO_HEAP,objspace,pointer)
#define PROBE_GC_OBJ_FREE_ENTRY(objspace,obj) PROBE_OBJSPACE_OBJ_ENTRY(GC_OBJ_FREE,objspace,obj)
#define PROBE_GC_OBJ_FREE_RETURN(objspace,obj) PROBE_OBJSPACE_OBJ_RETURN(GC_OBJ_FREE,objspace,obj)
#define PROBE_GC_GARBAGE_COLLECT_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_GARBAGE_COLLECT,objspace)
#define PROBE_GC_GARBAGE_COLLECT_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_GARBAGE_COLLECT,objspace)
#define PROBE_GC_SWEEP_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_SWEEP,objspace)
#define PROBE_GC_SWEEP_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_SWEEP,objspace)
#define PROBE_GC_FREE_UNUSED_HEAPS_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_FREE_UNUSED_HEAPS,objspace)
#define PROBE_GC_FREE_UNUSED_HEAPS_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_FREE_UNUSED_HEAPS,objspace)
#define PROBE_GC_ADD_FREELIST_ENTRY(objspace,pointer) PROBE_OBJSPACE_PTR_ENTRY(GC_ADD_FREELIST,objspace,pointer)
#define PROBE_GC_ADD_FREELIST_RETURN(objspace,pointer) PROBE_OBJSPACE_PTR_RETURN(GC_ADD_FREELIST,objspace,pointer)
#define PROBE_GC_MARK_ENTRY(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_ENTRY(GC_MARK,objspace,pointer,level)
#define PROBE_GC_MARK_RETURN(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_RETURN(GC_MARK,objspace,pointer,level)
#define PROBE_GC_MARK_CHILDREN_ENTRY(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_ENTRY(GC_MARK_CHILDREN,objspace,pointer,level)
#define PROBE_GC_MARK_CHILDREN_RETURN(objspace,pointer,level) PROBE_OBJSPACE_PTR_INT_RETURN(GC_MARK_CHILDREN,objspace,pointer,level)
#define PROBE_GC_HEAPS_INCREMENT_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_HEAPS_INCREMENT,objspace)
#define PROBE_GC_HEAPS_INCREMENT_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_HEAPS_INCREMENT,objspace)
#define PROBE_GC_ASSIGN_HEAP_SLOT_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_ASSIGN_HEAP_SLOT,objspace)
#define PROBE_GC_ASSIGN_HEAP_SLOT_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_ASSIGN_HEAP_SLOT,objspace)

#define PROBE_GC_NEWOBJ_ENTRY() PROBE_ENTRY(GC_NEWOBJ)
#define PROBE_GC_NEWOBJ_RETURN(obj) PROBE_RETURN(GC_NEWOBJ,(unsigned long)rb_obj_id(obj))
#define PROBE_GC_NEWNODE_ENTRY(type) PROBE_ENTRY(GC_NEWNODE,(int)type)
#define PROBE_GC_NEWNODE_RETURN(type) PROBE_RETURN(GC_NEWNODE,(int)type)
#define PROBE_GC_INIT_HEAP_ENTRY(objspace) PROBE_OBJSPACE_ENTRY(GC_INIT_HEAP,objspace)
#define PROBE_GC_INIT_HEAP_RETURN(objspace) PROBE_OBJSPACE_RETURN(GC_INIT_HEAP,objspace)