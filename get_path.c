#include "main.h"
/**
 * _getpath - get the path from the command
 * @pcommand: the command
 * Return: the actual path
 */
char *_getpath(char *pcommand)
{
char *path, *path_copy, *path_token, *fp;
int command_len, dir_len;
struct stat buffer;
path = getenv("PATH");
if (path)
{
path_copy = _strdup(path);
command_len = _strlen(pcommand);
path_token = strtok(path_copy, ":");
while (path_token != NULL)
{
dir_len = strlen(path_token);
fp = malloc(command_len + dir_len + 2);
_strcpy(fp, path_token);
_strcat(fp, "/");
_strcat(fp, pcommand);
_strcat(fp, "\0");
if (stat(fp, &buffer) == 0)
{
free(path_copy);
return (fp);
}
else
{
path_token = strtok(NULL, ":");
}
}
free(path_copy);
if (stat(pcommand, &buffer) == 0)
{
return (pcommand);
}
return (NULL);
}
return (NULL);
}
