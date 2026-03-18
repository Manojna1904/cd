#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char *str) {
    char *keywords[] = {"int","float","if","else","while","return"};
    for(int i=0;i<6;i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[100];
    int i=0, tokens=0;

    printf("Enter code:\n");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0') {
        if(isalnum(str[i])) {
            char temp[20];
            int j=0;

            while(isalnum(str[i]))
                temp[j++] = str[i++];

            temp[j] = '\0';

            if(isKeyword(temp))
                printf("%s -> Keyword\n", temp);
            else
                printf("%s -> Identifier\n", temp);

            tokens++;
        }
        else if(strchr("+-*/=;", str[i])) {
            printf("%c -> Operator\n", str[i]);
            tokens++;
            i++;
        }
        else {
            i++;
        }
    }

    printf("Total tokens = %d\n", tokens);
    return 0;
}
