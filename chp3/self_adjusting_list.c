#include <stdio.h>
#include <stdlib.h>

typedef struct linklist_ {
    int data;
    struct linklist_ *next;
} linklist;

static void print_list(linklist *p) {
	p = p->next;
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

static int find(linklist *l, int x) {
	linklist *p = l->next;
	int found = 0;
	int i = 0;
	while(p && found == 0) {
		printf("i:%d, data:%d\n", i, p->data);

		if(p->data == x) {
			found = 1;
			break;
		}
		p = p->next;
		i++;
	}

	if(found) {
		printf("i: %d\n", i);
		p = l->next;
		int p_pre_data = p->data;

		int j = 0;
		while(j < i) {
			p = p->next;
			int temp = p->data;
			p->data = p_pre_data;
			p_pre_data = temp;
			p = p->next;
			j++;

			printf("i:%d, j:%d, pre:%d\n", i, j, p_pre_data);
		}
		l->next->data = x;
	}
	return found;
}

/*
int main() {
	linklist *head = (linklist*)malloc(sizeof(linklist));
	head->data = 0;
	head->next = NULL;
	linklist *tail = head;

	int i = 1, n = 5;
	while(i <= n) {
		linklist *p = (linklist*)malloc(sizeof(linklist));
		p->data = i*i;
		p->next = NULL;

		tail->next = p;
		tail = p;
		i++;
	}

	print_list(head);
	int found = find(head, 4);
	print_list(head);

	printf("found: %d\n", found);

	free(head);
	return 0;
}
*/
