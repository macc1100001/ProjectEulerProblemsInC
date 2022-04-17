// Problem 4: Largest palindrome product
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXLENGTH 150
void strrev(const char* s, char* out){
    size_t tam = strlen(s);
    for(int i = tam; i > 0; i--)
        out[tam-i] = s[i-1];
    out[tam] = '\0';
}
int main(){
    char line[MAXLENGTH];
    int product, palindrome, digits;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%d", &digits);
        palindrome = 1;
        int maxnum = (int)pow(10, digits);
        char s[2*digits], rev[2*digits];
        for(int i = 10; i < maxnum; i++){
            for(int j = 10; j < maxnum; j++){
                product = i * j;
                snprintf(s, 2*digits+1, "%d", product);
                strrev(s, rev);
                if((product > palindrome) && strcmp(s, rev) == 0)
                    palindrome = product;
            }
        }
        printf("%d\n", palindrome);
    }
    return EXIT_SUCCESS;
}
