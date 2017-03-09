/* Standard Deviation Calculator */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argv, char **argc)
{
	int i = 1;
	float curnum, total = 0, numbers[argv];

	printf("%d Arguments \n", (argv-1));

	for(i; i < argv; i += 1)
	{
		if (argc[i][0] > 47 && argc[i][0] < 58)
		{
			curnum = atof(argc[i]);
			total += curnum;
			numbers[(i-1)] = curnum;
//			printf("Curnum: %f \n", curnum);
		}
		else
		{
			printf("ERROR: Non-number detected. Aborting.\n");
			return 0;
		}
	}
	printf("ADDITION TOTAL: %f \n", total);

	total = (total / (argv-1));

	printf("MEAN: %f \n", total);

	for(i = 1; i < argv; i += 1)
	{
		numbers[(i-1)] -= total;
		numbers[(i-1)] *= numbers[(i-1)];
	}

	total = 0;

	for(i = 1; i < argv; i += 1)
	{
		total += numbers[(i-1)];
	}
	printf("NEW TOTAL: %f \n", total);
	total /= (argv-1);
	printf("NEW MEAN: %f \n", total);

	curnum = sqrt(total);
	printf("STANDARD DEVIANCE: %f \n", curnum);

return 0;
}
