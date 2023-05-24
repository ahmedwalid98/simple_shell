#include "main.h"
/**
 * tokenize_input - tokenize input string into array of strings
 * @input: input string to tokenize
 * @delim: delimiter used for tokenization
 *
 * Return: array of strings containing tokens
 */
char **tokenize_input(char *input, const char *delim)
{
char **argv;
char *input_copy;
char *token;
int i, j,num_tokens = 0;
int nchars_read = _strlen(input);
input_copy = malloc(sizeof(char *) * nchars_read);
if (input_copy == NULL)
{
perror("allocation");
return (NULL);
}
_strcpy(input_copy, input);
token = strtok(input, delim);
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;
argv = malloc(sizeof(char *) * num_tokens);
if (argv == NULL)
{
	free(input_copy);
	return (NULL);
}
token = strtok(input_copy, delim);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * _strlen(token));
if (argv[i] == NULL)
{
	for (j = 0; j <= i; j++)
		free(argv[j]);
	free(argv);
	free(input_copy);
	return (NULL);
}
_strcpy(argv[i], token);
token = strtok(NULL, delim);
}
argv[i] = NULL;
free(input_copy);
return (argv);
}
