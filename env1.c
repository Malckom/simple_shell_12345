#include "main.h"
/**
 * cmp_env_name - compares environment variable names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if they are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
    int i;

    for (i = 0; nenv[i] != '='; i++)
    {
        if (nenv[i] != name[i])
        {
            return (0);
        }
    }

    return (i + 1);
}

/**
 * _getenv - get an environment variable
 * @name: name of the environment variable
 * @environ: environment variable
 *
 * Return: value of the environment variable if found.
 * In other cases, returns NULL.
 */
char *_getenv(const char *name, char **environ)
{
    char *ptr_env;
    int i, mov;

    /* Initialize ptr_env value */
    ptr_env = NULL;
    mov = 0;
    /* Compare all environment variables */
    for (i = 0; environ[i]; i++)
    {
        /* If name and env are equal */
        mov = cmp_env_name(environ[i], name);
        if (mov)
        {
            ptr_env = environ[i];
            break;
        }
    }

    return (ptr_env + mov);
}

/**
 * _env - prints the environment variables
 *
 * @dath: data relevant.
 * Return: 1 on success.
 */
int _env(dt_sh *dath)
{
    int i, j;

    for (i = 0; dath->_environ[i]; i++)
    {
        for (j = 0; dath->_environ[i][j]; j++)
            ;

        write(STDOUT_FILENO, dath->_environ[i], j);
        write(STDOUT_FILENO, "\n", 1);
    }
    dath->status = 0;

    return (1);
}

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
    char *new;
    int len_name, len_value, len;

    len_name = _strlen(name);
    len_value = _strlen(value);
    len = len_name + len_value + 2;
    new = malloc(sizeof(char) * (len));
    _strcpy(new, name);
    _strcat(new, "=");
    _strcat(new, value);
    _strcat(new, "\0");

    return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @dath: data structure (_environ)
 * Return: no return
 */
void set_env(char *name, char *value, dt_sh *dath)
{
    int i;
    char *var_env, *name_env;

    for (i = 0; dath->_environ[i]; i++)
    {
        var_env = _strdup(dath->_environ[i]);
        name_env = _strtok(var_env, "=");
        if (_strcmp(name_env, name) == 0)
        {
            free(dath->_environ[i]);
            dath->_environ[i] = copy_info(name_env, value);
            free(var_env);
            return;
        }
        free(var_env);
    }

    dath->_environ = _reallocdp(dath->_environ, i, sizeof(char *) * (i + 2));
    dath->_environ[i] = copy_info(name, value);
    dath->_environ[i + 1] = NULL;
}

