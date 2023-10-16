#include "main.h"

/**
 * get_help - function that retrieves help messages according to the builtin
 * @envData: Environment data structure
 * Return: Return 0
 */
int get_help(EnvData *envData)
{
if (envData->args[1] == NULL)
{
aux_help_general();
}
else if (strcmp(envData->args[1], "help") == 0)
{
aux_help();
}
else if (strcmp(envData->args[1], "exit") == 0)
{
aux_help_exit();
}
else if (strcmp(envData->args[1], "cd") == 0)
{
aux_help_cd();
}
else if (strcmp(envData->args[1], "alias") == 0)
{
aux_help_alias();
}
else if (strcmp(envData->args[1], "setenv") == 0)
{
aux_help_setenv();
}
else if (strcmp(envData->args[1], "env") == 0)
{
aux_help_env();
}
else if (strcmp(envData->args[1], "unsetenv") == 0)
{
aux_help_unsetenv();
}
else
{
write(STDERR_FILENO, envData->args[0], _strlen(envData->args[0]));
}
envData->status = 0;
return (1);
}
