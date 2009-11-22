#ifdef ENABLE_DTRACE
#include <sys/sdt.h>
#include "dtrace.h"
#define PROBE_BEGIN(probe) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN();\
} while (0)
#define PROBE_INT_BEGIN(probe,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((int)val);\
} while (0)
#define PROBE_PTR_BEGIN(probe,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN(val);\
} while (0)
#define PROBE_ULONG_BEGIN(probe,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((unsigned long)val);\
} while (0)
#define PROBE_ULONG1_BEGIN(probe,val,val2) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((unsigned long)val,(unsigned long)val);\
} while (0)
#define PROBE_ULONG_OBJECT_BEGIN(probe,val,obj) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((unsigned long)val,(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_ULONG1_OBJECT_BEGIN(probe,val,val1,obj) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((unsigned long)val,(unsigned long)val1,(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_STR_BEGIN(probe,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((char*)val);\
} while (0)
#define PROBE_STR_INT_BEGIN(probe,val,ival) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((char*)val,(int)ival);\
} while (0)
#define PROBE_INT1_BEGIN(probe,val,val1) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
    RUBY_##probe##_BEGIN((int)val,(int)val1);\
} while (0)
#define PROBE_ID_BEGIN(probe,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_BEGIN(probe,class) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_INT_BEGIN(probe,class,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(int)val);\
} while (0)
#define PROBE_CLASS1_BEGIN(probe,class,oclass) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(char*)rb_class2name(oclass));\
} while (0)
#define PROBE_CLASS2_BEGIN(probe,class,oclass,aclass) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(char*)rb_class2name(oclass),(char*)rb_class2name(aclass));\
} while (0)
#define PROBE_OBJECT_BEGIN(probe,class) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class));\
} while (0)
#define PROBE_OBJECT_STRING_BEGIN(probe,class,str) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class),(char*)str);\
} while (0)
#define PROBE_OBJECT_STRING1_BEGIN(probe,class,str,str1) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class),(char*)str,(char*)str1);\
} while (0)
#define PROBE_OBJECT1_BEGIN(probe,class,oclass) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class),(char*)rb_obj_classname(oclass));\
} while (0)
#define PROBE_OBJECT2_BEGIN(probe,class,oclass,aclass) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class),(char*)rb_obj_classname(oclass),(char*)rb_obj_classname(aclass));\
} while (0)
#define PROBE_OBJECT_CLASS_BEGIN(probe,obj,class) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(obj),(char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_OBJECT_BEGIN(probe,class,obj) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_CLASS_OBJECT1_BEGIN(probe,class,obj,obj1) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_CLASS_AND_ID_BEGIN(probe,class,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_OBJECT_AND_ID_BEGIN(probe,class,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_obj_classname(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_END(probe) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END();\
} while (0)
#define PROBE_INT_END(probe,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((int)val);\
} while (0)
#define PROBE_PTR_END(probe,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END(val);\
} while (0)
#define PROBE_ULONG_END(probe,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((unsigned long)val);\
} while (0)
#define PROBE_ULONG1_END(probe,val,val1) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((unsigned long)val,(unsigned long)val1);\
} while (0)
#define PROBE_ULONG_OBJECT_END(probe,val,obj) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((unsigned long)val,(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_ULONG1_OBJECT_END(probe,val,val1,obj) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((unsigned long)val,(unsigned long)val1,(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_STR_END(probe,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((char*)val);\
} while (0)
#define PROBE_STR_INT_END(probe,val,ival) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((char*)val,(int)ival);\
} while (0)
#define PROBE_INT1_END(probe,val,val1) do {\
  if (RUBY_##probe##_END_ENABLED())\
    RUBY_##probe##_END((int)val,(int)val1);\
} while (0)
#define PROBE_ID_END(probe,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_END(probe,class) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_INT_END(probe,class,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(int)val);\
} while (0)
#define PROBE_CLASS1_END(probe,class,oclass) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(char*)rb_class2name(oclass));\
} while (0)
#define PROBE_CLASS2_END(probe,class,oclass,aclass) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(char*)rb_class2name(oclass),(char*)rb_class2name(aclass));\
} while (0)
#define PROBE_OBJECT_END(probe,class) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class));\
} while (0)
#define PROBE_OBJECT_STRING_END(probe,class,str) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class), (char*)str);\
} while (0)
#define PROBE_OBJECT_STRING1_END(probe,class,str,str1) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class),(char*)str,(char*)str1);\
} while (0)
#define PROBE_OBJECT1_END(probe,class,oclass) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class),(char*)rb_obj_classname(oclass));\
} while (0)
#define PROBE_OBJECT2_END(probe,class,oclass,aclass) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class),(char*)rb_obj_classname(oclass),(char*)rb_obj_classname(aclass));\
} while (0)
#define PROBE_OBJECT_CLASS_END(probe,obj,class) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(obj),(char*)rb_class2name(class));\
} while (0)
#define PROBE_CLASS_OBJECT_END(probe,class,obj) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(char*)rb_obj_classname(obj));\
} while (0)
#define PROBE_CLASS_OBJECT1_END(probe,class,obj,obj1) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(char*)rb_obj_classname(obj),(char*)rb_obj_classname(obj1));\
} while (0)
#define PROBE_CLASS_AND_ID_END(probe,class,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class),(char*)rb_id2name(id));\
} while (0)
#define PROBE_OBJECT_AND_ID_END(probe,class,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_obj_classname(class),(char*)rb_id2name(id));\
} while (0)

#include "probes/string.h"
#include "probes/method.h"
#include "probes/eval.h"
#include "probes/st.h"
#include "probes/object.h"
#include "probes/mem.h"
#include "probes/gc.h"
#include "probes/trace.h"
#include "probes/fiber.h"
#include "probes/ins.h"
#include "probes/proc.h"
#else
#include "noop_probes/string.h"
#include "noop_probes/method.h"
#include "noop_probes/eval.h"
#include "noop_probes/st.h"
#include "noop_probes/object.h"
#include "noop_probes/mem.h"
#include "noop_probes/gc.h"
#include "noop_probes/trace.h"
#include "noop_probes/fiber.h"
#include "noop_probes/ins.h"
#include "noop_probes/proc.h"
#endif