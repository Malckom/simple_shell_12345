#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

/* parsing function*/
int execute(char *args[]);
int launch(char *args[], int background);
/*cd function prototype*/
/*
void changeCurrentDirectoryDot(char *oldpwd, int *status);
int cd_shell(const char *dir);
void changeCurrentDirectoryTo(my_data, const char *dir);
void changeCurrentDirectoryToHome(char *oldpwd, int *status)    
void changeCurrentDirectoryPrevious(char *oldpwd, int *status)
*/
changeCurrentDirectoryToHome(oldpwd, newpwd, &status);
changeCurrentDirectoryToHome();
int execute(char *args[]);
void changeCurrentDirectoryToHome(char *oldpwd, char *newpwd, int *status);
void changeCurrentDirectoryTo(data_shell *my_data, const char *dir);
void changeCurrentDirectoryTo(my_data, const char *dir);








#endif
