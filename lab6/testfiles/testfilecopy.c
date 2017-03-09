#include <stdio.h>

int main( int argc, char **argv)
{
	FILE *fp;
	int c;

	if ( (fp = fopen(*++argv, "r")) == NULL)
	{
		printf("Not a valid file. \n");
		return 0;
	}
	while( (c = getc(fp)) != EOF )
	{
		putc( c, stdout );
	}
		fclose( fp );


return 0;
}
