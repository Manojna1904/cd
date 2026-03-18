#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int main() {
    char input[50];
    int i = 0;

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    push('$');

    printf("\nSTACK\tINPUT\tACTION\n");

    while(1) {
        printf("%s\t%s\t", stack, input + i);

        if(stack[top] == '$' && input[i] == '$') {
            printf("ACCEPTED\n");
            break;
        }

        if(input[i] == 'i') {
            push('i');
            i++;
            printf("Shift\n");
        }
        else if(stack[top] == 'i') {
            pop();
            push('E');
            printf("Reduce E->i\n");
        }
        else if(input[i] == '+') {
            push('+');
            i++;
            printf("Shift\n");
        }
        else {
            printf("REJECTED\n");
            break;
        }
    }

    return 0;
}
