#include "main.h"

/**
 * _strcat - concatenate two strings
 * @destination: char pointer the dest of the copied str
 * @source: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *destination, const char *source)
{
    int i;
    int j;

    for (i = 0; destination[i] != '\0'; i++)
        ;

    for (j = 0; source[j] != '\0'; j++)
    {
        destination[i] = source[j];
        i++;
    }

    destination[i] = '\0';
    return destination;
}

/**
 * _strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{
    size_t index;

    for (index = 0; src[index] != '\0'; index++)
    {
        dest[index] = src[index];
    }
    dest[index] = '\0';

    return dest;
}

/**
 * _strcmp - Function that compares two strings.
 * @string1: type str compared
 * @string2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *string1, char *string2)
{
    int index;

    for (index = 0; string1[index] == string2[index] && string1[index]; index++)
        ;

    if (string1[index] > string2[index])
        return 1;
    if (string1[index] < string2[index])
        return -1;
    return 0;
}

/**
 * _strchr - locates a character in a string,
 * @string: string.
 * @character: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *string, char character)
{
    unsigned int i = 0;

    for (; *(string + i) != '\0'; i++)
        if (*(string + i) == character)
            return string + i;
    if (*(string + i) == character)
        return string + i;
    return '\0';
}

/**
 * _strspn - gets the length of a prefix substring.
 * @input: initial segment.
 * @acceptedBytes: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *input, char *acceptedBytes)
{
    int i, j, bool;

    for (i = 0; *(input + i) != '\0'; i++)
    {
        bool = 1;
        for (j = 0; *(acceptedBytes + j) != '\0'; j++)
        {
            if (*(input + i) == *(acceptedBytes + j))
            {
                bool = 0;
                break;
            }
        }
        if (bool == 1)
            break;
    }
    return i;
}

