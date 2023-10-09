#include "main.h"

/**
 *changeCurrentDirectoryDot - Changes the current directory for "." case
 *@oldpwd: Pointer to the previous working directory (OLDPWD)
 *@newpwd: Pointer to the new working directory (PWD)
 *@status: Pointer to the shell status
 *This function handles changing the current directory when the "cd ." command
 *is used. It updates the environment variables and status accordingly.
 */
void changeCurrentDirectoryDot(char *oldpwd, char *newpwd, int *status)
{/* Get the current working directory. */
char pwd[PATH_MAX];
getcwd(pwd, sizeof(pwd));
char *cp_pwd = _strdup(pwd);/* Create copies of the current working directory. */
strcpy(oldpwd, cp_pwd);/* Set the 'OLDPWD' environment variable to the previous working directory. */
/* Get the directory argument passed to the function. */
/*char *dir = datash->args[1];*/
if (_strcmp(".", dir) == 0)/* Check if the argument is "." (current directory). */
strcpy(newpwd, cp_pwd);/* Set the 'PWD' environment variable to the current directory. */
free(cp_pwd);/* Free the memory allocated for 'cp_pwd'. */
*status = 0;/* Set the status to 0 (indicating success). */
return;
}
if (_strcmp("/", cp_pwd) == 0)/* Check if the current working directory is the root directory "/". */
{
free(cp_pwd);/* Free the memory allocated for 'cp_pwd'. */
return;
}
char *cp_strtok_pwd = cp_pwd;/* Create a copy of 'cp_pwd' for tokenization. */
rev_string(cp_strtok_pwd); /* Reverse the copy for tokenization. */
cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");/* Tokenize the reversed string by '/' to get the parent directory. */
if (cp_strtok_pwd != NULL)
{
cp_strtok_pwd = _strtok(NULL, "\0");/* Tokenize again to get the final new directory name. */
if (cp_strtok_pwd != NULL)
rev_string(cp_strtok_pwd);/* Reverse the final directory name. */
}
if (cp_strtok_pwd != NULL)
{
chdir(cp_strtok_pwd);/* Set the 'PWD' environment variable to the new directory. */
strcpy(newpwd, cp_strtok_pwd);
}
else
{
chdir("/");/* Change the current directory to the root directory "/". */
strcpy(newpwd, "/");/* Set the 'PWD' environment variable to the root directory. */
}
*status = 0;/* Set the status to 0 (indicating success). */
free(cp_pwd);/* Free the memory allocated for 'cp_pwd'. */
}

/**
 *  * changeCurrentDirectoryPrevious - Changes the current directory to the previous directory
 *   *
 *    * This function changes the current working directory to the previous working directory,
 *     * updates the environment variables 'PWD' and 'OLDPWD' accordingly, and sets the status
 *      * to 0 (indicating success).
 *       *
 *        * @param oldpwd Pointer to the previous working directory (OLDPWD).
 *         * @param newpwd Pointer to the new working directory (PWD).
 *          * @param status Pointer to the shell status.
 *           */
void changeCurrentDirectoryPrevious(char *oldpwd, char *newpwd, int *status)
{
char pwd[PATH_MAX];
getcwd(pwd, sizeof(pwd));
char *cp_pwd = _strdup(pwd);
char *p_oldpwd = _getenv("OLDPWD", environ);
if (!p_oldpwd)
{
p_oldpwd = cp_pwd;
}

set_env("OLDPWD", cp_pwd);
if (chdir(p_oldpwd) == -1)
{
set_env("PWD", cp_pwd);
}
else
{
set_env("PWD", p_oldpwd);
}
write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
write(STDOUT_FILENO, "\n", 1);
free(cp_pwd);
*status = 0;
chdir(p_pwd);
}
/**
 *changeCurrentDirectoryToHome - Changes the current directory to the user's home directory
 *This function changes the current working directory to the user's home directory,
 *updates the environment variables 'PWD' and 'OLDPWD' accordingly, and sets the status
 *to 0 (indicating success).
 *@param oldpwd Pointer to the previous working directory (OLDPWD).
 *@param newpwd Pointer to the new working directory (PWD).
 *@param status Pointer to the shell status.
 */
void changeCurrentDirectoryToHome(char *oldpwd, char *newpwd, int *status)
{
char pwd[PATH_MAX];
getcwd(pwd, sizeof(pwd));
char *p_pwd = _strdup(pwd);
char *home = getenv("HOME");
if (!home)
{
set_env("OLDPWD", p_pwd);
free(p_pwd);
return;
}
if (chdir(home) == -1)
{
perror("chdir");
free(p_pwd);
return;
}
set_env("OLDPWD", p_pwd);
set_env("PWD", home);
free(p_pwd);
*status = 0;
}
#include "main.h"

/**
 *  * cd_shell - changes current directory
 *   *
 *    * @dir: directory path to change to
 *     * Return: 1 on success
 *      */
int cd_shell(const char *dir)
{
int ishome, ishome2, isddash;
if (dir != NULL)
{
ishome = _strcmp("$HOME", dir);
ishome2 = _strcmp("~", dir);
isddash = _strcmp("--", dir);
}
if (dir == NULL || !ishome || !ishome2 || !isddash)
{
cd_to_home();
return (1);
}
if (_strcmp("-", dir) == 0)
{
cd_previous();
return (1);
}
if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
{
cd_dot();
return (1);
}
cd_to(dir);

return (1);
}
/* changeCurrentDirectoryTo - Changes the current directory to a given directory
	*This function changes the current working directory to the specified directory,
	*updates the environment variables 'PWD' and 'OLDPWD' accordingly and sets the status
	*to 0 (indicating success).
	*@param my_data Pointer to the data_shell structure or equivalent.
	*@param dir The directory to change to.
	**/
void changeCurrentDirectoryTo(data_shell *my_data, const char *dir)
{
char pwd[PATH_MAX];
getcwd(pwd, sizeof(pwd));
if (chdir(dir) == -1)
{
get_error(my_data, 2);
return;
}
char *cp_pwd = _strdup(pwd);
set_env("OLDPWD", cp_pwd, my_data);
free(cp_pwd);
char *cp_dir = _strdup(dir);
set_env("PWD", cp_dir, my_data);
free(cp_dir);
my_data->status = 0;
}
