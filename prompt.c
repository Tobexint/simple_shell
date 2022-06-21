#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * Displays a shell prompt for the user to interact with the operating system
 *
 * Main - Entry point
 * Return- Always 0
 *
 */

void  type_prompt(void)
{
static int first_time = 1;
if (first_time) { /*clear screen for the first time*/
const char* CLEAR_SCREEN_ANSI = "\e[1:1H\e[2J";
write(STDOUT_FILENO, CLEAR_SCREEN_ANSI,12);
first_time = 0;
}
printf("#");  /*display prompt*/
}
int main(void)
{
char cmd[100], command[100], *parameters[20];
/* environment variable*/
char *envp[] = { (char*) "PATH=/bin", 0};
while (1) {     /*repeat forever*/
 type_prompt();   /*display prompt on screen*/
 read_command (command, parameters); /* read input from terminal*/
 if (fork() != 0) /* parent*/
   wait (NULL);   /*wait for child*/
 else{
  strcpy (cmd, "/bin/");
  strcat (cmd, command);
  execve (cmd, parameters, envp); /* execute command*/
 }
 if (strmcmp (command, "exit") == 0)
   break;
}

return 0;
