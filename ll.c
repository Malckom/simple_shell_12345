#include "main.h"
#include "envdata.h"

/**
 *exec_line - finds builtins and commands
 *@env_data: Environment data relevant (args)
 *return: 1 on success.
 */
int exec_line(EnvData *env_data)
{
/* Extract the command and arguments from env_data */
char *cmd = env_data->args[0];  /* Extract the command */
char **args = env_data->args;   /* Extract the arguments */
/* Check if the command is NULL */
if (cmd == NULL)
return (1);
/* Check if the command is a builtin */
if (strcmp(cmd, "exit") == 0)
{
return point_of_myexit(env_data);
}
else if (strcmp(cmd, "cd") == 0)
{
return my_change_directory(env_data);
}
/* Handle external commands */
return exec_command(cmd, args, env_data);
}
/* Define the main function or your shell loop */
int main(int argc, char *argv[], char *env[])
{
EnvData env_data;
env_data.env = env;        /* Set the environment */

env_data.path = NULL;      /* Set the path (if needed) */
env_data.args = NULL;      /* Initialize the arguments */
env_data.status = 0;       /* Set the initial status */

/* Your shell loop or input handling code here */
/* You can add your custom code here to read user input, parse it, etc. */
/* ... */
/* Example: Read user input and set env_data.args */
char input[MAX_INPUT_LENGTH];
while (1)
{
printf("$ ");
if (fgets(input, sizeof(input), stdin) == NULL)
{
/* Handle EOF or errors */
break;
}
/* Parse the input and set env_data.args */
env_data.args = _strtok(input, " \t\n");
/* Execute the command with arguments */
exec_line(&env_data);
/* Reset arguments for the next iteration */
env_data.args = NULL;
}
/* Cleanup and exit */
return (0);
}

