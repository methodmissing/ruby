#define PROBE_INS_GETLOCAL_BEGIN(idx) PROBE_ULONG_BEGIN(INS_GETLOCAL,idx)
#define PROBE_INS_GETLOCAL_END(obj) PROBE_OBJECT_END(INS_GETLOCAL,obj)
#define PROBE_INS_SETLOCAL_BEGIN(idx,obj) PROBE_ULONG_OBJECT_BEGIN(INS_SETLOCAL,idx,obj)
#define PROBE_INS_SETLOCAL_END(obj) PROBE_END(INS_SETLOCAL)
#define PROBE_INS_GETDYNAMIC_BEGIN(idx,level) PROBE_ULONG1_BEGIN(INS_GETDYNAMIC,idx,level)
#define PROBE_INS_GETDYNAMIC_END(obj) PROBE_OBJECT_END(INS_GETDYNAMIC,obj)
#define PROBE_INS_SETDYNAMIC_BEGIN(idx,level,obj) PROBE_ULONG1_OBJECT_BEGIN(INS_SETDYNAMIC,idx,level,obj)
#define PROBE_INS_SETDYNAMIC_END() PROBE_END(INS_SETDYNAMIC) 