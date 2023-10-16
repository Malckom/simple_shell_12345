#include "main.h"
/**
 * cd_dot - changes to the parent directory
 * @EnvData: data relevant (environ)
 * Return: nothing
 */
void cd_dot(EnvData *envData)
{
char pwd[PATH_MAX];
char *dir, *cp_pwd, *cp_strtok_pwd;
getcwd(pwd, sizeof(pwd));
cp_pwd = _strdup(pwd);
set_env("OLDPWD", cp_pwd, envData);
dir = envData->args[1];
if (strcmp(".", dir) == 0)
{
set_env("PWD", cp_pwd, envData);
free(cp_pwd);
return;
}
if (strcmp("/", cp_pwd) == 0)
{
free(cp_pwd);
return;
}
cp_strtok_pwd = cp_pwd;
rev_string(cp_strtok_pwd);
cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
if (cp_strtok_pwd != NULL)
{
cp_strtok_pwd = _strtok(NULL, "\0");
if (cp_strtok_pwd != NULL)
rev_string(cp_strtok_pwd);
}
if (cp_strtok_pwd != NULL)
{
chdir(cp_strtok_pwd);
set_env("PWD", cp_strtok_pwd, envData);
}
else
{
chdir("/");
set_env("PWD", "/", envData);
}
envData->status = 0;
free(cp_pwd);
}

/**
 * cd_to - changes to a directory given by the user
 * @envData: data relevant (directories)
 * Return: no return
 */
void cd_to(EnvData *envData)
{
char pwd[PATH_MAX];
char *dir, *cp_pwd, *cp_dir;
getcwd(pwd, sizeof(pwd));
dir = envData->args[1];
if (chdir(dir) == -1)
{
get_error(envData, 2);
return;
}
cp_pwd = _strdup(pwd);
set_env("OLDPWD", cp_pwd, envData);
cp_dir = _strdup(dir);
set_env("PWD", cp_dir, envData);
free(cp_pwd);
free(cp_dir);
envData->status = 0;
chdir(dir);
}


/**
 * cd_shell - changes current directory
 *
 * @envData: environment data relevant
 * Return: 1 on success
 */
int cd_shell(EnvData *envData)
{
char **args = envData->args;
char *dir;
int ishome, ishome2, isddash;
dir = args[1];
if (dir != NULL)
{
ishome = strcmp("$HOME", dir);
ishome2 = strcmp("~", dir);
isddash = strcmp("--", dir);
}
if (dir == NULL || !ishome || !ishome2 || !isddash)
{
cd_to_home(envData);
return (1);
}
if (strcmp("-", dir) == 0)
{
cd_previous(envData);
return (1);
}
if (strcmp(".", dir) == 0 || strcmp("..", dir) == 0) {
cd_dot(envData);
return (1);
}
cd_to(envData);
return (1);
}
void cd_previous(EnvData *envData)
{
char pwd[PATH_MAX];
const char *const_oldpwd;
const char *const_pwd;
char *cp_pwd, *cp_oldpwd;
getcwd(pwd, sizeof(pwd));
cp_pwd = _strdup(pwd);
const_oldpwd = (const char *)_getenv("OLDPWD", (const char **)envData);
if (const_oldpwd == NULL)
cp_oldpwd = cp_pwd;
else
cp_oldpwd = _strdup(const_oldpwd);
set_env("OLDPWD", cp_pwd, envData);
if (chdir(cp_oldpwd) == -1)
set_env("PWD", cp_pwd, envData);
else
set_env("PWD", cp_oldpwd, envData);
const_pwd = (const char *)_getenv("PWD", (const char **)envData);
write(STDOUT_FILENO, const_pwd, strlen(const_pwd));
write(STDOUT_FILENO, "\n", 1);
free(cp_pwd);
if (const_oldpwd)
free(cp_oldpwd);
envData->status = 0;
chdir(const_pwd);
}
void cd_to_home(EnvData *envData)
{
const char *const_home;
char *p_pwd;
char pwd[PATH_MAX];
getcwd(pwd, sizeof(pwd));
p_pwd = _strdup(pwd);
const_home = (const char *)_getenv("HOME", (const char **)envData);
if (const_home == NULL)
{
set_env("OLDPWD", p_pwd, envData);
free(p_pwd);
return;
}
if (chdir(const_home) == -1)
{
get_error(envData, 2);
free(p_pwd);
return;
}
set_env("OLDPWD", p_pwd, envData);
set_env("PWD", const_home, envData);
free(p_pwd);
envData->status = 0;
}
