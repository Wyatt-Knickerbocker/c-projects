#include <stdio.h>

int main(int argv, char **argc)
{
	FILE *infile;
	FILE *outfile;
	int c;

	if(argv != 3)
	{
		printf("Please include only the filenames. \n");
	}

	if( (infile = fopen(argc[1], "r")) != NULL)
	{
		outfile = fopen(argc[2], "w");
		while( (c = getc(infile)) != EOF)
			putc( c, outfile);
	fclose(infile);
	fclose(outfile);
	}
}
