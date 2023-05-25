#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string to check it's lentgh
 *
 * Return: num of lentgh
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
/**
 * _strcmp - makes a comparison between 2 strings
 * @s1: the first strang
 * @s2: the second strang
 * Return: negative if s1 < s2 and the opposite is righh and positive if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the string to find
 * Return: the address
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * _strcat - concatenates 2 strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
