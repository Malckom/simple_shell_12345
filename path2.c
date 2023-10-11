#include "main.h"
/* Define _getenv */
char *_getenv(const char *name, char **env) 
{
int i;
for (i = 0; env[i] != NULL; i++)
{
if (strncmp(env[i], name, strlen(name)) == 0)
{
return (env[i] + strlen(name) + 1);
}
}
return (NULL);
}
/* Define _strdup */
char *_strdup(const char *s)
{
size_t len = strlen(s) + 1;
char *dup = malloc(len);
if (dup)
{
strcpy(dup, s);
}
return (dup);
}
/* Define _strlen */
size_t _strlen(const char *s)
{
size_t len = 0;
while (s[len] != '\0')
{
len++;
}
return (len);
}
/* Define _strtok */
char *_strtok(char *str, const char *delim)
{
char *end;
static char *token = NULL;
if (str != NULL)
{
token = str;
}
if (token == NULL)
{
return (NULL);
}
end = strpbrk(token, delim);
if (end != NULL)
{
*end = '\0';
token = end + 1;
}
else
{
token = NULL;
}
return (token);
}


/**
 *exec_command - function to  execute all command lines
 *@cid: identity of command
 *@args: arguments for the command
 *@envData: environment data (env and path)
 *Return: 1 on success.
 **/
int exec_command(const char *cmd, char *const args[], const EnvData *envData)
{
pid_t pd;
pid_t wpd;
int state;
int exec;
char *dir;
(void) wpd;
exec = exe_path(cmd,envData);
if (exec == -1)
{
return (1);
}
else if (exec == 0)
{
dir = command_locate(cmd, envData);
if (check_error_cmd(dir, envData) == 1)
{
return (1);
}
}
else
{
}
pd = fork();
if (pd == 0)
{
if (exec == 0)
{
dir = command_locate(cmd, envData);
}
else
{
dir = (char *)cmd;
}
execve(dir, args, envData->env);
perror(args[0]);
return (1);
}
else if (pd == -1)
{
perror(args[0]);
return (1);
}
else
{
do
{
wpd = waitpid(pd, &state, WUNTRACED);
}
while (!WIFEXITED(state) && !WIFSIGNALED(state));
}
return (1);
}
/**
 *check_error_cmd - verifies if user has permissions to access
 *@dir: destination directory
 *@envData: environment data structure
 *Return: 1 if there is an error, 0 if not
 **/
int check_error_cmd(char *dir, const EnvData *envData)
{
if (dir == NULL)
{
/* Handle the case where the directory is NULL*/
return (1);
}
if (strcmp(envData->path, dir) != 0)
{
if (access(dir, X_OK) == -1)
{
/*Handle the case where there's no execute permission*/
free(dir);
return (1);
}
free(dir);
}
else
{
if (access(envData->path, X_OK) == -1)
{
/*Handle the case where there's no execute permission*/
return (1);     
}
}
return (0);
}
