/*
** string.c - String module suppliment (enhancement)
**
** See Copyright Notice in mruby.h
*/

#include "mruby.h"
#include "mruby/string.h"



/*********************************************************************/
void
mrb_mruby_string_enhancement_gem_init(mrb_state* mrb)
{
  struct RClass *s;

  if (mrb->string_class == NULL) { /* Might be PARANOID. */
  }
  s = mrb->string_class;

  mrb_define_method(mrb, s, "dump",  mrb_str_dump, ARGS_NONE());
}

void
mrb_mruby_string_enhancement_gem_final(mrb_state* mrb)
{
  /* nothing to do. */
}

