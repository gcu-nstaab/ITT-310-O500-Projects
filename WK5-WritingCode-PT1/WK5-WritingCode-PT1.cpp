#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Swap 1 method with scalrs; why does this not work?
*/

void swap1(int x, int y)
{
	int temp = x;
		x = y;
	y = temp;

}

/*
* Swap 2 method with pointers; Why does this work?
*/
void swap2(int* x, int* y)
{
	int temp = *x;
	*x = *y;
		* y = temp;
}

/*
* Play pointer method - don't forget to clean up your memory allocation! (malloc)
*/
char* playPointer(char* input)
{
	 // Allocate memory to hold a copy of the input array, copy input to it, return a pointer to the new array
	// Discussion: How does strcpy_s() make your code more secure?
	// Discussion: How does strcpy_s() demonstrate defensive coding?
	// Discussion: Loop up strncpy() and compare this to the one provided by strcopy_s()
	char* name = malloc(strlen(input) + 1);
	strcpy_s(name, strlen(input) + 1, input);
	return name;
}