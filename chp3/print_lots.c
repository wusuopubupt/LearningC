#include <stdio.h>
#include <stdlib.h>

typedef struct linklist_ {
	int data;
	struct linklist_ *next;
} linklist;

static void free_list(linklist *head) {
	linklist *p = head;
	if(p->next) {
		free_list(p->next);
	}
	free(p);
	p = NULL;
}

void print_lots(linklist *l, linklist *p) {
	int i = 1;
	while(p) {
		int index = p->data;
		while(i < index) {
			if(l->next) {
				l = l->next;
			}
			else{
				break;
			}
			i++;
		}
		printf("%d ", l->data);

		p = p->next;
	}
}

/*
int main() {
	linklist *l1 = (linklist *)malloc(sizeof(linklist));
	linklist *l2 = (linklist *)malloc(sizeof(linklist));
	linklist *tail1 = l1;
	linklist *tail2 = l2;

	int n1 = 10;
	int n2 = 4;

	int i = 1;
	while(i < n1) {
		linklist *p = (linklist *)malloc(sizeof(linklist));
		p->data = i;
		p->next = NULL;

		tail1->next = p;
		tail1 = p;
		i++;
	}

	i = 0;
	int a[4] = {1, 3, 4, 6};
	while(i < n2) {
		linklist *p = (linklist*)malloc(sizeof(linklist));
		p->data = a[i];
		p->next = NULL;

		tail2->next = p;
		tail2 = p;
		i++;
	}

	print_lots(l1->next, l2->next);

	free_list(l1);
	free_list(l2);

	return 0;
}
*/
