#include "main.h"

/**
 *is_cdir - checks ":" if is in the current directory.
 *@path: type char pointer char.
 *u: index pointer
 *return: 0 on failure , 1 0n success.
 */
int is_cdir(char *path, int *u)
{
if (path[*u] == ':')
return (1);
while (path[*u] != ':' && path[*u])
{
*u += 1;
}
if (path[*u])
*u += 1;
return (0);
}

/**
 *is_executable - determines if a file is an executable
 *@envData: structure containing environment variables and path
 *Return: 0 if it's not an executable, the length of the path if it is
 */
int is_xcta(EnvData *envData)
{
struct stat st;
int u = 0;
char *input = envData->path;
switch (input[u])
{
case '.':
if (input[u + 1] == '.')
return 0;
if (input[u + 1] == '/')
break;
else
return 0;
case '/':
if (u != 0)
{
if (input[u + 1] == '.')
break;
u++;
break;
}
default:
break;
}
if (u == 0)
return 0;
if (stat(input + u, &st) == 0)
{
return u;
}
/*Handle the case where the file is not found.*/
return (-1);
}
/**
 *  * _which - Locate the full path of a command in the system
 *   *
 *    * This function searches for the full path of a given command (cid) in the directories listed
 *     * in the PATH environment variable. If the command is found, it returns the full path.
 *      *
 *       * @cid: The command name to locate.
 *        * @_environ: The environment variable.
 *         *
 *          * Return: The full path of the command if found, or NULL if not found.
 *           */
char *_which(char *cid, char **_environ) 
{
char *path, *ptr_path, *token_path, *dir;
int len_dir, len_cid, u;
struct stat st;
path = _getenv("PATH", _environ);
if (path) {
ptr_path = _strdup(path);
len_cid = _strlen(cid);
token_path = _strtok(ptr_path, ":");
u = 0;
while (token_path != NULL) {
switch (is_cdir(path, &u)) {
case 1:
if (stat(cid, &st) == 0)
return (cid);
break;
default:
len_dir = _strlen(token_path);
dir = malloc(len_dir + len_cid + 2);
strcpy(dir, token_path);
strcat(dir, "/");
strcat(dir, cid);
strcat(dir, "\0");
if (stat(dir, &st) == 0) {
free(ptr_path);
return (dir);
}
free(dir);
token_path = _strtok(NULL, ":");
}
}
free(ptr_path);
/*Handle the case where the command is not found*/
return (NULL);
}
if (cid[0] == '/') {
if (stat(cid, &st) == 0)
return (cid);
}
/*Handle the case where the command is not found*/
return (NULL);
}



