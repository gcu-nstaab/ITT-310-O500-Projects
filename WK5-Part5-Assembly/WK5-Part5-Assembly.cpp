//Original Code
#include <stdio.h>

//Declare add as extern tells the compiler the definition
extern int add_asm(int a, int b);

int main()
{
	int ret = add_asm(10, 20);
	printf("The result is %d", ret);
	return 0;
}


//Revised Code for addition/ subtraction

