#include "main.h"

/**
 * get_sigint - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void get_sign(int sign)
{
(void)sign;
write(STDOUT_FILENO, "\n^-^ ", 5);
}
