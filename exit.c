#include "main.h"
/*
 * get_error -function  reports errors related to the "exit" command
 * @EnvData - contains information about the environment and path for the shell
 * @int error_code - error code to be reported
 */
void get_error(EnvData *env_data, int error_code)
{
(void)env_data;
fprintf(stderr, "Error: Exit failed with code %d\n", error_code);
exit(EXIT_FAILURE);
}
/*
 * exit_shell - function handles "exit" built-in command.
 * @EnvData - has environment, path, and a status code.
 * return - 1 on error, 0 success.
 */
int exit_shell(EnvData *env_data)
{
unsigned int ustatus;
int is_digit;
int str_len;
int big_number;
if (env_data->env[1] != NULL)
{
ustatus = atoi(env_data->env[1]);
is_digit = isdigit(env_data->env[1][0]);
str_len = strlen(env_data->env[1]);
big_number = ustatus > (unsigned int)INT_MAX;
if (!is_digit || str_len > 10 || big_number)
{
get_error(env_data, 2);
return (1);
}
env_data->status = (ustatus % 256);
}
exit(env_data->status);
return (0);
}
