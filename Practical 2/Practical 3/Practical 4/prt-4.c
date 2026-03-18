#include <stdio.h>
#include <string.h>

char stack[50], input[50];
int top = -1, i = 0;

// Push into stack
void push(char x) {
    stack[++top] = x;
}

// Pop from stack
void pop() {
    top--;
}

// LL(1) Parsing function
void parse() {
    push('$');
    push('E');   // Start symbol

    printf("\nSTACK\tINPUT\tACTION\n");

    while(top != -1) {
        printf("%s\t%s\t", stack, input + i);

        // If both are $
        if(stack[top] == '$' && input[i] == '$') {
            printf("Accepted\n");
            return;
        }

        // If terminal matches
        if(stack[top] == input[i]) {
            pop();
            i++;
            printf("Match\n");
        }
        // Apply productions
        else if(stack[top] == 'E' && input[i] == 'i') {
            pop();
            push('A');
            push('i');
            printf("E → iA\n");
        }
        else if(stack[top] == 'A' && input[i] == '+') {
            pop();
            push('A');
            push('i');
            push('+');
            printf("A → +iA\n");
        }
        else if(stack[top] == 'A' && input[i] == '$') {
            pop();
            printf("A → ε\n");
        }
        else {
            printf("Rejected\n");
            return;
        }
    }
}

int main() {
    printf("Enter input string (end with $): ");
    scanf("%s", input);

    parse();

    return 0;
}
