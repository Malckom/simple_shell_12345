#include "main.h"

/**
 * read_line - gets and splits the line
 * @i_eof: return value of getline function
 * Return: line
 */
char *read_line(int *i_eof)
{
char *line = NULL;
size_t len = 0;
ssize_t read_buff;
char *token;
/* prompt and read line */
write(STDOUT_FILENO, "#stevemax$$ ", 12);
read_buff = getline(&line, &len, stdin);
if (read_buff == -1)
{
free(line);
exit(EXIT_FAILURE);
}
/* Tokenize the line */
token =_ strtok(line, "\t\n");
*i_eof = (int)read_buff; /*Store the return value of getline in i_eof*/
return (token);
}

