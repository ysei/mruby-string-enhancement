/*
** string.c - String module suppliment (enhancement)
**
** See Copyright Notice in mruby.h
*/

#include "mruby.h"
#include "mruby/string.h"

/* mrb_str_dump is in mruby core. */

static mrb_value
mrb_str_getbyte(mrb_state *mrb, mrb_value str)
{
  mrb_int idx;
  struct RString *s;
  mrb_value str2;
  unsigned char *p;

  mrb_get_args(mrb, "i", &idx);
  str2 = mrb_str_substr(mrb, str, idx, 1);
  if (mrb_nil_p(str2) || RSTRING_LEN(str2) == 0) {
    return mrb_nil_value();
  }

  s = mrb_str_ptr(str2);
  p = (unsigned char *)(s->ptr);

  return mrb_fixnum_value(p[0]);
}


/*********************************************************************/
void
mrb_mruby_string_enhancement_gem_init(mrb_state* mrb)
{
  struct RClass *s;

  if (mrb->string_class == NULL) { /* Might be PARANOID. */
  }
  s = mrb->string_class;

  mrb_define_method(mrb, s, "dump",  mrb_str_dump, ARGS_NONE());
  mrb_define_method(mrb, s, "getbyte",         mrb_str_getbyte,         ARGS_REQ(1));
}

void
mrb_mruby_string_enhancement_gem_final(mrb_state* mrb)
{
  /* nothing to do. */
}

