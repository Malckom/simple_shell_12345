#include "main.h"

/**
 *comma_line - finds builtins and commands
 *@env_data: Environment data relevant (args)
 *Return: 1 on success.
 */
int exec_line(EnvData *env_data)
{
char *cmd = env_data->args[0]; /*Extract the command*/
char **args = env_data->args; /* Extract the arguments*/
if (cmd == NULL)
return (1);
/* Check if the command is a builtin*/
if (strcmp(cmd, "exit") == 0)
{
return point_of_myexit(env_data);
}
else if (strcmp(cmd, "cd") == 0)
{
return my_change_directory(env_data);
}			
/*Handle external commands*/
return exec_command(cmd, args, env_data);
}

