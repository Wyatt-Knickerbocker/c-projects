#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isBuiltIn(char **command)
{
  //our CD function using wonderful unistd.h
  if(!strcmp(command[0], "cd"))
  {
    if(chdir(command[1]) == -1)
      printf("directory does not exist.\n");
    return 1;
  }
  ////////////
  //WARNING///
  ////////////
  //This bit here WILL ACTUALLY CHANGE YOUR BASH PATH.
  //You have been warned.
  //Didn't know what you meant by BASH compatible.
  else if(!strcmp(command[0], "pathadd"))
  {
    char *path = getenv("PATH");
    char *base = path, *add = malloc((strlen(command[1])*sizeof(char)));
    strcpy(add,":");
    strcat(add, command[1]);
    printf("ADDING: %s to PATH.\n", add);

    free(add);
    return 1;
  }
  else if(!strcmp(command[0], "exit"))
  {
    printf("Thank you.\n");
    exit(0);
  }

  //History commands. See below for more details.
  else if(!strcmp(command[0], "history"))
  {
    fetchHistory();
   return 1;
  }
  else if(command[0][0] == '!')
  {
    if(!strcmp(command[0], "!!"))
    {
      doHistoryLast();
      return 1;
    }
    else
    {
      doHistoryNum(command[0]);
      return 1;
    }
  }

  else
    return 0;

}

//Global variables for ease of access.
int _HistCount = 1;
char _HistItem[20][255];


int storeHistory( char *command)
{
  int i;

  _HistCount += 1;

  for(i = 1; i < 20; i += 1)
  {
    strcpy(_HistItem[i-1], _HistItem[i]);
  }

  strcpy(_HistItem[19], command);
}

//This will -not- print (null)
//if you 'history' before you make it past 20
//command line usages.
int fetchHistory()
{
  int i, n = (_HistCount - 20);

  for(i = 0; i < 20; i += 1)
  {
    if(n > 0)
    {
      printf("%d:\t%s\n", n, _HistItem[i]);
      n++;
    }
    else
    {
      n++;
      continue;
    }
  }
}

/////////////////
//!!!CAUTION!!!//
/////////////////
//While this will work fine
//the first time, it WILL
//segfault if you call it again.
//This is because it catches itself in
//an infinite loop.
int doHistoryLast()
{
  char **arg;
  int n;
  n = makeArg(_HistItem[19], &arg);

  //This one was tricky, at least in my setup.
  //Due to where I track my history,
  //I have to set it as the second, not the previous.
  //Or else infinite loop goodness.

  if(!isBuiltIn(arg))
    executeCommand(arg);
}

//Can do one of the last twenty commands entered,
//counted from then the shell started.
int doHistoryNum(char *num)
{
  int histnum, complace, i;
  char tmp[255], **arg;

  //Chop off that pesky bang.
  for(i = 1; i < strlen(num); i += 1)
  {
    tmp[i-1] = num[i];
  }

  histnum = atoi(tmp);

  //Here we capture where the variable is in the array.
  complace = 20-(_HistCount-histnum);

  if((_HistCount-histnum) < 20 && (_HistCount-histnum) >= 0)
  {

    makeArg(_HistItem[complace], &arg);

    if(!isBuiltIn(arg))
      executeCommand(arg);
  }
  else
    printf("Sorry, command not in history.\n");
}
