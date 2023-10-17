#include "main.h"

/**
 * free_data - frees data structure
 *
 * @dath: data structure
 * Return: no return
 */
void free_data(dt_sh *dath)
{
    unsigned int i;

    for (i = 0; dath->_environ[i]; i++)
    {
        free(dath->_environ[i]);
    }

    free(dath->_environ);
    free(dath->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @dath: data structure
 * @av: argument vector
 * Return: no return
 */
void set_data(dt_sh *dath, char **av)
{
    unsigned int i;

    dath->av = av;
    dath->input = NULL;
    dath->args = NULL;
    dath->status = 0;
    dath->counter = 1;

    for (i = 0; environ[i]; i++)
        ;

    dath->_environ = malloc(sizeof(char *) * (i + 1));

    for (i = 0; environ[i]; i++)
    {
        dath->_environ[i] = _strdup(environ[i]);
    }

    dath->_environ[i] = NULL;
    dath->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
    dt_sh dath;
    (void)ac;

    signal(SIGINT, get_sign);
    set_data(&dath, av);
    shell_loop(&dath);
    free_data(&dath);
    if (dath.status < 0)
        return (255);
    return (dath.status);
}

