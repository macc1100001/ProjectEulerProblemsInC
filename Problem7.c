// Problem 7: 10001st prime
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXLENGTH 150
int main(){
    char line[MAXLENGTH];
    long n;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%lu", &n);
        size_t targetP = 100*n;
        bool primes[targetP];
        memset(primes, false, sizeof(primes));
        for(size_t i = 0; i < targetP; ++i){
            if(!primes[i]){
                for(size_t j = (i+2)*(i+2); j < targetP; ++j){
                    if(j % (i+2) == 0)                
                        primes[j-2] = true;
                }
           }
        }
        long nth = 0;
        for(size_t i = 0; i < targetP; ++i){
            if(!primes[i])
                ++nth;
            if(nth == n){
                printf("%ld: %ld\n", nth, i+2);
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}
