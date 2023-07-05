// Problem 13: Large Sum
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 150

int main(void){
	FILE *numbersFile;
	char line[MAXLENGTH], filename[MAXLENGTH];
	unsigned int firstDigits, size, length;
	while(fgets(line, MAXLENGTH, stdin)){
		sscanf(line, "%s %u %u %u", filename, &firstDigits, &size, &length);
		numbersFile = fopen(filename, "r");
		if(numbersFile == NULL)
			return EXIT_FAILURE;
		double numbers[length];
		for(int i = 0; i < length; ++i)
			fscanf(numbersFile, "%lf", numbers+i);
		fclose(numbersFile);
		
		double sum = 0.0;
		for(int i = 0; i < length; ++i){
			sum += numbers[i];
		}
		printf("sum = %lf\n", sum);		
	
	}
	return EXIT_SUCCESS;
}

