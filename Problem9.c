// Problem 9: Special Pythagorean triplet
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXLENGTH 150
int main(){
    unsigned int sum;
    char line[MAXLENGTH];
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%u", &sum);
        unsigned int currSum = 0, c = 0;
        unsigned int i, j;
        for(i = 1; 2*i < sum && currSum != sum; ++i){
            for(j = (i+1); 2*j < sum && currSum != sum; ++j){
                c = (unsigned int)sqrt(i*i + j*j);
                if((c*c) == (i*i + j*j))
                    currSum = i + j + c;
            }
        }
        printf("(%u, %u, %u), abc = %u\n", i-1, j-1, c, (i-1)*(j-1)*c);
    }
    return EXIT_SUCCESS;
}
