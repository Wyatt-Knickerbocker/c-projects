#ifndef MAKEARG_H
#define MAKEARG_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//COMMAND PARSER
//In here currently simply to save space.
//Will likely move when syntax
//becomes more important.
char* getCommand()
{
  char *tmp = (char *)malloc(200*sizeof(char));
  char c;
  int i = 0;

  while( (*(tmp+i) = getchar()) != '\n')
  {
    i += 1;
  }

  *(tmp + i) = '\0';

  return tmp;
}

//ARGUMENT PARSER
//Uses strtok to break up arguments
//then attaches them to a ragged list
//for proper input.
int makeArg(char *s, char ***args)
{

  int n = 0, i = 1;
  char *copy = strdup(s);

  char *p = strtok(copy, " \t");

  //Loops while p isn't null.
  //Captures the number of arguments.
  for(p ; p ; p = strtok(0, " \t"))
  {
    n += 1;
  }

  //p has now taken the place of copy.
  //no need for copy anymore.
  free(copy);

  char **ap = calloc(n+1, sizeof( char* ) );

  //If there was any arguments, fill the list.
  if(n)
  {
    ap[0] = strtok(s, " \t");
    for( i ; i < n ; i += 1)
    {
      ap[i] = strtok(0, " \t");
    }
  }

  //otherwise it will simply return 0
  //and an empty array.
  *args = ap;
  return n;
}

int splitCommands(char *s, char ***args)
{
  //This is different from makeArgs
  //Only in that it returns an array
  //of commands parsed on ';' rather
  //than the command args themselves.
  int n = 0, i = 1;
  char *copy = strdup(s);

  char *p = strtok(copy, ";");

  //Loops while p isn't null.
  //Captures the number of commands.
  for(p ; p ; p = strtok(0, ";"))
  {
    n += 1;
  }

  //p has now taken the place of copy.
  //no need for copy anymore.
  free(copy);

  char **ap = calloc(n+1, sizeof( char* ) );

  //If there was any commands, fill the list.
  if(n)
  {
    ap[0] = strtok(s, ";");
    for( i ; i < n ; i += 1)
    {
      ap[i] = strtok(0, ";");
    }
  }

  //otherwise it will simply return 0
  //and an empty array.
  *args = ap;
  return n;
}

int remPipe(char *s, char ***args)
{
//This is different from makeArgs
//Only in that it returns an array
//of commands parsed on '|' rather
//than the command args themselves.
int n = 0, i = 1;
char *copy = strdup(s);

char *p = strtok(copy, "|");

//Loops while p isn't null.
//Captures the number of commands.
for(p ; p ; p = strtok(0, "|"))
{
  n += 1;
}

//p has now taken the place of copy.
//no need for copy anymore.
free(copy);

char **ap = calloc(n+1, sizeof( char* ) );

//If there was any commands, fill the list.
if(n)
{
  ap[0] = strtok(s, "|");
  for( i ; i < n ; i += 1)
  {
    ap[i] = strtok(0, "|");
  }
}

//otherwise it will simply return 0
//and an empty array.
*args = ap;
return n;
}

int
forkPipes (char *arg)
{

      pid_t pid;
      int status, argv1, argv2, i, fd[2];
      char **uncom, **comm1, **comm2;

  pipe(fd);

if((pid = fork()) == -1)
  {
    fprintf(stderr, "Error in forking\n");
    exit(1);
  }

    //BEGIN CHILD PROCESS
    else if (pid == 0)
    {

      remPipe(arg, &uncom);

      argv1 = makeArg(uncom[0], &comm1);
      argv2 = makeArg(uncom[1], &comm2);

      if (!fork()) {
          close(1);       /* close normal stdout */
          dup(fd[1]);   /* make stdout same as pfds[1] */
          close(fd[0]); /* we don't need this */
          execvp(comm1[0], comm1);
        } else {
          close(0);       /* close normal stdin */
          dup(fd[0]);   /* make stdin same as pfds[0] */
          close(fd[1]); /* we don't need this */
          execvp(comm2[0], comm2);
        }
    }

  //CHILD ERROR DURING RUNTIME?
  else if (pid != wait(&status))
  {
    fprintf(stderr, "An error occured within the child.\n");
  }

  return 0;

}

#endif
