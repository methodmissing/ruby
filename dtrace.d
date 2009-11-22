provider ruby {
    probe str__set__length__begin(char *, int);
    probe str__set__length__end(char *, int);
    probe str__dec__length__begin(char *);
    probe str__dec__length__end(char *);
    probe str__resize__capacity__begin(char *, int);
    probe str__resize__capacity__end(char *, int);
    probe str__replace__begin(char *, char *);
    probe str__replace__end(char *, char *);
    probe str__shared__replace__begin(char *, char *);
    probe str__shared__replace__end(char *, char *);
    probe str__buf__new__begin(int);
    probe str__buf__new__end(int);
    probe str__buf__cstr__new__begin(char *);
    probe str__buf__cstr__new__end(char *);
    probe str__new__begin(char *, int);
    probe str__new__end(char *, int);
    probe str__new__shared__begin(char *);
    probe str__new__shared__end(char *);    
    probe str__free__begin(char *);
    probe str__free__end(char *);
    probe str__dup__begin(char *);
    probe str__dup__end(char *);

    probe evalstr__begin(char *obj);
    probe evalstr__end(char *obj);
    probe instance__eval__begin(char *klass);
    probe instance__eval__end(char *klass);
    probe instance__exec__begin(char *klass);
    probe instance__exec__end(char *klass);
    probe module__eval__begin(char *klass);
    probe module__eval__end(char *klass);
    probe module__exec__begin(char *klass);
    probe module__exec__end(char *klass);
    probe send__begin();
    probe send__end();
    probe caller__begin();
    probe caller__end();
    probe block__given__begin();
    probe block__given__end();
    probe catch__begin();
    probe catch__end();
    probe throw__begin();
    probe throw__end();
    probe method__call__begin(char *klass, char *method);
    probe method__call__end(char *klass, char *method);
    probe super__begin();
    probe super__end();
    probe method__missing__begin();
    probe method__missing__end();
    probe yield__begin();
    probe yield__end();
    probe loop__begin();
    probe loop__end();
    probe block__call__begin(char *klass, char *method);
    probe block__call__end(char *klass, char *method);

    probe clear__cache__begin();
    probe clear__cache__end();
    probe clear__cache__undef__begin(char *klass, char *method);
    probe clear__cache__undef__end(char *klass, char *method);
    probe clear__cache__id__begin(char *method);
    probe clear__cache__id__end(char *method);
    probe clear__cache__class__begin(char *klass);
    probe clear__cache__class__end(char *klass);
    probe vm__change__state__begin(int v);
    probe vm__change__state__end(int v);
    probe add__method__begin(char *klass, char *method);
    probe add__method__end(char *klass, char *method);
    probe remove__method__begin(char *klass, char *method);
    probe remove__method__end(char *klass, char *method);
    probe method__entry__begin(char *klass, char *method);
    probe method__entry__end(char *klass, char *method);

    probe st__init__numtable__begin();
    probe st__init__numtable__end();
    probe st__init__sized__numtable__begin(int size);
    probe st__init__sized__numtable__end(int size);
    probe st__init__strtable__begin();
    probe st__init__strtable__end();
    probe st__init__sized__strtable__begin(int size);
    probe st__init__sized__strtable__end(int size);
    probe st__init__strcasetable__begin();
    probe st__init__strcasetable__end();
    probe st__init__sized__strcasetable__begin(int size);
    probe st__init__sized__strcasetable__end(int size);
    probe st__clear__begin(long bins, long entries, long memsize);
    probe st__clear__end(long bins, long entries, long memsize);
    probe st__free__begin(long bins, long entries, long memsize);
    probe st__free__end(long bins, long entries, long memsize);
    probe st__copy__begin(long bins, long entries, long memsize);
    probe st__copy__end(long bins, long entries, long memsize);
    probe st__cleanup__safe__begin(long bins, long entries, long memsize, long never);
    probe st__cleanup__safe__end(long bins, long entries, long memsize, long never);
    probe st__delete__begin(long bins, long entries, long memsize, long key, long value);
    probe st__delete__end(long bins, long entries, long memsize, long key, long value);
    probe st__delete__safe__begin(long bins, long entries, long memsize, long key, long value, long never);
    probe st__delete__safe__end(long bins, long entries, long memsize, long key, long value, long never);
    probe st__insert__begin(long bins, long entries, long memsize, long key, long value);
    probe st__insert__end(long bins, long entries, long memsize, long key, long value);
    probe st__insert2__begin(long bins, long entries, long memsize, long key, long value);
    probe st__insert2__end(long bins, long entries, long memsize, long key, long value);
    probe st__lookup__begin(long bins, long entries, long memsize, long key, long value);
    probe st__lookup__end(long bins, long entries, long memsize, long key, long value);
    probe st__add__direct__begin(long bins, long entries, long memsize, long key, long value);
    probe st__add__direct__end(long bins, long entries, long memsize, long key, long value);
    probe st__get__key__begin(long bins, long entries, long memsize, long key);
    probe st__get__key__end(long bins, long entries, long memsize, long key);

    probe obj__clone__begin(char *class);
    probe obj__clone__end(char *class);
    probe obj__dup__begin(char *class);
    probe obj__dup__end(char *class);
    probe obj__inspect__begin(char *class);
    probe obj__inspect__end(char *class);
    probe obj__instance__of__begin(char *class, char *oclass);
    probe obj__instance__of__end(char *class, char *oclass);
    probe obj__kind__of__begin(char *class, char *oclass);
    probe obj__kind__of__end(char *class, char *oclass);
    probe obj__freeze__begin(char *class);
    probe obj__freeze__end(char *class);
    probe obj__frozen__begin(char *class);
    probe obj__frozen__end(char *class);

    probe mod__initialize__begin(char *class);
    probe mod__initialize__end(char *class);
    probe class__initialize__begin(char *class);
    probe class__initialize__end(char *class);
    probe obj__alloc__begin(char *class);
    probe obj__alloc__end(char *class);
    probe class__superclass__begin(char *class);
    probe class__superclass__end(char *class);

    probe mod__const__get__begin(char *class);
    probe mod__const__get__end(char *class);
    probe mod__const__set__begin(char *class, char *const, char *val);
    probe mod__const__set__end(char *class, char *const, char *val);
    probe mod__const__defined__begin(char *class);
    probe mod__const__defined__end(char *class);

    probe obj__methods__begin(char *class);
    probe obj__methods__end(char *class);
    probe obj__private__methods__begin(char *class);
    probe obj__private__methods__end(char *class);
    probe obj__public__methods__begin(char *class);
    probe obj__public__methods__end(char *class);
    probe obj__protected__methods__begin(char *class);
    probe obj__protected__methods__end(char *class);

    probe obj__ivar__get__begin(char *class, char *var);
    probe obj__ivar__get__end(char *class, char *var);
    probe obj__ivar__set__begin(char *class, char *var, char *val);
    probe obj__ivar__set__end(char *class, char *var, char *val);
    probe obj__ivar__defined__begin(char *class, char *var);
    probe obj__ivar__defined__end(char *class, char *var);

    probe mod__cvar__get__begin(char *class, char *var);
    probe mod__cvar__get__end(char *class, char *var);
    probe mod__cvar__set__begin(char *class, char *var, char *val);
    probe mod__cvar__set__end(char *class, char *var, char *val);
    probe mod__cvar__defined__begin(char *class, char *var);
    probe mod__cvar__defined__end(char *class, char *var);

    probe convert__type__begin(char *class, char *type, char *method);
    probe convert__type__end(char *class, char *type, char *method);
    probe coerce__integer__begin(char *class);
    probe coerce__integer__end(char *class);
    probe coerce__float__begin(char *class);
    probe coerce__float__end(char *class);
    probe coerce__string__begin(char *class);
    probe coerce__string__end(char *class);
    probe coerce__array__begin(char *class);
    probe coerce__array__end(char *class);

    probe mem__xfree__begin();
    probe mem__xfree__end();
    probe mem__xmalloc__begin(long size);
    probe mem__xmalloc__end(long size);
    probe mem__xrealloc__begin(long size);
    probe mem__xrealloc__end(long size);
    probe mem__xmalloc2__begin(long slots, long size);
    probe mem__xmalloc2__end(long slots, long size);
    probe mem__xcalloc__begin(long slots, long size);
    probe mem__xcalloc__end(long slots, long size);
    probe mem__xcalloc2__begin(long slots, long size);
    probe mem__xcalloc2__end(long slots, long size);

    probe gc__objspace__alloc__begin();
    probe gc__objspace__alloc__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__objspace__free__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__objspace__free__end();
    probe gc__is__pointer__to__heap__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer);
    probe gc__is__pointer__to__heap__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer);
    probe gc__obj__free__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, char *class);
    probe gc__obj_free__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, char *class);
    probe gc__garbage__collect__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__garbage_collect__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__sweep__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__sweep__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__free__unused__heaps__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__free__unused__heaps__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count);
    probe gc__add__freelist__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer);
    probe gc__add__freelist__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer);
    probe gc__mark__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer, int level);
    probe gc__mark__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer, int level);
    probe gc__mark__children__begin(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer, int level);
    probe gc__mark__children__end(long malloc_limit, long malloc_increase, long heap_increment, long heap_length, long heap_used, unsigned int count, void *pointer, int level);

    probe rb__trace__begin(char *id);
    probe rb__trace__end(char *id);

    probe fiber__mark__begin(char *class, int status);
    probe fiber__mark__end(char *class, int status);
    probe fiber__free__begin(char *class, int status);
    probe fiber__free__end(char *class, int status);
    probe fiber__switch__begin(char *class, int status);
    probe fiber__switch__end(char *class, int status);
    probe fiber__start__begin(char *class, int status);
    probe fiber__start__end(char *class, int status);
    probe fiber__terminate__begin(char *class, int status);
    probe fiber__terminate__end(char *class, int status);

    probe proc__mark__begin(void *pointer);
    probe proc__mark__end(void *pointer);
    probe proc__free__begin(void *pointer);
    probe proc__free__end(void *pointer);
    probe proc__dup__begin(char *class);
    probe proc__dup__end(char *class);
    probe binding__mark__begin(void *pointer);
    probe binding__mark__end(void *pointer);
    probe binding__free__begin(void *pointer);
    probe binding__free__end(void *pointer);
    probe binding__dup__begin(char *class);
    probe binding__dup__end(char *class);
    probe binding__new__begin();
    probe binding__new__end();
    probe proc__new__begin(char *class,int lambda);
    probe proc__new__end(char *class,int lambda);
    probe proc__call__begin(char *class);
    probe proc__call__end(char *class,char *class1);

    probe ins__getlocal__begin(unsigned long);
    probe ins__getlocal__end(char *class);
    probe ins__setlocal__begin(unsigned long,char *class);
    probe ins__setlocal__end();
    probe ins__getdynamic__begin(unsigned long,unsigned long);
    probe ins__getdynamic__end(char *class);
    probe ins__setdynamic__begin(unsigned long,unsigned long,char *class);
    probe ins__setdynamic__end();
    probe ins__getinlinecache__begin(long dst);
    probe ins__getinlinecache__end(char *class);
    probe ins__onceinlinecache__begin(long dst);
    probe ins__onceinlinecache__end(char *class);
    probe ins__setinlinecache__begin(long dst, char *class);
    probe ins__setinlinecache__end(char *class);
    probe ins__opt__case__dispatch__begin(long dst, long else_offset, char *class);
    probe ins__opt__case__dispatch__end();
    probe ins__opt__checkenv__begin();
    probe ins__opt__checkenv__end();
    probe ins__opt__plus__begin(char *receiver, char *obj);
    probe ins__opt__plus__end(char *class);
    probe ins__opt__minus__begin(char *receiver, char *obj);
    probe ins__opt__minus__end(char *class);
    probe ins__opt__mult__begin(char *receiver, char *obj);
    probe ins__opt__mult__end(char *class);
    probe ins__opt__div__begin(char *receiver, char *obj);
    probe ins__opt__div__end(char *class);
    probe ins__opt__mod__begin(char *receiver, char *obj);
    probe ins__opt__mod__end(char *class);
    probe ins__opt__eq__begin(char *receiver, char *obj);
    probe ins__opt__eq__end(char *class);
    probe ins__opt__neq__begin(char *receiver, char *obj);
    probe ins__opt__neq__end(char *class);
    probe ins__opt__lt__begin(char *receiver, char *obj);
    probe ins__opt__lt__end(char *class);
    probe ins__opt__le__begin(char *receiver, char *obj);
    probe ins__opt__le__end(char *class);
    probe ins__opt__gt__begin(char *receiver, char *obj);
    probe ins__opt__gt__end(char *class);
    probe ins__opt__ge__begin(char *receiver, char *obj);
    probe ins__opt__ge__end(char *class);
    probe ins__opt__ltlt__begin(char *receiver, char *obj);
    probe ins__opt__ltlt__end(char *class);
    probe ins__opt__aref__begin(char *receiver, char *obj);
    probe ins__opt__aref__end(char *class);
    probe ins__opt__aset__begin(char *receiver, char *obj, char *set);
    probe ins__opt__aset__end(char *class);
    probe ins__opt__length__begin(char *receiver);
    probe ins__opt__length__end(char *class);
    probe ins__opt__size__begin(char *receiver);
    probe ins__opt__size__end(char *class);
    probe ins__opt__succ__begin(char *receiver);
    probe ins__opt__succ__end(char *class);
    probe ins__opt__not__begin(char *receiver);
    probe ins__opt__not__end(char *class);
    probe ins__opt__call__c__function__begin();
    probe ins__opt__call__c__function__end();
    probe ins__opt__check__env__begin();
    probe ins__opt__check__env__end();
    probe ins__opt__regexpmatch1__begin(char *class1, char *class2);
    probe ins__opt__regexpmatch1__end(char *class);
    probe ins__opt__regexpmatch2__begin(char *class1, char *class2);
    probe ins__opt__regexpmatch2__end(char *class);
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args