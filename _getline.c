#include "main.h"
/**
 * _getline - gets an entire line the user wrote
 * @lineptr: pointer to the line
 * @n: size of the buffer
 * @stream: file stream
 * Return: number of chars read`
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
static char buffer[1024];
static size_t pos;
static size_t size;
size_t count = 0;
char c = '\0';
if (*lineptr == NULL || *n == 0)
{
*lineptr = malloc(128);
*n = 128;
}
while (c != '\n')
{
if (pos >= size)
{
size = read(fileno(stream), buffer, 1024);
if (size == 0)
{
if (count > 0)
{
(*lineptr)[count] = '\0';
return (count);
}
else
{
return (-1);
}
}
pos = 0;
}
c = buffer[pos++];
if (count + 1 >= *n)
{
*n *= 2;
*lineptr = realloc(*lineptr, *n);
}
(*lineptr)[count++] = c;
}
(*lineptr)[count] = '\0';
return (count);
}
