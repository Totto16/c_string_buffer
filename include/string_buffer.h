#ifndef __STRING_BUFFER_H__
#define __STRING_BUFFER_H__

#include <stdbool.h>
#include <stddef.h>

/**
 * The struct fields should not be accessed directly.
 * They are exposed mainly for testing purposes but all operations on the struct
 * must go through the public string_buffer_xxx operations.
 */
struct StringBuffer
{
  size_t initial_size;
  size_t content_size;
  size_t max_size;
  char   *value;
  bool   allow_resize;
};

struct StringBuffer *string_buffer_new();
struct StringBuffer *string_buffer_new_with_options(const size_t, const bool);

bool string_buffer_clear(struct StringBuffer *);
void string_buffer_release(struct StringBuffer *);

bool string_buffer_ensure_capacity(struct StringBuffer *, const size_t);
bool string_buffer_shrink(struct StringBuffer *);

bool string_buffer_append(struct StringBuffer *, char);
bool string_buffer_append_string(struct StringBuffer *, char *);
bool string_buffer_append_bool(struct StringBuffer *, bool);
bool string_buffer_append_short(struct StringBuffer *, short);
bool string_buffer_append_int(struct StringBuffer *, int);
bool string_buffer_append_long(struct StringBuffer *, long);
bool string_buffer_append_long_long(struct StringBuffer *, long long);

char *string_buffer_to_string(struct StringBuffer *);

#endif

