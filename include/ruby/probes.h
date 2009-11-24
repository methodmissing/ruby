#ifdef ENABLE_DTRACE
#include <sys/sdt.h>
#include "dtrace.h"
#define PROBE_ENTRY(probe,...) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY(__VA_ARGS__);\
} while (0)
#define PROBE_INT_ENTRY(probe,val) PROBE_ENTRY(probe,(int)val)
#define PROBE_PTR_ENTRY(probe,val) PROBE_ENTRY(probe,val)
#define PROBE_ULONG_ENTRY(probe,val) PROBE_ENTRY(probe,(unsigned long)val)
#define PROBE_ULONG1_ENTRY(probe,val,val2) PROBE_ENTRY(probe,(unsigned long)val,(unsigned long)val2)
#define PROBE_ULONG_OBJECT_ENTRY(probe,val,obj) PROBE_ENTRY(probe,(unsigned long)val,(char*)rb_obj_classname(obj))
#define PROBE_ULONG1_OBJECT_ENTRY(probe,val,val2,obj) PROBE_ENTRY(probe,(unsigned long)val,(unsigned long)val2,(char*)rb_obj_classname(obj))
#define PROBE_ULONG1_OBJECT1_ENTRY(probe,val,val2,obj,obj2) PROBE_ENTRY(probe,(unsigned long)val,(unsigned long)val2,(char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj2))
#define PROBE_STR_ENTRY(probe,val) PROBE_ENTRY(probe,(char*)val)
#define PROBE_STR_INT_ENTRY(probe,val,ival) PROBE_ENTRY(probe,(char*)val,(int)ival)
#define PROBE_INT1_ENTRY(probe,val,val1) PROBE_ENTRY(probe,(int)val,(int)val1)
#define PROBE_ID_ENTRY(probe,id) PROBE_ENTRY(probe,(char*)rb_id2name(id))
#define PROBE_CLASS_ENTRY(probe,class) PROBE_ENTRY(probe,(char*)rb_class2name(class))
#define PROBE_CLASS_INT_ENTRY(probe,class,val) PROBE_ENTRY(probe,(char*)rb_class2name(class),(int)val)
#define PROBE_CLASS1_ENTRY(probe,class,oclass) PROBE_ENTRY(probe,(char*)rb_class2name(class),(char*)rb_class2name(oclass))
#define PROBE_CLASS2_ENTRY(probe,class,oclass,aclass) PROBE_ENTRY(probe,(char*)rb_class2name(class),(char*)rb_class2name(oclass),(char*)rb_class2name(aclass))
#define PROBE_OBJECT_ENTRY(probe,obj) PROBE_ENTRY(probe,(char*)rb_obj_classname(obj))
#define PROBE_OBJECT_STRING_ENTRY(probe,obj,str) PROBE_ENTRY(probe,(char*)rb_obj_classname(obj),(char*)str)
#define PROBE_OBJECT_STRING1_ENTRY(probe,obj,str,str1) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_obj_classname(obj),(char*)str,(char*)str1);\
} while (0)
#define PROBE_OBJECT1_ENTRY(probe,obj,obj1) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_OBJECT2_ENTRY(probe,obj,obj1,obj2) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1),(char*)rb_obj_classname(obj2));\
} while (0)
#define PROBE_OBJECT_CLASS_ENTRY(probe,obj,class) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_obj_classname(obj),(char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_OBJECT_ENTRY(probe,class,obj) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_class2name(class),(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_CLASS_OBJECT1_ENTRY(probe,class,obj,obj1) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_class2name(class),(char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_CLASS_AND_ID_ENTRY(probe,class,id) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_class2name(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_OBJECT_AND_ID_ENTRY(probe,obj,id) do {\
  if (RUBY_##probe##_ENTRY_ENABLED())\
   RUBY_##probe##_ENTRY((char*)rb_obj_classname(obj),(char*)rb_id2name(id));\
} while (0)
#define PROBE_RETURN(probe) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN();\
} while (0)
#define PROBE_INT_RETURN(probe,val) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((int)val);\
} while (0)
#define PROBE_PTR_RETURN(probe,val) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN(val);\
} while (0)
#define PROBE_ULONG_RETURN(probe,val) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((unsigned long)val);\
} while (0)
#define PROBE_ULONG1_RETURN(probe,val,val1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((unsigned long)val,(unsigned long)val1);\
} while (0)
#define PROBE_ULONG_OBJECT_RETURN(probe,val,obj) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((unsigned long)val,(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_ULONG1_OBJECT_RETURN(probe,val,val1,obj) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((unsigned long)val,(unsigned long)val1,(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_ULONG1_OBJECT1_RETURN(probe,val,val1,obj,obj1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((unsigned long)val,(unsigned long)val1,(char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_STR_RETURN(probe,val) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((char*)val);\
} while (0)
#define PROBE_STR_INT_RETURN(probe,val,ival) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((char*)val,(int)ival);\
} while (0)
#define PROBE_INT1_RETURN(probe,val,val1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
    RUBY_##probe##_RETURN((int)val,(int)val1);\
} while (0)
#define PROBE_ID_RETURN(probe,id) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_RETURN(probe,class) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_INT_RETURN(probe,class,val) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class),(int)val);\
} while (0)
#define PROBE_CLASS1_RETURN(probe,class,oclass) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class),(char*)rb_class2name(oclass));\
} while (0)
#define PROBE_CLASS2_RETURN(probe,class,oclass,aclass) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class),(char*)rb_class2name(oclass),(char*)rb_class2name(aclass));\
} while (0)
#define PROBE_OBJECT_RETURN(probe,obj) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_OBJECT_STRING_RETURN(probe,obj,str) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj), (char*)str);\
} while (0)
#define PROBE_OBJECT_STRING1_RETURN(probe,obj,str,str1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj),(char*)str,(char*)str1);\
} while (0)
#define PROBE_OBJECT1_RETURN(probe,obj,obj1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_OBJECT2_RETURN(probe,obj,obj1,obj2) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1),(char*)rb_obj_classname(obj2));\
} while (0)
#define PROBE_OBJECT_CLASS_RETURN(probe,obj,class) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj),(char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_OBJECT_RETURN(probe,class,obj) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class),(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_CLASS_OBJECT1_RETURN(probe,class,obj,obj1) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class),(char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_CLASS_AND_ID_RETURN(probe,class,id) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_class2name(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_OBJECT_AND_ID_RETURN(probe,obj,id) do {\
  if (RUBY_##probe##_RETURN_ENABLED())\
   RUBY_##probe##_RETURN((char*)rb_obj_classname(obj),(char*)rb_id2name(id));\
} while (0)

#include "probes/string.h"
#include "probes/method_table.h"
#include "probes/eval.h"
#include "probes/st.h"
#include "probes/object.h"
#include "probes/mem.h"
#include "probes/gc.h"
#include "probes/trace.h"
#include "probes/fiber.h"
#include "probes/ins.h"
#include "probes/proc.h"
#include "probes/vm.h"
#else
#include "noop_probes/string.h"
#include "noop_probes/method_table.h"
#include "noop_probes/eval.h"
#include "noop_probes/st.h"
#include "noop_probes/object.h"
#include "noop_probes/mem.h"
#include "noop_probes/gc.h"
#include "noop_probes/trace.h"
#include "noop_probes/fiber.h"
#include "noop_probes/ins.h"
#include "noop_probes/proc.h"
#include "noop_probes/vm.h"
#endif