#include <stdio.h>

int main(void)
{
	int numberOfGrades, i, grade;
	int gradeTotal = 0;
	int failureCount = 0;
	float	average;

	printf("How many grades will you be entering? ");
	scanf_s ("%i", &numberOfGrades);
		
	for (i = 1; i <= numberOfGrades; ++i);
	{
		printf ("Enter grade #%i: ", i);
		scanf_s ("%i", &grade);

			gradeTotal = gradeTotal + grade;
		
		if (grade < 65)
			++failureCount;
		
		}

	average = (float)gradeTotal / numberOfGrades;

	printf ("\nGrade average = %.2f\n", average);
	printf("Number of failures = %i\n", failureCount);

	return 0;
}