#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ShowHeader(FILE *outfile);
void StdDev(FILE *outfile, float num[], int count, float avg);
void MinMaxAvg(FILE *outfile,  float num[], int count);

int main(int argv, char **argc)
{
	//Variable declarations
	FILE *infile, *outfile;
	float numbers[100], getnum;
	int count = 0;
	char check;

//	printf("%d \n", argv);
/*	PROGRAM START		*/

	//File error handling.
	if( ( argv != 3) )
	{
		if(argv == 1)
		{
			printf("\nThis program takes one formatted file");
			printf(" and returns the \nminimum, maximum, average, and standard deviation\n");
			printf("of the information. Please include the file you are sampling and\n");
			printf("the name of the file to write to, in that order. \n\n");
			return 0;
		}
		else
		{
			printf("\nMust have infile and outfile names only. \n\n");
			return 0;
		}
	}

	if( (infile = fopen(argc[1], "r")) == NULL)
	{
		printf("ERROR: Input file does not exist. Aborting. \n");
		return 0;
	}

	if( (outfile = fopen(argc[2], "r")) != NULL)
	{
		printf("WARNING: Using this filename may overwrite the original file! \n Continue (Y/N)?");
		do
		{
			check = getchar();
			if(check == 'n' ||check == 'N')
			{
				printf("Understood. Aborting. \n");
				fclose( outfile );
				return 0;
			}
			else if(check == 'Y' || check == 'y')
			{
				printf("Understood. Continuing. \n");

				fclose( outfile );
			}

		} while(check != 'y' && check != 'Y');
	}

	//Program start.
	while((fscanf( infile, "%f", &getnum )) != EOF)
	{
 		numbers[count] = getnum;
		count++;
	}
	printf("COUNTED %d DATA\n", (count));
	outfile = fopen(argc[2], "w");
	ShowHeader( outfile );

	fprintf(outfile, "\nSAMPLED FILE: %s\n", argc[1]);

	MinMaxAvg( outfile, numbers, count);


	//Cleanup.
//	printf("Program finished. \n");
	fclose( infile );
	fclose( outfile );
	return 0;
}

void ShowHeader( FILE *outfile )
{
	fprintf(outfile, "     NUMBER ANALYSIS OUTPUT FILE\n");
	fprintf(outfile, "\n        BY WYATT KNICKERBOCKER\n");
	fprintf(outfile, "\n             OF CS 121-01\n");
	fprintf(outfile,"\nOUTPUTS MIN, MAX, AVG, AND STD DEVIATION\n");
}

void MinMaxAvg(FILE *outfile, float numbers[], int count)
{
	int loop;
	float min = 0, max = 0, avg = 0;
	printf("\nCOMPUTING MAXIMUM...\n");
	for(loop = 0; loop < count; loop++)
	{
		if(loop == 0)
		{
			max = numbers[loop];
		}
		if(max < numbers[loop])
		{
			max = numbers[loop];
		}
	}
	printf("MAXIMUM COMPUTED.\n");
	fprintf(outfile, "\nMAXIMUM VALUE: %f\n", max);

	printf("\nCOMPUTING MINIMUM...\n");
	for(loop = 0; loop < count; loop++)
	{
		if(loop == 0)
		{
			min = numbers[loop];
		}
		if(min > numbers[loop])
		{
			min = numbers[loop];
		}
	}
	printf("MINIMUM COMPUTED.\n");
	fprintf( outfile, "\nMINUMUM VALUE: %f\n", min);

	printf("\nCOMPUTING AVERGAGE...\n");
	for(loop = 0; loop < count; loop++)
	{
		avg += numbers[loop];
	}
	avg /= loop;
	printf("AVERGAGE COMPUTED.\n");
	fprintf( outfile, "\nAVERAGE VALUE: %f\n", avg);

	StdDev(outfile, numbers, count, avg);

	printf("\nANALYSIS FINISHED.\n");
}

void StdDev(FILE *outfile, float numbers[],int count, float avg)
{
	float newnum[100];
	float runningtotal = 0, dev;
	int loop;

	printf("\nCOMPUTING STANDARD DEVIATION...\n");
	for(loop = 0; loop < count; loop ++)
	{
		newnum[loop] = (numbers[loop] - avg);
		newnum[loop] *= newnum[loop];
		runningtotal +=  newnum[loop];
	}
	runningtotal /= (count);
	dev = sqrt (runningtotal);
	printf("STANDARD DEVIATION COMPUTED.\n");
	fprintf(outfile, "\nSTANDARD DEVIATION: %f\n", dev);
}
