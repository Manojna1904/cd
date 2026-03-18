#include <stdio.h>
#include <string.h>

char input[20];
int i = 0;

void E();
void Eprime();

void E() {
    if(input[i] == 'i') {
        i++;
        Eprime();
    }
}

void Eprime() {
    if(input[i] == '+') {
        i++;
        if(input[i] == 'i') {
            i++;
            Eprime();
        }
    }
}

int main() {
    printf("Enter string: ");
    scanf("%s", input);

    strcat(input, "$");

    E();

    if(input[i] == '$')
        printf("Valid String\n");
    else
        printf("Invalid String\n");

    return 0;
}
