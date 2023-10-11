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
/*separ*/
/*
 *struct new_sep_list_s - is a single linked list
 *@separator: used to separate ; | &
 *@next: its the next node
 *Description: single linked list to store separators
 **/
typedef struct new_sep_list_s
{
char separator;
struct new_sep_list_s *next;
} new_sep_list;
new_sep_list *add_sep_node_end(new_sep_list **head, char sep);
void handle_separator(new_sep_list **head, char sep);
new_sep_list *add_line_node_end(new_sep_list **head);
void free_add_line_list(new_sep_list **head);
void free_add_node_list(new_sep_list **head);
/*separ2.c*/
typedef struct variable_node
{
int variableLength;
char *value;       
int valueLength;   
struct variable_node *next;
} variable_node;
variable_node *add_variable_node_recursive(variable_node **head, int variableLength, char *value, int valueLength);
void free_variable_list_recursive(variable_node **head);

#endif
