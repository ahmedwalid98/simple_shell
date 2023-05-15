#include "main.h"
/**
 * main - entry point
 * @argc: arguments number
 * @argv: pointer to some arguments
 * Return: 0 if success
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
char *input = NULL;
size_t input_size = 0;
const char *delim = " \n";
ssize_t nchars_read;
char **s;
size_t len;
char **tokens;
while (1)
{
write(STDOUT_FILENO, "$ ", 2);
nchars_read = _getline(&input, &input_size, stdin);
if (nchars_read == -1)
{
break;
}
if (_strcmp(input, "exit") == 0)
{
exit(0);
}
if (_strcmp(input, "env") == 0)
{
s = environ;
for (s = environ; *s; s++)
{
len = _strlen(*s);
write(STDOUT_FILENO, *s, len);
write(STDOUT_FILENO, "\n", 1);
}
}
else
{
tokens = tokenize_input(input, delim);
exec(tokens);
free(tokens);
}
}
return (0);
}
