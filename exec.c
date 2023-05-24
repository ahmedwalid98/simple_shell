#include "main.h"
/**
 * exec - execute specific process
 * @argv: pointer to some arguments
 * Return: process id
 */
pid_t exec(char **argv)
{
int status;
char *command = NULL, *real_command = NULL;
pid_t pid;
if (argv)
{
command = argv[0];
real_command = _getpath(command);
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(real_command, argv, NULL) == -1)
{
write(STDOUT_FILENO, "./hsh: No such file or directory\n", 33);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}

return (pid);
}
