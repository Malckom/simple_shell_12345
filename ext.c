#include "main.h"

/**
 * exit_shell - exits the shell
 *
 * @dt_sh: data relevant (status and args)
 * Return: 0 on success.
 */
int exit_shell(dt_sh *dath)
{
    unsigned int ustatus;
    int is_digit;
    int str_len;
    int big_number;

    if (dath->args[1] != NULL)
    {
        ustatus = _atoi(dath->args[1]);
        is_digit = _isdigit(dath->args[1]);
        str_len = _strlen(dath->args[1]);
        big_number = ustatus > (unsigned int)INT_MAX;
        if (!is_digit || str_len > 10 || big_number)
        {
            get_error(dath, 2);
            dath->status = 2;
            return (1);
        }
        dath->status = (ustatus % 256);
    }
    return (0);
}

