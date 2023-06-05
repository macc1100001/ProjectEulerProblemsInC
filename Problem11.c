// Problem 11: Largest product in a grid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLENGTH 150

int str2int(const char a1, const char a2){
    return (a1 - '0')*10 + (a2 - '0');
}
unsigned long prodtarH(const char *g, int initialidx, int maxP){
    unsigned long tmpprod = 1;
    for(size_t i = initialidx; i < initialidx + 2*maxP; i+=2){
        tmpprod *= str2int(g[i-1], g[i]);
    }
    return tmpprod;
}
unsigned long prodtarV(const char *g, int initialidx, int maxP){
    unsigned long tmpprod = 1;
    for(size_t i = initialidx; i < initialidx + 2*maxP*4; i+=maxP*2){
        tmpprod *= str2int(g[i-1], g[i]);
    }
    return tmpprod;
}
unsigned long prodtarD1(const char *g, int initialidx, int gSize, int maxP){
    unsigned long tmpprod = 1;
    for(size_t i = initialidx; i < initialidx + 2*gSize*maxP; i+=gSize*2+2){
        tmpprod *= str2int(g[i-1], g[i]);
    }
    return tmpprod;
}
unsigned long prodtarD2(const char *g, int initialidx, int gSize, int maxP){
    unsigned long tmpprod = 1;
    for(size_t i = initialidx; i < initialidx + 2*gSize*maxP-2*maxP; i+=gSize*2-2){
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
        for(size_t i = 0; i < gSize; ++i){
        	for(size_t j = 1; j < 2*gSize; j+=2){
        		printf("%2d ", str2int(grid[(i*2*gSize + j)-1], grid[i*2*gSize + j])); // el grid en enteros
        		
		        //multiplicacion diagonal 1
		        if((j-1) <= 2*(gSize - targetP) && i <= (gSize - targetP)){
		        	currProd = prodtarD1(grid, i*2*gSize + j, gSize, targetP);
		        	if(largestProduct < currProd)
		        		largestProduct = currProd;
	        		//printf("\033[32mproduct: %ld\n", currProd); // color green
	            	//printf("\033[0m");//reset color
		        }
		        //multiplicacion diagonal 2
		        if((j+1) >= 2*targetP && (j+1) <= 2*gSize && i <= (gSize - targetP)){
		        	currProd = prodtarD2(grid, i*2*gSize + j, gSize, targetP);
		        	if(largestProduct < currProd)
		        		largestProduct = currProd;
	        		//printf("\033[32mproduct: %ld\n", currProd); // color green
	            	//printf("\033[0m");//reset color
		        }
        		// multiplicacion horizontal
        		if((j-1) <= 2*(gSize - targetP)){
        			currProd = prodtarH(grid, i*2*gSize + j, targetP);
           			if(largestProduct < currProd)
           				largestProduct = currProd;
	           	 	//printf("\033[32mproduct: %ld\n", currProd); // color green
	            	//printf("\033[0m");//reset color
    			}
    			//multiplicacion vertical
		        if(i <= (gSize - targetP)){
		        	currProd = prodtarV(grid, i*2*gSize + j, gSize);
		        	if(largestProduct < currProd)
		    			largestProduct = currProd;
		        	//printf("\033[32mproduct: %ld\n",  currProd); // color green
		            //printf("\033[0m");//reset color
		        }
        	}
        	printf("\n");
        }
        printf("\n");
        printf("Largest product: %ld\n", largestProduct);
    }
    return EXIT_SUCCESS;
}
