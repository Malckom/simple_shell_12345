#include "main.h"

int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
			{
				if (stat(cmd, &st) == 0)
					return cmd;
			}
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return dir;
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return cmd;
		return NULL;
	}
	if (cmd[0] == '/')
	{
		if (stat(cmd, &st) == 0)
			return cmd;
	}
	return NULL;
}

int is_executable(dt_sh *dath)
{
	struct stat st;
    int i = 0;
    char *input = dath->args[0];
    while (input[i])
    {
        switch (input[i])
        {
        case '.':
            if (input[i + 1] == '.')
                return 0;
            if (input[i + 1] == '/')
            {
                i++;
            }
            break;
        case '/':
            if (i != 0 && input[i + 1] != '.')
            {
                i++;
            }
            break;
        default:
            i = input[i] == '.' ? i + 1 : 0;
            if (stat(input + i, &st) == 0)
            {
                return i;
            }
            get_error(dath, 127);
            return -1;
        }
    }
    return 0;
}

int check_error_cmd(char *dir, dt_sh *dath)
{
	if (dir == NULL)
	{
		get_error(dath, 127);
		return 1;
	}

	if (_strcmp(dath->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(dath, 126);
			free(dir);
			return 1;
		}
		free(dir);
	}
	else
	{
		if (access(dath->args[0], X_OK) == -1)
		{
			get_error(dath, 126);
			return 1;
		}
	}

	return 0;
}

int cmd_exec(dt_sh *dath)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(dath);
	if (exec == -1)
		return 1;
	if (exec == 0)
	{
		dir = _which(dath->args[0], dath->_environ);
		if (check_error_cmd(dir, dath) == 1)
			return 1;
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(dath->args[0], dath->_environ);
		else
			dir = dath->args[0];
		execve(dir + exec, dath->args, dath->_environ);
	}
	else if (pd < 0)
	{
		perror(dath->av[0]);
		return 1;
	}
	else
	{
		do
		{
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	dath->status = state / 256;
	return 1;
}

