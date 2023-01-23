// Problem 11: Largest product in a grid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 150

int str2int(const char a1, const char a2){
    return (a1 - '0')*10 + (a2 - '0');
}
unsigned long prodtar(const char *g, int initialidx, int maxP){
    unsigned long tmpprod = 1;
    for(size_t i = initialidx; i < 2*maxP; i+=2){
        tmpprod *= str2int(g[i-1], g[i]);
    }
    return tmpprod;
}
int main(){
    FILE *gridFile;
    unsigned int targetP, gSize;
    char line[MAXLENGTH], filename[MAXLENGTH];
    while(fgets(line, MAXLENGTH, stdin) != NULL){
        sscanf(line, "%s %u %u", filename, &gSize, &targetP);
        unsigned long largestProduct = 1, currProd;
        char grid[gSize*gSize*2];
        gridFile = fopen(filename, "r");
        fread(&grid, sizeof(char), gSize*gSize*2, gridFile);
        fclose(gridFile);
        for(size_t i = 1; i < gSize*gSize*2; i+=2){
            //printf("%2d ", str2int(grid[i-1], grid[i])); // el grid en enteros
            //printf("%c%c ", grid[i-1], grid[i]);  // el grid en chars
            if(((i+1)/2) % gSize == 0){
                printf("\n");
                continue;
            }
            // multiplicacion horizontal
            if((i+1)/2 < (gSize - targetP)){
                currProd = prodtar(grid, i, targetP);
            }
            if(currProd == 0)
                continue;
            printf("currProd = %ld\n", currProd);
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
