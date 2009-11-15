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
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args