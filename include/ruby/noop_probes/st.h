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