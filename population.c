#include <stdio.h>

int populationSize(int prev, float birth, float death); //function declaration

int main(){
	int startSize = 0; //assignments
	int years = 0;
	int currentSize = 0;
	float birthRate = 0.0;
	float deathRate = 0.0;

	printf("What is the starting size of the population?\n"); //asks for starting size
	fflush(stdout);
	scanf("%d", &startSize); //stores int into memory location for startSize
	while (startSize < 2){ //input validation
		printf("Value too small. Please enter another:\n");
		fflush(stdout);
		scanf("%d", &startSize);
	}
	printf("What is the birth rate of the population? (In decimal percent)\n"); //asks for birthRate
	fflush(stdout);
	scanf("%f", &birthRate); //stores float into mem location for birthRate
	while (birthRate < 0){ //input validation
		printf("No negatives please. Enter again:\n");
		fflush(stdout);
		scanf("%f", &birthRate);
	}
	printf("What is the deathRate of the population? (In decimal percent)\n"); //asks for deathRate
	fflush(stdout);
	scanf("%f", &deathRate); //stores float into mem location for deathRate
	while (deathRate < 0){ //input validation
		printf("No negatives please. Enter again:\n");
		fflush(stdout);
		scanf("%f", &deathRate);
	}
	printf("How many years?\n"); //asks for years
	fflush(stdout);
	scanf("%d", &years); //stores int into mem location for years
	while (years < 1){ //input validation
		printf("Too small. Please enter another:\n");
		fflush(stdout);
		scanf("%d", &years);
	}

	for (int i = 0; i < years; i++){ //repeats for a certain number of years
		currentSize = populationSize(startSize, birthRate, deathRate); //calls func
		startSize = currentSize; //changes startSize to currentSize to accurately repeat the loop
	}

	printf("The size of the population after %d years is %d people.", years, currentSize); //returns answer

	return 0;
}

int populationSize(int prev, float birth, float death){ //function definition
	int new;

	new = prev + (prev*birth) - (prev*death); //performs calculation

	return new; //returns answer
}



