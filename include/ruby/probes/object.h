#define PROBE_OBJ_CLONE_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_CLONE,obj)
#define PROBE_OBJ_CLONE_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_CLONE,obj)
#define PROBE_OBJ_DUP_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_DUP,obj)
#define PROBE_OBJ_DUP_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_DUP,obj)
#define PROBE_OBJ_INSPECT_ENTRY(obj) PROBE_OBJECT_RETURN(OBJ_DUP,obj)
#define PROBE_OBJ_INSPECT_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_DUP,obj)
#define PROBE_OBJ_INSTANCE_OF_ENTRY(obj,class) PROBE_OBJECT_CLASS_ENTRY(OBJ_INSTANCE_OF,obj,class)
#define PROBE_OBJ_INSTANCE_OF_RETURN(obj,class) PROBE_OBJECT_CLASS_RETURN(OBJ_INSTANCE_OF,obj,class)
#define PROBE_OBJ_KIND_OF_ENTRY(obj,class) PROBE_OBJECT_CLASS_ENTRY(OBJ_KIND_OF,obj,class)
#define PROBE_OBJ_KIND_OF_RETURN(obj,class) PROBE_OBJECT_CLASS_RETURN(OBJ_KIND_OF,obj,class)
#define PROBE_OBJ_FREEZE_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_FREEZE,obj)
#define PROBE_OBJ_FREEZE_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_FREEZE,obj)
#define PROBE_OBJ_FROZEN_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_FROZEN,obj)
#define PROBE_OBJ_FROZEN_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_FROZEN,obj)

#define PROBE_MOD_INITIALIZE_ENTRY(mod) PROBE_CLASS_ENTRY(MOD_INITIALIZE,mod)
#define PROBE_MOD_INITIALIZE_RETURN(mod) PROBE_CLASS_RETURN(MOD_INITIALIZE,mod)
#define PROBE_CLASS_INITIALIZE_ENTRY(class) PROBE_CLASS_ENTRY(CLASS_INITIALIZE,class)
#define PROBE_CLASS_INITIALIZE_RETURN(class) PROBE_CLASS_RETURN(CLASS_INITIALIZE,class)
#define PROBE_OBJ_ALLOC_ENTRY(class) PROBE_CLASS_ENTRY(OBJ_ALLOC,class)
#define PROBE_OBJ_ALLOC_RETURN(class) PROBE_CLASS_RETURN(OBJ_ALLOC,class)
#define PROBE_CLASS_SUPERCLASS_ENTRY(class) PROBE_CLASS_RETURN(CLASS_SUPERCLASS,class)
#define PROBE_CLASS_SUPERCLASS_RETURN(class) PROBE_CLASS_RETURN(CLASS_SUPERCLASS,class)

#define PROBE_MOD_CONST_GET_ENTRY(mod) PROBE_CLASS_ENTRY(MOD_CONST_GET,mod)
#define PROBE_MOD_CONST_GET_RETURN(mod) PROBE_CLASS_RETURN(MOD_CONST_GET,mod)
#define PROBE_MOD_CONST_SET_ENTRY(mod,const,val) PROBE_CLASS2_ENTRY(MOD_CONST_SET,mod,const,val)
#define PROBE_MOD_CONST_SET_RETURN(mod,const,val) PROBE_CLASS2_RETURN(MOD_CONST_SET,mod,const,val)
#define PROBE_MOD_CONST_DEFINED_ENTRY(mod) PROBE_CLASS_ENTRY(MOD_CONST_DEFINED,mod)
#define PROBE_MOD_CONST_DEFINED_RETURN(mod) PROBE_CLASS_RETURN(MOD_CONST_DEFINED,mod)

