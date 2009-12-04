#define PROBE_MT_CLEAR_CACHE_ENTRY() PROBE_ENTRY(MT_CLEAR_CACHE)
#define PROBE_MT_CLEAR_CACHE_RETURN() PROBE_RETURN(MT_CLEAR_CACHE)
#define PROBE_MT_CLEAR_CACHE_UNDEF_ENTRY(class,id) PROBE_CLASS_AND_ID_ENTRY(MT_CLEAR_CACHE_UNDEF,class,id)
#define PROBE_MT_CLEAR_CACHE_UNDEF_RETURN(class,id) PROBE_CLASS_AND_ID_RETURN(MT_CLEAR_CACHE_UNDEF,class,id)
#define PROBE_MT_CLEAR_CACHE_ID_ENTRY(id) PROBE_ID_ENTRY(MT_CLEAR_CACHE_ID,id)
#define PROBE_MT_CLEAR_CACHE_ID_RETURN(id) PROBE_ID_RETURN(MT_CLEAR_CACHE_ID,id)
#define PROBE_MT_CLEAR_CACHE_CLASS_ENTRY(class) PROBE_CLASS_ENTRY(MT_CLEAR_CACHE_CLASS,class)
#define PROBE_MT_CLEAR_CACHE_CLASS_RETURN(class) PROBE_CLASS_RETURN(MT_CLEAR_CACHE_CLASS,class)
#define PROBE_MT_ADD_METHOD_ENTRY(class,id) PROBE_CLASS_AND_ID_ENTRY(MT_ADD_METHOD,class,id)
#define PROBE_MT_ADD_METHOD_RETURN(class,id) PROBE_CLASS_AND_ID_RETURN(MT_ADD_METHOD,class,id)
#define PROBE_MT_REMOVE_METHOD_ENTRY(class,id) PROBE_CLASS_AND_ID_ENTRY(MT_REMOVE_METHOD,class,id)
#define PROBE_MT_REMOVE_METHOD_RETURN(class,id) PROBE_CLASS_AND_ID_RETURN(MT_REMOVE_METHOD,class,id)
#define PROBE_MT_METHOD_ENTRY_ENTRY(class,id) PROBE_CLASS_AND_ID_ENTRY(MT_METHOD_ENTRY,class,id)
#define PROBE_MT_METHOD_ENTRY_RETURN(class,id) PROBE_CLASS_AND_ID_RETURN(MT_METHOD_ENTRY,class,id)
#define PROBE_MT_GET_METHOD_ENTRY_ENTRY(class,id) PROBE_CLASS_AND_ID_ENTRY(MT_GET_METHOD_ENTRY,class,id)
#define PROBE_MT_GET_METHOD_ENTRY_RETURN(class,id) PROBE_CLASS_AND_ID_RETURN(MT_GET_METHOD_ENTRY,class,id)
#define PROBE_MT_SEARCH_METHOD_ENTRY(class,id) PROBE_CLASS_AND_ID_ENTRY(MT_SEARCH_METHOD,class,id)
#define PROBE_MT_SEARCH_METHOD_RETURN(class,id) PROBE_CLASS_AND_ID_RETURN(MT_SEARCH_METHOD,class,id)