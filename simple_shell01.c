#include "main.h"

/**
 * execute - a function to execute a particular command
 * @args: an array of exec commands
 * Return: returns a function
 */
int execute(char *args[])
{
int background = 0;
int i;
if (args[0] == NULL)
{
return (1);
}
if (strcmp(args[0], "exit") == 0)
{
exit(EXIT_SUCCESS);
}
else if (strcmp(args[0], "cd") == 0)
{
if (args[1] == NULL)
{
fprintf(stderr, "shell: expected argument to 'cd'\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("shell");
}
}
return (1);
}
for (i = 0; args[i] != NULL; i++)
{
if (strcmp(args[i], "&") == 0)
{
background = 1;
args[i] = NULL;
break;
}
}
return (launch(args, background));
}

/**
 * launch - a function to execute the command
 * @args: args to be executed
 * @background: flag for running in the background
 * Return: returns 1
 */
int launch(char *args[], int background)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("shell");
exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("shell");
}
else
{
if (!background)
{
do {
pid = waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
}
return (1);
}

int main(void)
{
char input[MAX_INPUT_LENGTH];
char *args[MAX_ARGS];
int arg_count;
while (1)
{
char *token;
int input_length;
write(STDOUT_FILENO, "#cisfun$ ", 9);
fflush(stdout);
if (fgets(input, sizeof(input), stdin) == NULL)
{
write(STDOUT_FILENO, "\n", 1);
break;
}
input_length = strlen(input);
if (input_length > 0 && input[input_length - 1] == '\n')
{
input[input_length - 1] = '\0';
}
arg_count = 0;
token = strtok(input, " ");
while (token != NULL && arg_count < MAX_ARGS - 1)
{
args[arg_count] = token;
arg_count++;
token = strtok(NULL, " ");
}
args[arg_count] = NULL;
if (arg_count > 0)
{
int result = execute(args);
(void)result; /* Suppress unused variable warning */
}
}
return (0);
}

