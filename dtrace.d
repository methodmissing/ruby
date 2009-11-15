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
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args