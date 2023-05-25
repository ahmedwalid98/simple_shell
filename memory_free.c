#include "shell.h"
/**
 * bfree - frees pointer
 * @ptr: address of the free pointer
 * Return: 1 on right 0 on fail
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
