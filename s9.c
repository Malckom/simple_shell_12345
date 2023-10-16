#include "main.h"
/**
 * copy_info - copies info to create a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(const char *name, const char *value)
{
    char *new;
    size_t len_name, len_value, len;

    len_name = strlen(name);
    len_value = strlen(value);
    len = len_name + len_value + 2;
    new = malloc(sizeof(char) * len);
    if (new)
    {
        strcpy(new, name);
        strcat(new, "=");
        strcat(new, value);
        return new;
    }
    return NULL;
}

/**
 * set_env - sets an environment variable
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @envData: environment data structure
 *
 * Return: no return
 */
void set_env(const char *name, const char *value, EnvData *envData)
{
    int i;
    char *var_env, *name_env;

    for (i = 0; envData->env[i]; i++)
    {
        var_env = strdup(envData->env[i]);
        name_env = strtok(var_env, "=");
        if (strcmp(name_env, name) == 0)
        {
            free(envData->env[i]);
            envData->env[i] = copy_info(name_env, value);
            free(var_env);
            return;
        }
        free(var_env);
    }

    envData->env = realloc(envData->env, sizeof(char *) * (i + 2));
    envData->env[i] = copy_info(name, value);
    envData->env[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names with the name passed.
 * @envData: environment data structure
 *
 * Return: 1 on success.
 */
int _setenv(EnvData *envData)
{
    if (envData->args[1] == NULL || envData->args[2] == NULL)
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return 1;
    }

    set_env(envData->args[1], envData->args[2], envData);

    return 1;
}

/**
 * _unsetenv - deletes an environment variable
 * @envData: environment data structure
 *
 * Return: 1 on success.
 */
int _unsetenv(EnvData *envData)
{
    char **realloc_environ;
    char *var_env, *name_env;
    int i, j, k;

    if (envData->args[1] == NULL)
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return 1;
    }

    k = -1;
    for (i = 0; envData->env[i]; i++)
    {
        var_env = strdup(envData->env[i]);
        name_env = strtok(var_env, "=");
        if (strcmp(name_env, envData->args[1]) == 0)
        {
            k = i;
        }
        free(var_env);
    }
    if (k == -1)
    {
        fprintf(stderr, "Variable not found: %s\n", envData->args[1]);
        return 1;
    }
    realloc_environ = malloc(sizeof(char *) * (i));
    for (i = j = 0; envData->env[i]; i++)
    {
        if (i != k)
        {
            realloc_environ[j] = envData->env[i];
            j++;
        }
    }
    realloc_environ[j] = NULL;
    free(envData->env[k]);
    free(envData->env);
    envData->env = realloc_environ;

    return 1;
}

