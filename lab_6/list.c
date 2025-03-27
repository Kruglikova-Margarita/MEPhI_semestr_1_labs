#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *list_new() {
	return (List *) calloc(1, sizeof(List));
}

void list_print(const List *list) {
	Item *ptr = list->head;
	printf("\"");
	while (ptr) {
		printf("%c", ptr->sym);
		ptr = ptr->next;
	}
	printf("\"\n");
}

int list_add(List *list, char sym) {
	Item *new = (Item *) malloc(sizeof(Item));
	if (!new) {
		return 1;
	}
	new->sym = sym;
	new->next = NULL;
	if (!list->head) {
		list->head = new;
		list->tail = new;
	} else {
		list->tail->next = new;
		list->tail = new;
	}
	return 0;
}

int list_str(List **list, const char *str) {
	int ind = 0;
	while (str[ind] != '\0') {
		int ch = list_add((*list), str[ind]);
		if (ch == 1) {
			return 1;
		}
		ind++;
	}
	
	return 0;
}

void list_free(List *list) {
	Item *ptr = list->head;
	Item *ptr_prev;
	while(ptr) {
		ptr_prev = ptr;
		ptr = ptr->next;
		free(ptr_prev);
	}
	free(list);
}
