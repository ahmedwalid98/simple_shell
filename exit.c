#include "shell.h"
/**
 ** _strncpy - copies string
 * @dest: the destination of the string
 * @src: the source of the string
 * @n: the amount of chars
 * Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
while (src[i] != '\0' && i < n - 1)
{
dest[i] = src[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (s);
}
/**
 ** _strncat - concatenates 2 strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be used
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}
/**
 ** _strchr - locates a character in string
 * @s: string
 * @c: the character
 * Return: (s)
 */
char *_strchr(char *s, char c)
{
do
{
if (*s == c)
return (s);
}
while (*s++ != '\0');
return (NULL);
}
