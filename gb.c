#include "main.h"

/**
 * get_builtin - Retrieve a pointer to a built-in function.
 *
 * @cmd: The command name to search for.
 *
 * Return: Pointer to the built-in function or NULL if not found.
 */
/*int (*get_builtin(const char *cmd))(EnvData *) {
    struct builtin_s builtin[] = {
        { "env", _env },
        { "exit", exit_shell },
        { "setenv", _setenv },
        { "unsetenv", _unsetenv },
        { "cd", cd_shell },
        { "help", get_help },
        { NULL, NULL }
    };

    int i;
    for (i = 0; builtin[i].name; i++) {
        if (strcmp(builtin[i].name, cmd) == 0) {
            return builtin[i].p;
        }
    }
*/
  /*  return NULL; Command not found. 
}
*/
int (*get_builtin(const char *cmd))(EnvData *)
{
    builtin_t builtin[] = {
        { "env", _env},
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
        if (strcmp(builtin[i].name, cmd) == 0)
            break;
    }

    return (builtin[i].p);
}

