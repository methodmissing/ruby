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
#define PROBE_EVALSTR_BEGIN(self) do {\
  if (RUBY_EVALSTR_BEGIN_ENABLED())\
   RUBY_EVALSTR_BEGIN((char*)rb_obj_classname(self));\
} while (0)
#define PROBE_EVALSTR_END(self) do {\
  if (RUBY_EVALSTR_END_ENABLED())\
   RUBY_EVALSTR_END((char*)rb_obj_classname(self));\
} while (0)
#define PROBE_EVAL_BEGIN(PROBE,self) do {\
  if (RUBY_##PROBE##_EVAL_BEGIN_ENABLED())\
   RUBY_##PROBE##_EVAL_BEGIN((char*)rb_obj_classname(self));\
} while (0)
#define PROBE_EVAL_END(PROBE,self) do {\
  if (RUBY_##PROBE##_EVAL_END_ENABLED())\
   RUBY_##PROBE##_EVAL_END((char*)rb_obj_classname(self));\
} while (0)
#define PROBE_EXEC_BEGIN(PROBE,self) do {\
  if (RUBY_##PROBE##_EXEC_BEGIN_ENABLED())\
   RUBY_##PROBE##_EXEC_BEGIN((char*)rb_obj_classname(self));\
} while (0)
#define PROBE_EXEC_END(PROBE,self) do {\
  if (RUBY_##PROBE##_EXEC_END_ENABLED())\
   RUBY_##PROBE##_EXEC_END((char*)rb_obj_classname(self));\
} while (0)
#define PROBE_BEGIN(probe) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN();\
} while (0)
#define PROBE_ST_TABLE_BEGIN(probe,table) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table));\
} while (0)
#define PROBE_ST_TABLE1_BEGIN(probe,table,data1) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1);\
} while (0)
#define PROBE_ST_TABLE2_BEGIN(probe,table,data1,data2) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2);\
} while (0)
#define PROBE_ST_TABLE3_BEGIN(probe,table,data1,data2,data3) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2,(int)data3);\
} while (0)
#define PROBE_BEGIN_INT(probe,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((int)val);\
} while (0)
#define PROBE_ID_BEGIN(probe,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_BEGIN(probe,class) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class));\
} while (0)
#define PROBE_OBJECT_BEGIN(probe,class) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class));\
} while (0)
#define PROBE_CLASS_AND_ID_BEGIN(probe,class,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_OBJECT_AND_ID_BEGIN(probe,class,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_END(probe) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END();\
} while (0)
#define PROBE_ST_TABLE_END(probe,table) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table));\
} while (0)
#define PROBE_ST_TABLE1_END(probe,table,data1) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1);\
} while (0)
#define PROBE_ST_TABLE2_END(probe,table,data1,data2) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2);\
} while (0)
#define PROBE_ST_TABLE3_END(probe,table,data1,data2,data3) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2,(int)data3);\
} while (0)
#define PROBE_END_INT(probe,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((int)val);\
} while (0)
#define PROBE_ID_END(probe,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_END(probe,class) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class));\
} while (0)
#define PROBE_OBJECT_END(probe,class) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class));\
} while (0)
#define PROBE_CLASS_AND_ID_END(probe,class,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_OBJECT_AND_ID_END(probe,class,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class),(char*)rb_id2name(id));\
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
#define PROBE_METHOD_CALL_BEGIN(obj,id) PROBE_OBJECT_AND_ID_BEGIN(METHOD_CALL,obj,id)
#define PROBE_METHOD_CALL_END(obj,id) PROBE_OBJECT_AND_ID_END(METHOD_CALL,obj,id)
#define PROBE_SUPER_BEGIN() PROBE_BEGIN(SUPER)
#define PROBE_SUPER_END() PROBE_END(SUPER)
#define PROBE_METHOD_MISSING_BEGIN() PROBE_BEGIN(METHOD_MISSING)
#define PROBE_METHOD_MISSING_END() PROBE_END(METHOD_MISSING)
#define PROBE_YIELD_BEGIN() PROBE_BEGIN(YIELD)
#define PROBE_YIELD_END() PROBE_END(YIELD)
#define PROBE_LOOP_BEGIN() PROBE_BEGIN(LOOP)
#define PROBE_LOOP_END() PROBE_END(LOOP)
#define PROBE_BLOCK_CALL_BEGIN(obj,id) PROBE_OBJECT_AND_ID_BEGIN(METHOD_CALL,obj,id)
#define PROBE_BLOCK_CALL_END(obj,id) PROBE_OBJECT_AND_ID_END(METHOD_CALL,obj,id)
#define PROBE_CLEAR_CACHE_BEGIN() PROBE_BEGIN(CLEAR_CACHE)
#define PROBE_CLEAR_CACHE_END() PROBE_END(CLEAR_CACHE)
#define PROBE_VM_CHANGE_STATE_BEGIN(version) PROBE_BEGIN_INT(VM_CHANGE_STATE,version)
#define PROBE_VM_CHANGE_STATE_END(version) PROBE_END_INT(VM_CHANGE_STATE,version)
#define PROBE_CLEAR_CACHE_UNDEF_BEGIN(class,id) PROBE_CLASS_AND_ID_BEGIN(CLEAR_CACHE_UNDEF,class,id)
#define PROBE_CLEAR_CACHE_UNDEF_END(class,id) PROBE_CLASS_AND_ID_END(CLEAR_CACHE_UNDEF,class,id)
#define PROBE_CLEAR_CACHE_ID_BEGIN(id) PROBE_ID_BEGIN(CLEAR_CACHE_ID,id)
#define PROBE_CLEAR_CACHE_ID_END(id) PROBE_ID_END(CLEAR_CACHE_ID,id)
#define PROBE_CLEAR_CACHE_CLASS_BEGIN(class) PROBE_CLASS_BEGIN(CLEAR_CACHE_CLASS,class)
#define PROBE_CLEAR_CACHE_CLASS_END(class) PROBE_CLASS_END(CLEAR_CACHE_CLASS,class)
#define PROBE_ADD_METHOD_BEGIN(class,id) PROBE_CLASS_AND_ID_BEGIN(ADD_METHOD,class,id)
#define PROBE_ADD_METHOD_END(class,id) PROBE_CLASS_AND_ID_END(ADD_METHOD,class,id)
#define PROBE_REMOVE_METHOD_BEGIN(class,id) PROBE_CLASS_AND_ID_BEGIN(REMOVE_METHOD,class,id)
#define PROBE_REMOVE_METHOD_END(class,id) PROBE_CLASS_AND_ID_END(REMOVE_METHOD,class,id)
#define PROBE_METHOD_ENTRY_BEGIN(class,id) PROBE_CLASS_AND_ID_BEGIN(METHOD_ENTRY,class,id)
#define PROBE_METHOD_ENTRY_END(class,id) PROBE_CLASS_AND_ID_END(METHOD_ENTRY,class,id)
#define PROBE_ST_INIT_NUMTABLE_BEGIN() PROBE_BEGIN(ST_INIT_NUMTABLE)
#define PROBE_ST_INIT_NUMTABLE_END() PROBE_END(ST_INIT_NUMTABLE)
#define PROBE_ST_INIT_STRTABLE_BEGIN() PROBE_BEGIN(ST_INIT_STRTABLE)
#define PROBE_ST_INIT_STRTABLE_END() PROBE_END(ST_INIT_STRTABLE)
#define PROBE_ST_INIT_STRCASETABLE_BEGIN() PROBE_BEGIN(ST_INIT_STRCASETABLE)
#define PROBE_ST_INIT_STRCASETABLE_END() PROBE_END(ST_INIT_STRCASETABLE)
#define PROBE_ST_INIT_SIZED_NUMTABLE_BEGIN(size) PROBE_BEGIN_INT(ST_INIT_SIZED_NUMTABLE,size)
#define PROBE_ST_INIT_SIZED_NUMTABLE_END(size) PROBE_END_INT(ST_INIT_SIZED_NUMTABLE,size)
#define PROBE_ST_INIT_SIZED_STRTABLE_BEGIN(size) PROBE_BEGIN_INT(ST_INIT_SIZED_STRTABLE,size)
#define PROBE_ST_INIT_SIZED_STRTABLE_END(size) PROBE_END_INT(ST_INIT_SIZED_STRTABLE,size)
#define PROBE_ST_INIT_SIZED_STRCASETABLE_BEGIN(size) PROBE_BEGIN_INT(ST_INIT_SIZED_STRCASETABLE,size)
#define PROBE_ST_INIT_SIZED_STRCASETABLE_END(size) PROBE_END_INT(ST_INIT_SIZED_STRCASETABLE,size)
#define PROBE_ST_CLEAR_BEGIN(table) PROBE_ST_TABLE_BEGIN(ST_CLEAR,table)
#define PROBE_ST_CLEAR_END(table) PROBE_ST_TABLE_END(ST_CLEAR,table)
#define PROBE_ST_FREE_BEGIN(table) PROBE_ST_TABLE_BEGIN(ST_FREE,table)
#define PROBE_ST_FREE_END(table) PROBE_ST_TABLE_END(ST_FREE,table)
#define PROBE_ST_COPY_BEGIN(table) PROBE_ST_TABLE_BEGIN(ST_COPY,table)
#define PROBE_ST_COPY_END(table) PROBE_ST_TABLE_END(ST_COPY,table)
#define PROBE_ST_CLEANUP_SAFE_BEGIN(table,never) PROBE_ST_TABLE1_BEGIN(ST_CLEANUP_SAFE,table,never)
#define PROBE_ST_CLEANUP_SAFE_END(table,never) PROBE_ST_TABLE1_END(ST_CLEANUP_SAFE,table,never)
#define PROBE_ST_DELETE_BEGIN(table,key,val) PROBE_ST_TABLE2_BEGIN(ST_DELETE,table,key,val)
#define PROBE_ST_DELETE_END(table,key,val) PROBE_ST_TABLE2_END(ST_DELETE,table,key,val)
#define PROBE_ST_DELETE_SAFE_BEGIN(table,key,val,never) PROBE_ST_TABLE3_BEGIN(ST_DELETE_SAFE,table,key,val,never)
#define PROBE_ST_DELETE_SAFE_END(table,key,val,never) PROBE_ST_TABLE3_END(ST_DELETE_SAFE,table,key,val,never)
#define PROBE_ST_INSERT_BEGIN(table,key,val) PROBE_ST_TABLE2_BEGIN(ST_INSERT,table,key,val)
#define PROBE_ST_INSERT_END(table,key,val) PROBE_ST_TABLE2_END(ST_INSERT,table,key,val)
#define PROBE_ST_INSERT2_BEGIN(table,key,val) PROBE_ST_TABLE2_BEGIN(ST_INSERT2,table,key,val)
#define PROBE_ST_INSERT2_END(table,key,val) PROBE_ST_TABLE2_END(ST_INSERT2,table,key,val)
#define PROBE_ST_LOOKUP_BEGIN(table,key,val) PROBE_ST_TABLE2_BEGIN(ST_LOOKUP,table,key,val)
#define PROBE_ST_LOOKUP_END(table,key,val) PROBE_ST_TABLE2_END(ST_LOOKUP,table,key,val)
#define PROBE_ST_ADD_DIRECT_BEGIN(table,key,val) PROBE_ST_TABLE2_BEGIN(ST_ADD_DIRECT,table,key,val)
#define PROBE_ST_ADD_DIRECT_END(table,key,val) PROBE_ST_TABLE2_END(ST_ADD_DIRECT,table,key,val)
#define PROBE_ST_GET_KEY_BEGIN(table,key) PROBE_ST_TABLE1_BEGIN(ST_GET_KEY,table,key)
#define PROBE_ST_GET_KEY_END(table,key) PROBE_ST_TABLE1_END(ST_GET_KEY,table,key)
#else
#define PROBE_STRING_BEGIN(PROBE,str,len)
#define PROBE_STRING_END(PROBE,str,len)
#define PROBE_EVALSTR_BEGIN(self)
#define PROBE_EVALSTR_END(self)
#define PROBE_EVAL_BEGIN(PROBE)
#define PROBE_EVAL_END(PROBE)
#define PROBE_EXEC_BEGIN(PROBE)
#define PROBE_EXEC_END(PROBE)
#define PROBE_SEND_BEGIN()
#define PROBE_SEND_END()
#define PROBE_BLOCK_GIVEN_BEGIN()
#define PROBE_BLOCK_GIVEN_END()
#define PROBE_CATCH_BEGIN()
#define PROBE_CATCH_END()
#define PROBE_THROW_BEGIN()
#define PROBE_THROW_END()
#define PROBE_CALLER_BEGIN()
#define PROBE_CALLER_END()
#define PROBE_METHOD_CALL_BEGIN(obj,id)
#define PROBE_METHOD_CALL_END(obj,id)
#define PROBE_SUPER_BEGIN()
#define PROBE_SUPER_END()
#define PROBE_METHOD_MISSING_BEGIN()
#define PROBE_METHOD_MISSING_END()
#define PROBE_YIELD_BEGIN()
#define PROBE_YIELD_END()
#define PROBE_LOOP_BEGIN()
#define PROBE_LOOP_END()
#define PROBE_BLOCK_CALL_BEGIN(obj,id)
#define PROBE_BLOCK_CALL_END(obj,id)
#define PROBE_CLEAR_CACHE_BEGIN()
#define PROBE_CLEAR_CACHE_END()
#define PROBE_VM_CHANGE_STATE_BEGIN(version)
#define PROBE_VM_CHANGE_STATE_END(version)
#define PROBE_CLEAR_CACHE_UNDEF_BEGIN(class,id)
#define PROBE_CLEAR_CACHE_UNDEF_END(class,id)
#define PROBE_CLEAR_CACHE_ID_BEGIN(id)
#define PROBE_CLEAR_CACHE_ID_END(id)
#define PROBE_CLEAR_CACHE_CLASS_BEGIN(class)
#define PROBE_CLEAR_CACHE_CLASS_END(class)
#define PROBE_ADD_METHOD_BEGIN(class,id)
#define PROBE_ADD_METHOD_END(class,id)
#define PROBE_REMOVE_METHOD_BEGIN(class,id)
#define PROBE_REMOVE_METHOD_END(class,id)
#define PROBE_METHOD_ENTRY_BEGIN(class,id)
#define PROBE_METHOD_ENTRY_END(class,id)
#define PROBE_ST_INIT_NUMTABLE_BEGIN()
#define PROBE_ST_INIT_NUMTABLE_END()
#define PROBE_ST_INIT_SIZED_NUMTABLE_BEGIN(size)
#define PROBE_ST_INIT_SIZED_NUMTABLE_END(size)
#define PROBE_ST_INIT_STRTABLE_BEGIN()
#define PROBE_ST_INIT_STRTABLE_END()
#define PROBE_ST_INIT_SIZED_STRTABLE_BEGIN(size)
#define PROBE_ST_INIT_SIZED_STRTABLE_END(size)
#define PROBE_ST_INIT_STRCASETABLE_BEGIN()
#define PROBE_ST_INIT_STRCASETABLE_END()
#define PROBE_ST_INIT_SIZED_STRCASETABLE_BEGIN(size)
#define PROBE_ST_INIT_SIZED_STRCASETABLE_END(size)
#define PROBE_ST_CLEAR_BEGIN(table)
#define PROBE_ST_CLEAR_END(table)
#define PROBE_ST_FREE_BEGIN(table)
#define PROBE_ST_FREE_END(table)
#define PROBE_ST_COPY_BEGIN(table)
#define PROBE_ST_COPY_END(table)
#define PROBE_ST_CLEANUP_SAFE_BEGIN(table,never)
#define PROBE_ST_CLEANUP_SAFE_END(table,never)
#define PROBE_ST_DELETE_BEGIN(table,key,val)
#define PROBE_ST_DELETE_END(table,key,val)
#define PROBE_ST_DELETE_SAFE_BEGIN(table,key,val,never)
#define PROBE_ST_DELETE_SAFE_END(table,key,val,never)
#define PROBE_ST_INSERT_BEGIN(table,key,val)
#define PROBE_ST_INSERT_END(table,key,val)
#define PROBE_ST_INSERT2_BEGIN(table,key,val)
#define PROBE_ST_INSERT2_END(table,key,val)
#define PROBE_ST_LOOKUP_BEGIN(table,key,val)
#define PROBE_ST_LOOKUP_END(table,key,val)
#define PROBE_ST_ADD_DIRECT_BEGIN(table,key,val)
#define PROBE_ST_ADD_DIRECT_END(table,key,val)
#define PROBE_ST_GET_KEY_BEGIN(table,key)
#define PROBE_ST_GET_KEY_END(table,key)
#endif