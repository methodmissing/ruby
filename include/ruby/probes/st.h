#define PROBE_ST_TABLE_ENTRY(probe,table) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table));\
} while (0)
#define PROBE_ST_TABLE1_ENTRY(probe,table,data1) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1);\
} while (0)
#define PROBE_ST_TABLE2_ENTRY(probe,table,data1,data2) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2);\
} while (0)
#define PROBE_ST_TABLE3_ENTRY(probe,table,data1,data2,data3) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2,(int)data3);\
} while (0)

#define PROBE_ST_TABLE_RETURN(probe,table) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table));\
} while (0)
#define PROBE_ST_TABLE1_RETURN(probe,table,data1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1);\
} while (0)
#define PROBE_ST_TABLE2_RETURN(probe,table,data1,data2) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2);\
} while (0)
#define PROBE_ST_TABLE3_RETURN(probe,table,data1,data2,data3) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((int)table->num_bins,(int)table->num_entries,(int)st_memsize(table),(int)data1,(int)data2,(int)data3);\
} while (0)

#define PROBE_ST_INIT_NUMTABLE_ENTRY() PROBE_ENTRY(ST_INIT_NUMTABLE)
#define PROBE_ST_INIT_NUMTABLE_RETURN() PROBE_RETURN(ST_INIT_NUMTABLE)
#define PROBE_ST_INIT_STRTABLE_ENTRY() PROBE_ENTRY(ST_INIT_STRTABLE)
#define PROBE_ST_INIT_STRTABLE_RETURN() PROBE_RETURN(ST_INIT_STRTABLE)
#define PROBE_ST_INIT_STRCASETABLE_ENTRY() PROBE_ENTRY(ST_INIT_STRCASETABLE)
#define PROBE_ST_INIT_STRCASETABLE_RETURN() PROBE_RETURN(ST_INIT_STRCASETABLE)
#define PROBE_ST_INIT_SIZED_NUMTABLE_ENTRY(size) PROBE_INT_ENTRY(ST_INIT_SIZED_NUMTABLE,size)
#define PROBE_ST_INIT_SIZED_NUMTABLE_RETURN(size) PROBE_INT_RETURN(ST_INIT_SIZED_NUMTABLE,size)
#define PROBE_ST_INIT_SIZED_STRTABLE_ENTRY(size) PROBE_INT_ENTRY(ST_INIT_SIZED_STRTABLE,size)
#define PROBE_ST_INIT_SIZED_STRTABLE_RETURN(size) PROBE_INT_RETURN(ST_INIT_SIZED_STRTABLE,size)
#define PROBE_ST_INIT_SIZED_STRCASETABLE_ENTRY(size) PROBE_INT_ENTRY(ST_INIT_SIZED_STRCASETABLE,size)
#define PROBE_ST_INIT_SIZED_STRCASETABLE_RETURN(size) PROBE_INT_RETURN(ST_INIT_SIZED_STRCASETABLE,size)
#define PROBE_ST_CLEAR_ENTRY(table) PROBE_ST_TABLE_ENTRY(ST_CLEAR,table)
#define PROBE_ST_CLEAR_RETURN(table) PROBE_ST_TABLE_RETURN(ST_CLEAR,table)
#define PROBE_ST_FREE_ENTRY(table) PROBE_ST_TABLE_ENTRY(ST_FREE,table)
#define PROBE_ST_FREE_RETURN(table) PROBE_ST_TABLE_RETURN(ST_FREE,table)
#define PROBE_ST_COPY_ENTRY(table) PROBE_ST_TABLE_ENTRY(ST_COPY,table)
#define PROBE_ST_COPY_RETURN(table) PROBE_ST_TABLE_RETURN(ST_COPY,table)
#define PROBE_ST_CLEANUP_SAFE_ENTRY(table,never) PROBE_ST_TABLE1_ENTRY(ST_CLEANUP_SAFE,table,never)
#define PROBE_ST_CLEANUP_SAFE_RETURN(table,never) PROBE_ST_TABLE1_RETURN(ST_CLEANUP_SAFE,table,never)
#define PROBE_ST_DELETE_ENTRY(table,key,val) PROBE_ST_TABLE2_ENTRY(ST_DELETE,table,key,val)
#define PROBE_ST_DELETE_RETURN(table,key,val) PROBE_ST_TABLE2_RETURN(ST_DELETE,table,key,val)
#define PROBE_ST_DELETE_SAFE_ENTRY(table,key,val,never) PROBE_ST_TABLE3_ENTRY(ST_DELETE_SAFE,table,key,val,never)
#define PROBE_ST_DELETE_SAFE_RETURN(table,key,val,never) PROBE_ST_TABLE3_RETURN(ST_DELETE_SAFE,table,key,val,never)
#define PROBE_ST_INSERT_ENTRY(table,key,val) PROBE_ST_TABLE2_ENTRY(ST_INSERT,table,key,val)
#define PROBE_ST_INSERT_RETURN(table,key,val) PROBE_ST_TABLE2_RETURN(ST_INSERT,table,key,val)
#define PROBE_ST_INSERT2_ENTRY(table,key,val) PROBE_ST_TABLE2_ENTRY(ST_INSERT2,table,key,val)
#define PROBE_ST_INSERT2_RETURN(table,key,val) PROBE_ST_TABLE2_RETURN(ST_INSERT2,table,key,val)
#define PROBE_ST_LOOKUP_ENTRY(table,key,val) PROBE_ST_TABLE2_ENTRY(ST_LOOKUP,table,key,val)
#define PROBE_ST_LOOKUP_RETURN(table,key,val) PROBE_ST_TABLE2_RETURN(ST_LOOKUP,table,key,val)
#define PROBE_ST_ADD_DIRECT_ENTRY(table,key,val) PROBE_ST_TABLE2_ENTRY(ST_ADD_DIRECT,table,key,val)
#define PROBE_ST_ADD_DIRECT_RETURN(table,key,val) PROBE_ST_TABLE2_RETURN(ST_ADD_DIRECT,table,key,val)
#define PROBE_ST_GET_KEY_ENTRY(table,key) PROBE_ST_TABLE1_ENTRY(ST_GET_KEY,table,key)
#define PROBE_ST_GET_KEY_RETURN(table,key) PROBE_ST_TABLE1_RETURN(ST_GET_KEY,table,key)
