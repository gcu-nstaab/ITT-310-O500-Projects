#include <stdio.h>
#include "test.h"

int main(int argc, char** argv)
{
//Loop Prints ALL Even Numbers
	for (int a = 0; a <= MAX_NUMBER; ++a)
	{	
		if (a % 2 == 0)
			printf("%d\n", a);
	}
//While Lop To Print ALL ODD Numbers
int b = 0;
while (b <= MAX_NUMBER)
{
	if (b % 2 != 0)
		printf("%d\n", b);
	++b;
}
//Do While Loop to print all numbers divisible by 3
int c = 0;
do
{
	if (c % 3 == 0)
		printf("%d\n", c);
		++c;
} while (c <= MAX_NUMBER);

{
	//Create variables and assign them
	int a = MAX_NUMBER;
	int b;

	//Ask the user for a number
	printf("Enter any Number: ");
	scanf_s("%d", &b);

	//Print those results to console
	printf("\nThe addition result is %d\n", a + b);
	printf("\nThe subtraction result is %d\n", a - b);
	printf("\nThe multiplacation result is %d\n", a * b);
	printf("\nThe division result is %d\n", a / b);

	return 0;

}

return 0;
}