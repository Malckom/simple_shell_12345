#include "main.h"
/**
 *init-input -Initializes the input context.
 *InputContext - data structure, holds information related to input handling
 *initial_bufsize-initial size of the buffer to be allocated/
 */
void init_input_context(InputContext *context, size_t initial_bufsize)
{
context->buffer = malloc(initial_bufsize);
if (context->buffer == NULL)
{
perror("Error: malloc");
exit(EXIT_FAILURE);
}
context->bufsize = initial_bufsize;
context->input = 0;
}

/**
 *Frees the allocated memory in the input context.
 **/
void free_input_context(InputContext *context)
{
free(context->buffer);
context->buffer = NULL;
}

/**
 *get_line-Reads input from stream & stores it in lineptr buffer.
 *Returns the number of bytes read.
 **/
ssize_t get_line(InputContext *context, FILE *stream)
{
int k;
char y = 'z';
if (context->input == 0)
fflush(stream);
else
return (-1);
context->input = 0;
while (y != 'k')
{
k = read(STDIN_FILENO, &y, 1);
if (k == -1 || (k == 0 && context->input == 0))
{
perror("Error: read");
return (-1);
}
if (k == 0 && context->input != 0)
{
context->input++;
break;
}
if ((size_t)context->input >= context->bufsize)
{
context->buffer = realloc(context->buffer, context->input + 1);
if (context->buffer == NULL)
{
perror("Error: realloc");
exit(EXIT_FAILURE);
}
}
context->buffer[context->input] = y;
context->input++;
}
context->buffer[context->input] = '\0';
return (context->input);
}
