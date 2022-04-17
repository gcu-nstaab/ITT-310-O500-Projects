#include <stdio.h>

#ifndef MESSAGE
	#define MESSAGE "Hello World!"
#endif

#define message_for (fn, ln) \
	printf("My name is " #fn #ln "\n")

int main()
{
	printf(MESSAGE"\n")

		message_for(Bob, Johnson)

		printf("File :%s\n", __FILE__);
	printf("Date :%s\n", __DATE__);
	printf("Time :%s\n", __TIME__);
	printf("Line :%d\n", __LINE__);
}
