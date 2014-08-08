#include<stdio.h>
#include<stdlib.h>

typedef struct linklist_ {
    int data;
    struct linklist_ *next;
} linklist;

static void print_list(linklist *p) {
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

static void free_list(linklist *p) {
	if(p->next) {
		free_list(p->next);
	}
	free(p);
	p = NULL;
}

int find(linklist *l, int x) {
	linklist *p = l;
	p = p->next;
	while(p) {
		if(p->data == x) {
			return 1;
		}
		p = p->next;
	}
	return 0;
}

/*
int main() {
	linklist *head, *tail, *p;
	head = (linklist *)malloc(sizeof(linklist));
	head->next = NULL;
	head->data = 0;
	tail = head;

	int i;
	for(i = 1; i < 10; i++){
		p = (linklist *)malloc(sizeof(linklist));
		p->data = i*i;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}

	int ret = find(head, 2);
	printf("ret: %d\n", ret);

	free_list(head);
    return 0;
}
*/

