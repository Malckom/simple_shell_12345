#include "main.h"

/**
 * without_comment - deletes comments from the input
 *
 * @input: its the input string
 * Return: input less comment
 */
char *without_comment(char *input)
{
    int i, up_to;

    up_to = 0;
    for (i = 0; input[i]; i++)
    {
        if (input[i] == '#')
        {
            if (i == 0)
            {
                free(input);
                return (NULL);
            }

            if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
                up_to = i;
        }
    }

    if (up_to != 0)
    {
        input = _realloc(input, i, up_to + 1);
        input[up_to] = '\0';
    }

    return (input);
}
/**
 * shell_loop - Loop of shell
 * @dath: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(dt_sh *dath)
{
    int loop, i_eof;
    char *input;

    loop = 1;
    while (loop == 1)
    {
        write(STDIN_FILENO, "^-^ ", 4);
        input = read_line(&i_eof);
        if (i_eof != -1)
        {
            input = without_comment(input);
            if (input == NULL)
                continue;

            if (check_syntax_error(dath, input) == 1)
            {
                dath->status = 2;
                free(input);
                continue;
            }
            input = rep_var(input, dath);
            loop = split_commands(dath, input);
            dath->counter += 1;
            free(input);
        }
        else
        {
            loop = 0;
            free(input);
        }
    }
}
