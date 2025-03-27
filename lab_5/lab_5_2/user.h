#ifndef USER_H
#define USER_H

typedef struct {
	char *name;
	char number[17];
	int time;
} User;

User user_new(char *name, char *number, int time);
void user_print(const User *u);
void user_array_print(const User *arr, int len);
void user_free(User *arr, int len);


int user_cmp_name_incr(const User *u1, const User *u2);
int user_cmp_name_decr(const User *u1, const User *u2);

int user_cmp_number_incr(const User *u1, const User *u2);
int user_cmp_number_decr(const User *u1, const User *u2);


int user_cmp_time_incr(const User *u1, const User *u2);
int user_cmp_time_decr(const User *u1, const User *u2);

#endif
