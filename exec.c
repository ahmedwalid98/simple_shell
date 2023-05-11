#include "main.h"

void exec(char **argv)
{
char *command = NULL;

if (argv)
{
command = argv[0];


if (execve(command, argv, NULL) == -1)
{
write(STDOUT_FILENO, "./hsh: No such file or directory\n", 33);
}

}

}
