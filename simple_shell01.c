#include "main.h"
/*Include header file named "main.h" (contains necessary declarations)*/

/*
*wordsparser_args - parses words from an input string
*@args - stores an array of strings
*@char *input and  @char *args: are function's parameters or arguments
*/
int wordsparser_args(char *input, char *args[])
{
int arg_count = 0;/* Initialize the argument count to zero*/
 /*Tokenize the input string using space, tab, and newline as delimiters*/
char *token = strtok(input, " \t\n");
while (token != NULL)/*process tokens till no more found*/
{
args[arg_count++] = token;/*Store token in [args] & increment argument count*/
token = strtok(NULL, " \t\n");/* Get the next token*/
if (arg_count >= MAX_ARGS)/*Check if argument count exceed allowed limit*/
{
fprintf(stderr, "Too many arguments.\n"); /*Print an error message to stderr*/
exit(EXIT_FAILURE);  /* Exit the program with a failure status*/
}
}
args[arg_count] = NULL;/*Null-terminate the argument list*/
return (arg_count);/*Return the argument count*/
}
/*
 * int main - its the program main entry point
 * return 0 - on success
 */
int main(void)
{
char input[MAX_INPUT_LENGTH];  /*Declare an input buffer*/
char *args[MAX_ARGS]; /* Declare an array to store parsed arguments*/
int arg_count;
while (1)
{
/*STDOUT_FILENO-constant file descriptor defined in <unistd.h>*/
write(STDOUT_FILENO, "SteveMax$$$ ", 12);  /*Display the shell prompt*/
if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)/*get user input line*/
{
break;  /*Exit the loop if an error occurs or end of file (Ctrl+D) is reached*/
}
input[strcspn(input, "\n")] = '\0';  /*Remove newline character if present*/
arg_count = wordsparser_args(input, args);  /*Parse input to arguments*/
if (arg_count > 0)/*Check if there are valid arguments*/
{
pid_t pid = fork();/*Fork a new process*/
if (pid == -1)
{
perror("fork");  /*Print an error message if fork fails*/
exit(EXIT_FAILURE);  /*Exit the program with a failure status*/
}
else if (pid == 0) /*Child process*/
{
execvp(args[0], args);  /*Execute the command specified by the user*/
perror("execvp");  /* Print an error message if execvp fail*/
exit(EXIT_FAILURE);  /*Exit the child process with a failure status*/
}
else
{/* Parent process creation*/
int status;
if (arg_count > 1 && strcmp(args[arg_count - 1], "&") != 0)
{
waitpid(pid, &status, 0);
/*Wait for the child process to finish if it's not a background process*/
}
}
}
}
write(STDOUT_FILENO, "\n", 1);  /* Display a newline character*/
return (0);  /* Return 0 to indicate successful execution*/
}
