provider ruby {
    probe string__new__begin(char *, int);
    probe string__new__end(char *, int);
    probe string__new__external__begin(char *, int);
    probe string__new__external__end(char *, int);
    probe string__new__shared__begin(char *, int);
    probe string__new__shared__end(char *, int);
    
    probe eval__begin();
    probe eval__end();
    probe instance__eval__begin();
    probe instance__eval__end();
    probe instance__exec__begin();
    probe instance__exec__end();
    probe module__eval__begin();
    probe module__eval__end();
    probe module__exec__begin();
    probe module__exec__end();
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
    probe method__call__begin();
    probe method__call__end();
    probe super__begin();
    probe super__end();
    probe method__missing__begin();
    probe method__missing__end();
    probe yield__begin();
    probe yield__end();
    probe loop__begin();
    probe loop__end();
    probe block__call__begin();
    probe block__call__end();
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args