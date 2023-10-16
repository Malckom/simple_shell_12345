#ifndef MAIN_H
#define MAIN_H

#include <ctype.h>
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
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
typedef struct
{
    char **env;
    char *path;
    char **args;
    int status;
} EnvData;
typedef struct builtin_s {
    char *name;
    int (*p)(EnvData *envData);
} builtin_t;
typedef struct
{
    char *buffer;
    size_t bufsize;
    ssize_t input;
} InputContext;

/* parsing function */
int launch(char *args[], int background);

typedef struct
{
    char **av;
    char *input;
    char **args;
    int status;
    int counter;
    char **_environ;
    char *pid;
} CustomData;
/*string_fnts.c*/
void rev_string(char *s);
/*str/get fnts*/
const char *_getenv(const char *name,const char **env);

/* str/get functions */
/*char *_getenv(const char *name, char **_environ);*/

char *_strdup(const char *s);
size_t _strlen(const char *s);
char *_strtok(char *str, const char *delim);
int (*get_builtin(const char *name))(EnvData *env_data);
/*set_env.c*/
char *copy_info(const char *name, const char *value);
void set_env(const char *name, const char *value, EnvData *envData);
int _unsetenv(EnvData *envData);
int _setenv(EnvData *envData);
char *_getenv_envdata(const char *name, const EnvData *envData);
int _env(EnvData *envData);
/* for kk.c */
int change_directory(const char *new_dir);
void update_pwd(void);

/* path.c */
/*int is_xcta(EnvData *envData);*/
int is_xcta(const char *input);
int is_cdir(char *path, int *i);
char *exe_path(const char *cmd, const EnvData *envData);
char *command_locate(const char *cmd, const EnvData *envData);
int check_error_cmd(char *dir, const EnvData *envData);
int exec_command(const char *cmd, char *const args[], const EnvData *envData);
char *_which(const char *cid, const EnvData *envData);

/*char *_which(char *cid, const char **_environ);*/
/*char *_which(EnvData *envData, char *cid);*/
/* separ*/
/*
 *struct new_sep_list_s - is a single linked list
 *@separator: used to separate ; | &
 *@next: its the next node
 *Description: single linked list to store separators
 **/

/*char exec_command(const char *cmd, char *const args[], const EnvData *envData);*/

/* separ */
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

/* separ2.c */
typedef struct variable_node
{
    int variableLength;
    char *value;
    int valueLength;
    struct variable_node *next;
} variable_node;
variable_node *add_variable_node_recursive(variable_node **head, int variableLength, char *value, int valueLength);
void free_variable_list_recursive(variable_node **head);

/* betty_style.c */
void jackbauer_bettystyle(void);

/* putchar.c */
int _putchar(char c);
void custom_print(const char *text);

/* exit.c */
int exit_shell(EnvData *env_data);
void get_error(EnvData *env_data, int error_code);
/*build-in.c*/
/*int (*get_builtin(char *cmd, EnvData *envData))(EnvData *);
*int point_of_myexit(EnvData *env_data);
*int my_change_directory(EnvData *env_data);
*/
/*commandline.c*/

/* build-in.c */
int exec_line(EnvData *envData);
/* commandline.c */
int comma_line(EnvData *env_data);
int (*get_builtin(const char *cmd))(EnvData *);
/* for getline.c */
void init_input_context(InputContext *context, size_t initial_bufsize);
void free_input_context(InputContext *context);
ssize_t get_line(InputContext *context, FILE *stream);
/*memory_functions.c */
/*void free_argv(custom_args *argv);*/
/*cd.c task10*/
void cd_dot(EnvData *envData);
void cd_to(EnvData *envData);
void cd_previous(EnvData *envData);
void cd_to_home(EnvData *envData);
/*help functions*/
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
int cd_shell(EnvData *envData);
int get_help(EnvData *envData);

#endif
