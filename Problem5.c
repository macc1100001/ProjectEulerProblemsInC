// Problem 5: Smallest multiple
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 150
int main(){
    char line[MAXLENGTH];
    int maxnum;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%d", &maxnum);
        int factors[maxnum-1];
        long smallestMultiple = 1;
        for(int i = 0; i < maxnum; i++)
            factors[i] = i+2;
        for(int i = 0; i < maxnum - 1; i++){
            for(int j = i+1; j < maxnum - 1; j++){
                if(factors[j] % factors[i] == 0)
                    factors[j] = factors[j]/factors[i];
            }
        }
        for(int i = 0; i < maxnum - 1; i++)
            smallestMultiple *= factors[i];
        printf("%ld\n", smallestMultiple);
    }
    return EXIT_SUCCESS;
}
