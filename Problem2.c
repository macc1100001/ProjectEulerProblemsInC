// Problem 2: Even fibonacci numbers
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 150
int main(){
    char line[MAXLENGTH];
    unsigned int max, sum, kp, kp2, term;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%u", &max);
        kp = 1; kp2 = 0;
        sum = 0; term = 2;
        while(term <= max){
            sum += term;
            kp = term/2;
            term = 2*(2*term + kp2);
            kp2 = kp;
        }
        printf("%u\n", sum);
    }
    return EXIT_SUCCESS;
}
