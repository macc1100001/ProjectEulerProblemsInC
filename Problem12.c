// Problem 12: Highly Divisible Triangular Number
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 150

int main(void){
	char line[MAXLENGTH];
	unsigned int gtDivisors;
	while(fgets(line, MAXLENGTH, stdin) != NULL){
		sscanf(line, "%u", &gtDivisors);
		unsigned int triangularNumber = 1;
		unsigned int currDivisors;
		unsigned int i;
		for(i = 2; ;++i){
			triangularNumber = (i)*(i+1)/2;
			currDivisors = 2;
			for(unsigned int j = 2; j*j < triangularNumber; ++j){
				if(triangularNumber % j == 0){
					if(triangularNumber / j == j)
						++currDivisors;
					else
						currDivisors+=2;
				}
			}
			if(currDivisors > gtDivisors)
				break;
		}
		printf("The first triangular number that has over %u divisors is %u\n", gtDivisors, triangularNumber);
		printf("total divisors = %u\n", currDivisors);
	}
	return EXIT_SUCCESS;
}

