/*
 * @author	: wusuopubupt
 * @date	: 2014-10-21
 * @desc	: reverse linked list
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
	int data;
	struct node_ *next;
} node;

void free_list(node *head) {
	node *p = head->next;
	if(p->next) {
		free_list(p->next);
	}
	free(p);
	p = NULL;
}

void print_list(node *head) {
	node *p = head->next;
	while(p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void reverse_list(node *head) {
	node *p = head->next;
	node *pre = NULL;
	while(p) {
		node *p_next = p->next;
		if(p_next == NULL)
			head->next = p;
		p->next = pre;
		pre = p;
		p = p_next;
	}
}

int main() {
	node *head = (node *)malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;
	node *tail = head;

	//head->1->2->3->4->5;
	int i = 0;
	int n = 5;
	while(i < n) {
		node *p = (node *)malloc(sizeof(node));
		p->data = i+1;
		p->next = NULL;
		tail->next = p;
		tail = p;
		i++;
	}

	//print_list(head);
	reverse_list(head);
	//print_list(head);

	free_list(head);
	return 0;
}
