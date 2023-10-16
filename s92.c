#include "main.h"

/**
 * cmp_env_name - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if they are not equal. Another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name) {
    int i;

    for (i = 0; nenv[i] != '='; i++) {
        if (nenv[i] != name[i]) {
            return 0;
        }
    }

    return (i + 1);
}
/**
 * _getenv - get an environment variable using the EnvData structure
 * @name: name of the environment variable
 * @envData: pointer to the environment data structure
 *
 * Return: value of the environment variable if found, NULL otherwise.
 */
char *_getenv_envdata(const char *name, const EnvData *envData) {
   char **_environ = (char **)envData->env;
    char *ptr_env;
    int i, mov;

    /* Initialize ptr_env value */
    ptr_env = NULL;
    mov = 0;
    /* Compare all environment variables */
    for (i = 0; _environ[i]; i++) {
       /* If name and env are equal */
        mov = cmp_env_name(_environ[i], name);
        if (mov) {
            ptr_env = _environ[i];
            break;
        }
    }

    return (ptr_env + mov);
}
/**
 * _env - prints the environment variables
 *
 * @envData: environment data relevant.
 * Return: 1 on success.
 */
int _env(EnvData *envData) {
    char **_environ = (char **)envData->env;
    int i, j;

    for (i = 0; _environ[i]; i++) {
        for (j = 0; _environ[i][j]; j++)
            ;
        write(STDOUT_FILENO, _environ[i], j);
        write(STDOUT_FILENO, "\n", 1);
    }
    envData->status = 0;

    return 1;
}

