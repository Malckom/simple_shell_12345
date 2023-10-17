#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;
/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;
/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

typedef struct data
{
        char **av;
        char *input;
        char **args;
        int status;
        int counter;
        char **_environ;
        char *pid;
} dt_sh;

typedef struct builtin_s
{
    char *name;
    int (*p)(dt_sh *dath);
} builtin_t;

/*sig.c*/
void get_sign(int sign);
/*exit shell*/
int exit_shell(dt_sh *dath);
/*stringuts*/
char *_strcat(char *destination, const char *source);
char *_strcpy(char *dest, char *src);
int _strcmp(char *string1, char *string2);
char *_strchr(char *string, char character);
int _strspn(char *input, char *acceptedBytes);
/*strut2.c*/
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
/*aux_help*/
void aux_help_env(void);
void aux_help_unsetenv(void);
void aux_help_setenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void rev_string(char *s);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

/*stdlib*/
int get_len(int num);
char *aux_itoa(int num);
int _atoi(char *str);
/*cd*/
int cd_shell(dt_sh *dath);
void cd_dot(dt_sh *dath);
void cd_to(dt_sh *dath);
void cd_previous(dt_sh *dath);
void cd_to_home(dt_sh *dath);
/*memutils*/
void _memcpy(void *dest, const void *src, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
/*env.c*/
int cmp_env_name(const char *nenv, const char *name);
char *_getenv(const char *name, char **environ);
int _env(dt_sh *dath);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, dt_sh *dath);
int _setenv(dt_sh *dath);
int _unsetenv(dt_sh *dath);
int get_error(dt_sh *dath, int eval);
/*errorh.c*/
char *strcat_cd(dt_sh *dath, char *msg, char *error, char *ver_str);
char *error_get_cd(dt_sh *dath);
char *error_not_found(dt_sh *dath);
char *error_exit_shell(dt_sh *dath);
char *error_env(dt_sh *dath);
char *error_path_126(dt_sh *dath);
/*main.c*/
void free_data(dt_sh *dath);
void set_data(dt_sh *dath, char **av);
int main(int ac, char **av);
char *without_comment(char *input);
void shell_loop(dt_sh *dath);
/*syerror.c*/
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(dt_sh *dath, char *input, int i, int bool);
int check_syntax_error(dt_sh *dath, char *input);
char *read_line(int *i_eof);
/*rep_var*/
void check_env(r_var **h, char *in, dt_sh *data);
int check_vars(r_var **h, char *in, char *st, dt_sh *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, dt_sh *dath);
/*listops.c*/
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);
void free_rvar_list(r_var **head);
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, dt_sh *dath);
int split_commands(dt_sh *dath, char *input);
char **split_line(char *input);
/*execline.c*/
int exec_line(dt_sh *dath);
/*getbt.c*/
int (*get_builtin(char *cmd))(dt_sh *);
/*gethelp.c*/
int get_help(dt_sh *dath);
/*cmd.c*/
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(dt_sh *dath);
int check_error_cmd(char *dir, dt_sh *dath);
int cmd_exec(dt_sh *dath);

  #endif
