#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

/* parsing function*/
/*int execute(char *args[]);*/
int launch(char *args[], int background);
typedef struct /*structure to hold data*/
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;

} CustomData;

/*for kk.c*/
int change_directory(const char *new_dir);
void update_pwd(void);
/*int main(int argc, char *argv[]);*/


#endif
