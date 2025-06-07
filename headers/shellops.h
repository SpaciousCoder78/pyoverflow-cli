/***********************************************************
 * 
 * @headerfile       shellops.h
 * 
 * @author           Aryan Karamtoth (SpaciousCoder78)
 * 
 * @date             Thursday, August 15 2024
 * 
 * @brief            Gigahertz Shell's Operation Functions
 * 
 * 
 * 
 * 
 **********************************************************/



//header file for handling shell operations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include "commands.h"
//avoiding double execution
#ifndef SHELLOPS_H
#define SHELLOPS_H
#define GHZ_RL_BUFFERSIZE 1024 //buffer size
#define EXIT_FAILURE 1 //exit error code
#define GHZ_TOK_BUFFERSIZE 64
#define GHZ_TOK_DELIM " \t\n\r\a"
// function for reading input
char *ghzsh_readLine();
char **ghzsh_splitLine();
int ghzsh_execute(char **args);

//loop for shell
void ghzsh_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf("> ");
        //reading and executing input
        line= ghzsh_readLine();
        args = ghzsh_splitLine();
        status = ghzsh_execute(args);

        //freeing allocated memory
        free(line);
        free(args);
    }while(status);
}

// function for reading input

char *ghzsh_readLine(void){
    //setting buffer size
    int bufsize = GHZ_RL_BUFFERSIZE;
    //setting buffer position
    int position = 0;
    //allocating memory for buffer
    char *buffer = (char*)malloc(sizeof(char)*bufsize);
    int c;

    //handling buffer memory allocation error
    if(!buffer){
        fprintf(stderr,"ghz-sh: Buffer Allocation Failed");
        exit(EXIT_FAILURE);
    }

    while(1){
        //reading input
        c=getchar();

        //handling null or EOF event
        if(c==EOF || c=='\n'){
            buffer[position]='\0';
            return buffer;
        }else{
            buffer[position]=c;
        }
        position++;

        //handling event where buffer limit is exceeded
        if(position>=bufsize){
            bufsize+=GHZ_RL_BUFFERSIZE;
            //realloc the buffer
            buffer = (char*)realloc(buffer,bufsize);
            if(!buffer){
                fprintf(stderr,"ghz-sh: Buffer Allocation Error");
                exit(EXIT_FAILURE);
            }
        }


    }

}

//split line
char **ghzsh_splitLine(){
    //defining buffersize and position
    int bufsize = GHZ_TOK_BUFFERSIZE, position =0;
    //allocating mem for tokens
    char **tokens = (char**)malloc(bufsize*sizeof(char*));
    char *token;
    char *line;

    //handling mem allocation failure
    if(!tokens){
        fprintf(stderr,"ghz-sh: Buffer Allocation Failed");
        exit(EXIT_FAILURE);
    }
    token = strtok(line,GHZ_TOK_DELIM);
    while(token!=NULL){
        tokens[position]=token;
        position++;

        //if buffer size exceeds
        if(position>=bufsize){
            bufsize+=GHZ_TOK_BUFFERSIZE;
            //realloc bufsize
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "ghz-sh: allocation error\n");
                exit(EXIT_FAILURE);
      }
            
        }
        token = strtok(NULL,GHZ_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

//launch function
int ghzsh_launch(char **args)
{
  pid_t pid, wpid;
  int status;

  //using for sys call
  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("ghz-sh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Error forking
    perror("ghz-sh");
  } else {
    // Parent process
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int ghzsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < ghzsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return ghzsh_launch(args);
}



#endif
