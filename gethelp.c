#include "main.h"
/**
 * get_help - function that retrieves help messages according to the builtin
 * @dath: data structure (args and input)
 * Return: Return 0
 */
int get_help(dt_sh *dath)
{
	char *arg = dath->args[1];

	if (arg == NULL)
		aux_help_general();
	else
	{
		if (_strcmp(arg, "setenv") == 0)
			aux_help_setenv();
		else if (_strcmp(arg, "env") == 0)
			aux_help_env();
		else if (_strcmp(arg, "unsetenv") == 0)
			aux_help_unsetenv();
		else if (_strcmp(arg, "help") == 0)
			aux_help();
		else if (_strcmp(arg, "exit") == 0)
			aux_help_exit();
		else if (_strcmp(arg, "cd") == 0)
			aux_help_cd();
		else if (_strcmp(arg, "alias") == 0)
			aux_help_alias();
		else
			write(STDERR_FILENO, dath->args[0], _strlen(dath->args[0]));
	}

	dath->status = 0;
	return (1);
}

