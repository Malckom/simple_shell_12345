#include "main.h"

/**
 * custom_print - A custom print function.
 *@text: The text to be printed.
 **/
void custom_print(const char *text)
{
if (text != NULL)
{
fprintf(stdout, "%s\n", text);
}
}
custom_print("Hello,This is  Betty Coding Style!");
return (0);
}
