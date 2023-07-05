// Problem 14: Longest Collatz Sequence
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MAXLENGTH 150

uint64_t CollatzSequence(uint64_t);

int main(void){
	FILE *upperNumbersFile;
	char line[MAXLENGTH], filename[MAXLENGTH];
	uint_least64_t upperBound;
	while(fgets(line, MAXLENGTH, stdin)){
		sscanf(line, "%lu", &upperBound);
		
		uint64_t longestTerms = 1, startinNumber;
		for(uint64_t i = 1; i <= upperBound; ++i){
			uint64_t terms = CollatzSequence(i);
			if(terms > longestTerms){
				longestTerms = terms;
				startinNumber = i;
			}
		}
		printf("Starting number is %lu\n", startinNumber);
		printf("With %lu number of terms\n", longestTerms);
			
	}
	
	
	return EXIT_SUCCESS;
}

uint64_t CollatzSequence(uint64_t startinNumber){
	uint64_t numTerms = 1;
	uint64_t seq = startinNumber;
	while(seq != 1){
		++numTerms;
		if(seq % 2 == 0)
			seq = seq/2;
		else
			seq = 3*seq + 1;
	}
	return numTerms;
}

