#include "shell.h"
/**
 * _memset - fills memory with byte
 * @s: pointer to mem area
 * @b: byte to fill the s with
 * @n: num of bytes
 * Return: (s)
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
/**
 * ffree - frees a string of strings
 * @pp: string power 2
 */
void ffree(char **pp)
{
char **a = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}
/**
 * _realloc - reallocate a memory
 * @ptr: pointer to previous malloc
 * @old_size: old size
 * @new_size: new size
 * Return: pointer to p
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
