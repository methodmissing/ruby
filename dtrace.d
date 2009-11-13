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
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args