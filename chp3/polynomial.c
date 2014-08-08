#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct LNode {
	int coef;
	int expn;
	struct LNode *next;
} LNode, *polynomial;

void creatpolyn(polynomial p,int m)
{
	printf("creatpolyncreatpolyncreatpolyncreatpolyny\n");
	int i;
	int coef;
	int expn;
	polynomial s;
	p=(polynomial)malloc(sizeof(LNode));
	p->next=NULL;
	for(i=1;i<=m;++i)
	{
		s=(polynomial)malloc(sizeof(LNode));
		printf("请输入一元多项式的系数和指数:");
		scanf("%d %d",&coef,&expn);
		s->coef=coef;
		s->expn=expn;
		s->next=p->next;
		p->next=s;
	}
} //CreatPolyn

polynomial addpolyn(polynomial pa,polynomial pb)
{
	polynomial c,pc;
	pc=(polynomial)malloc(sizeof(LNode));
	pc->next=NULL;
	pa=pa->next;
	pb=pb->next;
	while(pa && pb)
	{
		if((pa->expn)==(pb->expn))
		{
			c=(polynomial)malloc(sizeof(LNode));
			c->expn=pa->expn;
			c->coef=((pa->coef)+(pb->coef));
			pa=pa->next;
			pb=pb->next;

		} //if
		else if((pa->expn)>(pb->expn))
		{
			c=(polynomial)malloc(sizeof(LNode));
			c->expn=pb->expn;
			c->coef=pb->coef;
			pb=pb->next;

		} //if
		else
		{
			c=(polynomial)malloc(sizeof(LNode));
			c->expn=pa->expn;
			c->coef=pa->coef;
			pa=pa->next;
		} //if
		c->next=pc->next;
		pc->next=c;
	} //while
	if(!pa && pb)
	{	while(c->next!=NULL)
		{
			c=c->next;
		} //while
		c->next=pb;}
	if(!pb && pa)
	{	while(c->next!=NULL)
		{
			c=c->next;
		} //while
		c->next=pa;}
	return pc;
} //AddPolyn

void printpolyn(polynomial p)
{

	while(p->next!=NULL)
	{	printf("test_print");
		p=p->next;
		printf(" %dX^%d+   ",p->coef,p->expn);
		printf("\n");
	} //while
} //printpolyn

//void main(void) {
//	int n, m;
//	polynomial pa, pb, pc;
//
//	printf("pa:");
//	scanf("%d", &n);
//	creatpolyn(pa, n);
//	printf("pb:");
//	scanf("%d", &m);
//	creatpolyn(pb, m);
//	pc = addpolyn(pa, pb);
//	printf("pa+pb=\n");
//	printpolyn(pc);
//}
