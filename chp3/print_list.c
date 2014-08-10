/*
 * @author : dash
 * @desc : the most fundamental operation for linked list
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct linklist_ {
	int data;
	struct linklist_ *next;
} linklist;

void print_list(linklist *head) {
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

/*
int main() {
	linklist *root = (linklist*)malloc(sizeof(linklist));
	root->data = 0;
	root->next = NULL;
	linklist *tail = root;

	int i = 1, n = 10;
	while(i <= n) {
		linklist *p = (linklist*)malloc(sizeof(linklist));
		p->data = i*i;
		p->next = NULL;

		tail->next = p;
		tail = tail->next;

		i++;
	}

	print_list(root->next);
	free_list(root);
	return 0;
}*/



