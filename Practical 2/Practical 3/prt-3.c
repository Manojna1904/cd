#include <stdio.h>
#include <string.h>

int main() {
    char username[50], password[50];
    int at=0, upper=0, lower=0, digit=0, special=0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for(int i=0;i<strlen(username);i++) {
        if(username[i]=='@')
            at++;
    }

    for(int i=0;i<strlen(password);i++) {
        if(password[i]>='A' && password[i]<='Z') upper++;
        else if(password[i]>='a' && password[i]<='z') lower++;
        else if(password[i]>='0' && password[i]<='9') digit++;
        else special++;
    }

    if(at==1)
        printf("Valid Username\n");
    else
        printf("Invalid Username\n");

    if(upper>0 && lower>0 && digit>0 && special>0 && strlen(password)>=8)
        printf("Valid Password\n");
    else
        printf("Invalid Password\n");

    return 0;
}
