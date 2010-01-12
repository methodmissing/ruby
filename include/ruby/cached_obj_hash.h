#ifndef HASH_CACHE_H
#define HASH_CACHE_H
#include "st.h"

RUBY_EXTERN st_table *rb_obj_hash_cache;

#define LIKELY_CACHE_OBJ_HASH FL_USER6
#define CACHED_OBJ_HASH       FL_USER7
#define FREE_CACHED_OBJ_HASH(obj) do {\
  if FL_TEST(obj,CACHED_OBJ_HASH){ \
    st_lookup(rb_obj_hash_cache, (st_data_t)obj, &hsh); \
    st_delete(rb_obj_hash_cache, (st_data_t*)obj, &hsh); \
  } \
} while (0)
#define EXPIRE_CACHED_OBJ_HASH(obj) FREE_CACHED_OBJ_HASH(obj)
#define COND_EXPIRE_CACHED_OBJ_HASH(obj) do {\
  st_data_t hsh; \
  if FL_TEST(obj,CACHED_OBJ_HASH){ \
    EXPIRE_CACHED_OBJ_HASH(obj); \
    FL_UNSET(obj,CACHED_OBJ_HASH); \
  } \
} while (0)
#define CACHE_OBJ_HASH_DIRECT(obj,val) do {\
  st_add_direct(rb_obj_hash_cache, (st_data_t)obj, (st_data_t)val); \
  FL_SET(obj,CACHED_OBJ_HASH); \
} while (0)
#define CACHE_OBJ_HASH(obj,val) do {\
  if(FL_TEST(obj,LIKELY_CACHE_OBJ_HASH)){ \
    CACHE_OBJ_HASH_DIRECT(obj,val); \
  }else{ \
    FL_SET(obj,LIKELY_CACHE_OBJ_HASH); \
  } \
} while (0)
#define GET_CACHED_OBJ_HASH(obj) do {\
  st_data_t cached_hash; \
  if FL_TEST(obj,CACHED_OBJ_HASH){ \
    st_lookup(rb_obj_hash_cache, (st_data_t)obj, &cached_hash); \
    return LONG2FIX(cached_hash); \
  } \
} while (0)
#endif