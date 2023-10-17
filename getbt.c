#include "main.h"

/**
 * get_builtin - returns a function pointer to a builtin command
 * @cmd: command name
 * Return: function pointer to the corresponding builtin command
 */
int (*get_builtin(char *cmd))(dt_sh *)
{
    builtin_t builtin[] = {
        { "env", _env },
        { "exit", exit_shell },
        { "setenv", _setenv },
        { "unsetenv", _unsetenv },
        { "cd", cd_shell },
        { "help", get_help },
        { NULL, NULL }
    };
    int i;

    for (i = 0; builtin[i].name; i++)
    {
        if (_strcmp(builtin[i].name, cmd) == 0)
            break;
    }

    return (builtin[i].p);
}
