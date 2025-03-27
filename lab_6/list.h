#ifndef LIST_H
#define LIST_H

typedef struct Item {
	char sym;
	struct Item *next;
} Item;

typedef struct List {
	Item *head;
	Item *tail;
} List;

List *list_new();

void list_print(const List *list);

int list_add(List *list, char sym);

int list_str(List **list, const char *str);

void list_free(List *list);

#endif
