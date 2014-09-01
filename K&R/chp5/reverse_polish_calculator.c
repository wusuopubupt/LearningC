#include <stdio.h>

#define MAX 100

int stack[MAX];
int sp = -1;

void push(int a) {
    stack[++sp] = a;
}

int pop() {
    return stack[sp--];
}

/* ./test 3 4 2 - + */
int main(int argc, char **argv) {
    int i;
    int j;
    int a, b;
    i = 1;
    int temp = 0;
    while(i < argc) {
        char *s = argv[i];
        //printf("%s\n", s);

        char c = s[0];

        switch(c){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                //push(c - '0');
				temp = c - '0';
                j = 1;
                while(s[j] != '\0') {
                    //push(s[j]);
					temp = temp * 10 + (s[j] - '0');
                    j++;
                }
				push(temp);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                a = pop();
                push(pop() - a);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                a = pop();
                if(b != 0) {
                    push(pop() / a);
                }
                break;
            default:
                break;
        }

        i++;
    }

    printf("result: %d\n", pop());
    return 0;
}
