/****************************************************
 *
 * @headerfile       commands.h
 *
 * @author           Aryan Karamtoth (SpaciousCoder78)
 *
 * @date             Saturday, June 07 2025
 *
 * @brief            QuickOverflow's Command Functions
 *
 ****************************************************/


//including python header for calling python scripts
#include <Python.h>

#ifndef COMMANDS_H
#define COMMANDS_H

#include<stdio.h>
#include<unistd.h>
/*
  Function Declarations for builtin shell commands:
 */
int quickoverflow_search(char **args); //open search
int quickoverflow_help(char **args); //help command
int quickoverflow_quit(char **args); //exit command
int quickoverflow_about(char **args); //about command

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
  "search", //search command
  "help", //help command
  "quit", //exit command
  "about",
};

int (*builtin_func[]) (char **) = {
  &quickoverflow_search, //search directory
  &quickoverflow_help, //help command
  &quickoverflow_quit, //exit command
  &quickoverflow_about,
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
  
  //Update 1.1.0 removed Py_Finalise to avoid segmentation faults
  
  return 1;
}

//***************************************tell*************************************************


//*****************************************sos*********************************************** */
int quickoverflow_help(char **args){
  int i;
  printf("--------------------------------QuickOverflow-----------------------------\n");
  printf("---------------------------------Version 1.0.1----------------------------\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < quickoverflow_num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  return 1;
}


//*****************************************leave*********************************************** */
int quickoverflow_quit(char **args){
  return 0;
}

//**************************************about (ofc credits)************************************* */

int quickoverflow_about(char **args){
    printf("-------------------------------QuickOverflow-----------------------------------\n");
    printf("Version:  1.0.1\n");
    printf("License: MIT License\n");
    printf("Author: Aryan Karamtoth (SpaciousCoder78)\n");
    printf("Author Email: aryankmmiv@outlook.com\n");
    printf("Supported Operating Systems: Linux\n");
    printf("Github Repository: https://github.com/SpaciousCoder78/QuickOverflow\n");
    printf("Github Issues: https://github.com/SpaciousCoder78/QuickOverflow/issues\n");
}


#endif
