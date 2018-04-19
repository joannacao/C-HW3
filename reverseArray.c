#include <stdio.h>

int *reverse(int *arr, int *arr2, int SIZE); //initializes reverse function
/* This function returns a pointer, and takes in two int arrays and the int size.
 * The first array is the array we want to reverse. The second array is the
 * array we want to copy it into.
 */

int main(){
	const int SIZE = 8; //creates size
	int array1[] = {4, 5, 7, 1, 7, 2, 5, 6}; //initialize first array

	int array2[SIZE]; //declare second array but leave it empty

	int *ptr = reverse(array1, array2, SIZE); //declares a pointer and it is initialized to the pointer returned from the reverse function
	//(and the pointer from the reverse func points to array2, with its reversed contents

	printf("New reversed array is: ");
	for (int i = 0; i < SIZE; i++){
		printf("%d ", *ptr++); //prints out whatever the pointer is pointing to
	} //(the contents of array2)


	return 0;
}

int *reverse(int *arr, int *arr2, int SIZE){
	int size = SIZE; //initializes size as SIZE
	int element2 = 0; //used to iterate through array2
	int element = size - 1; //used to iterate through array1

	for(int i = 0; i < size; i++){
		arr2[element2] = arr[element]; //starts at opposite ends and assigns the values from array1 to array2
		element--; //decrements
		element2++; //increments
	}

	int *rArr = arr2; //creates a pointer pointing to array2

	return rArr; //returns this pointer, where the address of array2 is stored into the ptr where the func was called
}




