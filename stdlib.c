#include "main.h"

/**
 * get_len - Get the length of a number.
 * @num: type int number.
 * Return: Length of a number.
 */
int get_len(int num)
{
    unsigned int n1;
    int length = 1;

    if (num < 0)
    {
        length++;
        n1 = num * -1;
    }
    else
    {
        n1 = num;
    }
    while (n1 > 9)
    {
        length++;
        n1 = n1 / 10;
    }

    return length;
}

/**
 * aux_itoa - function converts int to string.
 * @num: type int number
 * Return: String.
 */
char *aux_itoa(int num)
{
    unsigned int n1;
    int length = get_len(num);
    char *buffer;

    buffer = malloc(sizeof(char) * (length + 1));
    if (buffer == 0)
        return (NULL);

    *(buffer + length) = '\0';

    if (num < 0)
    {
        n1 = num * -1;
        buffer[0] = '-';
    }
    else
    {
        n1 = num;
    }

    length--;
    do {
        *(buffer + length) = (n1 % 10) + '0';
        n1 = n1 / 10;
        length--;
    } while (n1 > 0);

    return buffer;
}

/**
 * _atoi - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */
int _atoi(char *str)
{
    unsigned int count = 0, size = 0, result = 0, sign = 1, multiplier = 1, i;

    while (*(str + count) != '\0')
    {
        if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
        {
            break;
        }

        if (*(str + count) == '-')
        {
            sign *= -1;
        }

        if ((*(str + count) >= '0') && (*(str + count) <= '9'))
        {
            if (size > 0)
            {
                multiplier *= 10;
            }
            size++;
        }
        count++;
    }

    for (i = count - size; i < count; i++)
    {
        result = result + ((*(str + i) - '0') * multiplier);
        multiplier /= 10;
    }
    return (result * sign);
}

