/**
 * @desc : get union and intersection of list A and B
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

static linklist* get_union(linklist *p1, linklist *p2) {
	linklist *p = (linklist*)malloc(sizeof(linklist));
	linklist *tail = p;
	p->data = 0;
	p->next = NULL;

	if(p1 && p1->next) {
		p1 = p1->next;
	}
	if(p2 && p2->next) {
		p2 = p2->next;
	}
	while(p1 && p2) {
		linklist *t = (linklist*)malloc(sizeof(linklist));
		t->next = NULL;
		if(p1->data < p2->data) {
			t->data = p1->data;
			p1 = p1->next;
		}
		else if(p1->data > p2->data){
			t->data = p2->data;
			p2 = p2->next;
		}
		else {
			t->data = p1->data;
			p1 = p1->next;
			p2 = p2->next;
		}

		tail->next = t;
		tail = t;
	}

	if(p1 && p->data != p1->data) {
		tail->next = p1;
	}
	if(p2 && p->data != p2->data) {
		tail->next = p2;
	}

	return p;
}

static linklist *get_intersection(linklist *p1, linklist *p2) {
	linklist *p = (linklist*)malloc(sizeof(linklist));
	linklist *tail = p;
	p->data = 0;
	p->next = NULL;

	if(p1 && p1->next) {
		p1 = p1->next;
	}
	if(p2 && p2->next) {
		p2 = p2->next;
	}

	while(p1 && p2) {
		linklist *t = (linklist*)malloc(sizeof(linklist));
		int a = p1->data, b = p2->data;
		printf("a: %d, b: %d\n", a, b);
		t->next = NULL;
		if(p1->data < p2->data) {
			p1 = p1->next;
		}
		else if(p1->data > p2->data){
			p2 = p2->next;
		}
		else {
			t->data = p1->data;
			p1 = p1->next;
			p2 = p2->next;

			tail->next = t;
			tail = t;
		}
	}

	return p;
}

/*
int main() {
	linklist *head1 = (linklist*)malloc(sizeof(linklist));
	linklist *head2 = (linklist*)malloc(sizeof(linklist));
	linklist *tail1 = head1;
	linklist *tail2 = head2;

	head1->data = 0;
	head1->next = NULL;
	head2->data = 0;
	head2->next = NULL;

	int i = 1;
	while(i < 10) {
		linklist *p = (linklist*)malloc(sizeof(linklist));
		p->data = i;
		p->next = NULL;

		tail1->next = p;
		tail1 = p;
		i++;
	}

	i = 1;
	while(i < 6) {
		linklist *p = (linklist *)malloc(sizeof(linklist));
		p->data = i*i;
		p->next = NULL;

		tail2->next = p;
		tail2 = p;
		i++;
	}

	print_list(head1->next);
	print_list(head2->next);
	linklist *p = get_intersection(head1, head2);
	print_list(p->next);

	free(head1);
	free(head2);

	return 0;
}*/
