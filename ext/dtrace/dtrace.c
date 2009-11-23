#include <ruby/ruby.h>

static VALUE
rb_dtrace(int argc, VALUE *argv, VALUE self)
{
    VALUE probe_id;
    char *probe_str;
    if (!rb_block_given_p()) {
      rb_raise(rb_eArgError, "block required for instrumentation!");
    }else{
      rb_scan_args(argc, argv, "01", &probe_id);
      probe_str = RSTRING_PTR(rb_obj_as_string(probe_id));
      PROBE_RB_TRACE_BEGIN(probe_str);
      rb_yield(Qnil);
      PROBE_RB_TRACE_RETURN(probe_str);
    }
}

void
Init_dtrace(void)
{
   rb_define_global_function("dtrace", rb_dtrace, -1);
}