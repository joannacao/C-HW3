#include <stdio.h>

int main(){

	const double PI = 3.14159; //creates a PI constant
	int i = 0; //creates i (stands for input)

	printf("Geometry Calculator\n\n");
	printf("1. Calculate the Area of a Circle\n");
	printf("2. Calculate the Area of a Rectangle\n");
	printf("3. Calculate the Area of a Triangle\n");
	printf("4. Quit\n\nEnter your choice (1-4): "); //prompts user

	fflush(stdout); //ECLIPSE BUG
	scanf("%d", &i); //stores the integer into the memory location for i
	while ((i < 1) || (i > 4)){ //will keep prompting for input if it isn't valid
		printf("\nInvalid input. Enter a choice (1-4): ");
		fflush(stdout);
		scanf("%d", &i);
	}

	if (i == 1){ //if the user wants to calculate the area of a circle
		double area;
		int radius = 0;
		printf("\nWhat is the radius of the circle: "); //asks for radius
		fflush(stdout);
		scanf("%d", &radius); //stores the integer into the memory location for radius
		while (radius < 0){ //will keep prompting for input if it isn't valid
			printf("\nPlease do not enter negative numbers.\n");
			printf("Enter the radius of the circle: ");
			fflush(stdout);
			scanf("%d", &radius);
		}
		area = PI*radius*radius; //calculates area
		printf("\nThe area of the circle is %f", area); //prints area
	} else if (i == 2) { //if the user wants to find the area of a rectangle
		int length = 0, width = 0; //creates length and wicth
		printf("\nWhat is the length of the rectangle: "); //asks for length
		fflush(stdout);
		scanf("%d", &length); //stores int into memory location of length
		while (length < 0){ //input validation
			printf("\nPlease do not enter negative numbers.\n");
			printf("Enter the length of the rectangle: ");
			fflush(stdout);
			scanf("%d", &length);
		}
		printf("\nWhat is the width of the rectangle: "); //asks for width
		fflush(stdout);
		scanf("%d", &width); //stores int into memory location of width
		while (width < 0){ //input validation
			printf("\nPlease do not enter negative numbers.\n");
			printf("Enter the width of the rectangle: ");
			fflush(stdout);
			scanf("%d", &width);
		}
		int area = length*width; //calculates area
		printf("\nThe area of the rectangle is %d", area); //prints area
	} else if (i == 3) { //if the user wants the area of a triangle
		int base, height; //declares base and height
		printf("What is the base of the triangle: "); //asks for base
		fflush(stdout);
		scanf("%d", &base); //stores int into mem location for base
		while (base < 0){ //input validation
			printf("\nPlease do not enter negative numbers.\n");
			printf("Enter the base of the triangle: ");
			fflush(stdout);
			scanf("%d", &base);
		}
		printf("\nWhat is the height of the triangle: "); //asks for height
		fflush(stdout);
		scanf("%d", &height); //stores int into mem location for height
		while (height < 0){ //input validation
			printf("\nPlease do not enter negative numbers.\n");
			printf("Enter the height of the triangle: ");
			fflush(stdout);
			scanf("%d", &height);
		}
		double area = base*height*0.5; //calculates area
		printf("The area of the triangle is %f\n", area); //prints area
	} else if (i == 4) { //if the user wants to quit
		printf("Okay bye!"); //says goodbye
	}

	return 0;

}




