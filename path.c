#include "main.h"

/**
 *is_cdir - checks ":" if is in the current directory.
 *@path: type char pointer char.
 *u: index pointer
 *return: 0 on failure , 1 0n success.
 */
int is_cdir(char *path, int *u)
{
if (path[*u] == ':')
return (1);
while (path[*u] != ':' && path[*u])
{
*u += 1;
}
if (path[*u])
*u += 1;
return (0);
}

/**
 *is_executable - determines if a file is an executable
 *@envData: structure containing environment variables and path
 *Return: 0 if it's not an executable, the length of the path if it is
 */
int is_xcta(EnvData *envData)
{
struct stat st;
int u = 0;
char *input = envData->path;
switch (input[u])
{
case '.':
if (input[u + 1] == '.')
return 0;
if (input[u + 1] == '/')
break;
else
return 0;
case '/':
if (u != 0)
{
if (input[u + 1] == '.')
break;
u++;
break;
}
default:
break;
}
if (u == 0)
return 0;
if (stat(input + u, &st) == 0)
{
return u;
}
/*Handle the case where the file is not found.*/
return (-1);
}
/**
 *_which - Locate the full path of a command in the system
 *This function searches for the full path of a given command (cid) in the directories listed
 *in the PATH environment variable. If the command is found, it returns the full path.
 *@cid: The command name to locate.
 *@_environ: The environment variable.
 *return: The full path of the com
*/
/*char *_which(const char *cid, const EnvData *envData)
{
    const char **_environ = (const char **)envData->env;
    const char *path = _getenv("PATH", _environ);

    if (path) {
        char *ptr_path = _strdup(path);
        const size_t len_cid = strlen(cid);
        char *token_path = _strtok(ptr_path, ":");
        int u = 0;
        struct stat st;

        while (token_path != NULL) {
            switch (is_cdir(token_path, &u)) {
                case 1:
                    if (stat(cid, &st) == 0)
                        return (char *)cid;
                    break;
                default:
                    const size_t len_dir = strlen(token_path);
                    char *dir = malloc(len_dir + len_cid + 2);

                    if (dir) {
                        strcpy(dir, token_path);
                        strcat(dir, "/");
                        strcat(dir, cid);

                        if (stat(dir, &st) == 0) {
                            free(ptr_path);
                            return dir;
                        }

                        free(dir);
                    }

                    token_path = _strtok(NULL, ":");
            }
        }

        free(ptr_path);
         Handle the case where the command is not found 
        return NULL;
    }

    if (cid[0] == '/') {
        struct stat st;
        if (stat(cid, &st) == 0)
            return (char *)cid;
    }

    Handle the case where the command is not found 
    return NULL;
}*/

char *_which(const char *cid, const EnvData *envData)
{
    const char **_environ = (const char **)envData->env;
    const char *path = _getenv("PATH", _environ);

    if (path) {
        char *ptr_path = _strdup(path);
        const size_t len_cid = strlen(cid);
        char *token_path = _strtok(ptr_path, ":");
        int u = 0;
        struct stat st;

        while (token_path != NULL) {
            const size_t len_dir = strlen(token_path);
            char *dir = malloc(len_dir + len_cid + 2);

            if (dir) {
                switch (is_cdir(token_path, &u)) {
                    case 1:
                        if (stat(cid, &st) == 0) {
                            free(ptr_path);
                            return (char *)cid;
                        }
                        break;
                    default:
                        strcpy(dir, token_path);
                        strcat(dir, "/");
                        strcat(dir, cid);

                        if (stat(dir, &st) == 0) {
                            free(ptr_path);
                            return dir;
                        }

                        free(dir);
                        break;
                }
            }

            token_path = _strtok(NULL, ":");
        }

        free(ptr_path);
        /* Handle the case where the command is not found */
        return NULL;
    }

    if (cid[0] == '/') {
        struct stat st;
        if (stat(cid, &st) == 0)
            return (char *)cid;
    }

    /* Handle the case where the command is not found */
    return NULL;
}

