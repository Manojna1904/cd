#include <stdio.h>

int main() {
    char str[100];
    int vowels=0, digits=0, special=0, consonants=0;

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    for(int i=0; str[i]!='\0'; i++) {
        char ch = str[i];

        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u' ||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            vowels++;

        else if(ch>='0' && ch<='9')
            digits++;

        else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
            consonants++;

        else if(ch!=' ' && ch!='\n')
            special++;
    }

    printf("Vowels: %d\nDigits: %d\nConsonants: %d\nSpecial: %d\n",
            vowels, digits, consonants, special);

    return 0;
}
