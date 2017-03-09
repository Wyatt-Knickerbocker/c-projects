#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argv, char **argc)
{

	int i = 1;
	float num;
	for(i;i < argv; i += 1)
	{
		if(argc[i][0] > 47 && argc[i][0] < 58)
		{
			num = atof(argc[i]);
			printf("%f \n", num);
		}

		else
		{
			printf("%s \n", argc[i]);
		}
	}
	return 0;
}
