#include "main.h"
/**
 * aux_help - Help information for the builtin help.
 */
void aux_help(void)
{
char *help = "help: help [-dms] [pattern ...]\n";
write(STDOUT_FILENO, help, strlen(help));
help = "\tDisplay information about builtin commands.\n";
write(STDOUT_FILENO, help, strlen(help));
help = "Displays brief summaries of builtin commands.\n";
write(STDOUT_FILENO, help, strlen(help));
}

/**
 * aux_help_alias - Help information for the builtin alias.
 */
void aux_help_alias(void)
{
char *help = "alias: alias [-p] [name[=value]...]\n";
write(STDOUT_FILENO, help, strlen(help));
help = "\tDefine or display aliases.\n";
write(STDOUT_FILENO, help, strlen(help));
}

/**
 * aux_help_cd - Help information for the builtin cd.
 */
void aux_help_cd(void)
{
char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";
write(STDOUT_FILENO, help, strlen(help));
help = "\tChange the shell working directory.\n";
write(STDOUT_FILENO, help, strlen(help));
}
