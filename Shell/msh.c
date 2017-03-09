#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "makearg.h"
//               -._                                   _.
//                \ `-.._                           _,' |
//                 \     `-._    _,.--------.._  _."    '
//                  \        `--'              ``.     /
//                   \                                j    __
//__         __       \                               |.-"' /
//`.`-.`-.__`.`'"----"\                              |    /
//    `.       `.       '        ._                       /
//    `..        \               | `.               /|   /
//      `.        `.             |   `._          .' |  /
//        `.  .-----`            |      `.       /   ' '""''
//          `. `.            .    ._      `_    /  ,'    .'
//            `. `.           `._   `'""'"'     ""' ,  ,'
//             `. `.          `.`.              ,-/ ,'       _..
//                `. `.          \|,---..  ,--"./ / ,--------".  \
//                  `._           `.     `/ , .`.',:           \  \
//                     `._          `..".,./ ' _.' :            \  `.
//                   ,-'" `-._              _."     .   |.-"`.   \  |
//                  .         `-..........-'        |   `..   \   |_'
//                  |           `".                 `.._   .  '  ,'
//                  |         |   |                     `"'    .'
//                  |   /\    |'  '
//                  '  /  \   ||   .
//                 '   \  '   |'   ;
//                  \  '  \   `...'
//                   `""   `,' mh
int main()
{

  char *s, **comm, **args;
  int numargs, commands, i;
  while(1)
  {
    //GET COMMAND
    printf("?: ");
    s = getCommand();

    performCommand(s);

  }
  return(0);
}

performCommand( char *s)
{
  pid_t pid;
  int i, commands, numargs;
  char **comm, **args;
  commands = splitCommands(s, &comm);

  //Split commands and then feed each command
  //Into the command parser. Essentially, the
  //Same function is used to split the raw
  //input into first a commands array, then
  //into an arguments array, then fed into execvp.

  for( i = 0; i < commands; i += 1)
  {

    if(strstr(comm[i], "!") == NULL)
    {
      storeHistory(comm[i]);
    }

    if(strstr(comm[i], "|") != NULL)
    {
      forkPipes(comm[i]);
      free(args);
    }
    else
    {
      numargs = makeArg(comm[i], &args);
      //isBuiltIn returns 1 (true) if
      //command is built in function,
      //and 0 if it is not recognized.
      if(!isBuiltIn(args))
        //So what's left gets passed to
        //execute Command right here to play with.
        executeCommand(args);
    }

  }
}

executeCommand( char **args)
{
  pid_t childpid;
  int status;

  //FORK ERROR?
  if((childpid = fork()) == -1)
    {
      fprintf(stderr, "Error in forking\n");
      exit(1);
    }

      //BEGIN CHILD PROCESS
      else if (childpid == 0)
      {
        if(execvp(args[0], args) == -1)
          {
            fprintf(stderr, "%s failed to run.\n", args[0]);
            exit(-1);
          }
          exit(0);
      }

    //CHILD ERROR DURING RUNTIME?
    else if (childpid != wait(&status))
    {
      fprintf(stderr, "An error occured within the child.\n");
    }

    //Better empty out our args[] list
    //so nothing's leftover
    free(args);
}
