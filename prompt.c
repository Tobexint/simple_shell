#include "shell.h"

/**
* shellPrompt - shell prompt
* Return: void
*/

void shellPrompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
