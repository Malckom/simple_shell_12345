#include "main.h"

/**
 * cd_shell - changes current directory
 *
 * @dath: data relevant
 * Return: 1 on success
 */
int cd_shell(dt_sh *dath)
{
    char *dir;
    int ishome, ishome2, isddash;

    dir = dath->args[1];

    if (dir != NULL)
    {
        ishome = _strcmp("$HOME", dir);
        ishome2 = _strcmp("~", dir);
        isddash = _strcmp("--", dir);
    }

    if (dir == NULL || !ishome || !ishome2 || !isddash)
    {
        cd_to_home(dath);
        return (1);
    }

    if (_strcmp("-", dir) == 0)
    {
        cd_previous(dath);
        return (1);
    }

    if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
    {
        cd_dot(dath);
        return (1);
    }

    cd_to(dath);

    return (1);
}
#include "main.h"

/**
 * cd_dot - changes to the parent directory
 *
 * @dath: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot(dt_sh *dath)
{
    char pwd[PATH_MAX];
    char *dir, *cp_pwd, *cp_strtok_pwd;

    getcwd(pwd, sizeof(pwd));
    cp_pwd = _strdup(pwd);
    set_env("OLDPWD", cp_pwd, dath);
    dir = dath->args[1];
    if (_strcmp(".", dir) == 0)
    {
        set_env("PWD", cp_pwd, dath);
        free(cp_pwd);
        return;
    }
    if (_strcmp("/", cp_pwd) == 0)
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
        set_env("PWD", cp_strtok_pwd, dath);
    }
    else
    {
        chdir("/");
        set_env("PWD", "/", dath);
    }
    dath->status = 0;
    free(cp_pwd);
}

/**
 * cd_to - changes to a directory given by the user
 *
 * @dath: data relevant (directories)
 * Return: no return
 */
void cd_to(dt_sh *dath)
{
    char pwd[PATH_MAX];
    char *dir, *cp_pwd, *cp_dir;

    getcwd(pwd, sizeof(pwd));
    dir = dath->args[1];
    if (chdir(dir) == -1)
    {
        get_error(dath, 2);
        return;
    }
    cp_pwd = _strdup(pwd);
    set_env("OLDPWD", cp_pwd, dath);
    cp_dir = _strdup(dir);
    set_env("PWD", cp_dir, dath);
    free(cp_pwd);
    free(cp_dir);
    dath->status = 0;
    chdir(dir);
}

/**
 * cd_previous - changes to the previous directory
 *
 * @dath: data relevant (environ)
 * Return: no return
 */
void cd_previous(dt_sh *dath)
{
    char pwd[PATH_MAX];
    char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

    getcwd(pwd, sizeof(pwd));
    cp_pwd = _strdup(pwd);
    p_oldpwd = _getenv("OLDPWD", dath->_environ);
    if (p_oldpwd == NULL)
        cp_oldpwd = cp_pwd;
    else
        cp_oldpwd = _strdup(p_oldpwd);
    set_env("OLDPWD", cp_pwd, dath);
    if (chdir(cp_oldpwd) == -1)
        set_env("PWD", cp_pwd, dath);
    else
        set_env("PWD", cp_oldpwd, dath);
    p_pwd = _getenv("PWD", dath->_environ);
    write(STDOUT_FILENO, p_pwd, _strlen(p_pwd));
    write(STDOUT_FILENO, "\n", 1);
    free(cp_pwd);
    if (p_oldpwd)
        free(cp_oldpwd);
    dath->status = 0;
    chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 *
 * @dath: data relevant (environ)
 * Return: no return
 */
void cd_to_home(dt_sh *dath)
{
    char *p_pwd, *home;
    char pwd[PATH_MAX];

    getcwd(pwd, sizeof(pwd));
    p_pwd = _strdup(pwd);
    home = _getenv("HOME", dath->_environ);
    if (home == NULL)
    {
        set_env("OLDPWD", p_pwd, dath);
        free(p_pwd);
        return;
    }
    if (chdir(home) == -1)
    {
        get_error(dath, 2);
        free(p_pwd);
        return;
    }
    set_env("OLDPWD", p_pwd, dath);
    set_env("PWD", home, dath);
    free(p_pwd);
    dath->status = 0;
}

