#include "main.h"

/**
 * Execute a command specified in the EnvData structure.
 *
 * This function finds built-in commands and external commands based on the
 * EnvData structure and executes the appropriate command.
 *
 * Args:
 * - envData: Pointer to the EnvData structure containing command and arguments.
 *
 * Returns:
 * - 1 on success, indicating that the command was executed successfully.
 */
int exec_line(EnvData *envData) {
    int (*builtin)(EnvData *);

    if (envData->args[0] == NULL)
        return (0); /*Success, as there is nothing to execute.*/

   /* builtin = get_builtin(envData->args[0], envData);*/
    builtin = get_builtin(envData->args[0]);
    if (builtin != NULL)
        return builtin(envData);
return exec_command(envData->args[0], envData->args, envData);

    /*return exec_command(envData->args[0], envData);*/
}

