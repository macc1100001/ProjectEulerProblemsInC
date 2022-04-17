// Problem 3: Largest prime factor
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 150
int main(){
    char line[MAXLENGTH];
    long n, largestFactor;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%ld", &n);
        largestFactor = 1;
        for(int i = 2; n > 1; i++){
            if(n % i == 0){
                largestFactor = i;
                n = n/i;
                while(n % i == 0){
                    n = n/i;
                }
            }
        }
        printf("%ld\n", largestFactor);
    }        
    return EXIT_SUCCESS;
}
