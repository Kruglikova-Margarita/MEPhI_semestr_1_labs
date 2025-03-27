#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "changeLine.h"

/*
void change_line(List *list, int k) {
	if (list->head) {
		delete_space(list);
		if (list->head->sym != '\0') {
			Item *start = list->head;
			Item *end = list->head;
			int f = 0;

			while (end->next) {
				if (f == 1) {
					start = end->next->next;
					end = start;
				}
				while (end->next != NULL) {
					if (end->next->sym != ' ') {
						end = end->next;
					} else {
						break;
					}
				}
				for (int i = 0; i < k; i++) {
					char buf = start->sym;
					Item *ptr = start;
					while (ptr != end) {
						ptr->sym = ptr->next->sym;
						ptr = ptr->next;
					}
					ptr->sym = buf;	
				}
				f = 1;
			}
		}
	}
}
*/

/*
void change_line(List *list, int k) {
	if (list->head) {
		delete_space(list);
		if (list->head->sym != '\0') {
			int count = 0;
			Item *ptr_prev = list->head;
			Item *ptr = list->head;
			while (count < k) {
				if (ptr_prev != ptr) {
					ptr_prev = ptr_prev->next;
				}
				ptr = ptr->next;
				count++;
			}
			Item *start = list->head;
			Item *end = list->tail;
			list->head = ptr;
			list->tail = ptr_prev;
			list->tail->next = NULL;
			end->next = start;
		}
	}
}
*/

void change_line(List *list, int k) {
	if (list->head) {
		delete_space(list);
		if ((list->head->sym != '\0') && (k != 0)) {
			Item *start_prev = list->head;
			Item *start = list->head;
			Item *end = list->head;
			int f = 0;

			while (end->next) {
				if (f == 1) {
					start_prev = end->next;
					start = end->next->next;
					end = start;
				}
				int len = 1;
				while (end->next != NULL) {
					if (end->next->sym != ' ') {
						end = end->next;
						len++;
					} else {
						break;
					}
				}
				
				int stop = k % len;
				int count = 0;
				if (stop != 0) {
					Item *ptr_prev = start;
					Item *ptr = start;
					while (count < stop) {
						if (ptr_prev != ptr) {
							ptr_prev = ptr_prev->next;
						}
						ptr = ptr->next;
						count++;
					}
					ptr_prev->next = end->next;

					end->next = start;
					start = ptr;
					end = ptr_prev;
					if (f) {
						start_prev->next = start;
					} else {
						list->head = start;
					}
				}
				
				f = 1;
			}
		}
	}
}

void delete_space(List *list) {
	replace_tabs(list);
	Item *tmp;
	while ((list->head->sym == ' ') && (list->head->next)) {
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
	Item *ptr_prev3 = list->head;
	Item *ptr_prev2 = list->head;
	Item *ptr_prev = list->head;
	Item *ptr = ptr_prev->next;
	while (ptr) {
		if ((ptr_prev->sym == ' ') && (ptr->sym == ' ')) {
			tmp = ptr;
			ptr = ptr->next;
			ptr_prev->next = ptr;
			free(tmp);
		} else {
			ptr_prev3 = ptr_prev2;
			ptr_prev2 = ptr_prev;
			ptr_prev = ptr;
			ptr = ptr->next;
		}
	}
	list->tail = ptr_prev;

	if (list->head->sym == ' ') {
		list->head->sym = '\0';
	} else if (list->tail->sym == ' ') {
		list->tail->sym = ptr_prev2->sym;
		ptr_prev3->next = list->tail;
		free(ptr_prev2);
	}
}

void replace_tabs(List *list) {
	Item *ptr = list->head;
	while(ptr) {
		if (ptr->sym == '\t') {
			ptr->sym = ' ';
		}
		ptr = ptr->next;
	}
}
