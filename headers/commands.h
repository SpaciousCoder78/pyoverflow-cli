/****************************************************
 *
 * @headerfile       commands.h
 *
 * @author           Aryan Karamtoth (SpaciousCoder78)
 *
 * @date             Sunday, March 16 2024
 *
 * @brief            Gigahertz Shell's Command Functions
 *
 ****************************************************/


#include <Python.h>

#ifndef COMMANDS_H
#define COMMANDS_H

#include<stdio.h>
#include<unistd.h>
/*
  Function Declarations for builtin shell commands:
 */
int quickoverflow_search(char **args); //change directory
int quickoverflow_help(char **args); //help command
int quickoverflow_leave(char **args); //exit command

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "search", //change directory
  "help", //help command
  "leave", //exit command
};

int (*builtin_func[]) (char **) = {
  &quickoverflow_search, //change directory
  &quickoverflow_help, //help command
  &quickoverflow_leave, //exit command
};

int quickoverflow_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
***********************************Builtin function implementations*************************************
*/

//***************************************sofsearch*********************************************** */
//function for calling the python files for searching
int quickoverflow_search(char **args)
{
  
  int argc = 0;
  while (args[argc] != NULL) {
    argc++;
  }
  
  // Initialize the Python interpreter.
  Py_Initialize();
  FILE *fp = fopen("search.py", "r");
  if (fp == NULL) {
    perror("QuickOverFlowFileNotFoundError: Have you deleted search.py by any chance?");
    return 1;
  } 
  PyRun_SimpleFile(fp, "search.py");
  fclose(fp);
  
  // Finalize the Python interpreter.
  Py_Finalize();
  
  return 1;
}

//***************************************tell*************************************************


//*****************************************sos*********************************************** */
int quickoverflow_help(char **args)
{
  int i;
  printf("--------------------------------QuickOverflow-----------------------------\n");
  printf("---------------------------------Version 1.0----------------------------\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < quickoverflow_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  return 1;
}


//*****************************************leave*********************************************** */
int quickoverflow_leave(char **args)
{
  return 0;
}


#endif
