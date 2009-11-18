provider ruby {
    probe string__new__begin(char *, int);
    probe string__new__end(char *, int);
    probe string__new__external__begin(char *, int);
    probe string__new__external__end(char *, int);
    probe string__new__shared__begin(char *, int);
    probe string__new__shared__end(char *, int);    

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

    probe xfree__begin();
    probe xfree__end();
    probe xmalloc__begin(long size);
    probe xmalloc__end(long size);
    probe xrealloc__begin(long size);
    probe xrealloc__end(long size);
    probe xmalloc2__begin(long slots, long size);
    probe xmalloc2__end(long slots, long size);
    probe xcalloc__begin(long slots, long size);
    probe xcalloc__end(long slots, long size);
    probe xcalloc2__begin(long slots, long size);
    probe xcalloc2__end(long slots, long size);

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
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args