#include <stdio.h>
#include <string.h>

int main() {
    char stack[20]="$", input[20];
    int top = 0, i = 0;

    printf("Enter input string (end with $): ");
    scanf("%s", input);

    printf("\nSTACK\tINPUT\tACTION\n");

    while(1) {
        printf("%s\t%s\t", stack, input+i);

        if(stack[top]=='$' && input[i]=='$') {
            printf("Accepted\n");
            break;
        }

        if(input[i]=='i') {
            stack[++top] = input[i++];
            stack[top+1] = '\0';
            printf("Shift\n");
        }
        else if(stack[top]=='i') {
            stack[top--] = '\0';
            stack[++top] = 'E';
            stack[top+1] = '\0';
            printf("Reduce\n");
        }
        else {
            printf("Rejected\n");
            break;
        }
    }

    return 0;
}
