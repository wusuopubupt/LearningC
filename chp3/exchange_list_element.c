/**
 * @desc : exchange linked list by pointer
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct linklist_ {
	int data;
	struct linklist_ *next;
} linklist;

static void print_list(linklist *head) {
	linklist *p = head;
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	putchar('\n');
}

static void free_list(linklist *head) {
	linklist *p = head;
	if(p->next) {
		free_list(p->next);
	}
	free(p);
	p = NULL;
}

static void exchange(linklist **pp, int index) {
	int i = 0;
	linklist *p = *pp;
	if(p) {
		while(i < index-1) {
			if(p->next) {
				p = p->next;
			}
			i++;
		}

		linklist *p_pre = p;
		linklist *p_cur = p->next;
		linklist *p_next = p->next->next;

		p_pre->next = p_next;
		p_cur->next = p_next->next;
		p_next->next = p_cur;
	}
}

/*
int main() {
	linklist *head = (linklist*)malloc(sizeof(linklist));
	head->data = 0;
	head->next = NULL;
	linklist *tail = head;

	int n = 10;
	int i = 1;
	while(i < n) {
		linklist *p = (linklist*)malloc(sizeof(linklist));
		p->data = i;
		p->next = NULL;

		tail->next = p;
		tail = p;
		i++;
	}

	print_list(head->next);
	exchange(&head, 4);
	print_list(head->next);

	free(head);
	return 0;
}
*/
