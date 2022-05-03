//Original Code
//#include <stdio.h>

//Declare add as extern tells the compiler the definition
//extern int add_asm(int a, int b);

//int main()
//{
//	int ret = add_asm(10, 20);
//	printf("The result is %d", ret);
//	return 0;
//}


//Revised Code for addition/ subtraction

#include <stdio.h>

//Declare add as extern tells the compiler the definition
extern int add_asm(int a, int b);

int main()
{
	int ret = add_asm(10, 20);
	printf("The result is %d", ret);
	return 0;
}

int alt(int argc, char** argv)

{
	// Create some variables and assign them some values
		int a;
		int b;

	//Get a number from the user from stdin
	printf("Enter any number :");
	scanf_s("%d", &b);

	//Print the results from using stdout
	printf("\nThe addition result is %d\n", a + b);
	printf("\nThe subtraction result is %d\n", a - b);
	printf("\nThe multiplication result is %d\n", a * b);
	printf("\nThe division result is %d\n", a / b);

}