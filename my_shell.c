#include "main.h"
int main(int argc, char **argv)
{
char *input = NULL;
size_t input_size = 0;
int i = 0;
char *input_copy = NULL;
const char *delim = " \n";
ssize_t nchars_read;
char *token;
int num_tokens = 0;
(void)argc;
while (1)
{
write(STDOUT_FILENO, "$ ", 2);
nchars_read = getline(&input, &input_size, stdin);
if (nchars_read == -1)
{
break;
}
if (_strcmp(input, "exit") == 0)
{
exit(0);
}


input_copy = malloc(sizeof(char *) * nchars_read);
if (input_copy == NULL)
{
perror("allocation");
return (-1);
}



_strcpy(input_copy, input);


token = strtok(input, delim);
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;


argv = malloc(sizeof(char * ) * num_tokens);

token = strtok(input_copy, delim);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * _strlen(token));
_strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;

exec(argv);
}
free(input_copy);
free(input);
return (0);
}
