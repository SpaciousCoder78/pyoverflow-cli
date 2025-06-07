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
int pyoverflow_sofsearch(char **args); //change directory
int pyoverflow_help(char **args); //help command
int pyoverflow_leave(char **args); //exit command

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "sofsearch", //change directory
  "help", //help command
  "leave", //exit command
};

int (*builtin_func[]) (char **) = {
  &pyoverflow_sofsearch, //change directory
  &pyoverflow_help, //help command
  &pyoverflow_leave, //exit command
};

int ghzsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/*
***********************************Builtin function implementations*************************************
*/

//***************************************chdir*********************************************** */
int pyoverflow_sofsearch(char **args)
{
  
  int argc = 0;
  while (args[argc] != NULL) {
    argc++;
  }
  
  Py_Initialize();
  
  Py_Main(argc, args);
  Py_Finalize();
  return 0;
}

//***************************************tell*************************************************


//*****************************************sos*********************************************** */
int pyoverflow_help(char **args)
{
  int i;
  printf("Pyoverflow-cli\n");
  printf("Version 1.0\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < ghzsh_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  return 1;
}


//*****************************************leave*********************************************** */
int pyoverflow_leave(char **args)
{
  return 0;
}


#endif
