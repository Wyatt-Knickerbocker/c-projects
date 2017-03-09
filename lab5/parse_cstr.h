
using namespace std;

int parse_string( char *s, char **args);

int parse_string( char *s, char **args)
{
	if(char *s != NULL)
	{
		int argnum = 0, charplace = 0;
		char *point = s;
		while(point != NULL)
		{
			while(*point != ' ')
				{
					args[argnum][charplace] = *point;
					charplace++;
				}
				args[argnum][charplace] = '\0';
				argnum++;
				charplace = 0;
		}
		return argnum;
	}
	else
		return -1;
}
