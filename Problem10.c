// Problem 10: Summation of primes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAXLENGTH 150
int main(){
    unsigned long targetP;
    char line[MAXLENGTH];
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%lu", &targetP);
        bool primes[targetP];
        unsigned long sum = 0;
        memset(primes, false, sizeof(primes));
        for(size_t i = 0; i < targetP; ++i){
            if(!primes[i]){
                for(size_t j = (i+2)*(i+2); j < targetP; ++j){
                    if(j % (i+2) == 0)                
                        primes[j-2] = true;
                }
           }
        }
        for(size_t i = 0; i < targetP-2; ++i){
            if(!primes[i])
                sum += i+2;
        }
        printf("%lu\n", sum);
    }
    return EXIT_SUCCESS;
}
