#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100

typedef struct tnode_ {
	char *word;
	int count;
	struct tnode_ *left;
	struct tnode_ *right;
} tnode;

void print_tree(tnode *root);
tnode *add_tree(tnode *root, char *word);
void free_node(tnode *root);

char *copy_string(char *s) {
	char *p = (char *)malloc(strlen(s)+1);
	if(p != NULL) {
		strcpy(p, s);
	}

	return p;
}

tnode *add_tree(tnode *p, char *word) {
	int result;
	if(p == NULL) {
		tnode *p = (tnode *)malloc(sizeof(tnode));
		p->word= copy_string(word);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else {
		result = strcmp(word, p->word);
		if(result < 0) {
			p->left = add_tree(p->left, word);
		}
		else if(result > 0) {
			p->right = add_tree(p->right, word);
		}
		else {
			p->count++;
		}
	}

	return p;
}

void print_tree(tnode *p) {
	if(p) {
		print_tree(p->left);
		printf("%s : %4d", p->word, p->count);
		print_tree(p->right);
	}
}

void free_node(tnode *p) {
	if(p) {
		free_node(p->left);
		free_node(p->right);
		free(p);
	}
}

int getword(char *word, int n) {
	int c;
	char *w = word;

	while(isspace(c = getchar())) {
		;
	}
	if(c != EOF) {
		*w++ = c;
	}
	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	while(n > 0) {
		c = getchar();
		if(isalnum(c)) {
			*w++ = c;
		}
		else {
			break;
		}
		n--;
	}

	*w = '\0';
	return w[0];
}

int main() {
	tnode *root;
	char word[MAXWORD];

	while((getword(word, MAXWORD)) != EOF) {
		if(isalnum(word[0])) {
			add_tree(root, word);
		}
	}

	print_tree(root);

	//free_node(root);

	return 0;
}
