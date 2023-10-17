#include "main.h"

/**
 * exec_line - finds builtins and commands
 *
 * @dath: data relevant (args)
 * Return: 1 on success.
 */
int exec_line(dt_sh *dath)
{
    int (*builtin)(dt_sh *dath);

    if (dath->args[0] == NULL)
        return (1);

    builtin = get_builtin(dath->args[0]);

    if (builtin != NULL)
        return (builtin(dath));

    return (cmd_exec(dath));
}

