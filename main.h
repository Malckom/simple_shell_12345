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
#include <stddef.h>
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

/*str/get fnts*/
char *_getenv(const char *name, char **_environ);
char *_strdup(const char *s);
size_t _strlen(const char *s);
char *_strtok(char *str, const char *delim);
/*for kk.c*/
int change_directory(const char *new_dir);
void update_pwd(void);
/*for path.c*/
typedef struct 
{
char **env;
char *path;
} EnvData;

 /*path.c*/
int is_xcta(EnvData *envData);
int is_cdir(char *path, int *i);
int exec_command(const char *cmd, char *const args[], const EnvData *envData);
char *exe_path(const char *cmd, const EnvData *envData);
char *command_locate(const char *cmd, const EnvData *envData);
int check_error_cmd(char *dir, const EnvData *envData);


#endif
