//WK7-PT4 - PRogram to copy files from one to the other..
#include <stdio.h>

void copy_files(FILE* in, FILE* out)
{
	int c;
	//Copy all characters from the input to the output
	while ((c = getc(in)) != EOF)
		putc(c, out);
}

int main(int argc, char* argv[])
{
	FILE* in, * out;
	errno_t err;

	//Check for input args - prog name, input file, output file

	if (argc != 3)
	{
		fprintf(stderr, "Please enter two file names. \n");
		return 1;
	}

	//Open input file for reading
	if ((err = fopen_s(&in, argv[1], "r")) != 0)
	{
		fprintf(stderr, "Cant read from input file %s. \n", argv[1]);
		return 2;
	}
	//Open output file for writing
	if ((err = fopen_s(&out, argv[2], "w")) != 0)
	{
		fprintf(stderr, "Cant write to output file %s. \n", argv[2]);
		return 3;
	}
	//Copy all characters from input file to output file
	copy_files(in, out);
	printf("File has been copied.\n");
	//Cleanup
	fclose(in);
	fclose(out);

	return 0;
}
