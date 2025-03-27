#include <stddef.h>

#ifndef myString_H
#define myString_H

size_t myStrlen(const char *str);
char *myStrdup(const char *str);
void *myMemcpy(void *dest, const void *s, size_t size);
char *myStrcat(char *dest, const char *app);
char *myStrtok(char *str, const char *sep);

#endif
