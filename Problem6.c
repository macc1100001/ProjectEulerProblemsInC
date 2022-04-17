// Problem 6: Sum square difference
#include<stdio.h>
#include<stdlib.h>
#define MAXLENGTH 150
int main(){
    char line[MAXLENGTH];
    int n;
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%d", &n);
        long sum = n*(n+1)/2, sqrsum = n*(n+1)*(2*n+1)/6;
        printf("%ld\n", sum*sum - sqrsum);
    }
    return EXIT_SUCCESS;
}
