#include "main.h"
/**
 * _setenv - compares env variables names
 * with the name passed.
 * @dath: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(dt_sh *dath)
{

    if (dath->args[1] == NULL || dath->args[2] == NULL)
    {
        get_error(dath, -1);
        return (1);
    }

    set_env(dath->args[1], dath->args[2], dath);

    return (1);
}

/**
 * _unsetenv - deletes an environment variable
 *
 * @dath: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(dt_sh *dath)
{
    char **realloc_environ;
    char *var_env, *name_env;
    int i, j, k;

    if (dath->args[1] == NULL)
    {
        get_error(dath, -1);
        return (1);
    }
    k = -1;
    for (i = 0; dath->_environ[i]; i++)
    {
        var_env = _strdup(dath->_environ[i]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, dath->args[1]) == 0)
        {
            k = i;
        }
        free(var_env);
    }
    if (k == -1)
    {
        get_error(dath, -1);
        return (1);
    }
    realloc_environ = malloc(sizeof(char *) * (i));
    for (i = j = 0; dath->_environ[i]; i++)
    {
        if (i != k)
        {
            realloc_environ[j] = dath->_environ[i];
            j++;
        }
    }
    realloc_environ[j] = NULL;
    free(dath->_environ[k]);
    free(dath->_environ);
    dath->_environ = realloc_environ;
    return (1);
}

/**
 * get_error - calls the error according to the builtin, syntax or permission
 * @dath: data structure that contains arguments
 * @eval: error value
 * Return: error
 */
int get_error(dt_sh *dath, int eval)
{
    char *error;

    switch (eval)
    {
    case -1:
        error = error_env(dath);
        break;
    case 126:
        error = error_path_126(dath);
        break;
    case 127:
        error = error_not_found(dath);
        break;
    case 2:
        if (_strcmp("exit", dath->args[0]) == 0)
            error = error_exit_shell(dath);
        else if (_strcmp("cd", dath->args[0]) == 0)
            error = error_get_cd(dath);
        break;
    }

    if (error)
    {
        write(STDERR_FILENO, error, _strlen(error));
        free(error);
    }

    dath->status = eval;
    return (eval);
}

