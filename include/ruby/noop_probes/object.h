#define PROBE_OBJ_CLONE_ENTRY(obj)
#define PROBE_OBJ_CLONE_RETURN(obj)
#define PROBE_OBJ_DUP_ENTRY(obj)
#define PROBE_OBJ_DUP_RETURN(obj)
#define PROBE_OBJ_INSPECT_ENTRY(obj)
#define PROBE_OBJ_INSPECT_RETURN(obj)
#define PROBE_OBJ_INSTANCE_OF_ENTRY(obj,class)
#define PROBE_OBJ_INSTANCE_OF_RETURN(obj,class)
#define PROBE_OBJ_KIND_OF_ENTRY(obj,class)
#define PROBE_OBJ_KIND_OF_RETURN(obj,class)
#define PROBE_OBJ_FREEZE_ENTRY(obj)
#define PROBE_OBJ_FREEZE_RETURN(obj)
#define PROBE_OBJ_FROZEN_ENTRY(obj)
#define PROBE_OBJ_FROZEN_RETURN(obj)

#define PROBE_MOD_INITIALIZE_ENTRY(mod)
#define PROBE_MOD_INITIALIZE_RETURN(mod)
#define PROBE_CLASS_INITIALIZE_ENTRY(class)
#define PROBE_CLASS_INITIALIZE_RETURN(class)
#define PROBE_OBJ_ALLOC_ENTRY(class)
#define PROBE_OBJ_ALLOC_RETURN(class)
#define PROBE_CLASS_SUPERCLASS_ENTRY(class)
#define PROBE_CLASS_SUPERCLASS_RETURN(class)

#define PROBE_MOD_CONST_GET_ENTRY(mod)
#define PROBE_MOD_CONST_GET_RETURN(mod)
#define PROBE_MOD_CONST_SET_ENTRY(mod,const,val)
#define PROBE_MOD_CONST_SET_RETURN(mod,const,val)
#define PROBE_MOD_CONST_DEFINED_ENTRY(mod)
#define PROBE_MOD_CONST_DEFINED_RETURN(mod)

#define PROBE_OBJ_METHODS_ENTRY(obj)
#define PROBE_OBJ_METHODS_RETURN(obj)
#define PROBE_OBJ_PRIVATE_METHODS_ENTRY(obj)
#define PROBE_OBJ_PRIVATE_METHODS_RETURN(obj)
#define PROBE_OBJ_PUBLIC_METHODS_ENTRY(obj)
#define PROBE_OBJ_PUBLIC_METHODS_RETURN(obj)
#define PROBE_OBJ_PROTECTED_METHODS_ENTRY(obj)
#define PROBE_OBJ_PROTECTED_METHODS_RETURN(obj)

#define PROBE_OBJ_IVAR_GET_ENTRY(obj,var)
#define PROBE_OBJ_IVAR_GET_RETURN(obj,var)
#define PROBE_OBJ_IVAR_SET_ENTRY(obj,var,val)
#define PROBE_OBJ_IVAR_SET_RETURN(obj,var,val)
#define PROBE_OBJ_IVAR_DEFINED_ENTRY(obj,var)
#define PROBE_OBJ_IVAR_DEFINED_RETURN(obj,var)

#define PROBE_MOD_CVAR_GET_ENTRY(class,var)
#define PROBE_MOD_CVAR_GET_RETURN(class,var)
#define PROBE_MOD_CVAR_SET_ENTRY(class,var,val)
#define PROBE_MOD_CVAR_SET_RETURN(class,var,val)
#define PROBE_MOD_CVAR_DEFINED_ENTRY(class,var)
#define PROBE_MOD_CVAR_DEFINED_RETURN(class,var)

#define PROBE_CONVERT_TYPE_ENTRY(obj,class,method)
#define PROBE_CONVERT_TYPE_RETURN(obj,class,method)
#define PROBE_COERCE_INTEGER_ENTRY(obj)
#define PROBE_COERCE_INTEGER_RETURN(obj)
#define PROBE_COERCE_FLOAT_ENTRY(obj)
#define PROBE_COERCE_FLOAT_RETURN(obj)
#define PROBE_COERCE_STRING_ENTRY(obj)
#define PROBE_COERCE_STRING_RETURN(obj)
#define PROBE_COERCE_ARRAY_ENTRY(obj)
#define PROBE_COERCE_ARRAY_RETURN(obj)