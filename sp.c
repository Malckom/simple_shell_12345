#include "main.h"
/**
 * split_line - a function to split tokens from  the buffer
 * @line: the input from the user
 * @tokens: an array to store the split chars
 * Return: returns total count of tokens
**/
int split_line(char *line, char *tokens[])
{
	int token_count = 0;
	char *token = strtok(line, " \t\n");

	while (token != NULL)
	{
		tokens[token_count] = token;
		token_count++;
		token = strtok(NULL, " \t\n");
	}

	tokens[token_count] = NULL;
	return (token_count);
}
