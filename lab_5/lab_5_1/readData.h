#include "user.h"
#include <stdio.h>

#ifndef readData_H
#define readData_H

User *read_data(FILE *file, int *len);
char *freadline(FILE *file);
int check_data(char *line, char **f1, char f2[17], int *f3);
int count_sym(const char *s, char sym);

#endif
