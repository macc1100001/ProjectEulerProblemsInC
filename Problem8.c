// Problem 8: Largest product in a series
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAXLENGTH 150
#define DIGITSIZE 1000
int main(){
    FILE *numberFile;
    char series[DIGITSIZE];
    char line[MAXLENGTH], filename[MAXLENGTH];
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        int adjacent;
        unsigned long largestProduct = 1, currentProduct;
        sscanf(line, "%s %d", filename, &adjacent);
        numberFile = fopen(filename, "r");
        fread(series, sizeof(char), DIGITSIZE, numberFile);
        fclose(numberFile);
        for(size_t i = 0; i < DIGITSIZE-adjacent; ++i){
            currentProduct = 1;
            int numj;
            for(size_t j = i; j < i + adjacent; ++j){
                numj = series[j] - '0';
                currentProduct *= (unsigned long)numj;
                if(currentProduct == 0)
                    break;
            }
            if(currentProduct > largestProduct)
                largestProduct = currentProduct;
        }
        printf("%lu\n", largestProduct);    
    }
    return EXIT_SUCCESS;
}
