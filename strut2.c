#include "main.h"

/**
 * _strdup - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
    char *new;
    size_t length;

    length = _strlen(s);
    new = malloc(sizeof(char) * (length + 1));
    if (new == NULL)
        return (NULL);
    _memcpy(new, s, length + 1);
    return (new);
}

/**
 * _strlen - Returns the length of a string.
 * @s: Type char pointer
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
    int length;

    for (length = 0; s[length] != 0; length++)
    {
    }
    return length;
}

/**
 * cmp_chars - compare characters of strings
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: 1 if characters are equal, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
    unsigned int i, j, count;

    for (i = 0, count = 0; str[i]; i++)
    {
        for (j = 0; delim[j]; j++)
        {
            if (str[i] == delim[j])
            {
                count++;
                break;
            }
        }
    }
    if (i == count)
        return 1;
    return 0;
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @delim: delimiter.
 *
 * Return: string split.
 */
char *_strtok(char str[], const char *delim)
{
    static char *splitted, *str_end;
    char *str_start;
    unsigned int i, bool;

    if (str != NULL)
    {
        if (cmp_chars(str, delim))
            return NULL;
        splitted = str; /* Store first address */
        i = _strlen(str);
        str_end = &str[i]; /* Store last address */
    }
    str_start = splitted;
    if (str_start == str_end) /* Reaching the end */
        return NULL;

    for (bool = 0; *splitted; splitted++)
    {
        /* Breaking loop finding the next token */
        if (splitted != str_start)
            if (*splitted && *(splitted - 1) == '\0')
                break;
        /* Replacing delimiter for a null char */
        for (i = 0; delim[i]; i++)
        {
            if (*splitted == delim[i])
            {
                *splitted = '\0';
                if (splitted == str_start)
                    str_start++;
                break;
            }
        }
        if (bool == 0 && *splitted) /* Str != Delim */
            bool = 1;
    }
    if (bool == 0) /* Str == Delim */
        return NULL;
    return str_start;
}

/**
 * _isdigit - defines if the string passed is a number
 *
 * @s: input string
 * Return: 1 if the string is a number, 0 in other cases.
 */
int _isdigit(const char *s)
{
    unsigned int i;

    for (i = 0; s[i]; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return 0;
    }
    return 1;
}

