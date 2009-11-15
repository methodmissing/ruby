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
