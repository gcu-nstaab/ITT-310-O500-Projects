#include <stdio.h>

int main(void)
{
	// A Date Stucture
	typedef struct
	{
		int month;
		int day;
		int year;
	}Date;

	// Create an instance of Today
	Date today;

	//Populate the Date structure
	today.month = 07;
	today.day = 23;
	today.year = 1990;

	// Print the contents of the Data Structure
	//Discusion: what are some reasonable uses for structures and unions
	printf("The date is %i%i%.2i.\n", today.month, today.day, today.year % 100);

	//Prompt users for a number between 0 and 4095
	int number = 0;
	int ok = 0;
	while (!ok)
	{
		printf("\n Display a number between 0 and 4095: ");
		scanf_s("%d", &number);
		if (number < 0 || number > 4095)
		{
			printf("This number needs to be between 0 and 4095\n");
		}
		else
		{
			ok = 1;
		}
	}
	// Print some values using shift operators 
	// Discusion: What is the mathematical equivalence when you shift a number once to the left?
	// Discusion: What is the mathematical equivalance when you shift a nuber once to the right??
	printf("\nNumber shifted left 1 time %d: ", number << 1);
	printf("\nNumber shifted left 2 times %d: ", number << 2);
	printf("\nNumber shifted left 1 time %d: ", number >> 1);
	printf("\nNumber shifted left 2 times %d: ", number >> 2);

	return 0;
}