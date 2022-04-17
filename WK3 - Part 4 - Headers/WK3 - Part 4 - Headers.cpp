#include <stdio.h>
#include "Test.h"

int main(int argc, char** argv)
{
	//Create variables and assign values. our DEFAULT_NUMBER is taken from test.h
	int a = DEFAULT_NUMBER;
	int b;

	// Get a number from the user from stdin
	printf("Enter a number.. any number: ");
	scanf_s("%d", &b);

	//Print the results piping to stdout
	printf("The addition result is %d\n", a + b);
	return 0;
}