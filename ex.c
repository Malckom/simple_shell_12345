#include "main.h"
/**
 * execute - executes commands
 * @token: the command to be executed
 */
void execute(char *token)
{
	pid_t child_pid;

	/* fork and execute */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		char *args[2];

		args[0] = token;
		args[1] = NULL;

		execve(args[0], args, NULL);

		/* execve failed, command not found */
		perror("./shell");
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

#include "main.h"
/**
 * launch - a function to read the buffer
 *
 * @args: args to be executed
 * @background: the processes id running in the background
 *
 * Return: returns 1
**/
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
	} else if (pid < 0)
	{
		perror("shell");
	} else
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

