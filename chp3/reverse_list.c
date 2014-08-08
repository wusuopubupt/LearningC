/* @ref: http://blog.csdn.net/wusuopubupt/article/details/18318055 */

#include<stdio.h>
#include<stdlib.h>

typedef struct linklist_ {
    int data;
    struct linklist_ *next;
} linklist;

void debug(linklist *p) {
    while(p) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
}

linklist *reverseList(linklist *head) {
    if(head == NULL) {
        return NULL;
    }
    else {
        linklist *p, *temp, *pNext;
        temp = NULL;
        p = head->next;
        while(p) {
            pNext = p->next;
            if(pNext == NULL) {
                head = p;
            }
            p->next = temp;
            temp = p;
            p = pNext;
        }

        //debug(head);

        return head;
    }
}

/*
int main() {
    int i, m, n;
    while(scanf("%d", &n) != EOF) {
        linklist *head, *tail, *p;
        head = (linklist *)malloc(sizeof(linklist));
        head->next = NULL;
        tail = head;

        for(i = 0; i < n; i++){
            scanf("%d", &m);
            p = (linklist *)malloc(sizeof(linklist));
            p->data = m;
            p->next = NULL;
            tail->next = p;
            tail = p;
        }

        //debug(head->next);

        if(n == 0) printf("NULL");
        else {
            head = reverseList(head);
            p = head;
            while(p) {
                printf("%d", p->data);
                if(p->next) printf(" ");
                p = p->next;
            }
        }

        printf("\n");

        free(p);
        p = NULL;
        free(head);
        head = NULL;
    }

    return 0;
}
*/

