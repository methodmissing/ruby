#ifdef ENABLE_DTRACE
#include <sys/sdt.h>
#include "dtrace.h"
#define PROBE_BEGIN(probe) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN();\
} while (0)
#define PROBE_BEGIN_INT(probe,val) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((int)val);\
} while (0)
#define PROBE_ID_BEGIN(probe,id) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_BEGIN(probe,class) do {\
  if (RUBY_##probe##_BEGIN_ENABLED())\
   RUBY_##probe##_BEGIN((char*)rb_class2name(class));\
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
#define PROBE_END_INT(probe,val) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((int)val);\
} while (0)
#define PROBE_ID_END(probe,id) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_id2name(id));\
} while (0)
#define PROBE_CLASS_END(probe,class) do {\
  if (RUBY_##probe##_END_ENABLED())\
   RUBY_##probe##_END((char*)rb_class2name(class));\
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
#else
#include "noop_probes/string.h"
#include "noop_probes/method.h"
#include "noop_probes/eval.h"
#include "noop_probes/st.h"
#include "noop_probes/object.h"
#endif