// Problem 1: Multiples of 3 or 5
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 150
int main(){
    char line[MAXLENGTH];
    unsigned int sum;
    int max;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%d", &max);
        sum = 0;
        for(int i = max-1; i > 0; i--)
            if((i % 3) == 0 || (i % 5) == 0)
                sum += i;
        printf("%u\n", sum);
    }
    return EXIT_SUCCESS;
}
