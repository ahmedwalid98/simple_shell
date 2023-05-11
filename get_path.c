#include "main.h"
/**
 * _getpath - find the path of the program
 * @path: command to find a path from it
 * Return: the actual path
 */
char *_getpath(char *path)
{
	char *comm, *path_copy, *path_token, *path_file;
	int comm_length, dir_length;
	struct stat buffer;

	comm = getenv("PATH");
	if (comm)
	{
		path_copy = strdup(comm);
		comm_length = _strlen(path);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_length = _strlen(path_token);
			path_file = malloc(comm_length + dir_length + 2);
			_strcpy(path_file, path_token);
			_strcat(path_file, "/");
			_strcat(path_file, path);
			_strcat(path_file, "\0");

			if (stat(path_file, &buffer) == 0)
			{
				free(path_copy);
				return (path_file);
			} else
			{
				free(path_file);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(path, &buffer) == 0)
		{
			return (path);
		}
		return (NULL);
	}
	return (NULL);
}