#define PROBE_OBJ_METHODS_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_METHODS,obj)
#define PROBE_OBJ_METHODS_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_METHODS,obj)
#define PROBE_OBJ_PRIVATE_METHODS_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_PRIVATE_METHODS,obj)
#define PROBE_OBJ_PRIVATE_METHODS_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_PRIVATE_METHODS,obj)
#define PROBE_OBJ_PUBLIC_METHODS_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_PUBLIC_METHODS,obj)
#define PROBE_OBJ_PUBLIC_METHODS_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_PUBLIC_METHODS,obj)
#define PROBE_OBJ_PROTECTED_METHODS_ENTRY(obj) PROBE_OBJECT_ENTRY(OBJ_PROTECTED_METHODS,obj) 
#define PROBE_OBJ_PROTECTED_METHODS_RETURN(obj) PROBE_OBJECT_RETURN(OBJ_PROTECTED_METHODS,obj)

#define PROBE_OBJ_IVAR_GET_ENTRY(obj,var) PROBE_OBJECT1_ENTRY(OBJ_IVAR_GET,obj,var)
#define PROBE_OBJ_IVAR_GET_RETURN(obj,var) PROBE_OBJECT1_RETURN(OBJ_IVAR_GET,obj,var)
#define PROBE_OBJ_IVAR_SET_ENTRY(obj,var,val) PROBE_OBJECT2_ENTRY(OBJ_IVAR_SET,obj,var,val)
#define PROBE_OBJ_IVAR_SET_RETURN(obj,var,val) PROBE_OBJECT2_RETURN(OBJ_IVAR_SET,obj,var,val)
#define PROBE_OBJ_IVAR_DEFINED_ENTRY(obj,var) PROBE_OBJECT1_ENTRY(OBJ_IVAR_DEFINED,obj,var)
#define PROBE_OBJ_IVAR_DEFINED_RETURN(obj,var) PROBE_OBJECT1_ENTRY(OBJ_IVAR_DEFINED,obj,var)

#define PROBE_MOD_CVAR_GET_ENTRY(class,var) PROBE_CLASS_OBJECT_ENTRY(MOD_CVAR_GET,class,var)
#define PROBE_MOD_CVAR_GET_RETURN(class,var) PROBE_CLASS_OBJECT_RETURN(MOD_CVAR_GET,class,var)
#define PROBE_MOD_CVAR_SET_ENTRY(class,var,val) PROBE_CLASS_OBJECT1_ENTRY(MOD_CVAR_SET,class,var,val)
#define PROBE_MOD_CVAR_SET_RETURN(class,var,val) PROBE_CLASS_OBJECT1_RETURN(MOD_CVAR_SET,class,var,val)
#define PROBE_MOD_CVAR_DEFINED_ENTRY(class,var) PROBE_CLASS_OBJECT_ENTRY(MOD_CVAR_DEFINED,class,var)
#define PROBE_MOD_CVAR_DEFINED_RETURN(class,var) PROBE_CLASS_OBJECT_ENTRY(MOD_CVAR_DEFINED,class,var)

#define PROBE_CONVERT_TYPE_ENTRY(obj,class,method) PROBE_OBJECT_STRING1_ENTRY(CONVERT_TYPE,obj,class,method)
#define PROBE_CONVERT_TYPE_RETURN(obj,class,method) PROBE_OBJECT_STRING1_RETURN(CONVERT_TYPE,obj,class,method)
#define PROBE_COERCE_INTEGER_ENTRY(obj) PROBE_OBJECT_ENTRY(COERCE_INTEGER,obj)
#define PROBE_COERCE_INTEGER_RETURN(obj) PROBE_OBJECT_RETURN(COERCE_INTEGER,obj)
#define PROBE_COERCE_FLOAT_ENTRY(obj) PROBE_OBJECT_ENTRY(COERCE_FLOAT,obj)
#define PROBE_COERCE_FLOAT_RETURN(obj) PROBE_OBJECT_RETURN(COERCE_FLOAT,obj)
#define PROBE_COERCE_STRING_ENTRY(obj) PROBE_OBJECT_ENTRY(COERCE_STRING,obj)
#define PROBE_COERCE_STRING_RETURN(obj) PROBE_OBJECT_RETURN(COERCE_STRING,obj)
#define PROBE_COERCE_ARRAY_ENTRY(obj) PROBE_OBJECT_ENTRY(COERCE_ARRAY,obj)
#define PROBE_COERCE_ARRAY_RETURN(obj) PROBE_OBJECT_ENTRY(COERCE_ARRAY,obj)