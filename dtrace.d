provider ruby {
    probe newobj__location(char *, int);
    probe gvm_lock_begin__location(char *, int);
    probe gvm_lock_end__location(char *, int);
};

#pragma D attributes Evolving/Evolving/Common provider ruby provider
#pragma D attributes Private/Private/Common provider ruby module
#pragma D attributes Private/Private/Common provider ruby function
#pragma D attributes Evolving/Evolving/Common provider ruby name
#pragma D attributes Evolving/Evolving/Common provider ruby args